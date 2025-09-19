#include "vetor.h"

vetor *cria_vetor (int tamanho) {
	vetor *v;

	if (tamanho <= 0)
		return NULL;

	v = (vetor*) malloc (sizeof(vetor));

	if (!v)
		return NULL;

	v->tamanho = tamanho;
	v->vetor = (int*) malloc (tamanho * sizeof(int));

	if (!v->vetor)
		return NULL;
	return v;
}

vetor *destroi_vetor (vetor *vetor) {
	if (vetor) {
		free(vetor->vetor);
		vetor->vetor = NULL;
		free(vetor);
	}	
	
	return NULL;
}

vetor *cria_vetor_arquivo (const char* pathname) {
	vetor *v;
	FILE *f;
	char buffer[50];
	int tamanho, i, c, iterador;

	f = fopen (pathname, "r");

	if (!f)
		return NULL;

	i = 0;
	while ( (c = fgetc (f)) != '\n') {
		if (i < 49)
			buffer[i++] = (char) c;
	}
	buffer[i] = '\0';

	if (!(tamanho = atoi(buffer))) {
		fclose (f);
		return NULL;
	}
	
	v = cria_vetor (tamanho);

	if (!v) {
		fclose (f);
		return NULL;
	}
	
	i = 0;
	iterador = 0;
	while ((c = fgetc(f)) != EOF) {
		if (c == '\n') {
			buffer[i] = '\0';
			i = 0;
			if (iterador < tamanho)
				v->vetor[iterador++] = atoi (buffer);
		}
		else {
			if (i < 49)
				buffer[i++] = (char) c;
		}
	}

	buffer[i] = '\0';
	if (iterador < tamanho)
		v->vetor[iterador++] = atoi (buffer);

	fclose (f);
	return v;
}

void imprime_vetor (vetor *v) {
	if (!v)
		return;

	printf("%d\n", tamanho_vetor(v));
	
	for (int i = 0; i < tamanho_vetor(v); i++) {
		if (i < tamanho_vetor(v) - 1) 
			printf("%d\n", elemento_vetor(v,i));
	}
}

int ordenacao (vetor *vetor) {
	if (!vetor) 
		return NAO_ORDENADO;


	for (int i = 0; i < tamanho_vetor(vetor) - 1; i++) {
		if (elemento_vetor (vetor, i) > elemento_vetor (vetor, i + 1))
			return NAO_ORDENADO;
	}

	return ORDENADO;
}
