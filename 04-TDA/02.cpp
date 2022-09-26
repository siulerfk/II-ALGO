
//  deitel pag 617
#include <iostream>

#include <iomanip>
using std::setw;

using std::istream;
using std::ostream;

using std::cin;
using std::cout;
using std::endl;

class Arreglo{
	private:
		int *vector;
		size_t tamanio;
		static size_t cuenta_arreglo;

	public:
		Arreglo(size_t tamanio = 10);
		Arreglo(const Arreglo &); // Constructor copia.

		~Arreglo();

		size_t get_tamanio() const;

		const Arreglo &operator=(const Arreglo &);

		bool operator==(const Arreglo &) const;
		bool operator!=(const Arreglo &) const;

		int &operator[](int);             // La diferencia esta el el const derecho
		const int &operator[](int) const; // el const izq no hace nada si lo omitimos

		static size_t &obtener_cuente_arreglo();

		friend ostream &operator<<(ostream &, const Arreglo &);
		friend istream &operator>>(istream &, Arreglo &);
};

size_t Arreglo::cuenta_arreglo = 0;

Arreglo::Arreglo(size_t tamanio_vector){
	tamanio = (tamanio_vector > 0 ? tamanio_vector : 10);

	vector = new int[tamanio];

	cuenta_arreglo++;

	for (size_t i = 0; i < tamanio; i++)
	vector[i] = 0;
}

Arreglo::Arreglo(const Arreglo &copia):tamanio(copia.tamanio){ // equivalente tamanio = copia.tamanio;
	vector = new int[tamanio];

	cuenta_arreglo++;

	for (size_t i = 0; i < tamanio; i++)
		vector[i] = copia.vector[i];
}

Arreglo::~Arreglo(){
	delete[] vector;
	cuenta_arreglo--;
}

size_t Arreglo::get_tamanio()const{return tamanio;}
/*
pre:
post: Si los vectores son de distinto tananio se redefine el tamanio
y se copia.
*/
const Arreglo &Arreglo::operator=(const Arreglo &derecha) {
	if (&derecha != this){
		if (tamanio != derecha.tamanio){
			delete[] vector;
			tamanio = derecha.tamanio;
			vector = new int[tamanio];
		}

		for (size_t i = 0; i < tamanio; i++)
			vector[i] = derecha.vector[i];
	}

	return *this;
}
/*
pre: Se compara vect1 == derecha, se comnpara vec1 contra derecha
pos:
*/
bool Arreglo::operator==(const Arreglo &derecha) const {
	if (tamanio != derecha.tamanio)
		return false;

	for (size_t i = 0; i < tamanio; i++)
		if (vector[i] != derecha.vector[i])
			return false;

	return true;
}

bool Arreglo::operator!=(const Arreglo &derecha)const{return !(*this == derecha);}

int &Arreglo::operator[](int subindice){return vector[subindice];}

const int &Arreglo::operator[](int subindice)const{return vector[subindice];}

size_t &Arreglo::obtener_cuente_arreglo(){return cuenta_arreglo;}

/*
pos: Muestra por pantalla el vector
*/
ostream &operator<<(ostream &salida, const Arreglo &vec){
	size_t i;

	for (i = 0; i < vec.tamanio; i++) {
		salida << setw(12) << vec.vector[i];
		
		if ((i + 1) % 4 == 0) // cada 4 impresiones da un salto de linea
			salida << endl;
	}

	if (i % 4 != 0)
		salida << endl;

	return salida;
}
istream &operator>>(istream &entrada, Arreglo &vec) {
	for (size_t i = 0; i < vec.tamanio; i++)
		entrada >> vec.vector[i];
			return entrada;
}

int main(void) {
	const Arreglo p(2); // Al ser una variable constante el operador [] solo puede
	// usarse con una funcion const
	Arreglo vect_1(3);
	Arreglo vect_2(1);
	vect_2 = p;

	vect_2 = vect_1;

	int k = p[0];

	std::cout << k << endl;
	cout << p;
	return 0;
}