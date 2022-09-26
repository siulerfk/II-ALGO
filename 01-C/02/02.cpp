/* 
 * Como Compilar:
 *      La forma mas facil sin la necesidad de crear un make es:
 *      g++ *.cpp -o var
 *      ./var
 **/
#include <string>
#include "02-lectura.h"
#include "02-escritura.h"

int main() {

	std::string archivoConNotas = "entrada.txt";
	std::string archivoConSecuencia = "salida.txt";

	leerNotas(archivoConNotas);

	escribirSecuencia(archivoConSecuencia);

	return 0;
}
