#include <iostream>

#include "juegoDeLaVida.h"

int main(int argc, char *argv[]){
    char user;

    JuegoVida juego;
    crearJuegoVida(&juego, MAX_FIL, MAX_COL);

    cargarDatosJuego(&juego);
    mostrarJuego(&juego, 'X', '*');
    mostrarStatusJuego(&juego);
    
    cout << "\nMenu de Opcines: " << endl;
    cout << "(n) Siguente Turno." << endl;
    cout << "(r) Reiniciar Juego." << endl;
    cout << "(q) Salir del Juego." << endl;
   
    cout << "Elija una de las opciones: ";
    cin >> user;

    cout << endl;

    while(user != 'q'){
        switch(user){
            case 'n':
                ejecutarTurno(&juego);
                mostrarJuego(&juego, 'X', '*');
                mostrarStatusJuego(&juego);
            break;

            case 'r':
                crearJuegoVida(&juego, MAX_FIL, MAX_COL);

                cargarDatosJuego(&juego);
                mostrarJuego(&juego, 'X', '*');

                mostrarStatusJuego(&juego);

            break;
        }
        cout << "\nMenu de Opcines: " << endl;
        cout << "(n) Siguente Turno." << endl;
        cout << "(r) Reiniciar Juego." << endl;
        cout << "(q) Salir del Juego." << endl;

        cout << "Elija una de las opciones: ";
        cin >> user;

        cout << endl;

    }

    destruirJuego(&juego);

    return 0;

}
