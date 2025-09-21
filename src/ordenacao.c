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

/* Quick Sort */

int particiona (vetor *v, int ini, int fim) {
	int pivo = elemento_vetor (v, fim);
	int i = ini - 1;

	for (int j = ini; j < fim; j++) {
		if (elemento_vetor(v,j) <= pivo) {
			i++;
			troca (v, i, j);
		}
	}
	
	troca (v, i + 1, fim);
	
	return i + 1;
}

void quick_sort (vetor *v, int ini, int fim) {
	int p;

	if (ini < fim) {
		p = particiona (v, ini, fim);
		quick_sort (v, ini, p - 1);
		quick_sort (v, p + 1, fim);
	}
}

/* Merge Sort */
void merge (vetor *v, int ini, int meio, int fim) {
	int n1 = meio - ini + 1;
	int n2 = fim - meio;
	int i = 0, j = 0, k = 0;
	int tamanho = fim - ini + 1;
	vetor* aux = cria_vetor (tamanho);

	if (!aux || !v)
		return;

	/* Copiando os valores de v em aux */
	while (k < tamanho) { 
		elemento_vetor(aux, k) = elemento_vetor (v, ini + k);
		k++;
	}

	k = ini;
	while (i < n1 && j < n2) {
		if (elemento_vetor (aux, i) < elemento_vetor (aux, j)) {
			elemento_vetor (v, k) = elemento_vetor (aux, i);
			i++;
		} else {
			elemento_vetor (v, k) = elemento_vetor (aux, j);
			j++;
		}
		k++;
	}

	while (i < n1) 
		elemento_vetor (v, k++) = elemento_vetor (aux, i++);

	while (j < n2) 
		elemento_vetor (v, k++) = elemento_vetor (aux, j++);
	
}

void merge_sort (vetor *v, int ini, int fim) {
	int meio;

	if (ini < fim) {
		meio = ini + (fim - ini)/2;
		merge_sort (v, ini, meio);
		merge_sort (v, meio + 1, fim);
		merge(v, ini, meio, fim);
	}
}
