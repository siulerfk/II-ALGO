// g++ -Wall -pedantic 01.cpp -o var

#include <iostream>

using namespace std;

int main(){

	int var = 8;
	int *p = &var;
	int **pp = &p;

	cout << "Direccion memoria var: " << &var << endl;
	cout << "Direccion memoria p  : " << &p << endl;
	cout << "Direccion memoria pp : " << &pp << endl;

	cout << endl;
	
	cout << "Direccion memoria *pp  : " << &(*pp) << endl;
	cout << "Direccion memoria **pp : " << &(**pp) << endl;  
	
	cout << endl;
	
	cout << "Valor: pp  : " << (pp) << endl;
	cout << "Valor: *pp : " << (*pp) << endl;
	cout << "Valor: **pp: " << (**pp) << endl;

	return 0;
}