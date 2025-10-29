#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int valor;
    int posicao;
} celulaMenor;

typedef struct {
    int elemento;
    struct celula *seg;
} celula;

celula *CriarCelula(int valor) {
    celula *celulaNova = (celula *)malloc(sizeof(celula));
    celulaNova->elemento = valor;
    celulaNova->seg = NULL;
    return celulaNova;
}

void InserirCelula(celula **cabeca, int valor) {
    celula *celulaNova = CriarCelula(valor);
    if (*cabeca == NULL) {
        *cabeca = celulaNova;
    }
    else {
        celula *atual = *cabeca;
        while (atual->seg != NULL) {
            atual = atual->seg;
        }
        atual->seg = celulaNova;
    }
}

int main() {         
    char buffer[20000];
    int N, contador = 0;
    celula *Xcabeca = NULL;
    celulaMenor menorValor;
    scanf("%d", &N); 
    getchar();       

    fgets(buffer, sizeof(buffer),stdin); 

    char *texto = strtok(buffer, " "); 
    while (texto != NULL) {
        InserirCelula (&Xcabeca, atoi(texto)); 
        texto = strtok(NULL, " ");
    }

    menorValor.valor = Xcabeca->elemento; 
    menorValor.posicao = 0;
    celula *X = Xcabeca;

    while (X != NULL) {
        if (X->elemento < menorValor.valor) { 
            menorValor.valor = X->elemento;
            menorValor.posicao = contador;
        }
        X = X->seg;
        contador++;
    }

    printf("celulaMenor valor: %d\nPosicao: %d", menorValor.valor, menorValor.posicao);
    printf("\n");

    X = Xcabeca;
    while (X !=NULL) {
        celula *proxCelula = X->seg;
        free(X);
        X = proxCelula;
    }

    return 0;
}