// Importamos las librer�as necesarias para el programa //
// Programa hecho por Jorge Tejada // 
#include<iostream>
#include<vector>
#include<string>
#include<ctime>

// Incluimos el namespace std. 
using namespace std;

//Declaramos las funciones que usaremos en este programa. 
vector<string> GenerarInventario();
bool UnicaVerificacionDeCristales(vector<string> itemList);
void AbrirInventario(vector<string>& inventory);
void MenuDeRecolecciondeObjetos(vector<string> &inventory);
void MenuDeEliminarCristalesCrudos(vector<string> &inventory);
void EliminarCristal(string Crystal, vector<string> &inventory);
bool EliminarCristalCrudo(string Crystal, vector<string> inventory);
void MenuDeCreacionDeCristalesOpacos(vector<string> &inventory);
bool CrearCristalOpaco(string RawCrystal, vector<string> inventory);
void ReemplazarObjeto(string RawCrystal, string opaqueCrystal, vector<string> &inventory);


//Escribimos el cuerpo de la funci�n GenerarInventario().
vector<string> GenerarInventario()
{
	//Declaramos un inventario (local).
	vector<string> randomInventory(20, "NA");
	//Creamos un vector con todos los objetos posibles. 
	const vector<string> allItems = { "Crystallized Azure Dragon's Tears", "Crystallized Exiled Heretic's Bone", "Crystallized Great Feline's Ash", "Fishermen's Plate", "Iron Plate" };
	//Definimos las variables para el uso del rand().
	int randomItemPos;
	int min = 0;
	int max = allItems.size() - 1;
	//Definimos una variable que nos diga si hay un cristal presente en el inventario.
	const bool& containsRawCrystal = false;

	//Declaramos una variable booleana, "longBooleanExpression". Para el control de cristales �nicos. 
	bool longBooleanExpression;

	//Declaramos una variable booleana para el control de Fishermen's Plates.
	bool shortBooleanExpression;

	//Declaramos una variable contador para el ciclo while. 
	int counter = 0;

	//Creamos el ciclo que llena el inventario "random". 
	while (counter < 7) {
		//Generamos la posici�n "random".
		randomItemPos = rand() % (max - min + 1) + min;
		//Usando la funci�n UnicaVerificacionDeCristales, verificamos si hay un cristal en el inventario.
		const int containsRawCrystal = UnicaVerificacionDeCristales(randomInventory);

		//Si hay el item random escogido es un cristal y HAY un cristal presente en el inventario, entonces esta expresi�n tomar� el valor de true. 
		longBooleanExpression = ((allItems[randomItemPos] == "Crystallized Azure Dragon's Tears") || (allItems[randomItemPos] == "Crystallized Exiled Heretic's Bone") || (allItems[randomItemPos] == "Crystallized Great Feline's Ash")) && containsRawCrystal;

		//Si hay tres o m�s Fisherme's Plate en el inventario Y el item random es un Fisherme's Plate, esta variable tomar� el valor de true. 
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

//Creamos una funci�n que verifique si ya existe un cristal en la lista pasada como argumento. 
bool UnicaVerificacionDeCristales(vector<string> itemList)
{
	//Declaramos una variable counter por motivos pr�cticos. 
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

//Creamos una funci�n para ver el inventario y tirar objetos del mismo. 
void AbrirInventario(vector<string>& inventory)
{
	//Declaramos la variable que mantiene el inventario abierto. 
	bool inventoryOpened = true;
	//Declaramos la variable para la entrada del usuario. 
	int userInput;

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
		//Creamos la opci�n EXIT.
		cout << inventory.size() + 1 << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		//Esperamos la entrada del usuario.
		cout << "AWAITING USER INPUT:  "; cin >> userInput;
		//Si el usuario introduce el n�mero de alg�n item, entonces borra el item usando erase(). De otra forma, cierra el inventory. 
		if (userInput <= inventory.size())
		{
			inventory.erase(inventory.begin() + userInput - 1);
		}

		else if (userInput == inventory.size() + 1)
		{

			inventoryOpened = false;

		}
	}
}

void MenuDeRecolecciondeObjetos(vector<string> &inventoryItems)
{
	bool GatherInventoryMenuOpen = true;

	int UserNumberInput;

	while (GatherInventoryMenuOpen)
	{
		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = GATHER MENU INVENTORY = =" << "\n" << endl;
		for (int counter = 0; counter < 5; counter++)
		{

			cout << counter + 1 << ". " << inventoryItems[counter] << endl;
		}
		cout << inventoryItems.size() << ". " << "EXIT" << endl;
		cout << "===============================================================" << endl;
		cout << "AWAITING USER INPUT:  "; cin >> UserNumberInput;
		//Si el usuario introduce el n�mero de alg�n item, entonces borra el item usando erase(). De otra forma, cierra el inventory. 
		if (UserNumberInput<= inventoryItems.size())
		{
			inventoryItems.erase(inventoryItems.begin() + UserNumberInput- 1);
		}

		else if (UserNumberInput == inventoryItems.size() + 1)
		{

			GatherInventoryMenuOpen = false;

		}

		
	}

}
/* haremos un menu para que eliminemos los cristales crudos que tenemos en el inventario */
void MenuDeEliminarCristalesCrudos(vector<string> &inventory)
{
	bool eliminateMenuOpen = true;

	int eliminateMenuOption;

	while (eliminateMenuOpen)
	{
		string Crystal = "NA";

		bool IsEliminated = false;

		system("CLS");
		cout << "===============================================================" << endl;
		cout << "= = ELIMINATE RAWCRYSTAL MENU = =" << "\n" << endl;
		cout << "1. Crystallized Azure Dragon's Tears" << endl;
		cout << "2. Crystallized Exiled Heretic's Bone" << endl;
		cout << "3. Crystallized Great Feline's Ash" << endl;
		cout << "4. Exit" << endl;
		cout << "===============================================================" << endl;

		cout << "AWAITING USER INPUT:  "; cin >> eliminateMenuOption;

		switch (eliminateMenuOption)
		{
		case 1:
			Crystal = "Crystallized Azure Dragon's Tears";
			IsEliminated = EliminarCristalCrudo(Crystal, inventory);
			break;
		case 2:
			Crystal = "Crystallized Exiled Heretic's Bone";
			IsEliminated = EliminarCristalCrudo(Crystal, inventory);
			break;
		case 3:
			Crystal = "Crystallized Great Feline's Ash";
			IsEliminated = EliminarCristalCrudo(Crystal, inventory);
			break;
		case 4:
			eliminateMenuOpen = false;
			break;

		default:
			system("CLS");
			break;
		}
		if (IsEliminated)
		{
			system("CLS");
			cout << "Are you sure you want to destroy this Crystal ? You won�t be able to gather this unique Crystal anymore."<< "\n\n";
			system("PAUSE");
		}
	}
}

bool EliminarCristalCrudo(string Crystal, vector<string> inventory)
{
	 bool isEliminated = true;

	if (find(inventory.begin(), inventory.end(), Crystal) != inventory.end())
	{
		
		isEliminated = false;

	}

	return isEliminated;

}

void EliminarCristal(string Crystal, vector<string> &inventory)
{

	int counter = 0;
	bool ReemplazarObjeto = true;

	string UserInput;

	while (counter < inventory.size() && !ReemplazarObjeto) {

		if (inventory[counter] == Crystal)
		{

			inventory.erase(inventory.begin());

		}
		counter++;

	}
	
}

void MenuDeCreacionDeCristalesOpacos(vector<string> &inventory)
{

	//Declaro la variable que mantiene el inventario abierto.
	bool craftMenuOpen = true;

	//Declaro la variable para la entrada del usuario
	int craftMenuOption;

	while (craftMenuOpen) {

		//Declaro dos variables que ser�n �tiles para "craftear" los items. 
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

		//Controlamos el men� usando un switch. 
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

		//Solo har� el cambio al inventario si se ha creado algo.
		if (isCrafted) {

			cout << "Opaque Crystal crafted!" << endl;
			system("pause");

		}

	}

}

//Funci�n que se encarga de verificar si existe el cristal adecuado en el inventario.
bool CrearCristalOpaco(string RawCrystal, vector<string> inventory)
{
	const bool& isCrafted = false;

	if (find(inventory.begin(), inventory.end(), RawCrystal) != inventory.end()) {

		&isCrafted;

	}

	return isCrafted;

}

//Funci�n que se encarga de reemplazar el rawRawCrystal por el opaqueRawCrystal. 
void ReemplazarObjeto(string RawCrystal, string opaqueCrystal, vector<string> &inventory)
{

	int counter = 0;
	const bool& ReemplazarObjeto = false;

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
	//Creamos una variable bool para mantener el men� funcionando. 
	bool menuOpen = true;
	//Creamos la variable para la entrada del usuario. 
	int mainMenuOption;
	//Usamos un ciclo while para mantener el men� funcionando. 
	while (menuOpen) {
		//Este comando limpia la ventana de comandos. 
		system("CLS");
		//Creamos el "UI" para el men�.
		cout << "===============================================================" << endl;
		cout << "= = MAIN MENU = =" << "\n" << endl;
		cout << "1. INVENTORY GENERATOR (FOR DEVELOPERS)" << endl;
		cout << "2. OPEN INVENTORY" << endl;
		cout << "3. GATHERING MENU" << endl;
		cout << "4. CREATE OPAQUE CRYSTAL" << endl;
		cout << "5. ELIMINATE RAW CRYSTAL" << endl;
		cout << "6. EXIT GAME" << endl;
		cout << "===============================================================" << endl;

		//Leemos la entrada del usuario. 
		cout << "AWAITING USER INPUT:  "; cin >> mainMenuOption;
		//Usamos un switch() para manejar el men� con la entrada del usuario.
		switch (mainMenuOption) {
		case 1:
			inventory = GenerarInventario();
			break;

		case 2:
			AbrirInventario(inventory);
			break;

		case 3:
			MenuDeRecolecciondeObjetos(inventory);
			break;
		case 4:
			MenuDeCreacionDeCristalesOpacos(inventory);
			break;

		case 5:
			MenuDeEliminarCristalesCrudos(inventory);
			break;

		case 6:
			menuOpen = false;
			break;


		default:
			system("CLS");
			break;
		}
	}

	return 0;
}