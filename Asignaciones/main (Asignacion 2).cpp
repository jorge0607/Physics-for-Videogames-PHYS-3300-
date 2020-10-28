#include<iostream>
#include<vector>
#include<string>
#include<ctime>

// Incluimos el namespace std. 
using namespace std;

//Declaramos las funciones que usaremos en este programa. 
vector<string> GenerarInventario();
bool UnicaVerificacionDeCristales(vector<string> itemList);
void  AbrirInventario(vector<string>&inventory);
bool EliminarCristal(string Crystal, vector<string> inventory);
void ELiminarObjeto(string Crystal, vector<string> &inventory);
void  MenuDeRecolecciondeObjetos(vector<string> &inventory);
void MenuDeCreacionDeCristalesOpacos(vector<string> &inventory);
bool CrearCristalOpaco(string RawCrystal, vector<string> inventory);
void ReemplazarObjeto(string RawCrystal, string opaqueCrystal, vector<string>&inventory);


//Escribimos el cuerpo de la función GenerarInventario().
vector<string> GenerarInventario()
{
	//Declaramos un inventario (local).
	vector<string> randomInventory(20, "NA");
	//Creamos un vector con todos los objetos posibles. 
	const vector<string> allItems = { "Crystallized Azure Dragon's Tears", "Crystallized Exiled Heretic's Bone", "Crystallized Great Feline's Ash", "Fishermen's Plate", "Iron Plate" };
	const vector<string> allItemsCrystals = { "Crystallized Azure Dragon's Tears", "Crystallized Exiled Heretic's Bone", "Crystallized Great Feline's Ash" };
	//Definimos las variables para el uso del rand().
	int randomItemPos;
	int min = 0;
	int max = allItems.size() - 1;
	//Definimos una variable que nos diga si hay un cristal presente en el inventario.
	bool containsCrystal = false;

	//Declaramos una variable booleana, "longBooleanExpression". Para el control de cristales únicos. 
	bool longBooleanExpression;

	//Declaramos una variable booleana para el control de Fishermen's Plates.
	bool shortBooleanExpression;

	//Declaramos una variable contador para el ciclo while. 
	int counter = 0;

	//Creamos el ciclo que llena el inventario per
	while (counter < 7) {
		//Generamos la posición "random".
		randomItemPos = rand() % (max - min + 1) + min;
		//Usando la función UnicaVerificacionDeCristales, verificamos si hay un cristal en el inventario.
		const int containsCrystal = UnicaVerificacionDeCristales(randomInventory);

		//Si hay el item random escogido es un cristal y HAY un cristal presente en el inventario, entonces esta expresión tomará el valor de true. 
		longBooleanExpression = ((allItems[randomItemPos] == "Crystallized Azure Dragon's Tears") || (allItems[randomItemPos] == "Crystallized Exiled Heretic's Bone") || (allItems[randomItemPos] == "Crystallized Great Feline's Ash")) && containsCrystal;

		//Si hay tres o más Fisherme's Plate en el inventario Y el item random es un Fisherme's Plate, esta variable tomará el valor de true. 
		shortBooleanExpression = (count(randomInventory.begin(), randomInventory.end(), "Fishermen's Plate") >= 3) && (allItems[randomItemPos] == "Fishermen's Plate");

		if (!longBooleanExpression && !shortBooleanExpression) {

			randomInventory[counter] = allItems[randomItemPos];
			counter++; //El counter solo se aumenta cuando se haya agregado algo al inventario. 

		}
	}

	system("CLS");
	cout << "INVENTORY GENERATED! \n\n" << endl;
	system("pause"); //Para esperar que el usuario presione alguna tecla. 
	return randomInventory;
}

//Creamos una función que verifique si ya existe un cristal en la lista pasada como argumento. 
bool UnicaVerificacionDeCristales(vector<string> itemList)
{
	//Declaramos una variable counter por motivos prácticos. 
	int counter = 0;
	//Declaramos una variable que "diga" si hay un cristal en la lista pasada. 
	bool isCrystalPresent = false;
	//Declaramos el "longBooleanExpression". 
	bool longBooleanExpression;
	//Creamos el ciclo que verifica si hay un cristal en el vector (en la lista).
	while ((counter < itemList.size()) && (!isCrystalPresent)) {
		//Verificamos si hay alguno de los cristales en la lista de objetos. 
		longBooleanExpression = (itemList[counter] == "Crystallized Azure Dragon's Tears") || (itemList[counter] == "Crystallized Exiled Heretic's Bone") || (itemList[counter] == "Crystallized Great Feline's Ash");
		//Si hay un cristal, entonces cambiamos el valor de "isRawCrystalPresent" a "true".
		if (longBooleanExpression) {
			isCrystalPresent = true;
		}
		//Aumentamos el counter (ya que el while no lo hace solo).
		counter++;
	}
	return isCrystalPresent;

}

//Creamos una función para ver el inventario y tirar objetos del mismo. 
void AbrirInventario(vector<string> &inventory)
{
	//Declaramos la variable que mantiene el inventario abierto. 
	bool inventoryOpened = true;
	//Declaramos la variable para la entrada del usuario. 
	int userInput;
	/* hacemos un bool que hace que sabemos si existe ese cristal en el inventario*/
	string Crystal = "NA";

	bool isEliminated = false;

	while (inventoryOpened)
	{

		//Encabezado. 
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = INVENTORY = =" << "\n" << endl;

		//Creamos el ciclo que itera sobre el inventario para imprimirlo (mostrarlo en pantalla).
		for (int counter = 0; counter < inventory.size(); counter++)
		{

			cout << counter + 1 << ". " << inventory[counter] << endl;
		}
		//Creamos la opción EXIT.
		cout << inventory.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		//Esperamos la entrada del usuario.
		cout << "AWAITING USER INPUT:  "; cin >> userInput;
		//Si el usuario introduce el número de algún item, entonces borra el item usando erase(). De otra forma, cierra el inventory. 
		if (userInput <= inventory.size())
		{
			switch (userInput)
			{
			case  1:
				Crystal = "Crystallized Azure Dragon's Tears";
				isEliminated = EliminarCristal(Crystal, inventory);
				break;
			case 2:
				Crystal = "Crystallized Exiled Heretic's Bone";
				isEliminated = EliminarCristal(Crystal, inventory);
				break;
			case 3:
				Crystal = "Crystallized Great Feline's Ash";
				isEliminated = EliminarCristal(Crystal, inventory);
				break;

			case 4:
				inventoryOpened = false;
				break;

			default:
				system("CLS");
				break;
			}
		}
		if (isEliminated)
		{

			cout << "Are you sure you want to destroy this crystal ? You won’t be able to gather this unique crystal anymore..." << endl;
			system("pause");
		}

	}
}
/* aqui se hace que cuando revisa si hay un cristal en el inventario*/
bool EliminarCristal(string Crystal, vector<string> inventory)
{
	bool isEliminated = false;

	if (find(inventory.begin(), inventory.end(), Crystal) != inventory.end())
	{

		isEliminated;

	}


	return isEliminated;

}
/* Aqui se hace la idea de en vez de remplazar lo elimina*/
void ELiminarObjeto(string Crystal, vector<string> &inventory)
{
	int counter = 0;

	bool EliminarObjeto = false;

	while (counter < inventory.size() && !ELiminarObjeto) {

		if (inventory[counter] == Crystal)
		{

			inventory.erase(inventory.begin());
			EliminarObjeto;

		}

		counter++;

	}


}

// aqui se hace un menu que es mas o menos al AbrirInventario pero mas reducido//
void MenuDeRecolecciondeObjetos(vector<string> &inventoryItems)
{
	/* hacemos lo mismo como lo hemos hecho con los menus de hacer un bool que mantega abierto el menu*/
	bool GatherInventoryMenuOpen = true;
	/* aqui para el usuario introduza algo*/
	int UserNumberInput;
	/* Hacemos un while para que se vea el menu de recoleccion*/
	while (GatherInventoryMenuOpen)
	{
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = GATHER MENU INVENTORY = =" << "\n" << endl;
		for (int counter = 0; counter < 5; counter++)
		{

			cout << counter + 1 << ". " << inventoryItems[counter] << endl;
		}
		cout << inventoryItems.size() - 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		cout << "AWAITING USER INPUT:  "; cin >> UserNumberInput;
		//Si el usuario introduce el número de algún item, entonces borra el item usando erase(). De otra forma, cierra el inventory//
		if (UserNumberInput <= inventoryItems.size())
		{
			inventoryItems.erase(inventoryItems.begin() + UserNumberInput - 1);
		}

		else if (UserNumberInput == inventoryItems.size() + 1)
		{

			GatherInventoryMenuOpen = false;

		}


	}

}

void MenuDeCreacionDeCristalesOpacos(vector<string> &inventory)
{

	//Declaro la variable que mantiene el inventario abierto.
	bool craftMenuOpen = true;

	//Declaro la variable para la entrada del usuario
	int craftMenuOption;

	while (craftMenuOpen)
	{

		//Declaro dos variables que serán útiles para "craftear" los items. 
		string RawCrystal = "NA";
		string opaqueCrystal = "NA";

		//Declaro la variable para saber si se puede crear el cristal deseado. 
		bool isCrafted = false;

		//Creamos el UI.
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = OPAQUE CRYSTAL CRAFTING = =" << "\n" << endl;
		cout << "1. Opaque Azure Dragon's Sapphire" << endl;
		cout << "2. Opaque Humanity's Emerald" << endl;
		cout << "3. Opaque Feline's Ruby" << endl;
		cout << "4. Exit" << endl;
		cout << "===============================================================" << endl;

		//Esperamos la entrada del usuario.
		cout << "AWAITING USER INPUT:  "; cin >> craftMenuOption;

		//Controlamos el menú usando un switch. 
		switch (craftMenuOption) {

		case 1:
			RawCrystal = "Crystallized Azure Dragon's Tears";
			opaqueCrystal = "Opaque Azure Dragon's Sapphire";
			isCrafted = CrearCristalOpaco(RawCrystal, inventory);
			break;

		case 2:
			RawCrystal = "Crystallized Exiled Heretic's Bone";
			opaqueCrystal = "Opaque Humanity's Emerald";
			isCrafted = CrearCristalOpaco(RawCrystal, inventory);
			break;

		case 3:
			RawCrystal = "Crystallized Great Feline's Ash";
			opaqueCrystal = "Opaque Feline's Ruby";
			isCrafted = CrearCristalOpaco(RawCrystal, inventory);
			break;

		case 4:
			craftMenuOpen = false;
			break;

		default:
			system("CLS");
			break;
		}

		//Solo hará el cambio al inventario si se ha creado algo.
		if (isCrafted)
		{

			cout << "Opaque Crystal crafted!" << endl;
			system("pause");
		}


	}

}

//Función que se encarga de verificar si existe el cristal adecuado en el inventario.
bool CrearCristalOpaco(string RawCrystal, vector<string> inventory)
{
	bool isCrafted = false;

	if (find(inventory.begin(), inventory.end(), RawCrystal) != inventory.end()) {

		isCrafted;

	}

	return isCrafted;

}

//Función que se encarga de reemplazar el rawRawCrystal por el opaqueRawCrystal. 
void ReemplazarObjeto(string RawCrystal, string opaqueCrystal, vector<string> &inventory)
{

	int counter = 0;
	bool ReemplazarObjeto = false;

	while (counter < inventory.size() && !ReemplazarObjeto) {

		if (inventory[counter] == RawCrystal)
		{

			inventory[counter] = opaqueCrystal;
			ReemplazarObjeto;

		}

		counter++;

	}

}

int main()
{
	//RANDOM SEED.
	srand(time(0));
	//Creamos un vector para el inventario. 
	vector<string> inventory(7, "NA");
	//Creamos una variable bool para mantener el menú funcionando. 
	bool menuOpen = true;
	//Creamos la variable para la entrada del usuario. 
	int mainMenuOption;
	//Usamos un ciclo while para mantener el menú funcionando. 
	while (menuOpen) {
		//Este comando limpia la ventana de comandos. 
		system("CLS");
		//Creamos el "UI" para el menú.
		cout << "===============================================================" << endl;
		cout << "= = MAIN MENU = =" << "\n" << endl;
		cout << "1. INVENTORY GENERATOR (FOR DEVELOPERS)" << endl;
		cout << "2. OPEN INVENTORY" << endl;
		cout << "3. GATHERING MENU" << endl;
		cout << "4. CREATE OPAQUE CRYSTAL" << endl;
		cout << "5. EXIT GAME" << endl;
		cout << "===============================================================" << endl;

		//Leemos la entrada del usuario. 
		cout << "AWAITING USER INPUT:  "; cin >> mainMenuOption;
		//Usamos un switch() para manejar el menú con la entrada del usuario.
		switch (mainMenuOption) {
		case 1:
			inventory = GenerarInventario();
			break;

		case 2:
			 AbrirInventario;
			break;

		case 3:
			 MenuDeRecolecciondeObjetos;
			break;
		case 4:
			 MenuDeCreacionDeCristalesOpacos;
			break;

		case 5:
			menuOpen = false;
			break;


		default:
			system("CLS");
			break;
		}
	}

	return 0;
}