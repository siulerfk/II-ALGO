#include <iostream>

using namespace std;

typedef struct{
	int a;
	int f;
}datos_t;

int main() {
	datos_t casa = {7, 8};
	datos_t *var = &casa;//new datos_t;

		// var->a = 75;
		// var->f = 80;

	cout << &casa << endl;
	cout << &(casa.a) << endl;
	cout << &(casa.f) << endl;
	cout << &(var) << endl;
	cout << &(var->a) << endl;
	cout << &(*var) << endl;
	
	return 0;
}