/******************************************************************************
 *                   Algoritmos y Programación II - 75.41                     *
 *                        Cátedra Ing. Patricia Calvo                         *
 *            Facultad de Ingeniería - Universidad de Buenos Aires            *
 ******************************************************************************/ 

/* Punteros
 * Ejercicio Tipo Parcial Nº1 
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int* Pint;
typedef char* Pchar;

/*
  Datos: 
    '@' es 64
    'A' es 65
    ...
*/

int main(){

  Pint A, C, J, F;
  Pint* B;    //puntero doble
  Pchar D, E;
  char G;
  int H;
  
  H = 64;
  G = 'C';
  A = new int;
  F = new int;
  (*A) = 70; 
  cout << H << G << (*A) << endl;
  B = &A;
  (*F) = H; 
  cout << (**B) << (*A) << endl; //70 70
  D = (Pchar)F; // @
  E = (Pchar)(*B);
  C = (Pint)D;
  J = (Pint)E;
  cout << (*D) << (*E) << (**B) << endl;
  (*C) = (*C) - 62;
  (*J) = (*J) - (*J);
  
  if ((*F) == H) {
    cout << G << H << (*E) << endl;
  }
  
  while ((*C) != 0) {
    cout << (*A) << (*C) << endl;
    (*C) = (*C) - 1;
    (*E) = 'B';
  }
  
  delete A;
  delete F;
  
  return 0;
}

/*
  Resultado:
  
      64C70
      7070    
      @F70
      02
      661
  
*/