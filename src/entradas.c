#include "entradas.h"

int cria_entrada_aleatoria (const char* pathname, int tamanho) {
	FILE *f;

	if (tamanho <= 0)
		return ERRO;

	f = fopen (pathname, "w");

	if (!f)
		return ERRO;

	fprintf(f, "%d\n", tamanho);

	for (int i = 0; i < tamanho; i++) {
		int n = rand ();
		if (i < tamanho - 1)
			fprintf (f, "%d\n", n);
		else
			fprintf (f, "%d", n);
	}

	fclose(f);

	return SUCESSO;
}

int cria_entrada_crescente (const char* pathname, int tamanho) {
	FILE *f;

	if (tamanho <= 0)
		return ERRO;

	f = fopen (pathname, "w");

	if (!f)
		return ERRO;

	fprintf(f, "%d\n", tamanho);

	for (int i = 0; i < tamanho; i++) {
		if (i < tamanho - 1)
			fprintf (f, "%d\n", i);
		else
			fprintf (f, "%d", i);
	}

	fclose (f);

	return SUCESSO;

}

int cria_entrada_decrescente (const char* pathname, int tamanho) {
	FILE *f;

	if (tamanho <= 0)
		return ERRO;

	f = fopen (pathname, "w");

	if (!f)
		return ERRO;

	fprintf(f, "%d\n", tamanho);

	for (int i = 0; i < tamanho; i++) {
		if (i < tamanho - 1)
			fprintf (f, "%d\n", tamanho - i);
		else
			fprintf (f, "%d", tamanho - i);
	}

	fclose (f);

	return SUCESSO;
}
