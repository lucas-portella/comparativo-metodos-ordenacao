/*
	VETOR: Definição da estrutura de dados, funções e macros. 
*/

#ifndef VETOR_H
#define VETOR_H

#include <stdlib.h>
#include <stdio.h>

#define tamanho_vetor(x) x->tamanho
#define inicio_vetor(x) 0
#define fim_vetor(x) x->tamanho-1
#define elemento_vetor(x,y) x->vetor[y]

#define ORDENADO 1
#define NAO_ORDENADO 0

typedef struct Vetor {
	int *vetor;
	int tamanho;
} vetor;

vetor *cria_vetor (int tamanho);
vetor *destroi_vetor (vetor *vetor);
vetor *cria_vetor_arquivo (const char* pathname);
void imprime_vetor (vetor *vetor);
int ordenacao (vetor *vetor);

#endif
