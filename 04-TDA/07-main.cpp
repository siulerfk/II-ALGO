/* 
 *  Diseñar la especificación e implementar el TDA Restaurante.
 *  Debe proveer operaciones para:
 *  • Construir el Restaurante a partir de la cantidad de mesas que tiene. Cada mesa se identifica con un número.
 *  • adicionarEnMesa: agrega el monto dado [$] a la mesa indicada, dejándola abierta.
 *  • cerrarMesa: devuelve el total de la mesa indicada y la deja libre.
 *  • contarMesasLibres: cuenta la cantidad de mesas que están libres
 *  • totalizarRecaudacion: devuelve el total recaudado por el Restaurante.
 *  
 *  Como compilar:
 *
 * */
#include "07-restaurante.h"

int main() {

	Restaurante miResturante(4);

	miResturante.adicionarConsumoEnMesa(200, 3);
	miResturante.adicionarConsumoEnMesa(100, 1);

	return 0;
}
