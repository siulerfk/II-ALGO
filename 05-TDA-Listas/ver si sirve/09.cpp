#include <iostream>

using namespace std;

//**********************Nodo
class Nodo{
    private:
        Nodo *sig;
        int *dato;
    public:
        Nodo();                    
        Nodo(Nodo *, int *);
        Nodo *get_sig();
        int *get_dato();
        void set_dato(int *);
        void set_sig(Nodo *n);
};
Nodo::Nodo(){
    sig = NULL;
    dato = NULL;
}
Nodo::Nodo(Nodo *p, int *x){
    sig = p;
    dato = x;
}
Nodo *Nodo::get_sig(){
    return sig;
}
int *Nodo::get_dato(){
    return dato;
}
void Nodo::set_dato(int *info){
    dato = info;
}
void Nodo::set_sig(Nodo *n){
    sig = n;
}

class Lista{
    private:
        Nodo *prim;
    public:
        Lista();
        ~Lista();
		void agregar_pincipio(int *);
		void agregar_final(int *);
		void eliminar(int *);

};

Lista::Lista():prim(NULL){}

Lista::~Lista(){
    if(prim){
        Nodo *aux = prim;
        while(aux){
            prim = prim->get_sig();
            delete aux;
            aux = prim;
        }
    }
}
void Lista::agregar_pincipio(int *info){
    prim = new Nodo(prim, info);
}

void Lista::agregar_final(int *info){
	Nodo *actual = prim;

	if(prim == NULL)				// Validacion Lista vacia.
		prim = new Nodo(prim, info);
	else{
		while(actual && actual->get_sig())
			actual = actual->get_sig();
		
		actual->set_sig(new Nodo(NULL, info));
	}

}

void Lista::eliminar(int *info){
	if(prim){
		if((prim->get_dato() != *info) && (prim->get_sig())){
			Nodo *anterior = prim;
			Nodo *actual = prim->get_sig();

			while((actual->get_dato() != *info) && (actual->get_sig() != NULL)){
				anterior = actual;
				actual = actual->get_sig();
			}
			if(actual->get_dato() == *info){
				anterior->set_sig(actual->get_sig());
				delete actual;
			}
		}
		else if(prim->get_dato() == *info){
			Nodo *aux = prim;
			prim = prim->get_sig();

			delete aux;
		}

	}
}

int main(void){
	Lista *enteros = new Lista;
    // Nodo f;
    // int t = 78;
    // int *d = &t;
    
    // Nodo *g = new Nodo(&f,d);

    // cout << *(g->get_dato());


    // Nodo super(NULL, (void *)"Fernando");
    
    // char cadena[] = "Carlos martin";
    
    // cout << (char *)super.get_dato();
    
    // super.set_dato((void *)cadena);

    return 0;
}