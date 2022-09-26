// #include<iostream>
// #include "05-Lista.h"	

// using namespace std;	

// int main(){
// 	Lista<float> sueldos;
	
// 	float suel;
// 	float maximo=-1;
	
// 	cout << "Ingrese sueldo, -1 para finalizar" << endl;
// 	cin >> suel;
	
// 	while(suel != -1){
// 		sueldos.add(suel); 	
// 		cout<< "Ingrese sueldo, -1 para finalizar" << endl;
// 		cin >> suel;
// 	}
	
// 	sueldos.reiniciarCursor();
	
// 	while(sueldos.avanzarCursor())
// 		if (sueldos.getCursor() > maximo) 
// 			maximo = sueldos.getCursor(); 

// 	cout << "el sueldo máximo fue " << maximo << endl;
	
// 	return 0;
// }


// ************************ MAIN 2 ****************************++
#include<iostream>
#include "05-Lista.h"

using namespace std;

int main(){   
	Lista <string*> nombres;
	
	string* pnom, nom;
	
	cout<< "Ingrese nombre, * para finalizar" << endl;
	cin >> nom;
	
	while(nom != "*"){
		pnom = new string;
		*pnom = nom;
		
		nombres.add(pnom);
		
		cout << "Ingrese nombre, * para finalizar" << endl;
		cin >> nom;
	}
	
	nombres.reiniciarCursor();
	
	while (nombres.avanzarCursor())
	cout << *(nombres.getCursor()) << " ";
	
	cout << " fin de la lista " << endl;
	
	return 0;
}
