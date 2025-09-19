/* 
	ENTRADAS: Criação de valores aleatorios, crescentes, e decrescentes
			  para os vetores.
*/

#ifndef ENTRADAS_H
#define ENTRADAS_H

#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define ERRO 1

int cria_entrada_aleatoria (const char* pathname, int tamanho);
int cria_entrada_crescente (const char* pathname, int tamanho);
int cria_entrada_decrescente (const char* pathname, int tamanho);

#endif
