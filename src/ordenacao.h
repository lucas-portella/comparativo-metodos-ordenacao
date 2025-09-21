#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "vetor.h"

#define pai(x) x>>1
#define esquerda(x) x<<1
#define direita(x) x<<1+1

/* algoritmos quadraticos */
void insertion_sort (vetor *v);
void selection_sort (vetor *v);
void bubble_sort (vetor *v);

/* algoritmos logaritmicos */
void quick_sort (vetor *v, int ini, int fim);
void merge_sort (vetor *v, int ini, int fim);
/*
void quick_sort_aleatorizado (vetor *v, int ini, int fim);
void quick_sort_paralelo (vetor *v, int ini, int fim);
void merge_sort_paralelo (vetor *v, int ini, int fim);
void shell_sort (vetor *v, int ini, int fim);
void shell_sort_paralelo (vetor *v, int ini, int fim);
*/

/* algoritmos lineares */
/*
void bucket_sort (vetor *v);
buscar outros
*/

#endif
