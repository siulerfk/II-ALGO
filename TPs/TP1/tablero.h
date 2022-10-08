#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include "celula.h"

typedef struct{
   Celula **tablero;
   size_t fil;
   size_t  col;
}Tablero;
/* 
 * Pre: Recibe por parametro numeros enteros positivos
 * Post: Genera un tablero dinamico, recibido por parametro
 */
void crearTablero(Tablero *tablero, size_t fil, size_t col);
Celula **crearMatrizCelulas(size_t fil, size_t col);
/* 
 * Pos: Destruye el tablero dinamico
 */
void destruirTablero(Tablero *tablero);
void destruirMatrizCelulas(Celula **celula, size_t fil, size_t col);

void copiarTablero(Tablero *destino, Tablero *origen);
/* 
 * Pos: Inicializa el tablero con ceros = MUERTES 
 */
void iniciarTablero(Tablero *tablero);

size_t getFilasTablero(Tablero *tablero);
size_t getColumnasTablero(Tablero *tablero);

Celula getValorCelulaTablero(Tablero *tablero, size_t fil, size_t col);
/*
 * Pre: Recibe enteros positivos
 * Pos: Cambia el estado del la posicion 
 */
void setValorCelulaTablero(Tablero *tablero, size_t fil, size_t col, StatusCelula state);
/*
 * Pos: Se mostrara una matriz de ceros y unos
 */
void mostrarTablero(Tablero *tablero);
#endif
