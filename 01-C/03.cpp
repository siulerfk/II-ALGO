/* Como compilar por termnal:
 *      g++ 03.cpp -o var
 *      ./var < 03.txt >> salida.txt
 *
 * - 03.cpp
 *      Como usar el operador de flujo en la terminal. < y >>.}
 *      Lo que se hiso fue crear un archivo 03.txt el cual contine 
 *      entradas por stdout (cin >>); se creo un while para ver si
 *      el ciclo.
 */
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b, c, d;
    
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    
    int i = 0;
    int p = 0; 

    while(i < 5 && p != 2){
        cout << i << " - Fer" << endl;
        cin >> p;
        i++;
    }

    return 0;
}
