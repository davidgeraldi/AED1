#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// Define o limite máximo de nós que o array de resultado pode ter
#define MAX_NODES 1000

struct cel {
    int valor;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel no;
typedef no *arvore;

// Array global para armazenar os resultados da travessia
int resultado_travessia[MAX_NODES];
// Variável global para rastrear o índice atual no array de resultado
int indice_resultado;

no *Criarno (int num) {
    no *novo = (no *)malloc (sizeof (no));
    if (novo == NULL) exit(1);
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

// Funções de Percurso para Armazenamento

// Percurso Em Ordem (ERD) - Esquerda Raiz Direita
void TraveERD (arvore r) {
    if (r != NULL) {
        TraveERD (r->esq);
        resultado_travessia[indice_resultado++] = r->valor;
        TraveERD (r->dir);
    }
}

// Percurso Pré-ordem (RED) - Raiz Esquerda Direita
void TraveRED (arvore r) {
    if (r != NULL) {
        resultado_travessia[indice_resultado++] = r->valor;
        TraveRED(r->esq);
        TraveRED(r->dir);
    }
}

// Percurso Pós-ordem (EDR) - Esquerda Direita Raiz
void TraveEDR (arvore r) {
    if (r != NULL) {
        TraveEDR(r->esq);
        TraveEDR (r->dir);
        resultado_travessia[indice_resultado++] = r->valor;
    }
}

// Função de Liberação de Memória

void LimparArvore (arvore r) {
    if (r != NULL){
        LimparArvore (r->esq);
        LimparArvore (r->dir);
        free (r);
    }
}

// Função Auxiliar de Impressão

void ImprimeResultado(const char *label) {
    printf("%s:", label);
    for (int k = 0; k < indice_resultado; k++) {
        printf(" %d", resultado_travessia[k]);
    }
    printf("\n");
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
        
        printf("Case %d:\n", i);
        
        // Percurso Pré-ordem (RED)
        indice_resultado = 0;
        TraveRED(r);
        ImprimeResultado("Pre.");
        
        // Percurso Em Ordem (ERD)
        indice_resultado = 0;
        TraveERD (r); 
        ImprimeResultado("In..");

        // Percurso Pós-ordem (EDR)
        indice_resultado = 0;
        TraveEDR (r); 
        ImprimeResultado("Post"); // Nota: O problema 1195 pede "Post."
        
        // Liberação de memória
        LimparArvore (r);
        printf("\n");
        i++;
        
    } while (i <= C);

    return 0;
}