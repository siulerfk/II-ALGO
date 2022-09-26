// g++ -Wall -pedantic 01.cpp -o var

#include <iostream>

using namespace std;

class Complejo {
	private:
		double real;
  		double imag;

	public:
		Complejo(double = 0, double = 0);
		Complejo(const Complejo &);

		~Complejo();

		double get_real();
		double get_imag();

		void set_real(const double);
		void set_imag(const double);

		Complejo sumar(const Complejo &);
		Complejo sumar(double);

		Complejo operator + (const Complejo &)const;
		Complejo operator - (const Complejo &)const;
		Complejo operator * (const Complejo &)const;
		Complejo operator / (const double &)const;
		Complejo operator / (const Complejo &)const;
		Complejo operator ~ ()const;
		Complejo& operator = (const Complejo &);
		
		bool operator == (const Complejo &)const;
		bool operator != (const Complejo &)const;

		void mostrar();

		friend ostream& operator << (ostream &out, const Complejo &var);
		friend istream& operator >> (istream &in, Complejo &var);
};

Complejo::Complejo(double real, double imaginario):real(real), imag(imaginario){}

// Copia el complejo c pasado como referencia
Complejo::Complejo(const Complejo &copia) {
	real = copia.real;
	imag = copia.imag;
}

Complejo::~Complejo(){}

double Complejo::get_real(){return real;}
double Complejo::get_imag(){return imag;}

void Complejo::set_real(const double a){real = a;}
void Complejo::set_imag(const double b){imag = b;}

Complejo Complejo::sumar(const Complejo &a){return Complejo(real + a.real, imag + a.imag);}
Complejo Complejo::sumar(double var){return Complejo(real + var, imag);}

// Operadores miembros.
Complejo Complejo::operator+(const Complejo &var)const{
	Complejo aux;
	
	aux.real = this->real + var.real;
	aux.imag = this->imag + var.imag;

	return aux;
}

Complejo Complejo::operator-(const Complejo &var)const{
	Complejo aux;
	aux.real = this->real - var.real;
	aux.imag = this->imag - var.imag;

	return aux;
}

Complejo Complejo::operator*(const Complejo &var)const{
	Complejo aux;
	aux.real = this->real * var.real - this->imag * var.imag;
	aux.imag = this->real * var.imag + this->imag * var.real;

	return aux;
}
Complejo Complejo::operator / (const double &var)const{
	Complejo aux;
	aux.real = this->real / var;
	aux.imag = this->imag / var;

	return aux;

}

Complejo Complejo::operator / (const Complejo &var)const{
	Complejo aux;
	aux = (~var * *this) / (var.real * var.real + var.imag * var.imag);
	
	return aux;
}
Complejo Complejo::operator ~ ()const{
	Complejo aux;
	aux.real = this->real;
	aux.imag = - this->imag;

	return aux;
}

Complejo& Complejo::operator=(const Complejo &var){
	this->real = var.real;
	this->imag = var.imag;

	return *this;
}
bool Complejo::operator == (const Complejo &var)const {
	return this->real == var.real && this->imag == var.imag ? true : false;
}
bool Complejo::operator != (const Complejo &var)const{
	return !(*this == var);
}
void Complejo::mostrar(){
	std::cout << "\nParte real de a: " << real << "\nParte Imag de a: " << imag
	<< endl;
}

ostream& operator <<(ostream &out, const Complejo &var){
	out << var.real << " + " << var.imag << "i" << endl;
	return out;
}
istream& operator >> (istream &in, Complejo &var){
	cout << "Parte Real: ";
	in >>  var.real;
	cout << "Parte Imag: ";
	in >>  var.imag;
	return in;
}

// Independiente de la clase
void mostrar(Complejo a){
	std::cout << "\nParte real de a: " << a.get_real()
	<< "\nParte Imag de a: " << a.get_imag() << endl;
}


int main(void) {
    Complejo f(1, 8); 
    Complejo g(3,5);
    Complejo p;
 
    
    p =  f + 8;
	cin >> p;
	//mostrar(p);
	
	return 0;
}
/*
se presencio un tipo de error. si aun no sobrecargamos el operador de asignacin
=, cuando definimos     z = c + a     o    b = c.operator+(a);    se genera un
ingreso al constructor copia, donde la variable 'a' se copia asi misma. Si
quitamos esté constructor NO la asignacion sigue de manera usual. EL problema
está en que NO sobrecagamos el operador de asinación (dentro de este tenemos que
verificar la auto asignacion)
*/

/*
	Complejo a(1, 3), b(2, 3), c(5, 7); // z(b);

	std::cout << "Parte real de a: " << a.get_real()
	<< "\nParte Imag de a: " << a.get_imag() << endl;

	// b = c.operator+(a);        //equivalentes z = a + c;

	c + a; // z = c + a;

	// a.mostrar();

	// mostrar(a);
*/
