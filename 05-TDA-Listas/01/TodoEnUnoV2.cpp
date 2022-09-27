#include <iostream>
using namespace std;

class Nodo{
    private:
        Nodo *sig;
        int dato;
    
    public:
        Nodo();                    
        Nodo(Nodo *, int);
        Nodo(const Nodo *);                
        Nodo *get_sig();
        int get_dato();

        void set_dato(int);
        void set_sig(Nodo *n);
};

// Constructor
Nodo::Nodo(){
    sig = NULL;
    dato = 0;
}
// Constructor
Nodo::Nodo(Nodo *ptr, int info){
    sig = ptr;
    dato = info;
}
// Constructor copia
Nodo::Nodo(const Nodo *ptr){
    sig = ptr->sig;
    dato = ptr->dato;
}
Nodo *Nodo::get_sig(){
    return sig;
}
int Nodo::get_dato(){
    return dato;
}
void Nodo::set_dato(int info){
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

void Lista::agregar_pincipio(const int info){
    prim = new Nodo(prim, info);
}
Nodo *Lista::get_prim(){
    return this->prim;
}
void Lista::set_prim(Nodo *n){
    this->prim = n;
}
 
Lista ***crear_cubo_lista(size_t filas, size_t col){
    Lista ***lista = new Lista**[filas];

    for(size_t i = 0; i < filas; i++)
        lista[i] = new Lista*[col];

    for(size_t i = 0; i < filas; i++)
        for(size_t j = 0; j < col; j++)
            lista[i][j] = new Lista();

    return lista;
}
void destruir_cubo_lista(Lista ***lista, size_t filas, size_t col){

    for(size_t i = 0; i < filas; i++)
        for(size_t j = 0; j < col; j++)
            delete lista[i][j];

    for(size_t i = 0; i < filas; i++)
        delete[] lista[i];

    delete[] lista;
}
int main(void){
  
    Lista ***cubo = crear_cubo_lista(2, 3);
    
    (cubo[0][0])->agregar_pincipio(5);


    destruir_cubo_lista(cubo, 2, 3);

    return 0;
}
