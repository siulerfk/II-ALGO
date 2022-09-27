#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "01-Nodo.h"

using namespace std;
/* 
 * Las primitivas principales de la Lista son:
 *  1) agregar_principio().
 *  2) agregar_final().
 *  3) agregar_posicion().
 *  4) eliminar_buscado().
 *  5) eliminar_final().
 */
class Lista{
    private:
        Nodo *prim;
    public:
        Lista();
        Lista(Lista *lista);

        ~Lista();

        void agregar_pincipio(const int);
        void agregar_final(const int);
        void agregar_posicion(const int info, const int pos);

        bool eliminar_primero();
        bool eliminar_ultimo();
        bool eliminar_posicion(const int);
        bool eliminar_buscado(const int);

        int obtener_primero()const;
        
        Nodo *get_prim();
        void set_prim(Nodo *);

        Lista *interseccion(Lista *lista);

        void mostrar_datos()const;
        int eliminardato(int dato);
};

#endif
