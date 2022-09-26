#include "01-Lista.h"

Lista::Lista():prim(NULL){}

Lista::Lista(Lista *lista){
    Nodo *actual = lista->get_prim(); 

    this->prim = NULL;
 
    if(actual){
        this->prim = new Nodo(NULL, actual->get_dato());
        Nodo *nuevo = this->prim;

        actual = actual->get_sig();

        while(actual){
            nuevo->set_sig(new Nodo(NULL, actual->get_dato()));
            
            nuevo = nuevo->get_sig();

            actual = actual->get_sig();
        }
    }
}

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

void Lista::agregar_final(const int info){
	Nodo *actual = prim;

    if(prim == NULL)				// Validacion Lista vacia.
        prim = new Nodo(prim, info);
    else{
        while(actual && actual->get_sig())
            actual = actual->get_sig();
        
        actual->set_sig(new Nodo(NULL, info));
    }

}
/*	
	pre: Si la posicion no esta dentro de los limites de la lista no se agrega
*/
void Lista::agregar_posicion(const int info, const int pos){
    Nodo *nuevo = new Nodo(NULL, info);

    Nodo *anterior = NULL;
    Nodo *actual = prim;

    int contador = 0;

    if(pos == 0){							// Si la posicion esta al principio
        nuevo->set_sig(prim);
        prim = nuevo;
    }
    else if(prim){
        while(contador < pos && actual){
            anterior = actual;
            actual = actual->get_sig();
            contador++;
        }

        if(actual != NULL){					// Si la posicion esta en medio		
            anterior->set_sig(nuevo);
            nuevo->set_sig(actual);
        }
        else if(pos == contador && actual == NULL)	// Si la posicion esta al final
            anterior->set_sig(nuevo);
        
    }

}

bool Lista::eliminar_primero(){
    Nodo *aux = prim;

    if(prim){
        prim = prim->get_sig();

        delete aux;

        return true;
    }
	return false;
}
/*
	pre: Elimina el ultimo dato
	post: Retorna false si la lista esta vacia y true si pudo eliminar el dato
*/
bool Lista::eliminar_ultimo(){
    Nodo *anterior = NULL;
    Nodo *actual = prim;
    
    if(prim){
        while(actual->get_sig()){
            anterior = actual;
            actual = actual->get_sig();
        }
        anterior->set_sig(NULL);

        delete actual;
    
        return true;
    }

    return false;
}
/*
	Pre: Recibe argumento entero positivo, incluyendo el cero.
	Post: Si elimino algo retorna true sino false y no modifica la lista.
*/
bool Lista::eliminar_posicion(const int pos){
    Nodo *anterior = NULL;
    Nodo *actual = prim;

    int contador = 0;

    if(pos == 0 && eliminar_primero())
        return true;
    else if(prim){
        while(contador < pos && actual->get_sig()){
            anterior = actual;
            actual = actual->get_sig();

            contador++;
        }
        if(contador == pos){
            anterior->set_sig(actual->get_sig());
            delete actual;

            return true;	
        }

    }

    return false;
}

/*
 * Pre: Recibe el "dato" a eliminar.
 * Post: Retorna true si encuetra el "dato" en la lista, procede a eliminarlo,
 *       sino lo encuentra retorna false.
 */
bool Lista::eliminar_buscado(const int info){
    if(prim){
        // Si el dato esta en el centro o al final.
        if((prim->get_dato() != info) && (prim->get_sig() != NULL)){
            Nodo *anterior = prim;
            Nodo *actual = prim->get_sig();

            while((actual->get_dato() != info) && (actual->get_sig() != NULL)){
                anterior = actual;
                actual = actual->get_sig();
            }
            if(actual->get_dato() == info){
                anterior->set_sig(actual->get_sig());
                
                delete actual;

                return true;
            }
        }
        // Si el dato buscado esta al principio.
        else if(prim->get_dato() == info){
            Nodo *aux = prim;
            prim = prim->get_sig();

            delete aux;

            return true;
        }
    }
    return false;
}
/*
	Pre: 
	Post: Retorna el primer dato da lista.
*/
int Lista::obtener_primero()const{
	return prim->get_dato();
}
Nodo *Lista::get_prim(){
    return this->prim;
}
void Lista::set_prim(Nodo *n){
    this->prim = n;
}
/*
 * Pre:  Recibe como parametro una lista.
 * Post: Si no existe ninguna coincidencia o una (ambas) de las listas esta vacia
 *       se retorna una lista dinamica vacia.
 */
Lista *Lista::interseccion(Lista *lista){
    Nodo *actual_1 = this->prim;
    Nodo *actual_2 = lista->get_prim();
    
    Lista *nuevo = new Lista();

    bool status = true;

    while(actual_1 && actual_2){
        while(actual_2 && status){
            if(actual_1->get_dato() == actual_2->get_dato()){
                nuevo->agregar_final(actual_2->get_dato());
                status = false;
            }
            actual_2 = actual_2->get_sig();
         }

        actual_2 = lista->get_prim();
        actual_1 = actual_1->get_sig(); 
        status = true;
    }

    return nuevo;
}

void Lista::mostrar_datos()const{
	if(prim){
		Nodo *aux = prim;
		
		cout << "************************************************\n";	
		while(aux){
			cout << aux->get_dato() << " ";
			aux = aux->get_sig();
		}
		cout << endl;
		cout << "************************************************\n";

	}
}
