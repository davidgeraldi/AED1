#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOS 10001 

typedef struct No {
    int dest;
    struct No *prox;
} No;

No *lista_adj[MAX_NOS];
int N; 

int estados[MAX_NOS];
int tem_ciclo;

void AddAresta (int u, int v) {
    No *NovoNo = malloc (sizeof (No));
    NovoNo->dest = v;
    NovoNo->prox = lista_adj[u];
    lista_adj[u] = NovoNo;
}

void LimparLista () {
    for (int i = 1; i <= N; i++) {
        No *atual = lista_adj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->prox;
            free (temp);
        }
        lista_adj[i] = NULL;
    }
}

void BuscaDFS (int u) {
    estados[u] = 1; 

    No *atual = lista_adj[u];
    while (atual != NULL) {
        int v = atual->dest;

        if (estados[v] == 1) {
            tem_ciclo = 1;
            return;
        }
        
        if (estados[v] == 0) {
            BuscaDFS (v);
        }
        
        if (tem_ciclo) return;
        
        atual = atual->prox;
    }

    estados[u] = 2; 
}

int main() {
    int T; 
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int M; 
        if (scanf("%d %d", &N, &M) != 2) break;

        for (int i = 1; i <= N; i++) {
            lista_adj[i] = NULL;
            estados[i] = 0;
        }
        tem_ciclo = 0;

        for (int i = 0; i < M; i++) {
            int A, B; 
            if (scanf("%d %d", &A, &B) != 2) break;
            AddAresta (A, B);
        }

        for (int i = 1; i <= N; i++) {
            if (estados[i] == 0 && !tem_ciclo) {
                BuscaDFS (i);
            }
        }

        if (tem_ciclo) {
            printf ("SIM\n");
        } 
        else {
            printf ("NAO\n");
        }

        LimparLista ();
    }

    return 0;
}