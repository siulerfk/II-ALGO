#include <iostream>
#include "tablero.h"

void crearTablero(Tablero *tablero, size_t fil, size_t col){
	tablero->tablero = crearMatrizCelulas(fil, col);
    
	tablero->fil = fil;
	tablero->col = col;
}

Celula **crearMatrizCelulas(size_t fil, size_t col){
    Celula **tablero;
    
    tablero = new Celula*[fil];
    for(size_t i = 0; i < fil; i++)
        tablero[i] = new Celula[col];

    return tablero;
}

void destruirTablero(Tablero *tablero){
    destruirMatrizCelulas(tablero->tablero, tablero->fil, tablero->col);
    tablero->tablero = NULL;

    tablero->fil = 0;
    tablero->col = 0;
}

void destruirMatrizCelulas(Celula **celula, size_t fil, size_t col){
    for(size_t i = 0; i < fil; i++)
        delete [] celula[i];
    delete [] celula;
}

void copiarTablero(Tablero *destino, Tablero *origen){
    crearTablero(destino, origen->fil, origen->col);
    for(size_t i = 0; i < origen->fil; i++)
        for(size_t j = 0; j < origen->col; j++)
            destino->tablero[i][j] = origen->tablero[i][j];

    destino->fil = origen->fil;
    destino->col = origen->col;
}
void iniciarTablero(Tablero *tablero){
    for(size_t i = 0; i < tablero->fil; i++)
        for(size_t j = 0; j < tablero->col; j++)
            cambiarStatusCelula(&(tablero->tablero[i][j]), MUERTA);
}

size_t getFilasTablero(Tablero *tablero){
    return tablero->fil;
}
size_t getColumnasTablero(Tablero *tablero){
    return tablero->col;
}

Celula getValorCelulaTablero(Tablero *tablero, size_t fil, size_t col){
    return tablero->tablero[fil][col];
}

void setValorCelulaTablero(Tablero *tablero, size_t fil, size_t col, StatusCelula state){
    cambiarStatusCelula(&(tablero->tablero[fil][col]), state);
}
void mostrarTablero(Tablero *tablero){
    for(size_t i = 0; i < tablero->fil; i++){
        for(size_t j = 0; j < tablero->col; j++)
            std::cout <<  getStatusCelula(&(tablero->tablero[i][j]));
        std::cout << std::endl;
    }
}
