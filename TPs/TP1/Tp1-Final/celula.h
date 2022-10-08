#ifndef CELULA_H
#define CELULA_H

using namespace std;

enum StatusCelula {MUERTA, VIVA};

typedef struct {
    StatusCelula estado;
}Celula;
/*
 *  Pre: Recibe una celula
 *  Post : Inicializa el estado a muerta
 */
void iniciarCelula(Celula *celula);
void cambiarStatusCelula(Celula *celula, StatusCelula estado);
StatusCelula getStatusCelula(Celula *celula);

#endif
