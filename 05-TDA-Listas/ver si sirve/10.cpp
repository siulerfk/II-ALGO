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
bool Lista::agregar_pincipio(void *info){
    
}
int main(void){
    Nodo f;
    int t = 78;
    int *d = &t;
    
    Nodo *g = new Nodo(&f,d);

    cout << *(g->get_dato());


    // Nodo super(NULL, (void *)"Fernando");
    
    // char cadena[] = "Carlos martin";
    
    // cout << (char *)super.get_dato();
    
    // super.set_dato((void *)cadena);

    return 0;
}