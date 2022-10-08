#ifndef JUEGODELAVIDA_H
#define JUEGODELAVIDA_H

#include <iostream>
#include "tablero.h"

#define MAX_FIL 20 
#define MAX_COL 80

typedef struct{
    Tablero tablero;
    size_t cantCelulasVivas;
    size_t cantCelulasMuertas;

    size_t cantCelulasNacidasUltiTurno;
    size_t cantCelulasMuertasUltiTurno;

    float promCelNaciTotal;
    float promCelMuerTotal;
    
    size_t sumaNacTotal;
    size_t sumaMuerTotal;

    size_t cantTurnos;
}JuegoVida;
/* 
 * Pre: Recibe por parametro enteros positivos.
 * Pos: Instacia las varibles y el tablero.
 */
void crearJuegoVida(JuegoVida *juegoi, size_t fil, size_t col);
/* 
 * Pos: Destruye el tablero dinamico
 */
void destruirJuego(JuegoVida *juego);
/*
 * Pos: Cambia el estado de la celula por viva
 */
void setCelulaTableroJuego(JuegoVida *juego, size_t fil, size_t col);
/* 
 * Pre: recibe una posicion mayor que cero
 * Post: Retorna la cantidad de Celulas vivas en su radio de 8 casilleros
 */
size_t cantCelulasVecinasVivas(JuegoVida *juego, size_t fil, size_t col);
/* 
 * Pre: Para cargar datos tiene que estar previamente creado el juego
 * Post: Carga por estadar impuc las ubicaciones de las celulas
 */
void cargarDatosJuego(JuegoVida *juego);
/*
 * Pre: el Juego debe estar inicializado.
 * Pos: realiza toda la verificacion de creacion y elimancion de celulas
 */
void ejecutarTurno(JuegoVida *juego);
/*
 * Pre: Muestra el tablero con el formato que se recibe por parametros.
 * Post:
 */
void mostrarJuego(JuegoVida *juego, char viva, char muerta);
/*
 * Pos: Mustra el estado de las vatibles por pantallla.
 */
void mostrarStatusJuego(JuegoVida *juego);


#endif
