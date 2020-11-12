// aqui pongo las bibliotecas para hacer el segundo problema de este proyecto//
//Programa hecho por Jorge Tejada//
#include <iostream>
#include <string> 
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>


/* aqui úse el namespace de std , chrono y this_thread para este proyecto largo*/
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;


// aqui se declara las funciones del Programa para hacer funcionar el menu//
vector<string>GenerarInventario();
vector<string>AbrirInventario (vector<string>inventory);
vector<string>MenuDeRecoleccion(vector<string>inventory);
vector<string> BuscarRocas(vector<string>inventory);
vector<string>MostrarInventario(vector<string>inventory);


// aqui se declara el cuerpo para que funcione cuando se genera el inventario
vector<string> GenerarInventario()
{

	/* aqui se  declara una variable local que va a generar el inventario */
	vector<string> randomInventory(19, "NA");
	
	const vector<string>  itemsGenerated = { "Hierba mala (HM)", "Gusano dorado (GD)" };
	/* aqui se define lo necesario de rand para los objetos que se generan*/
	int randomItemPos;
	int min = 0;
	int max = itemsGenerated.size()-1;
	int counter = 0;

	/* aqui hace que el counter en el while hace que se llene el inventario de manera random, pero en este caso solo se llenara 7*/
	while (counter < 7)
	{
		
		randomItemPos = rand() % (max - min + 1) + min;
		randomInventory[counter] = itemsGenerated[randomItemPos];
		counter++;
	}

	system("CLS");
	cout << "INVENTORY GENERATED! \n\n" << endl;
	system("pause"); 
	return randomInventory;
}

/* aqui se hace un vector para abrir el inventario de manera que se vea lo que genera */
vector<string>AbrirInventario(vector<string> inventory)
{
	
	bool inventoryOpened = true;
	int userInput;

	while (inventoryOpened)
	{

		
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = INVENTORY = =" << "\n" << endl;

		
		for (int counter = 0; counter < inventory.size(); counter++)
		{

			cout << counter + 1 << ". " << inventory[counter] << endl;
		}
		
		cout << inventory.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		
		cout << "AWAITING USER INPUT:  "; cin >> userInput; 
		if (userInput <= inventory.size())
		{
			inventory.erase(inventory.begin() + userInput - 1);
		}

		else if (userInput == inventory.size() + 1)
		{

			inventoryOpened = false;

		}

		return  inventory;
	}
}
/* aqui se hace un vector espesificamente para buscar rocas y luego de ello se agregan para luego hacer 
  algo que los tome y luego llevarlo al inventario*/
vector<string>MenuDeRecoleccion(vector<string>inventory)
{
	bool MenuRecoleccionAbierto = true;

	int MenuOption;

	while (MenuRecoleccionAbierto)
	{
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = MENU PRINCIPAL DE RECOLECCION DE ROCAS = =" << "\n" << endl;
		cout << "1. BUSCAR ROCAS" << endl;
		cout << "2. MOSTRAR INVENTARIO" << endl;
		cout << "3. EXIT" << endl;
		cout << "===============================================================" << endl;
		cout << "AWAITING USER INPUT:  "; cin >> MenuOption;
		switch (MenuOption)
		{
		case 1:
			inventory = BuscarRocas(inventory);
			break;
		case 2:
			inventory = MostrarInventario(inventory);
			break;
		case 3:
			MenuRecoleccionAbierto = false;
			break;
		default:
			system("CLS");
			break;
		}
	}

	return inventory;

}
/* aqui en este vector se busca las rocas que se quiere buscar */
vector<string> BuscarRocas(vector<string>inventory)
{
	const int InventorySpaceMax = 5;

	int InventorySpaceAvaliable = 0;

	const vector <string>& rocas = { "roca Blanda","roca Dura","roca Cristalina","roca Magica" };

	string UserInput;

	int RocaRandomPos;

	int min = 0;
	int max = rocas.size() - 1;
	system("CLS");

	while (UserInput != "0" && UserInput != "Exit")
	{
		cout << "===========================================================================================" << endl;
		cout << "Esperando una desicion:"; cin >> UserInput; cout << "\n";
		if (UserInput == "b" || UserInput == "B")
		{
			cout << "Buscando.";
			sleep_for(milliseconds(500));
			cout << ".";
			sleep_for(milliseconds(500));
			cout << ".\n\n";

			if (InventorySpaceAvaliable < InventorySpaceMax)
			{

				RocaRandomPos = rand() % (max - min + 1) + min;

				cout << "Has Obtenido: " << rocas[RocaRandomPos] << "\n\n";
				InventorySpaceAvaliable++;

				inventory.push_back(rocas[RocaRandomPos]);

				cout << "Has Recolectado: " << InventorySpaceAvaliable << " de " << InventorySpaceMax << " minerales." << "\n\n";
			}
			else
			{
				cout << "INVENTARIO LLENO";
			}



			

		}
	}

	return inventory;
}
/* aqui se muestra para luego tomarla, pero depende del porcentaje*/
vector<string>MostrarInventario(vector<string>inventory)
{

	bool MostrarInventario = true;

	int UserInputInventory;

	enum Rocas
	{
		roca_blanda,
		roca_Dura,
		roca_Cristalina,
		roca_Magica

	};

	int RocaOportunidad = rand() % 100;

	while (MostrarInventario)
	{
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = INVENTORY = =" << "\n" << endl;
		for (int counter = 0; counter < inventory.size(); counter++)
		{

			cout << counter + 1 << ". " << inventory[counter] << endl;
		}
		cout << inventory.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		cout << "AWAITING USER INPUT:  "; cin >> UserInputInventory;
		if (UserInputInventory <= inventory.size())
		{
			if (RocaOportunidad < 75)
			{
				Rocas rocas = roca_blanda;

				if (RocaOportunidad < 75)
				{
					Rocas rocas = roca_Dura;
				}

				if (RocaOportunidad < 75)
				{
					Rocas rocas = roca_Cristalina;
				}
			}

			else if (RocaOportunidad < 50)
			{


				Rocas rocas = roca_Magica;

				if (RocaOportunidad < 50)
				{
					cout << "Roca Destruida!" << endl;
				}
			}
		}
		else if (UserInputInventory== inventory.size() + 1)
		{

		  MostrarInventario = false;

		}
		else
		{
			inventory.erase(inventory.begin() + UserInputInventory - 1);
		}

		
	}

	return inventory;

}

//Aqui en es donde el Programa contiene todo lo necesario para que funcione correctamente //
int main()
{
	
	srand(time(0));
	//Creamos dos  vectores inventarios del generador y otro para lo de rocas. 
	vector<string> inventory(19, "NA");
	vector<string> inventoryRocas;
	/* aqui luego hacemos un bool para hacer que funcione el menu de manera continua*/
	bool menuAbierto = true;
	/* aqui mostramos a  lo que el usuario va a introducir*/
	int mainMenuOption;
	
	while(menuAbierto)
	{
      
		system("CLS");
	  cout << "===============================================================" << endl;
	  cout << "= = MENU PRINCIPAL = =" << "\n" << endl;
	  cout << "1. GENERAR INVENTARIO" << endl;
	  cout << "2. ABRIR INVENTARIO" << endl;
	  cout << "3. MENU DE RECOLECCION DE ROCAS" << endl;
	  cout << "4. EXIT" << endl;
	  cout << "===============================================================" << endl;
	  
	  cout << "AWAITING USER INPUT:  "; cin >> mainMenuOption;
	  
	  switch (mainMenuOption) 
	  {
		 
	  case 1:
		  inventory = GenerarInventario();
		  break;

	  case 2:
		  inventory = AbrirInventario(inventory);
		  break;

	  case 3:
		  inventory = MenuDeRecoleccion(inventory);
		  break;
	  case 4:
		  menuAbierto = false;
		  break;

	  default:
		  system("CLS");
		  break;
	  }

	}
}