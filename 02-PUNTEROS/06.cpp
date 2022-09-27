/* 
 * Ejemplo de uma matriz de punteros.
 * Puntero triple
 */

#include <iostream>

int main(int argc, char *argv[]){ 
   
    int ***arreglo = new int**[5];

    for(int i = 0; i < 2; i++)
        arreglo[i] = new int*[7];
    
    int a =4;

    arreglo[0][0] = &a;    

    return 0;
}
