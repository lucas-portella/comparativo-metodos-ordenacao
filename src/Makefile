CC=gcc
FLAGS=-Wall -Wextra

all: main.o entradas.o vetor.o ordenacao.o
	$(CC) $(FLAGS) main.o entradas.o vetor.o ordenacao.o -o main

main.o: main.c
	$(CC) $(FLAGS) -c main.c

entradas.o: entradas.h entradas.c
	$(CC) $(FLAGS) -c entradas.c

vetor.o: vetor.h vetor.c
	$(CC) $(FLAGS) -c vetor.c

ordenacao.o: ordenacao.h ordenacao.c
	$(CC) $(FLAGS) -c ordenacao.c

clean:
	rm -f *.o

purge: clean
	rm -f main	
	rm -rf entradas
