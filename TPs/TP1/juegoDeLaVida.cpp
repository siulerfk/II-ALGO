#include <iostream>
#include "juegoDeLaVida.h"

void crearJuegoVida(JuegoVida *juego, size_t fil, size_t col){
    crearTablero(&(juego->tablero), fil, col);
    iniciarTablero(&(juego->tablero));  // Crea el tablero con todas las celulas Muertas
    
    juego->cantCelulasVivas = 0;
    juego->cantCelulasMuertas = fil * col;

    juego->cantCelulasNacidasUltiTurno = 0;
    juego->cantCelulasMuertasUltiTurno = 0;

    juego->promCelNaciTotal = 0;
    juego->promCelMuerTotal = 0;
    
    juego->sumaNacTotal = 0;
    juego->sumaMuerTotal = 0;

    juego->cantTurnos = 0;
}
void destruirJuego(JuegoVida *juego){
    destruirTablero(&(juego->tablero));
}
void setCelulaTableroJuego(JuegoVida *juego, size_t fil, size_t col){
    setValorCelulaTablero(&(juego->tablero), fil, col, VIVA);
}

size_t cantCelulasVecinasVivas(Tablero *tablero, size_t fil, size_t col){
    size_t fil_tablero = getFilasTablero(tablero);  
    size_t col_tablero = getColumnasTablero(tablero);  
    
    size_t contador = 0;

    for(int i = fil - 1; i <= (int)fil + 1; i++)
        for(int j = col - 1; j <= (int)col + 1; j++)
            if((i != (int)fil || j != (int)col) && 0 <= i && i < (int)fil_tablero && 0 <= j && j < (int)col_tablero){
                if(getStatusCelula(&(tablero->tablero[i][j])) == VIVA)
                    contador++;
            }
    return contador;

}


/* 
 * Pre: Para cargar datos tiene que estar previamente creado el juego
 * Post: Carga por estadar impuc las ubicaciones de las celulas
 */
void cargarDatosJuego(JuegoVida *juego){
    int fil;
    int col;

    cout <<  "Ingrese una Posicion para la celula:(un numero negativo para terminar) " << endl; 
    cout <<  "Posicion Fila entre [1-20]: ";
    cin >> fil;

    cout <<  "Posicion Columna entre [1-80]: "; 
    cin >> col;

    if(0 <= fil && 0 <= col)
        setCelulaTableroJuego(juego, fil - 1, col - 1);

    while(0 <= fil){

        cout << "f:" << --fil << "  c:" << --col << endl << endl;

        if(0 <= fil && 0 <= col){
            juego->cantCelulasVivas++;
            juego->cantCelulasMuertas--;
        }
            

        cout <<  "Ingrese una Posicion para la celula:(un numero negativo para terminar) " << endl; 
        cout <<  "Posicion Fila: ";
        cin >> fil;

        cout <<  "Posicion Columna: "; 
        cin >> col;

        if(0 <= fil && 0 <= col)
            setCelulaTableroJuego(juego, fil - 1, col - 1);
    }
    cout << endl;
}
void ejecutarTurno(JuegoVida *juego){
    Tablero aux;
    copiarTablero(&aux, &(juego->tablero));
    
    int cantCelVecVivas = 0;

    juego->cantCelulasNacidasUltiTurno = 0;
    juego->cantCelulasMuertasUltiTurno = 0;

    for(size_t i = 0; i < getFilasTablero(&(juego->tablero)); i++){
        for(size_t j = 0; j < getColumnasTablero(&(juego->tablero)); j++){
            //cout << "f:" << i << "c:" << j << "->" << cantCelulasVecinasVivas(&aux , i, j) << endl;

            cantCelVecVivas = cantCelulasVecinasVivas(&aux , i, j);

            if(getStatusCelula(&(aux.tablero[i][j])) == MUERTA){
                if(cantCelVecVivas == 3){
                    cambiarStatusCelula(&(juego->tablero.tablero[i][j]), VIVA);
                    juego->cantCelulasVivas++;
                    juego->cantCelulasMuertas--;

                    juego->cantCelulasNacidasUltiTurno++;

                }
            }
            else{
                if(cantCelVecVivas != 2 &&  cantCelVecVivas != 3){
                    cambiarStatusCelula(&(juego->tablero.tablero[i][j]), MUERTA);
                    juego->cantCelulasMuertas++;
                    juego->cantCelulasVivas--;


                    juego->cantCelulasMuertasUltiTurno++;
                }
            }
        }
    }    
    destruirTablero(&aux);
    
    juego->sumaNacTotal += juego->cantCelulasNacidasUltiTurno;
    juego->sumaMuerTotal += juego->cantCelulasMuertasUltiTurno;
   
    juego->cantTurnos++;

    juego->promCelNaciTotal =  juego->sumaNacTotal / juego->cantTurnos;
    juego->promCelMuerTotal =  juego->sumaMuerTotal / juego->cantTurnos; 

}
void mostrarJuego(JuegoVida *juego, char viva, char muerta){
    for(size_t i = 0; i < getFilasTablero(&(juego->tablero)); i++){
        for(size_t j = 0; j < getColumnasTablero(&(juego->tablero)); j++){
            if(getStatusCelula(&(juego->tablero.tablero[i][j])) == VIVA)
                std::cout << viva;
            else
                std::cout << muerta;
        }
        
        std::cout << std::endl;
    }   
}
void mostrarStatusJuego(JuegoVida *juego){
    cout << "Celulas Vivas: " << juego->cantCelulasVivas; 
    cout << "\t\t\tCelulas Muertas: " << juego->cantCelulasMuertas;

    cout << "\nCelulas Nacidas Ultimo Turno: " << juego->cantCelulasNacidasUltiTurno;
    cout << "\t\tCelulas Muertas Ultimo Turno: " << juego->cantCelulasMuertasUltiTurno;

    cout << endl;

    cout << "Prom Nacimentos Total: " << juego->promCelNaciTotal;
    cout << "\t\tProm Muertes Total: " << juego->promCelMuerTotal;

    cout << endl;
}
