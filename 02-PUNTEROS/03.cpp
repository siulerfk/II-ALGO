#include <iostream>

float suma(float x, float y) {
    return  x + y;
}

float resta(float x, float y) {
    return  x - y;
}

float multiplica(float x, float y) {
    return  x * y;
}

float divide(float x, float y) {
    return  x / y;
}


int main(int argc, char const *argv[]){
	// Se define un arreglo de punteros a funciones y se le asigna a cada
    // elemento la dirección de una función
    float (*operacion[4])(float, float) = { suma, resta, multiplica, divide };

    char oper[ ] = "+-x/";
    float a = 45, b = 12, c;

    printf("Operaciones:\n");
    for(int i = 0; i < 4; i++) {
        c = operacion[i] (a, b);  // Ejecutamos la función a través de los
                                         // elementos del arreglo
        printf("    %6.2f  %c  %6.2f = %6.2f\n", a, oper[i], b, c);
    }

	return 0;
}