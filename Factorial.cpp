/**Programa para calcular el numero factorial y funciones de banco**/

/**Sinopsis: Este programa sirve para que el usuario
elija si quiere calcular un numero factorial o si el usuario
quiere usar funciones de banco (consulta de saldo, retiros y mostrar saldo)**/

/**Version 1.1 **/


#include <iostream>
using namespace std;

/** Prototipo de la funcion factorial**/
int factorial(int n);

/** Prototipos de las funciones del cajero automatico **/
void consultarSaldo(double saldo);
void retirarEfectivo(double& saldo);
void mostrarSaldo(double saldo);

int main() {
    int opcion;
    double saldo = 20000.0; // Saldo inicial de la cuenta

    do {/**Menu principal**/
        cout << "\n--- Menu Principal ---\n";
        cout << "1. Calcular factorial\n";
        cout << "2. Funciones de cajero automatico\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            /**Calcular el factorial de un numero**/
        case 1: {
            int numero;
            cout << "Ingrese un numero para calcular su factorial: ";
            cin >> numero;

            if (numero < 0) {
                cout << "El factorial no esta definido para numeros negativos." << endl;
            }
            else {
                cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;
            }
            break;
        }
        case 2: {
            /**Funciones de cajero automatico**/
            int opcionCajero;
            
            do {
                cout << "\n--- Cajero Automatico ---\n";
                cout << "1. Consultar saldo\n";
                cout << "2. Retirar efectivo\n";
                cout << "3. Regresar al menu principal\n";
                cout << "Seleccione una opcion: ";
                cin >> opcionCajero;

                switch (opcionCajero) {
                case 1:
                    consultarSaldo(saldo);
                    break;
                case 2:
                    retirarEfectivo(saldo);
                    mostrarSaldo(saldo);
                    break;
                case 3:
                    cout << "Regresando al menu principal...\n";
                    break;
                default:
                    cout << "Opcion no valida.\n";
                }
            } while (opcionCajero != 3);
            break;
        }
        case 3:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 3);

    return 0;
}

/**Función recursiva para calcular el factorial**/
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

/**Funcion para consultar el saldo actual**/
void consultarSaldo(double saldo) {
    cout << "Su saldo actual es: $" << saldo << endl;
}

/**Funcion para retirar efectivo**/
void retirarEfectivo(double& saldo) {
    double cantidad;
    cout << "Ingrese la cantidad a retirar: $";
    cin >> cantidad;

    if (cantidad > saldo) {
        cout << "Saldo insuficiente para realizar el retiro.\n";
    }
    else {
        saldo -= cantidad;
        cout << "Retiro exitoso. Ha retirado: $" << cantidad << endl;
    }
}

/**Funcion para mostrar el saldo despues del retiro**/
void mostrarSaldo(double saldo) {
    cout << "Su saldo despues del retiro es: $" << saldo << endl;
}