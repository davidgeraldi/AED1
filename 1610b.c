#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Definindo o limite máximo de N para a Lista de Adjacência (casos grandes)
#define MAX_NODES 10001 

// Estrutura para a Lista de Adjacência
typedef struct AdjNode {
    int dest;
    struct AdjNode *next;
} AdjNode;

AdjNode *adj_list[MAX_NODES];
int N; // Número de documentos (nodes)

// Array de estados: 0=Branco, 1=Cinza, 2=Preto
int state[MAX_NODES];
bool has_cycle;

// Adiciona uma aresta (dependência) U -> V
void add_edge(int u, int v) {
    AdjNode *new_node = (AdjNode *)malloc(sizeof(AdjNode));
    new_node->dest = v;
    new_node->next = adj_list[u];
    adj_list[u] = new_node;
}

// Limpa a memória da lista de adjacência
void free_adj_list() {
    for (int i = 1; i <= N; i++) {
        AdjNode *curr = adj_list[i];
        while (curr != NULL) {
            AdjNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
        adj_list[i] = NULL;
    }
}

// Algoritmo DFS para Detecção de Ciclos
void dfs(int u) {
    state[u] = 1; // Cinza: Em processamento

    AdjNode *curr = adj_list[u];
    while (curr != NULL) {
        int v = curr->dest;

        if (state[v] == 1) {
            // Ciclo encontrado!
            has_cycle = true;
            return;
        }
        
        if (state[v] == 0) {
            // Não visitado (Branco)
            dfs(v);
        }
        
        if (has_cycle) return;
        
        curr = curr->next;
    }

    state[u] = 2; // Preto: Processamento concluído
}

int main() {
    int T; // Número de casos de teste
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int M; // Número de dependências (arestas)
        if (scanf("%d %d", &N, &M) != 2) break;

        // Inicializa a lista de adjacência e o array de estados
        for (int i = 1; i <= N; i++) {
            adj_list[i] = NULL;
            state[i] = 0;
        }
        has_cycle = false;

        // Leitura das M dependências e construção do grafo
        for (int i = 0; i < M; i++) {
            int A, B; // A depende de B (A -> B)
            if (scanf("%d %d", &A, &B) != 2) break;
            add_edge(A, B);
        }

        // Executa a DFS em todos os nós (para grafos desconectados)
        for (int i = 1; i <= N; i++) {
            if (state[i] == 0 && !has_cycle) {
                dfs(i);
            }
        }

        if (has_cycle) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        // Libera a memória alocada
        free_adj_list();
    }

    return 0;
}