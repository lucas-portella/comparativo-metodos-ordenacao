#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "entradas.h"
#include "vetor.h"
#include  "ordenacao.h"

int main (int argc, char *argv[]) {
	int entradas, tamanho;
	char buffer[50];
	vetor *v;
	struct timespec inicio, fim;
	double tempo;
	
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
		clock_gettime(CLOCK_MONOTONIC, &inicio);
		insertion_sort (v);
		clock_gettime(CLOCK_MONOTONIC, &fim);
		tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", i + 1, entradas, tempo);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	

	printf("Teste de ordenacao: selection sort\n");
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i + 1);
		v = cria_vetor_arquivo (buffer);
		clock_gettime(CLOCK_MONOTONIC, &inicio);
		selection_sort (v);
		clock_gettime(CLOCK_MONOTONIC, &fim);
		tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", i + 1, entradas, tempo);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	

	printf("Teste de ordenacao: bubble sort\n");
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i + 1);
		v = cria_vetor_arquivo (buffer);
		clock_gettime(CLOCK_MONOTONIC, &inicio);
		bubble_sort (v);
		clock_gettime(CLOCK_MONOTONIC, &fim);
		tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", i + 1, entradas, tempo);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	

	printf("Teste de ordenacao: quick sort\n");
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i + 1);
		v = cria_vetor_arquivo (buffer);
		clock_gettime(CLOCK_MONOTONIC, &inicio);
		quick_sort (v, inicio_vetor(v), fim_vetor(v));
		clock_gettime(CLOCK_MONOTONIC, &fim);
		tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", i + 1, entradas, tempo);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	

	printf("Teste de ordenacao: merge sort\n");
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/aleat_%d.txt", i + 1);
		v = cria_vetor_arquivo (buffer);
		clock_gettime(CLOCK_MONOTONIC, &inicio);
		merge_sort (v, inicio_vetor(v), fim_vetor(v));
		clock_gettime(CLOCK_MONOTONIC, &fim);
		tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
		if (ordenacao (v) == ORDENADO)
			printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", i + 1, entradas, tempo);
		else
			printf ("Teste %d / %d: Vetor desordenado\n", i + 1, entradas);
		v = destroi_vetor (v);
	}	

	return 0;
}
