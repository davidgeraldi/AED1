#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
	int valor;
	int contagem;
	struct No *esquerda;
	struct No *direita;
};

struct No *NovoNo (int v) {
	struct No *novo = (struct No *) malloc (sizeof (struct No));
	novo->valor = v;
	novo->contagem = 1;
	novo->esquerda = NULL;
	novo->direita = NULL;
	return novo;
}

struct No *Inserir (struct No *raiz, int v) {
	if (raiz == NULL) {
		return NovoNo (v);
	}

	if (v < raiz->valor) {
		raiz->esquerda = Inserir (raiz->esquerda, v);
	} 
    else if (v > raiz->valor) {
		raiz->direita = Inserir (raiz->direita, v);
	} 
    else if (v == raiz->valor) {
		raiz->contagem++;
	}

	return raiz;
}

void Leitura (struct No*raiz, int *primeiro) {
	if (raiz != NULL) {
		Leitura (raiz->esquerda, primeiro);
		for (int j = 0; j < raiz->contagem; j++) {
			if (! (*primeiro)) printf (" ");
			printf ("%d", raiz->valor);
			*primeiro = 0;
		}
		Leitura (raiz->direita, primeiro);
	}
}

int main () {
	int NC, N;
	scanf("%d", &NC);
	int *v = malloc (3000000 * sizeof (int));

	while (NC > 0) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &v[i]);
		}

		struct No *raiz = Inserir (NULL, v[0]);

		for (int i = 1; i < N; i++) {
			Inserir (raiz, v[i]);
		}

		int primeiro = 1;
		Leitura (raiz, &primeiro);
		printf ("\n");

		NC--;
	}

	return 0;
}