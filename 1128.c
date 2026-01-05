#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOS 2001 

typedef struct No {
    int dest;
    struct No *prox;
} No;

int N; // Número de intersecções
int M; // Número de ruas
No *adj_original[MAX_NOS]; 
No *adj_reverso[MAX_NOS];

void InsereAresta (No *adj_lista[], int u, int v) {
    No *novoNo = malloc (sizeof (No));
    novoNo->dest = v;
    novoNo->prox = adj_lista[u];
    adj_lista[u] = novoNo;
}

void LimparLista (No *adj_lista[]) {
    for (int i = 1; i <= N; i++) {
        No *atual = adj_lista[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free (temp);
        }
        adj_lista[i] = NULL;
    }
}

void BuscaDFS (No *adj_lista[], int u, int visitado[]) {
    visitado[u] = 1;

    No *atual = adj_lista[u];
    while (atual != NULL) {
        int v = atual->dest;
        if (!visitado[v]) {
            BuscaDFS (adj_lista, v, visitado);
        }
        atual = atual->prox;
    }
}

int main() {
    
    int atual_N, atual_M;

    while (scanf("%d %d", &atual_N, &atual_M) == 2 && (atual_N != 0 || atual_M != 0)) {
        
        N = atual_N; 
        M = atual_M; 

        for (int i = 1; i <= N; i++) {
            adj_original[i] = NULL;
            adj_reverso[i] = NULL;
        }

        //ler e construir grafo original e reverso
        for (int i = 0; i < M; i++) {
            int V, W, P;
            if (scanf ("%d %d %d", &V, &W, &P) != 3) break;

            InsereAresta (adj_original, V, W);
            InsereAresta (adj_reverso, W, V); 

            // P=2 mão dupla V <-> W
            if (P == 2) {
                InsereAresta (adj_original, W, V);
                InsereAresta (adj_reverso, V, W); 
            }
        }
        
        int conexaoForte = 1;
        int noInicial = 1;

        int saida_visitado[MAX_NOS] = {0};
        BuscaDFS (adj_original, noInicial, saida_visitado);
        
        for (int i = 1; i <= N; i++) {
            if (!saida_visitado[i]) {
                conexaoForte = 0;
                break;
            }
        }
        
        if (conexaoForte) {

            int entrada_visitado[MAX_NOS] = {0};
            BuscaDFS (adj_reverso, noInicial, entrada_visitado);
            
            for (int i = 1; i <= N; i++) {
                if (!entrada_visitado[i]) {
                    conexaoForte = 0;
                    break;
                }
            }
        }
        
        printf ("%d\n", conexaoForte ? 1 : 0);

        LimparLista (adj_original);
        LimparLista (adj_reverso);
    }
    
    return 0;
}