#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Aresta;

Aresta arestas[50005];
int pai[40005];

int compare(const void *a, const void *b) {
    Aresta *A = (Aresta *)a;
    Aresta *B = (Aresta *)b;
    return A->w - B->w;
}

int find(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = find(pai[i]);
}

int main() {
    int M, N;
    int total_distancia;
    int i; 
    
    int raiz_u, raiz_v;

    while (scanf("%d %d", &M, &N) && (M != 0 || N != 0)) {
        
        for (i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
        }

        qsort(arestas, N, sizeof(Aresta), compare);

        for (i = 0; i < M; i++) {
            pai[i] = i;
        }

        total_distancia = 0;

        for (i = 0; i < N; i++) {
            raiz_u = find(arestas[i].u);
            raiz_v = find(arestas[i].v);

            if (raiz_u != raiz_v) {
                pai[raiz_u] = raiz_v;
                total_distancia += arestas[i].w;
            }
        }

        printf("%d\n", total_distancia);
    }

    return 0;
}