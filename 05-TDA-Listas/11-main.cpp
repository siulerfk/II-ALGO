/* Como compilar:
 * g++ -Wall -pedantic -std=c++98 11-main.cpp -o var
 */
#include <iostream>
#include "11-Astronomo.h"

using namespace std;

int main(int argc, char *argv[]){
    Astronomo investigador; 

    Lista<Estrella*> *myEstrella = new Lista<Estrella*>();

    Estrella mercurio("mercurio", 14221, 2500);
    myEstrella->agregar(&mercurio);

    Estrella venus("venus", 2000, 3500);
    myEstrella->agregar(&venus);

    Estrella marte("marte", 3000, 4500);
    myEstrella->agregar(&marte);

    Estrella *minEstrella =investigador.buscarEstrellaMasCercana(myEstrella);

    cout << "La minima distancia a la estrella es: " << endl
         << "Nombre: " <<  minEstrella->obtenerNombre() << endl
         << "Distancia: " << minEstrella->obtenerDistancia() << endl
         << "Temperatura: " << minEstrella->obtenerTemperatura() << endl;
    
    Lista<Estrella*>* seleccionadas = new Lista<Estrella*>();
    investigador.seleccionarEstrellasPorTemperatura(myEstrella, 1000, 3010, seleccionadas);
    cout << "Seleccionadas Nombre: " <<  seleccionadas->obtener(1)->obtenerNombre() << endl;
    
    /* Con esto probamos los datos de las Lista "seleccionadas" apuntan de a los datos
     * de la Lista "investigador". NO se crea una nueva lista. Esto nos sierviria como un 
     * filtro para agrupar (seleccionar) datos especificos de la Lista.
     */
    mercurio.setNombre("juan");
    cout << myEstrella->obtener(1)->obtenerNombre() << endl
         << seleccionadas->obtener(1)->obtenerNombre() << endl;
    /* 
     * Direciones de memoria
     */
    cout << myEstrella->obtener(1) << endl
         << seleccionadas->obtener(1) << endl;


    return 0;
}
