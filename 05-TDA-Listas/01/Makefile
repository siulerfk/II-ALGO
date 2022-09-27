PROGRAM = main
CC = g++
CFLAGS = -Wall -pedantic -g

all: $(PROGRAM) #compila todas las ordenes

$(PROGRAM): 01.o 01-Nodo.o 01-Lista.o
	$(CC) $(CFLAGS) 01.o 01-Nodo.o 01-Lista.o -o $(PROGRAM)

01.o: 01.cpp 01-Nodo.h
	$(CC) $(CFLAGS) -c 01.cpp

01-Nodo.o: 01-Nodo.cpp 01-Nodo.h
	$(CC) $(CFLAGS) -c 01-Nodo.cpp

01-Lista.o: 01-Lista.cpp 01-Lista.h
	$(CC) $(CFLAGS) -c 01-Lista.cpp


correr:
	./$(PROGRAM)


clean:
	rm -vf *.o 
