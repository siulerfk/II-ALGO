#include "09-Lista.h"
#include "11-Estrella.h"

class Astronomo {

    public:

        /*
         * post: devuelve aquella Estrella de 'estrellas' cuya distancia
         *       es la mínima respecto al Sol.
         *       Si dos o más Estrellas están a distancia má­nima, devuelve
         *       la primera según su orden en la lista.
         *       Si 'estrellas' está vacía, devuelve NULL.
         */
        Estrella* buscarEstrellaMasCercana(Lista<Estrella*>* estrellas);


        /*
         * post: agrega a la lista 'seleccionadas' aquellas Estrellas de 'estrellas'
         *       cuya temperatura está entre 'temperaturaDesde' y
         *       'temperaturaHasta'.
         */
        void seleccionarEstrellasPorTemperatura(Lista<Estrella*>* estrellas,
                                                float minima,
                                                float maxima,
                                                Lista<Estrella*>* seleccionadas);
};

Estrella* Astronomo::buscarEstrellaMasCercana(Lista<Estrella*>* estrellas){
    if(estrellas->estaVacia())
        return NULL;

    Estrella *min = estrellas->obtener(1);

    estrellas->iniciarCursor();
    estrellas->avanzarCursor();

    while(estrellas->avanzarCursor())
        if(min->obtenerDistancia() > estrellas->obtenerCursor()->obtenerDistancia())
            min = estrellas->obtenerCursor();

    return min;
}

void Astronomo::seleccionarEstrellasPorTemperatura(Lista<Estrella*>* estrellas,
                                        float minima,
                                        float maxima,
                                        Lista<Estrella*>* seleccionadas){
    estrellas->iniciarCursor();
    while(estrellas->avanzarCursor()){
        float auxTemp = estrellas->obtenerCursor()->obtenerTemperatura();
        if(minima < auxTemp && auxTemp < maxima){
            seleccionadas->agregar(estrellas->obtenerCursor());
        }
    }

}
