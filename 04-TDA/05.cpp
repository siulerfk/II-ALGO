#include <iostream>


class Ficha{
	private:
		char valor;
		size_t	pos_x;
		size_t	pos_y;


	public:
		Ficha(char);
		void set_pos(const size_t x, const size_t y);

		
};
Ficha::Ficha(char tipo):valor(tipo){}

void Ficha::set_pos(const size_t x, const size_t y){
  this->pos_x = x;
  this->pos_y = y;
}

class Tablero{
	private:
		char **tablero;
		int fil;
		int col;

		int cant_mov;

	public:

		Tablero(int, int);
		~Tablero();


	
};

Tablero::Tablero(int fil, int col){
	this->fil = fil;
	this->col = col;

	this->tablero = new char*[fil];

	for(int i = 0; i < fil; i++)
		this->tablero[i] = new char[col];
}

Tablero::~Tablero(){
	for(int i = 0; i < fil; i++)
		delete [] tablero[i];

	delete [] tablero; 
}


int main(int argc, char const *argv[]){
	
	Tablero tablero(3, 4);


	return 0;
}
