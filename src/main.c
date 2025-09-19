#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "entradas.h"
#include "vetor.h"
#include  "ordenacao.h"

int main (int argc, char *argv[]) {
	int entradas, tamanho;
	char buffer[50];
	vetor *v;
	
	srand(0);
	
	if (argc != 3) {
		printf ("Uso: ./main [QTD_ENTRADAS] [TAMANHO]\n");
		exit (1);
	}	

	if (!(entradas = atoi(argv[1])))
		exit (1);

	if (!(tamanho = atoi(argv[2])))
		exit (1);

	mkdir ("./entradas", 0700);
	mkdir ("./entradas/aleatoria", 0700);

	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i+1);
		cria_entrada_aleatoria ((const char*) buffer, tamanho);
	}

	printf("Teste de ordenacao: insertion sort\n");
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i + 1);
		v = cria_vetor_arquivo (buffer);
		insertion_sort (v);
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado\n", i + 1, entradas);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	

	printf("Teste de ordenacao: selection sort\n");
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i + 1);
		v = cria_vetor_arquivo (buffer);
		selection_sort (v);
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado\n", i + 1, entradas);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	

	printf("Teste de ordenacao: bubble sort\n");
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i + 1);
		v = cria_vetor_arquivo (buffer);
		bubble_sort (v);
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado\n", i + 1, entradas);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	


	return 0;
}
