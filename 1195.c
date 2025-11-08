#include <stdio.h> 
#include <stdlib.h> 

struct cel {
    int valor;
    struct cel *esq;
    struct cel *dir;
};

typedef struct cel no;
typedef no *arvore;

arvore EhUltimono; // Ponteiro global para a último no

no *Criarno (int num) {
    no *novo = malloc (sizeof (no));
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

void ImprimeERD (arvore r) { //infixo esquerda raiz direita
    if (r != NULL) {
        ImprimeERD (r->esq);
        printf ("%d", r->valor);
        if(r != EhUltimono) printf(" ");
        ImprimeERD (r->dir);
    }
}

void ImprimeRED (arvore r) { //prefixo raiz esquerda direita
    if (r != NULL) {
        printf("%d", r->valor);
        if(r != EhUltimono) printf(" ");
        ImprimeRED(r->esq);
        ImprimeRED(r->dir);
    }
}

void ImprimeEDR (arvore r) { //posfixo esquerda direita raiz
    if (r != NULL) {
        ImprimeEDR(r->esq);
        ImprimeEDR (r->dir);
        printf("%d", r->valor);
        if(r != EhUltimono) printf(" ");
    }
}

//funções para encontrar o ultimo no em cada caso:

arvore UltimoNoERD (arvore r) {
    if (r == NULL) return NULL;
    while (r->dir != NULL){
        r = r->dir;
    }
    return r;
}

arvore UltimoNoRED(arvore r) {
    if (r == NULL) return NULL;
    if (r->dir != NULL) return UltimoNoRED(r->dir);
    else if (r->esq != NULL) return UltimoNoRED(r->esq);
    return r;
}

arvore UltimoNoEDR (arvore r) { 
    return r;
}

void LimparArvore (arvore r) {
    if (r != NULL){
        LimparArvore (r->esq);
        LimparArvore (r->dir);
        free (r);
    }
}

int main () {

    int C, N, i=1, num;
    printf("Numero de casos: ");
    scanf("%d", &C);
    do {
        arvore r = NULL;
        printf("\nQntd de numeros arvore %d: ", i);
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            printf ("Num %d: ", j+1);
            scanf("%d", &num);  
            r = Inserir (r, Criarno (num));
        } 
        printf("\nCase %d: \n", i);
        printf("Pre.: "); EhUltimono = UltimoNoRED (r); ImprimeRED (r); //prefixo
        printf("\nIn..: "); EhUltimono = UltimoNoERD (r); ImprimeERD (r); //infixo
        printf("\nPost: "); EhUltimono = UltimoNoEDR (r); ImprimeEDR (r); //posfixo

        printf("\n");
        LimparArvore (r);
        i++;
    } while (i <= C);

    return 0;
}