#ifndef NODO_H
#define NODO_H

#include <iostream>

class Nodo{
	private:
		Nodo *sig;
		void *dato;
	
	public:
        Nodo(Nodo * = NULL, void * = NULL);
        Nodo(const Nodo *);

        Nodo *get_sig();
        void *get_dato();

        void set_dato(void *);
        void set_sig(Nodo *);
};

#endif
