PROGRAM = main
CC = g++
CFLAGS = -Wall -pedantic -std=c++98 

all: $(PROGRAM) #compila todas las ordenes

$(PROGRAM): main.o celula.o tablero.o juegoDeLaVida.o
	$(CC) $(CFLAGS) main.o celula.o tablero.o juegoDeLaVida.o -o $(PROGRAM)

celula.o: celula.cpp celula.h
	$(CC) $(CFLAGS) -c celula.cpp

tablero.o: tablero.cpp tablero.h
	$(CC) $(CFLAGS) -c tablero.cpp

juegoDeLaVida.o: juegoDeLaVida.cpp juegoDeLaVida.h
	$(CC) $(CFLAGS) -c juegoDeLaVida.cpp

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

correr:
	./$(PROGRAM)

clean:
	rm -vf *.o 
