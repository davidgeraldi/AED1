#include <stdio.h>

void SubirHeap (int heap[], int i) {
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (heap[i] > heap[pai]) {
            int aux = heap[i];
            heap[i] = heap[pai];
            heap[pai] = aux;
            i = pai;
        } 
        else break;
    }
}

void DescerHeap (int heap[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && heap[esq] > heap[maior]) maior = esq;
    if (dir < n && heap[dir] > heap[maior]) maior = dir;

    if (maior != i) {
        int aux = heap[i];
        heap[i] = heap[maior];
        heap[maior] = aux;
        DescerHeap (heap, n, maior);
    }
}

int main () {
    int n;
    while (scanf("%d", &n) != EOF) {
        int pilha[1005], topo_pilha = 0;
        int fila[1005], inicio_fila = 0, fim_fila = 0;
        int heap[1005], cont_fp = 0;

        int ehPilha = 1, ehFila = 1, ehFilaPrior = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                if (ehPilha) pilha[topo_pilha++] = x;
                if (ehFila) fila[fim_fila++] = x;
                if (ehFilaPrior) {
                    heap[cont_fp] = x;
                    SubirHeap (heap, cont_fp++);
                }
            } 
            else {
                if (ehPilha && (topo_pilha == 0 || pilha[--topo_pilha] != x)) ehPilha = 0;
                
                if (ehFila && (inicio_fila == fim_fila || fila[inicio_fila++] != x)) ehFila = 0;

                if (ehFilaPrior) {
                    if (cont_fp == 0 || heap[0] != x) {
                        ehFilaPrior = 0;
                    } 
                    else {
                        heap[0] = heap[--cont_fp];
                        DescerHeap (heap, cont_fp, 0);
                    }
                }
            }
        }

        int total = ehPilha + ehFila + ehFilaPrior;
        if (total == 0) printf ("impossible\n");
        else if (total > 1) printf ("not sure\n");
        else if (ehPilha) printf ("stack\n");
        else if (ehFila) printf ("queue\n");
        else printf ("priority queue\n");
    }
    return 0;
}