#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

int movimentos;

typedef struct Node {
    int vizinho;
    struct Node *proximo;
} Node;

Node *adj[MAX_NODES]; 
int visitado[MAX_NODES];

void addEdge(int u, int v) {
    Node *newNode_uv = (Node *)malloc(sizeof(Node));
    if (newNode_uv == NULL) exit(1);
    newNode_uv->vizinho = v;
    newNode_uv->proximo = adj[u];
    adj[u] = newNode_uv;

    Node *newNode_vu = (Node *)malloc(sizeof(Node));
    if (newNode_vu == NULL) exit(1);
    newNode_vu->vizinho = u;
    newNode_vu->proximo = adj[v];
    adj[v] = newNode_vu;
}

void DFS(int u) {
    visitado[u] = 1;
    
    Node *atual = adj[u];
    while (atual != NULL) {
        int v = atual->vizinho;
        
        if (!visitado[v]) {
            movimentos++; 
            DFS(v);       
            movimentos++; 
        }
        
        atual = atual->proximo;
    }
}

void solve() {
    int N, M, S; 
    int u, v; 
    
    if (scanf("%d", &S) != 1) return;
    
    if (scanf("%d %d", &N, &M) != 2) return;
    
    movimentos = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        adj[i] = NULL;    
        visitado[i] = 0; 
    }

    for (int i = 0; i < M; i++) {
        if (scanf("%d %d", &u, &v) != 2) return;
        if (u >= MAX_NODES || v >= MAX_NODES) {
            continue; 
        }
        addEdge(u, v);
    }

    DFS(S); 

    printf("%d\n", movimentos);
    
    for (int i = 0; i < MAX_NODES; i++) {
        Node *atual = adj[i];
        while (atual != NULL) {
            Node *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    
    while (T--) {
        solve();
    }
    return 0;
}