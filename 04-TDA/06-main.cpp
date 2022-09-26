/*
 * Para compilar:
 *  g++ -Wall -pedantic -c 06-molinete.cpp
 *  g++ -Wall -pedantic -c 06-main.cpp
 *  g++ -Wall -pedantic 06-main.o 06-molinete.o -o main
 */
#include <iostream>
#include "06-molinete.h"

using namespace std;

int main() {
    cout << ".:: Accesos ::." << endl;

    Molinete molineteDeAcceso(10);
    char opcion;

    do {
        cout << "Comando? (E: entrar, S: salir, T: total, X: terminar): ";
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'E' : molineteDeAcceso.dejarEntrar();
            break;

            case 'S' : molineteDeAcceso.dejarSalir();
            break;

            case 'T' : cout << "Total de personas en el interior: "
                << molineteDeAcceso.contarPersonasDentro() 
                << endl
                << "Máxima cantidad dentro: "
                << molineteDeAcceso.obtenerMaximaCantidadDePersonasDentro()
                << endl;
            break;

            default:
            opcion = 'X';
        }

    } while (opcion != 'X');

    return 0;
}


