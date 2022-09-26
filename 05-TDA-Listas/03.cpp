/*
	03.cpp
	Entendimiento de como funcionan el pasaje por referencia y punteros.
	Diferencia entre:
		
		void funcion(char *var);
		void funcion_ref(char* &var);

	Explicacion:
		void funcion(char *var);
			cuando entramos la instancia de la funcion se crea un PUNTERO TEMPORAL DE LA INSTACIA EN LA 
			FUNCION puntero var este almecena la direcion de memoria de igual manera que el puntero de
			ptr de la instancia main, permitiendo así las operaciones normales.
		
		void funcion_ref(char* &var);
			Aca NO se crea un PUNTERO TEMPORAL, al ser var una referencia a un puntero char, estamos usando
			la misma varible que tenemos en el main ptr_ref.


		salida el ejecutable demuestra que existe la diferencia

	Fuente:
		https://www.youtube.com/watch?v=7HmCb343xR8
		https://www.delftstack.com/es/howto/cpp/pass-pointer-by-reference-in-cpp/#:~:text=in%20the%20array-,Utilice%20la%20notaci%C3%B3n%20*%26var%20para%20pasar%20un%20puntero%20a,puntero%20como%20par%C3%A1metro%20de%20funci%C3%B3n.


	Compilar de de esta forma sin lo flags:
	g++ 03.cpp -o var
	./var
*/

#include <iostream>

#include <cstring> // prototipos para strcpy y strncpy

using std::strcpy;
using std::strncpy;

using namespace std;

void funcion(char *var){
    var[2] = 't';
 
    cout << "Direccion de var:  " << &var << "  <---Puntero Temporal" << endl;

    strncpy(var + 3, "COMO", 4);

}

void funcion_ref(char* &var){
    /*
        Entonces como 'var' es una referencia a un puntero char 
        puedo usar 'var' como si estuviera usando 'ptr' en el
        bloque main.
    */
    var[2] = 't';

    cout << "Direccion de var (ref): " << &var << endl;

    strncpy(var + 3, "COMO", 4);

}


int main() {
   	// puntero  (char *var)
    char cadena[] = "Fernando";
    char *ptr;

    ptr = cadena;
    cout << "Direccion de &ptr: " << &ptr << endl;
    funcion(ptr);

    //**************************

    char cadena_ref[] = "Fernando";
    char *ptr_ref;

    ptr_ref = cadena_ref;
    
    cout << "\nDireccion de &ptr_ref:  " << &ptr_ref << endl;

    funcion_ref(ptr_ref);



    return 0;
}