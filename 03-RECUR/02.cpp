/*
	Convertir el factorial en recusividad de cola
*/

/*
	Recursividad simple
	Pre: Recibe como parametro un numero entero positivo
	Post: Retorna un numero entero positivo
*/
long factorial(int numero){
	if(n == 1)
		return 1;

	return (n * factorial(n - 1));
}

/*	
	Recursividad de cola
	Fuente: 
		https://www.youtube.com/watch?v=SIgfSYyWVjo
*/
long factorial(int numero){
	return factorial_rec(numero, 1);
}

long factorial_rec(int numero, int acumulador){
	if(numero == 1)
		return acumulador;
	return factorial_rec(numero -1, numero * acumulador);
}

//************************************************************
/*
	Sea la sucesion de fibonacci
	0 1 1 2 3 5 8 13 21 34 55 89 144 -> Sucesion
	0 1 2 3 4 5 6  7  8  9 10 11  12 -> Posicion

	Pre: n = posicion de la serie y ek valor devuelto

*/
size_t fibonacci(size_t n){
	if(n < 2)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);

}

/*	
	Recursividad de Cola
	Se realizo un ejemplo con https://pythontutor.com/
	con n = 10
		Recursividad simple o multiple cantidad de operaciones 888
		Resursividad de Cola cantida de operaciones 56
*/
size_t fibonacci(size_t n){
	return fibonacci_rec(n, 0, 1);
}

size_t fibonacci_rec(size_t n, int a , int b){
	if(n == 0)
		return a;	// acumulador
	if(n == 1)
		return b;	// acumulador
	return fibonacci_rec(n - 1, b, a + b);
}