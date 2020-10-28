// aqui vamos a declarar las librerias necesarias para hacer el programa//
// Programa hecho por Jorge Tejada//
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

// aqui declaro los "using namespace" necesarios para el programa como el std, chrono y this_thread//
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

// aqui empieza el programa//
int main()
{
    /*aqui declaro los espaciosde maximo y disponible por separado tanto de plantas como el los minerales
    para saber que el jugador esta sacando*/

    const int InventarioEspacioMaxMinerales = 3;
    int InventarioEspacioDisponibleMinerales = 0;

    const int InventarioEspacioMaxPlantas = 5;
    int InventarioEspacioDisponiblePlantas = 0;

    // ahora declaro los vectores para el inventario , minerales y plantas //

    const vector <string> minerales{ "Cristal Azul (A)", "Cristal Verde (V)" };

    vector <string> Inventario;

    const vector <string> plantas{ "Verila Pluma(VP)", "Secta Doralis (SD)", "Crystalia Fulminis (CF)" };

    // aqui declaramos lo que el usuario/jugador quiera hacer //

    string UserInput;

    // tambien declaramos lo que va a sacar lo minimo , maximo y lo random de plantas y minerales //

    int minMinerales = 0;
    int maxMinerales = minerales.size() - 1;

    int minPlantas = 0;
    int maxPlantas = plantas.size() - 1;

    int RandomMineralPos;
    int RandomPlantasPos;

    // ahora empezamos lo que seria la simulacion de desiciones que decida hacer el jugador //
    // si el usuario escribe "0" o "exit" sale del programa //

    while (UserInput != "0" && UserInput != "exit")
    {
        cout << "===========================================================================================" << endl;
        cout << "Esperando una desicion:"; cin >> UserInput; cout << "\n";

        // aqui si el usuario escribe m (ya sea mayusculua o minuscula) empezara a minar//

        if (UserInput == "m" || UserInput == "M")
        {
            cout << "Minando.";
            sleep_for(seconds(1));
            cout << ".";
            sleep_for(seconds(1));
            cout << ".\n\n";

            // aqui hace te saca un mineral que puede ser a lo random pero con el limite de 3 minerales//

            if (InventarioEspacioDisponibleMinerales < InventarioEspacioMaxMinerales)
            {

                RandomMineralPos = rand() % (maxMinerales - minMinerales + 1) + minMinerales;

                //aqui te dice lo que has recolectado//

                cout << "Has Obtenido: " << minerales[RandomMineralPos] << "\n\n";
                InventarioEspacioDisponibleMinerales++;

                Inventario.push_back(minerales[RandomMineralPos]);

                // aqui te dice la cantidad maxima y disponible tienes para los minerales y plantas//

                cout << "Has Recolectado: " << InventarioEspacioDisponibleMinerales << " de " << InventarioEspacioMaxMinerales << " minerales " << "\n\n";
                cout << "Has Recolectado: " << InventarioEspacioDisponiblePlantas << " de " << InventarioEspacioMaxPlantas << " plantas " << "\n\n";
            }
            else
            {
                // aqui te dice cuando esta al maximo te dira que esta lleno//
                cout << "INVENTARIO LLENO " << "\n\n";
            }


        }
        // aqui usaremos el mismo concepto que el de los minerales pero para las plantas en esta ocasion//
        if (UserInput == "h" || UserInput == "H")
        {
            cout << "Recogiendo.";
            sleep_for(seconds(1));
            cout << ".";
            sleep_for(seconds(1));
            cout << ". \n\n";

            if (InventarioEspacioDisponiblePlantas < InventarioEspacioMaxPlantas)
            {
                // aqui cual es la formula necesaria para saber que plantas vas a recoger a lo random//
                RandomPlantasPos = rand() % (maxPlantas - minPlantas + 1) + minPlantas;

                // aqui te dice lo que has recogido de las plantas//
                cout << "Has Obtenido:" << (plantas[RandomPlantasPos]) << "\n\n";
                InventarioEspacioDisponiblePlantas++;

                Inventario.push_back(plantas[RandomPlantasPos]);

                // aqui te dice el maximo y disponible que queda para las plantas y minerales//
                cout << "Has Recolectado: " << InventarioEspacioDisponiblePlantas << " de " << InventarioEspacioMaxPlantas << " plantas" << "\n\n";
                cout << "Has Recolectado: " << InventarioEspacioDisponibleMinerales << " de " << InventarioEspacioMaxMinerales << " minerales" << "\n\n";
            }

            else
            {
                // aqui cuando llega al maximo de plantas//
                cout << "INVENTARIO LLENO " << "\n\n";
            }

        }
        // aqui hara que cuando el usuario/jugador escribe i (mayuscula o minuscula) se abra el inventario para ver que es lo que tiene//
        if (UserInput == "i" || UserInput == "I")
        {
            cout << "Abriendo Inventario.";
            sleep_for(milliseconds(500));
            cout << ".";
            sleep_for(milliseconds(500));
            cout << ".\n\n";

            if (InventarioEspacioDisponibleMinerales == 0)
            {
                if (InventarioEspacioDisponiblePlantas == 0)
                {
                    cout << "INVENTARIO VACIO" << "\n\n";
                }
            }
            else 
            {
                for (int i = 0; i < Inventario.size(); i++)
                {
                    cout << Inventario[i] << " " << "\n\n";
                }
            }



        }
    }
}
    
