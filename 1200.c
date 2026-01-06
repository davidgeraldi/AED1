#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq; 
    struct No *dir; 
} No;

int primeiro_elemento;

No* CriarNo (char valor) {
    No* novo = malloc (sizeof (No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* Inserir (No* raiz, char valor) {
    if (raiz == NULL) {
        return CriarNo (valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esq = Inserir (raiz->esq, valor);
    } 
    else if (valor > raiz->valor) {
        raiz->dir = Inserir (raiz->dir, valor);
    }
    
    return raiz;
}

int Buscar (No* raiz, char valor) {
    if (raiz == NULL) return 0;
    if (valor == raiz->valor) return 1;
    
    if (valor < raiz->valor) {
        return Buscar (raiz->esq, valor);
    } 
    else {
        return Buscar (raiz->dir, valor);
    }
}

void BuscaERD (No* no) {
    if (no == NULL) return;
    
    BuscaERD(no->esq);
    
    if (primeiro_elemento) {
        printf ("%c", no->valor);
        primeiro_elemento = 0;
    } 
    else {
        printf (" %c", no->valor);
    }
    
    BuscaERD (no->dir);
}

void BuscaRED (No* no) {
    if (no == NULL) return;
    
    if (primeiro_elemento) {
        printf ("%c", no->valor);
        primeiro_elemento = 0;
    } 
    else {
        printf (" %c", no->valor);
    }
    
    BuscaRED (no->esq);
    BuscaRED (no->dir);
}

void BuscaEDR (No* no) {
    if (no == NULL) return;
    
    BuscaEDR (no->esq);
    BuscaEDR (no->dir);
    
    if (primeiro_elemento) {
        printf ("%c", no->valor);
        primeiro_elemento = 0;
    } 
    else {
        printf (" %c", no->valor);
    }
}

int main() {
    No* raiz = NULL;
    char linha[20]; 
    char comando[10];
    char valor;
    int cont;

    while (fgets (linha, sizeof(linha), stdin) != NULL) {
        
        cont = sscanf(linha, "%s %c", comando, &valor); //sscanf separa os elementos de uma string completa

        if (cont == 2) { 
            if (strcmp (comando, "I") == 0) {
                raiz = Inserir (raiz, valor);
            } 
            else if (strcmp (comando, "P") == 0) {
                if (Buscar (raiz, valor)) {
                    printf ("%c existe\n", valor);
                } 
                else {
                    printf ("%c nao existe\n", valor);
                }
            }
        } 

        else if (cont == 1) { 
            if (strcmp (comando, "INFIXA") == 0) {
                primeiro_elemento = 1;
                BuscaERD (raiz);
                printf ("\n");
            } 
            else if (strcmp (comando, "PREFIXA") == 0) {
                primeiro_elemento = 1;
                BuscaRED (raiz);
                printf ("\n");
            } 
            else if (strcmp (comando, "POSFIXA") == 0) {
                primeiro_elemento = 1;
                BuscaEDR (raiz);
                printf ("\n");
            }
        }
    }

    return 0;
}