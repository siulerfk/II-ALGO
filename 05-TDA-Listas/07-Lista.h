#ifndef LISTA_H
#define LISTA_H

#include "07-Nodo.h"

using namespace std;

// Lista simplemente ligada.
class Lista{
    private:
        Nodo *prim;
    public:
        Lista();
        ~Lista();

        void agregar_pincipio(void *);
        void agregar_final(const void *);
        bool agregar_posicion(void *dato, const size_t pos);

        bool eliminar_primero();
        bool eliminar_posicion(const size_t pos);

        void *obtener_dato(const size_t pos)const;

        void *buscar_dato(const void *dato, int (*cmp)(const void *a, const void *b));
        size_t lista_largo()const;

};

#endif
