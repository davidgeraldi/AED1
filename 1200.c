#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq; 
    struct No *dir; 
} No;

int first_print;

No* criar_no(char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    
    return raiz;
}

int buscar(No* raiz, char valor) {
    if (raiz == NULL) return 0;
    if (valor == raiz->valor) return 1;
    
    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    } else {
        return buscar(raiz->dir, valor);
    }
}

void in_order(No* no) {
    if (no == NULL) return;
    
    in_order(no->esq);
    
    if (first_print) {
        printf("%c", no->valor);
        first_print = 0;
    } else {
        printf(" %c", no->valor);
    }
    
    in_order(no->dir);
}

void pre_order(No* no) {
    if (no == NULL) return;
    
    if (first_print) {
        printf("%c", no->valor);
        first_print = 0;
    } else {
        printf(" %c", no->valor);
    }
    
    pre_order(no->esq);
    pre_order(no->dir);
}

void post_order(No* no) {
    if (no == NULL) return;
    
    post_order(no->esq);
    post_order(no->dir);
    
    if (first_print) {
        printf("%c", no->valor);
        first_print = 0;
    } else {
        printf(" %c", no->valor);
    }
}

int main() {
    No* raiz = NULL;
    char linha[20]; // Buffer de leitura
    char comando[10];
    char valor;
    int count;

    // Leitura robusta: linha por linha (fgets) e analise (sscanf)
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        
        count = sscanf(linha, "%s %c", comando, &valor);

        if (count == 2) { 
            // Comando 'I X' ou 'P X' (lido comando e valor)
            if (strcmp(comando, "I") == 0) {
                raiz = inserir(raiz, valor);
            } 
            else if (strcmp(comando, "P") == 0) {
                if (buscar(raiz, valor)) {
                    printf("%c existe\n", valor);
                } else {
                    printf("%c nao existe\n", valor);
                }
            }
        } 
        else if (count == 1) { 
            // Comando de Travessia (lido apenas o comando)
            if (strcmp(comando, "INFIXA") == 0) {
                first_print = 1;
                in_order(raiz);
                printf("\n");
            } 
            else if (strcmp(comando, "PREFIXA") == 0) {
                first_print = 1;
                pre_order(raiz);
                printf("\n");
            } 
            else if (strcmp(comando, "POSFIXA") == 0) {
                first_print = 1;
                post_order(raiz);
                printf("\n");
            }
        }
    }

    return 0;
}