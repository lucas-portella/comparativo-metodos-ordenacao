#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "entradas.h"
#include "vetor.h"
#include  "ordenacao.h"

typedef struct op_quadratica {
	const char *nome;
	void (*func)(vetor*);
} operacao_quadratica;

typedef struct op_log {
	const char *nome;
	void (*func)(vetor*,int,int);
} operacao_logaritmica;

int main (int argc, char *argv[]) {
	int entradas, tamanho;
	char buffer[100];
	vetor *v;
	struct timespec inicio, fim;
	double tempo;
	operacao_quadratica quadratica[] = { 
		{"Selection Sort", selection_sort},
		{"Insertion Sort", insertion_sort},
		{"Bubble Sort", bubble_sort}
	};

	operacao_logaritmica logaritmica[] = {
		{"Quick Sort", quick_sort},
		{"Merge Sort", merge_sort}
	};

	
	if (argc != 3) {
		printf ("Uso: ./main [QTD_ENTRADAS] [TAMANHO]\n");
		exit (1);
	}	

	if (!(entradas = atoi(argv[1])))
		exit (1);

	if (!(tamanho = atoi(argv[2])))
		exit (1);

	srand(time(NULL));

	mkdir ("./entradas", 0700);
	mkdir ("./entradas/aleatoria", 0700);
	mkdir ("./entradas/crescente", 0700);
	mkdir ("./entradas/decrescente", 0700);

	/* Criacao de entradas */
	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/aleatoria/ent_%d.txt", i+1);
		cria_entrada_aleatoria ((const char*) buffer, tamanho);
	}

	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/crescente/ent_%d.txt", i+1);
		cria_entrada_crescente ((const char*) buffer, tamanho);
	}

	for (int i = 0; i < entradas; i++) {
		sprintf (buffer, "./entradas/decrescente/ent_%d.txt", i+1);
		cria_entrada_decrescente ((const char*) buffer, tamanho);
	}

	printf("ENTRADA ALEATORIA\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < entradas; j++) {
			const char *op = quadratica[i].nome;
			if (j == 0)
				printf("Metodo de ordenacao: %s\n", op);

			sprintf(buffer, "./entradas/aleatoria/ent_%d.txt", j + 1);
			v = cria_vetor_arquivo (buffer);
			clock_gettime(CLOCK_MONOTONIC, &inicio);
			quadratica[i].func(v);
			clock_gettime(CLOCK_MONOTONIC, &fim);
			tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
			if (ordenacao (v) == ORDENADO)
				printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", j + 1, entradas, tempo);
			else
				printf ("Teste %d / %d: Vetor desordenado\n", j + 1, entradas);
			v = destroi_vetor (v);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < entradas; j++) {
			const char *op = logaritmica[i].nome;
			if (j == 0)
				printf("Metodo de ordenacao: %s\n", op);

			sprintf(buffer, "./entradas/aleatoria/ent_%d.txt", j + 1);
			v = cria_vetor_arquivo (buffer);
			clock_gettime(CLOCK_MONOTONIC, &inicio);
			logaritmica[i].func(v, inicio_vetor(v), fim_vetor(v));
			clock_gettime(CLOCK_MONOTONIC, &fim);
			tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
			if (ordenacao (v) == ORDENADO)
				printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", j + 1, entradas, tempo);
			else
				printf ("Teste %d / %d: Vetor desordenado\n", j + 1, entradas);
			v = destroi_vetor (v);
		}
		printf("\n");
	}

	printf("ENTRADA CRESCENTE\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < entradas; j++) {
			const char *op = quadratica[i].nome;
			if (j == 0)
				printf("Metodo de ordenacao: %s\n", op);

			sprintf(buffer, "./entradas/crescente/ent_%d.txt", j + 1);
			v = cria_vetor_arquivo (buffer);
			clock_gettime(CLOCK_MONOTONIC, &inicio);
			quadratica[i].func(v);
			clock_gettime(CLOCK_MONOTONIC, &fim);
			tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
			if (ordenacao (v) == ORDENADO)
				printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", j + 1, entradas, tempo);
			else
				printf ("Teste %d / %d: Vetor desordenado\n", j + 1, entradas);
			v = destroi_vetor (v);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < entradas; j++) {
			const char *op = logaritmica[i].nome;
			if (j == 0)
				printf("Metodo de ordenacao: %s\n", op);

			sprintf(buffer, "./entradas/crescente/ent_%d.txt", j + 1);
			v = cria_vetor_arquivo (buffer);
			clock_gettime(CLOCK_MONOTONIC, &inicio);
			logaritmica[i].func(v, inicio_vetor(v), fim_vetor(v));
			clock_gettime(CLOCK_MONOTONIC, &fim);
			tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
			if (ordenacao (v) == ORDENADO)
				printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", j + 1, entradas, tempo);
			else
				printf ("Teste %d / %d: Vetor desordenado\n", j + 1, entradas);
			v = destroi_vetor (v);
		}
		printf("\n");
	}

	printf("ENTRADA DECRESCENTE\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < entradas; j++) {
			const char *op = quadratica[i].nome;
			if (j == 0)
				printf("Metodo de ordenacao: %s\n", op);

			sprintf(buffer, "./entradas/decrescente/ent_%d.txt", j + 1);
			v = cria_vetor_arquivo (buffer);
			clock_gettime(CLOCK_MONOTONIC, &inicio);
			quadratica[i].func(v);
			clock_gettime(CLOCK_MONOTONIC, &fim);
			tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
			if (ordenacao (v) == ORDENADO)
				printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", j + 1, entradas, tempo);
			else
				printf ("Teste %d / %d: Vetor desordenado\n", j + 1, entradas);
			v = destroi_vetor (v);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < entradas; j++) {
			const char *op = logaritmica[i].nome;
			if (j == 0)
				printf("Metodo de ordenacao: %s\n", op);

			sprintf(buffer, "./entradas/decrescente/ent_%d.txt", j + 1);
			v = cria_vetor_arquivo (buffer);
			clock_gettime(CLOCK_MONOTONIC, &inicio);
			logaritmica[i].func(v, inicio_vetor(v), fim_vetor(v));
			clock_gettime(CLOCK_MONOTONIC, &fim);
			tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
			if (ordenacao (v) == ORDENADO)
				printf ("Teste %d / %d: Vetor ordenado - %.3f s\n", j + 1, entradas, tempo);
			else
				printf ("Teste %d / %d: Vetor desordenado\n", j + 1, entradas);
			v = destroi_vetor (v);
		}
		printf("\n");
	}

	return 0;
}
