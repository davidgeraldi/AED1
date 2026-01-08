#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define MAX_NOS 1000

struct cel {
    int valor;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel no;
typedef no *arvore;

int resultado_travessia[MAX_NOS];

int indice_atual;

no *Criarno (int num) {
    no *novo = malloc (sizeof (no));
    if (novo == NULL) return;
    novo->valor = num;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

arvore Inserir (arvore r, no *novo) {
    no *f, *p;
    if (r == NULL) return novo;
    f = r;
    while (f != NULL) {
        p = f;
        if (f->valor > novo->valor) f = f->esq;
        else f = f->dir;
    }
    if (p->valor > novo->valor) p->esq = novo;
    else p->dir = novo;
    return r;
}

// Infixo ERD - Esquerda Raiz Direita
void BuscaERD (arvore r) {
    if (r != NULL) {
        BuscaERD (r->esq);
        resultado_travessia[indice_atual++] = r->valor;
        BuscaERD (r->dir);
    }
}

// Prefixo RED - Raiz Esquerda Direita
void BuscaRED (arvore r) {
    if (r != NULL) {
        resultado_travessia[indice_atual++] = r->valor;
        BuscaRED (r->esq);
        BuscaRED (r->dir);
    }
}

// Pósfixo EDR - Esquerda Direita Raiz
void BuscaEDR (arvore r) {
    if (r != NULL) {
        BuscaEDR (r->esq);
        BuscaEDR (r->dir);
        resultado_travessia[indice_atual++] = r->valor;
    }
}

void LimparArvore (arvore r) {
    if (r != NULL) {
        LimparArvore (r->esq);
        LimparArvore (r->dir);
        free (r);
    }
}

void ImprimeResultado (const char *palavra) {
    printf ("%s:", palavra);
    for (int k = 0; k < indice_atual; k++) {
        printf (" %d", resultado_travessia[k]);
    }
    printf ("\n");
}

int main () {
    int C, N, i = 1, num;
    if (scanf("%d", &C) != 1) return 0;
    
    do {
        arvore r = NULL;
        if (scanf("%d", &N) != 1) return 0;
        
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &num) != 1) return 0;
            r = Inserir (r, Criarno (num));
        } 
        
        printf ("Case %d:\n", i);
        
        indice_atual = 0;
        BuscaRED (r);
        ImprimeResultado ("Pre.");
        
        indice_atual = 0;
        BuscaERD (r); 
        ImprimeResultado ("In..");

        indice_atual = 0;
        BuscaEDR (r); 
        ImprimeResultado ("Post"); 
        
        LimparArvore (r);
        printf ("\n");
        i++;
        
    } while (i <= C);

    return 0;
}