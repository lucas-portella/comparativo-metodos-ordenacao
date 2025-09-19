#include "ordenacao.h"

void troca (vetor *v, int p1, int p2) {
	int aux;

	if (p1 > tamanho_vetor (v) - 1 || p2 > tamanho_vetor (v) - 1)
		return;
	
	aux = elemento_vetor (v, p1);
	elemento_vetor (v, p1) = elemento_vetor (v, p2);
	elemento_vetor (v, p2) = aux;
}

void insertion_sort (vetor *v) {
	if (!v)
		return;

	for (int i = 0; i < tamanho_vetor (v) - 1; i++) {
		int p_menor = i;
		for (int j = i + 1; j < tamanho_vetor (v); j++) {
			if (elemento_vetor(v, j) < elemento_vetor (v, p_menor))
				p_menor = j;
		}
		troca (v, p_menor, i);
	}
}

void selection_sort (vetor *v) {
	if (!v)
		return;

	for (int i = 1; i < tamanho_vetor (v); i++) {
		for (int j = i; j > 0; j --) {
			if (elemento_vetor (v, j) < elemento_vetor (v, j -1))
				troca (v, j, j - 1);
		}
	}
}

void bubble_sort (vetor *v) {
	if (!v) 
		return;

	for (int i = 0; i < tamanho_vetor (v) - 1; i++) {
		for (int j = 0; j < tamanho_vetor (v) - i - 1; j++) {
			if (elemento_vetor (v, j) > elemento_vetor (v, j + 1))
				troca (v, j, j + 1);
		}
	}

}
