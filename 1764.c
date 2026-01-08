#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Aresta;

Aresta arestas[50005];
int pai[40005];

void QuickSort (int inicio, int fim) {
    int i = inicio, j = fim;
    int pivo = arestas[(inicio + fim) / 2].w;
    Aresta aux;
    while (i <= j) {
        while (arestas[i].w < pivo) i++;
        while (arestas[j].w > pivo) j--;
        
        if (i <= j) {
            aux = arestas[i];
            arestas[i] = arestas[j];
            arestas[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j) QuickSort (inicio, j);
    if (i < fim) QuickSort (i, fim);
}

int Encontrar (int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = Encontrar (pai[i]);
}

int main () {
    int M, N;
    int dist_total;
    int i; 
    
    int raiz_u, raiz_v;

    while (scanf("%d %d", &M, &N) && (M != 0 || N != 0)) {
        
        for (i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
        }

        if (N > 0) {
            QuickSort (0, N - 1);
        }

        for (i = 0; i < M; i++) {
            pai[i] = i;
        }

        dist_total = 0;

        for (i = 0; i < N; i++) {
            raiz_u = Encontrar (arestas[i].u);
            raiz_v = Encontrar (arestas[i].v);

            if (raiz_u != raiz_v) {
                pai[raiz_u] = raiz_v;
                dist_total += arestas[i].w;
            }
        }

        printf ("%d\n", dist_total);
    }

    return 0;
}