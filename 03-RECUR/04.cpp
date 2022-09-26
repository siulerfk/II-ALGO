/*
	Ordenamiento burbuja usando recursividad
	n = cant elementos
*/

#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int *buscar_min(int array[], size_t n){
	int *min = &array[0];
	for(size_t i = 1; i < n; i++)
		if(*min > array[i])
			min = &array[i];

	return min;
}

void selection_sort(int array[], size_t n){
	if(n == 1)
		return;

	swap(array, buscar_min(array + 1, n - 1));
	
	selection_sort(array + 1, n - 1);
}

void bubble_sort(int array[], size_t n){
	if(n == 1)
		return;

	for(size_t i = 0; i < n - 1; i++)
		if(array[i] > array[i + 1])
			swap(&array[i], &array[i + 1]);

	bubble_sort(array, n - 1);
}

int main() {
	int a[]= {4, 5, 3, 6};
	selection_sort(a, 4);
	
	return 0;
}