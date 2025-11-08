#include <stdio.h>
#include <stdlib.h>

struct cel {
    int altura;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel nó;

typedef nó *árvore;

árvore Insere (árvore r, nó *novo) {
    nó *f, *p;
    if (r == NULL) return novo;
    f = r;
    while (f != NULL) {
        p = f;
        if (f->altura > novo->altura) f = f->esq;
        else f = f->dir;
    }
    if (p->altura > novo->altura) p->esq = novo;
    else p->dir = novo;
    return r;
}

void ImprimeErd (árvore r) {
    if (r != NULL) {
        ImprimeErd (r->esq);
        printf ("%d ", r->altura);
        ImprimeErd (r->dir);
    }
}

void ImprimeRED (árvore r) {
    if (r != NULL) {
        printf("%d ", r->altura);
        ImprimeRED(r->esq);
        ImprimeRED(r->dir);
    }
}

void LiberaArvore(árvore r) {
    if (r != NULL) {
        LiberaArvore(r->esq);
        LiberaArvore(r->dir);
        free(r);
    }
}

void ImprimeEDR (árvore r) {
    if (r != NULL) {
        ImprimeEDR(r->esq);
        ImprimeEDR (r->dir);
        printf("%d ", r->altura);
    }
}

int main() {

    int NC, N;
    
    printf("Qntd de cidades:");
    scanf("%d", &NC);

    for(int i=0; i<NC; i++) {
        árvore r = NULL;
        printf("\nQntd de habitantes cidade %d: ", i+1);
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            nó *novo = malloc(sizeof(nó)); 
            novo->esq = NULL;
            novo->dir = NULL;
            printf("Altura do habitante %d: ", j+1);
            scanf("%d", &novo->altura);
            r = Insere (r, novo);
        }
        ImprimeErd (r);
        printf ("\n");
        ImprimeRED (r);
        printf ("\n");
        ImprimeEDR (r);
        LiberaArvore (r);
    }

    return 0;
}