/* **************************************************  */
void swap(int *ptr_x, int *ptr_y);
void ordenamBurbuja(int *arreglo, const int tamanio);

void ordenamBurbuja(int *arreglo, const int tamanio){ 
    for(int i = 0; i < tamanio - 1; i++)
        for(int j = 0; j < tamanio - i - 1; j++)
            if(arreglo[j] > arreglo[j + 1]) 
                swap(&arreglo[j], &arreglo[j + 1]);

}

/* 
   swap los valores en las ubicaciones de memoria a los cuales apunta ptr_x y
   ptr_y 
*/
void swap(int *ptr_x, int *ptr_y){
   int temp = *ptr_x;
   *ptr_x = *ptr_y;
   *ptr_y = temp;
} 

/* ************************************************** */

/** Ordena una lista de elementos según el método de selección.
 *  Pre: los elementos de la lista deben ser comparables.
 *  Post: la lista está ordenada.  */
void ordenar_seleccion(int L[], size_t n){
    for(size_t i = 0; i < n - 1; i++){
        size_t p = pos_min(L, i, n - 1);
        swap(L, p, i); 
    }
} 
/** Intercambia los elementos de L en los índices i y j */ 
void swap(int L[], size_t i, size_t j){
    int aux = L[i];
    L[i] = L[j];
    L[j] = aux;
}

/** Devuelve la posición del elemento mínimo en L entre
 *  los índices `desde` y `hasta` (inclusive).  */
size_t pos_min(int L[], size_t desde, size_t hasta){
    size_t pos_min = desde;
    for(size_t i = desde + 1; i <= hasta; i++)
        if(L[i] < L[pos_min])
            pos_min = i;
    
    return pos_min;
}

/* ************************************************** */
/* Pre: L[0]..L[i-1] está ordenada.
 * Post: L[0]..L[i] está ordenada y contiene los mismos elementos
 *   	que estaban en L[0]..L[i-1] más el elemento que estaba en i.
 */
void insertar_ordenado(int L[], size_t i) {
    int v = L[i];
    int j = i - 1;
    while (j >= 0 && L[j] > v) {
        L[j + 1] = L[j];
        j--;
    }
    L[j + 1] = v;
}

/*
 * Ordena una lista de elementos según el método de inserción.
 * Pre: los elementos de la lista deben ser comparables.
 * Post: la lista está ordenada.
 */
void ordenar_insercion(int L[], size_t n) {
    for (size_t i = 1; i < n; i++) {
        insertar_ordenado(L, i);
    }
}
