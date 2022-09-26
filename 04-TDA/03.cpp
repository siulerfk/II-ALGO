/*
        g++ -Wall -pedantic 04.cpp -o var
        valgrind ./var

*/
#include <iostream>

class Matriz{
    private:
        int **matriz;
        size_t filas;
        size_t columnas;

    public:
        Matriz(size_t);
        Matriz(size_t fil, size_t col);

        ~Matriz();

        size_t get_filas()const;
        size_t get_columnas()const;

        int get_valor(size_t pos_fil, size_t pos_col)const;

        void set_valor(size_t pos_fil, size_t pos_col, int valor);
        void set_init_matriz(int valor);

        void sumar_matriz(const Matriz &a, const Matriz &b)const;

        bool operator == (const Matriz &) const;
        bool operator != (const Matriz &) const;
        Matriz &operator = (const Matriz &derecha);
        Matriz operator + (const Matriz &derecha);

        void mostrar() const;
};

/* 
 * Pre: El parametro debe ser mayor que cero
 * Post: Crea un matriz dinamica cuadrada
 */
Matriz::Matriz(size_t filcol) {
    filas = filcol;
    columnas = filcol;

    matriz = new int *[filcol];

    for (size_t i = 0; i < filcol; i++)
        matriz[i] = new int[filcol];
}

Matriz::Matriz(size_t fil, size_t col) {
	filas = fil;
	columnas = col;

	matriz = new int *[filas];

	for (size_t i = 0; i < filas; i++)
        matriz[i] = new int[columnas];
}

Matriz::~Matriz(){
	for (size_t i = 0; i < filas; i++)
		delete[] matriz[i];

	delete[] matriz;
}

size_t Matriz::get_filas()const{return filas;}
size_t Matriz::get_columnas()const{return columnas;}

/* Pre: Recibe parametros postivos
 * Post: Retorna el valor de posicion [pos_fil, pos_col]
 */
int Matriz::get_valor(size_t pos_fil, size_t pos_col)const{
	return matriz[pos_fil][pos_col];
}
void Matriz::set_valor(size_t pos_fil, size_t pos_col, int valor) {
	matriz[pos_fil][pos_col] = valor;
}

void Matriz::set_init_matriz(int valor){
	for (size_t i = 0; i < filas; i++)
		for (size_t j = 0; j < columnas; j++)
			matriz[i][j] = valor;
}
/* 
 * Pre: 
 *  1) La matriz a y b deben estar creadas.
 *  2) La dimension a == dimension b.
 * Post:
 *  1) Retorna una matriz nueva.
 */
void Matriz::sumar_matriz(const Matriz &a, const Matriz &b)const{
    for(size_t i = 0; i < filas; i++)
        for(size_t j = 0; j < columnas; j++)
            matriz[i][j] = a.get_valor(i, j) + b.get_valor(i, j);

}
bool Matriz::operator == (const Matriz &derecha)const{
    if (filas != derecha.filas && columnas != derecha.columnas)
        return false;

    for (size_t i = 0; i < filas; i++)
        for (size_t j = 0; j < columnas; j++)
            if (matriz[i][j] != derecha.matriz[i][j])
                return false;

return true;
}

bool Matriz::operator != (const Matriz &derecha)const{
	return !(*this == derecha);
}
/*
 * Pre: 
 *  1) Ambas matrices deben estar creadas.
 *  2) Deben tener la misnma dimension.
 *
 * Post:
 *  1) Asigna un nuevo valor.
 */
Matriz &Matriz::operator = (const Matriz &derecha){
    for(size_t i = 0; i < filas; i++)
        for(size_t j = 0; j < columnas; j++)
            matriz[i][j] = derecha.get_valor(i, j);

    return *this;
}

Matriz Matriz::operator + (const Matriz &derecha){
    Matriz aux(filas, columnas);

    for(size_t i = 0; i < filas; i++)
        for(size_t j = 0; j < columnas; j++)
           aux.set_valor(i, j, matriz[i][j] + derecha.get_valor(i, j));

    return aux;
}
void Matriz::mostrar()const{
    std::cout << std::endl;

    for(size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j++)
            std::cout << matriz[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//****************************************************************************
int main(void) {
	Matriz A(3, 2);
	Matriz B(3, 2);
	Matriz C(3, 2);

	A.set_init_matriz(5);
	A.mostrar();

	B.set_init_matriz(2);
	B.mostrar();
    
    C = A + B;
    C.mostrar();

	return 0;
}

/*
        El Diseño del algoritmo que suma dos matrices de distint tamaño
agregando ceros y generando otra matriz es mas dificil de pensar


Matriz Matriz::operator+(const Matriz &derecha)const{
        size_t max_fil = filas;
        size_t max_col = columnas;

        size_t min_fil = derecha.filas;
        size_t min_col = derecha.columnas;

        std::cout << "**" << filas << "-" << columnas << "-" << derecha.filas <<
"-" << derecha.columnas << std::endl;

        if(filas <= derecha.filas){
                max_fil = derecha.filas;
                min_fil = filas;
                std::cout << "dfdf";
        }

        if(columnas <= derecha.columnas){
                max_col = derecha.columnas;
                min_col = columnas;
        }
        std::cout << max_fil << "-" << max_col << "-" << min_fil << "-" <<
min_col << std::endl;

        Matriz aux(max_fil, max_col);

        aux.set_init_matriz(0);

        for(size_t i = 0; i < max_fil; i++)
                for(size_t j = 0; j < max_col; j++){
                        if(0 <= i && i < min_fil && 0 <= j && j < min_col)
                                aux.set_valor(i, j, matriz[i][j] +
derecha.matriz[i][j]); if(0 <= i && i < min_fil && min_col <= j && j < max_col)
                                aux.set_valor(i, j, derecha.matriz[i][j]);
                        if(min_fil <= i && i < max_fil && 0 <= j && j < max_col)
                                aux.set_valor(i, j, derecha.matriz[i][j]);
                }

        return aux;
}
*/
