/* Para compilar hacemos:
 *      g++ -Wall -pedantic 07-*.cpp -o var
 *      ./var
 */
#include "07-Lista.h"
#include <cstring>

typedef struct{
    char name[10];
    size_t edad;
}persona_t;

// Se realiza una comparacion por el dato miembro name
int strcmp_names(const void *a, const void *b){
    char *aa = ((persona_t *)a)->name;
    char *bb = ((persona_t *)b)->name;

    return strcmp((const char *)aa, (const char *)bb);
}

int strcmp_edad(const void *a, const void *b){
    size_t aa = ((persona_t *)a)->edad;
    size_t bb = ((persona_t *)b)->edad;

    return aa - bb;
}


int main(int argc, char *argv[]){
    Lista *persona = new Lista();
    
    persona_t juan = {"juan", 14};
    persona_t maria = {"maria", 46};
    persona_t pedro = {"pedro", 34};
    persona_t noelia = {"Noelia", 25};
    persona_t fer = {"fernando", 20};
  
    persona->agregar_final(&juan);
    persona->agregar_final(&maria);
    persona->agregar_final(&pedro);
    persona->agregar_final(&noelia);
    persona->agregar_final(&fer);

    size_t n = persona->lista_largo();

    for(size_t i = 0; i < n; i++){
        persona_t *aux = (persona_t *)persona->obtener_dato(i);
        cout << i << "--> " <<  "nombre: " << aux->name << endl;
        cout << "     edad: " << aux->edad << endl << endl;
    }
    
    /* Se Busca si el dato (struct maria) se encuentra dentro de
     * la lista enlazada simple. Dentro de la funcion strcmp_names
     * se realiza una comparacion con los datos miembro "name".
     */
    cout <<  persona->buscar_dato(&maria, strcmp_names);
    delete persona;

    return 0;
}

/* 

Main: version con datos cadenas.

int strcmp_void(const void *a, const void *b){
    return strcmp((const char *)a, (const char *)b);
}

int main(int argc, char *argv[]){
    Lista *persona = new Lista();
  
    persona->agregar_final("Todos");
    persona->agregar_final("las");
    persona->agregar_final("Ranas");
    persona->agregar_final("son");
    persona->agregar_final("gatos");

    size_t n = persona->lista_largo();

    for(size_t i = 0; i < n; i++){
        persona_t *aux = (persona_t *)persona->obtener_dato(i);
        cout << i << "--> " <<  "nombre: " << aux->name << endl;
    }
    

    cout << (char *)persona->buscar_dato("Ranas", strcmp_void);

    delete persona;

    return 0;
}

*/
