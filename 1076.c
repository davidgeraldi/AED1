#include <stdio.h>
#include <stdlib.h>

#define MAX_NOS 50

int movimentos;

typedef struct No {
    int vizinho;
    struct No *proximo;
} No;

No *adj [MAX_NOS]; 
int visitado [MAX_NOS];

void addAresta (int u, int v) {
    No *novoNo_uv = malloc (sizeof (No));
    if (novoNo_uv == NULL) return;
    novoNo_uv->vizinho = v;
    novoNo_uv->proximo = adj[u];
    adj[u] = novoNo_uv;

    No *novoNo_vu = malloc (sizeof (No));
    if (novoNo_vu == NULL) return;
    novoNo_vu->vizinho = u;
    novoNo_vu->proximo = adj[v];
    adj[v] = novoNo_vu;
}

void DFS (int u) {
    visitado[u] = 1;
    
    No *atual = adj[u];
    while (atual != NULL) {
        int v = atual->vizinho;
        
        if (!visitado[v]) {
            movimentos++; 
            DFS (v);       
            movimentos++; 
        }
        
        atual = atual->proximo;
    }
}

void resolverLabirinto () {
    int N, M, S; 
    int u, v; 
    
    if (scanf("%d", &S) != 1) return;
    
    if (scanf("%d %d", &N, &M) != 2) return;
    
    movimentos = 0;
    for (int i = 0; i < MAX_NOS; i++) {
        adj[i] = NULL;    
        visitado[i] = 0; 
    }

    for (int i = 0; i < M; i++) {
        if (scanf("%d %d", &u, &v) != 2) return;
        if (u >= MAX_NOS || v >= MAX_NOS) {
            continue; 
        }
        addAresta (u, v);
    }

    DFS (S); 

    printf ("%d\n", movimentos);
    
    for (int i = 0; i < MAX_NOS; i++) {
        No *atual = adj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free (temp);
        }
    }
}

int main () {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    
    while (T--) {
        resolverLabirinto ();
    }
    return 0;
}