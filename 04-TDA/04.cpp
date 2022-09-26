#include <iostream>

template <typename T>

class Matriz {
private:
  T **matriz;
  size_t filas;
  size_t columnas;

public:
  Matriz(size_t);
  Matriz(size_t fil, size_t col);
  ~Matriz();

  size_t get_filas();
  size_t get_columnas();

  T get_valor(size_t pos_fil, size_t pos_col);
  void set_valor(size_t pos_fil, size_t pos_col, T valor);

  void set_init_matriz(T valor);

  bool operator==(const Matriz &) const;
  bool operator!=(const Matriz &) const;

  Matriz operator+(const Matriz &derecha) const;

  void mostrar() const;
};
template <typename T> // ver c++ deitel pag 637
Matriz<T>::Matriz(size_t filcol) {
  filas = filcol;
  columnas = filcol;

  matriz = new T *[filcol];
  for (size_t i = 0; i < filcol; i++)
    matriz[i] = new T[filcol];
}
template <typename T> Matriz<T>::Matriz(size_t fil, size_t col) {
  filas = fil;
  columnas = col;

  matriz = new T *[filas];

  for (size_t i = 0; i < filas; i++)
    matriz[i] = new T[columnas];
}
template <typename T> Matriz<T>::~Matriz() {
  for (size_t i = 0; i < filas; i++)
    delete[] matriz[i];

  delete[] matriz;
}
template <typename T> size_t Matriz<T>::get_filas() { return filas; }
template <typename T> size_t Matriz<T>::get_columnas() { return columnas; }
template <typename T> T Matriz<T>::get_valor(size_t pos_fil, size_t pos_col) {
  return matriz[pos_fil][pos_col];
}
template <typename T>
void Matriz<T>::set_valor(size_t pos_fil, size_t pos_col, T valor) {
  matriz[pos_fil][pos_col] = valor;
}
template <typename T> void Matriz<T>::set_init_matriz(T valor) {
  for (size_t i = 0; i < filas; i++)
    for (size_t j = 0; j < columnas; j++)
      matriz[i][j] = valor;
}
template <typename T> bool Matriz<T>::operator==(const Matriz &derecha) const {
  if (filas != derecha.filas && columnas != derecha.columnas)
    return false;

  for (size_t i = 0; i < filas; i++)
    for (size_t j = 0; j < columnas; j++)
      if (matriz[i][j] != derecha.matriz[i][j])
        return false;

  return true;
}
template <typename T> bool Matriz<T>::operator!=(const Matriz &derecha) const {
  return !(*this == derecha);
}

template <typename T>
Matriz<T> Matriz<T>::operator+(const Matriz &derecha) const {
  size_t max_fil;
  size_t max_col;

  size_t min_fil;
  size_t min_col;

  if (filas <= derecha.filas) {
    max_fil = derecha.filas;
    min_fil = filas;
  }
  if (columnas <= derecha.columnas) {
    max_col = derecha.columnas;
    min_col = columnas;
  }
  std::cout << max_fil << "-" << max_col << "-" << min_fil << "-" << min_col
            << std::endl;

  Matriz aux(max_fil, max_col);

  aux.set_init_matriz(0);

  for (size_t i = 0; i < max_fil; i++)
    for (size_t j = 0; j < max_col; j++) {
      if (0 <= i && i < min_fil && 0 <= j && j < min_col)
        aux.set_valor(i, j, matriz[i][j] + derecha.matriz[i][j]);
      if (0 <= i && i < min_fil && min_col <= j && j < max_col)
        aux.set_valor(i, j, derecha.matriz[i][j]);
      if (min_fil <= i && i < max_fil && 0 <= j && j < max_col)
        aux.set_valor(i, j, derecha.matriz[i][j]);
    }

  return aux;
}
template <typename T> void Matriz<T>::mostrar() const {
  std::cout << std::endl;
  for (size_t i = 0; i < filas; i++) {
    for (size_t j = 0; j < columnas; j++)
      std::cout << matriz[i][j] << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main(void) {
  Matriz<int> A(4, 2);
  Matriz<int> B(5, 3);

  A.set_init_matriz(5);
  B.set_init_matriz(2);

  A.mostrar();
  B.mostrar();

  (B + A).mostrar();
}
