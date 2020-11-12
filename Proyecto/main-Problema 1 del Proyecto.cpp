/* este Programa fue hecho por jorge Tejada*/
// eso es la librerias que voy a usar en este programa.
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;
/* aqui va los vectores necesarios para hacer la contraseña*/
vector<string> GenerarPassword();
bool verificacionUnicadeMayusculas(vector<string>Letras_Mayusculas);
bool verificacionUnicadeCaracteresEspeciales(vector<string>Caracteres_Especiales);
bool verificacionUnicadeDigitos(vector<string>Digitos_Numeros);
void VerContraseña(vector<string>&Password );
void EscribirContraseña(vector<string>&Password);
/* aqui se hace que genere el inventario en 8*/
vector<string> GenerarPassword()
{
    vector<string>Password(8,"");

    const vector<string>AlfaNumericoEspecial = { "0","1","2","3","4","5","6","7","8","9","!","?","*","/","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
    const vector<string>Letras_Mayusculas = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
    const vector<string>Digitos_Numeros = { "0","1","2","3","4","5","6","7","8","9" };
    const vector<string>Caracteres_Especiales = { "!","?","*","/" };

    int randomAlfaNumEspPos;
    int min = 0;
    int max = AlfaNumericoEspecial.size() - 1;

    bool MayusculaContiene = false;
    bool CaracteresEspecialesContiene = false;
    bool DigitoContiene = false;

    bool largaExpresionBooleanadeMayusculas;
    bool largaExpresionBoolenadeCararcterEspecial;
    bool largaExpresionBooleanadeDigito;

    int counter = 0;
    
    while (counter <= 8)
    {
        randomAlfaNumEspPos = rand() % (max - min + 1) + min;

        const int MayusculaContiene = verificacionUnicadeMayusculas(Password);
        const int CaracteresEspecialesContiene = verificacionUnicadeCaracteresEspeciales(Password);
        const int DigitoContiene = verificacionUnicadeDigitos(Password);

        largaExpresionBoolenadeCararcterEspecial = (Caracteres_Especiales[counter] == "!") || (Caracteres_Especiales[counter] == "?") || (Caracteres_Especiales[counter] == "*") || (Caracteres_Especiales[counter] == "/");

        largaExpresionBooleanadeMayusculas = (Letras_Mayusculas[counter] == "A") || (Letras_Mayusculas[counter] == "B") || (Letras_Mayusculas[counter] == "C") || (Letras_Mayusculas[counter] == "D") || (Letras_Mayusculas[counter] == "E") || (Letras_Mayusculas[counter] == "F"|| (Letras_Mayusculas[counter] == "G") || (Letras_Mayusculas[counter] == "H") || (Letras_Mayusculas[counter] == "I") || (Letras_Mayusculas[counter] == "J") || (Letras_Mayusculas[counter] == "K") || (Letras_Mayusculas[counter] == "K") || (Letras_Mayusculas[counter] == "L")|| (Letras_Mayusculas[counter] == "M") || (Letras_Mayusculas[counter] == "N") || (Letras_Mayusculas[counter] == "O") || (Letras_Mayusculas[counter] == "P") || (Letras_Mayusculas[counter] == "Q") || (Letras_Mayusculas[counter] == "R") || (Letras_Mayusculas[counter] == "S")
         || (Letras_Mayusculas[counter] == "T") || (Letras_Mayusculas[counter] == "U") || (Letras_Mayusculas[counter] == "V") || (Letras_Mayusculas[counter] == "W") || (Letras_Mayusculas[counter] == "X") || (Letras_Mayusculas[counter] == "Y") || (Letras_Mayusculas[counter] == "Z"));

        largaExpresionBooleanadeDigito = (Digitos_Numeros[counter] == "0") || (Digitos_Numeros[counter] == "1") || (Digitos_Numeros[counter] == "2") || (Digitos_Numeros[counter] == "3") || (Digitos_Numeros[counter] == "4")
            || (Digitos_Numeros[counter] == "5" || (Digitos_Numeros[counter] == "6")) || (Digitos_Numeros[counter] == "7") || (Digitos_Numeros[counter] == "8") || (Digitos_Numeros[counter] == "9");


        if (!largaExpresionBooleanadeDigito&&!largaExpresionBooleanadeMayusculas&&!largaExpresionBoolenadeCararcterEspecial)
        {
            Password[counter] = AlfaNumericoEspecial[counter];
            counter++;
        }

    }
    system("CLS");
    cout << "PASSWORD GENERATED! \n\n" << endl;
    system("pause");
    return Password;
}
/* aqui verifica que hay un caracter especial en la contraseña*/
bool verificacionUnicadeCaracteresEspeciales(vector<string>Caracteres_Especiales)
{
    int counter = 0;

    bool CaracteresEspecialesContiene = false;

    bool largaExpresionBoolenadeCararcterEspecial;

    while ((counter < Caracteres_Especiales.size()) && (!CaracteresEspecialesContiene))
    {
        largaExpresionBoolenadeCararcterEspecial = (Caracteres_Especiales[counter] == "!") || (Caracteres_Especiales[counter] == "?") || (Caracteres_Especiales[counter] == "*") || (Caracteres_Especiales[counter] == "/");
        
        if (largaExpresionBoolenadeCararcterEspecial)
        {
            CaracteresEspecialesContiene = true;
        }

        counter++;
    }

    return CaracteresEspecialesContiene;
}
/* aqui verifica si hay una mayuscula en la contraseña*/
bool verificacionUnicadeMayusculas(vector<string>Letras_Mayusculas)
{
    int counter = 0;

    bool MayusculaContiene = false;

    bool largaExpresionBooleanadeMayusculas;

    while ((counter < Letras_Mayusculas.size()) && (!MayusculaContiene))
    {
        largaExpresionBooleanadeMayusculas =(Letras_Mayusculas[counter]== "A")|| (Letras_Mayusculas[counter] == "B")|| (Letras_Mayusculas[counter] == "C") || (Letras_Mayusculas[counter] == "D") || (Letras_Mayusculas[counter] == "E") || (Letras_Mayusculas[counter] == "F")
       || (Letras_Mayusculas[counter] == "G") || (Letras_Mayusculas[counter] == "H") || (Letras_Mayusculas[counter] == "I") || (Letras_Mayusculas[counter] == "J") || (Letras_Mayusculas[counter] == "K") || (Letras_Mayusculas[counter] == "K") || (Letras_Mayusculas[counter] == "L")
       || (Letras_Mayusculas[counter] == "M") || (Letras_Mayusculas[counter] == "N") || (Letras_Mayusculas[counter] == "O") || (Letras_Mayusculas[counter] == "P") || (Letras_Mayusculas[counter] == "Q") || (Letras_Mayusculas[counter] == "R") || (Letras_Mayusculas[counter] == "S")
       || (Letras_Mayusculas[counter] == "T") || (Letras_Mayusculas[counter] == "U") || (Letras_Mayusculas[counter] == "V") || (Letras_Mayusculas[counter] == "W") || (Letras_Mayusculas[counter] == "X") || (Letras_Mayusculas[counter] == "Y") || (Letras_Mayusculas[counter] == "Z");

        if (largaExpresionBooleanadeMayusculas)
        {
            MayusculaContiene = true;
        }
        
        counter++;
    }

    return MayusculaContiene;
}
/* aqui verifica si hay un digito en la contraseña*/
bool verificacionUnicadeDigitos(vector<string>Digitos_Numeros)
{
    int counter = 0;

    bool DigitoContiene = false;

    bool largaExpresionBooleanadeDigito;

    while ((counter < Digitos_Numeros.size()) && (!DigitoContiene))
    {
        largaExpresionBooleanadeDigito = (Digitos_Numeros[counter] == "0")|| (Digitos_Numeros[counter] == "1") || (Digitos_Numeros[counter] == "2") || (Digitos_Numeros[counter] == "3") || (Digitos_Numeros[counter] == "4")
        || (Digitos_Numeros[counter] == "5" || (Digitos_Numeros[counter] == "6")) || (Digitos_Numeros[counter] == "7") || (Digitos_Numeros[counter] == "8") || (Digitos_Numeros[counter] == "9");

        if (largaExpresionBooleanadeDigito)
        {
            DigitoContiene = true;
        }

        counter++;
    }

    return DigitoContiene;

}
/* aqui se puede ver la contraseña generada*/
void VerContraseña(vector<string>&Password)
{
    bool vercontraseñamenu = true;

    int userinput;

    while (vercontraseñamenu)
    {

        
        system("CLS");
        cout << "===============================================================" << endl;
        cout << "= = PASSWORD FOR TODAY = =" << "\n" << endl;
        for (int counter = 0; counter < Password.size(); counter++)
        {
            cout << counter +1 << Password[counter] << endl;
        }
        cout << Password.size() + 1 << ". " << "EXIT" << endl;
        cout << "===============================================================" << endl;
        cout << "AWAITING USER INPUT:  "; cin >> userinput;
    }

    
 } 
/* aqui la escrribes y una vez que la escribes vuel*/
void EscribirContraseña(vector<string>&Password)
{
    system("CLS");

    string password = "1Absdez%";
    
    cout << " hola usuario,me puede introducir la contraseña de hoy:" << endl;
    cout << "contraseña:"; cin >> password;
    if (password != "1Absdez%")
    {
        cout << "intentalo de nuevo";
    }
    else
    {
        cout << " bienvenido";
    }
}
/* aqui es el menu principal donde puedes generar, ver , introducir y salir del programa*/
int main()
{
    vector<string>Password(8, "");

    bool MainMenuPassword = true;

    int MainPasswordOption;

    cout << "==============================================================="<< endl;
    cout << " = = MENU PRINCIPAL = =" << endl;
    cout << " 1. GENERAR PASSWORD " << endl;
    cout << " 2. VER PASSWORD" << endl;
    cout << " 3. ESCRIBIR PASSWORD" << endl;
    cout << " 4. EXIT " << endl;
    cout << "================================================================"<< endl;
    cout << "ESPERNADO DESICION:"; cin >> MainPasswordOption;
    switch (MainPasswordOption)
    {
    case 1:
         Password = GenerarPassword();
        break;
    case 2:
        VerContraseña;
        break;
    case 3:
        EscribirContraseña;
        break;
    case 4:
        MainMenuPassword = false;
        break;
    default:
        system("CLS");
        break;
    }
}


