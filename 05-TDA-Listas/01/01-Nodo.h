#ifndef NODO_H
#define NODO_H

#include <iostream>

class Nodo{
	private:
		Nodo *sig;
		int dato;
	
	public:
		Nodo();                    
        Nodo(Nodo *, int);
        Nodo(const Nodo *);				// Constructor copia

        Nodo *get_sig();
        int get_dato();

        void set_dato(int);
        void set_sig(Nodo *n);
};

#endif
