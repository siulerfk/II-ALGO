#include "celula.h"
/* 
 * Instancia la celula por Muerta
 */
void iniciarCelula(Celula *celula){
    celula->estado = MUERTA;
}

void cambiarStatusCelula(Celula *celula, StatusCelula estado){
    celula->estado = estado;
}

StatusCelula getStatusCelula(Celula *celula){
    return celula->estado;
}
