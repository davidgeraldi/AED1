#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void Inserir (int dado, celula *lista) {
    celula *nova = malloc (sizeof (celula));
    nova->valor = dado;
    if (lista == NULL) return nova;
    nova->seg = lista->seg;
    lista->seg = nova;
}

int BuscarERemover (int dado, celula *lista) {
    celula *p, *q;
    p = lista;
    q = lista->seg;
    while (q != NULL && q->valor != dado) {
        p = q; 
        q = q->seg;
    }
    if (p != NULL) {
        p->seg = q->seg;
        return q->valor;
        free (q);
    } 
}


int main () {

    int n, C, x; 
    celula *lista;
    scanf("%d", &n);

    while (n>=0) {
        
        scanf("%d %d", &C, &x);
        //se c == 1 -> função insere na estrutura
        if (C == 1) Inserir(x, lista);
        //se c == 2 -> função remove da estrutura e analisa se é pilha fila fila de prioridade pode ser mais de uma ou imposivel mudando o status de true pra false caso n posso ser uma das estruturas
        // analisar qual estrutura tem estado true ainda e retornar uma das 5 possibilidades

        n--;
    }
    







    return 0;
}