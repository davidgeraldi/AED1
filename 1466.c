#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq, *dir;
} no;

no* Inserir (no *novo, int removido) {
    if (!novo) {
        novo = malloc (sizeof (no));
        novo->valor = removido;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (removido < novo->valor) novo->esq = Inserir (novo->esq, removido);
    else novo->dir = Inserir (novo->dir, removido);
    return novo;
}

typedef struct {
    no *d[2000];
    int inicio, fim;
} fila;

void BuscaEImprime (no *novo, int c) {
    fila fl;
    fl.inicio = fl.fim = 0;

    fl.d[fl.fim++] = novo;

    printf ("Case %d:\n", c);

    int espaco = 1;
    while (fl.inicio < fl.fim) {
        no *removido = fl.d[fl.inicio++];

        if (espaco) {
            printf ("%d", removido->valor);
            espaco = 0;
        } 
        else {
            printf (" %d", removido->valor);
        }

        if (removido->esq) fl.d[fl.fim++] = removido->esq;
        if (removido->dir) fl.d[fl.fim++] = removido->dir;
    }
    printf ("\n\n");
}

int main() {
    int c, n, x, i;
    scanf("%d", &c);

    for (int k = 1; k <= c; k++) {
        scanf("%d", &n);

        no *novo = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            novo = Inserir (novo, x);
        }

        BuscaEImprime (novo, k);
    }

    return 0;
}