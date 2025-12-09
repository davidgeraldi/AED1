#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 2001 // N <= 2000

// Estrutura para o nó da Lista de Adjacência
typedef struct AdjNode {
    int dest;
    struct AdjNode *next;
} AdjNode;

// --- Variáveis Globais ---
int N; // Número de intersecções
int M; // Número de ruas
AdjNode *adj_original[MAX_NODES];
AdjNode *adj_reverse[MAX_NODES];


// --- Funções Auxiliares de Grafo ---

// Adiciona uma aresta U -> V na lista de adjacência especificada
void add_edge(AdjNode *adj_list[], int u, int v) {
    AdjNode *new_node = (AdjNode *)malloc(sizeof(AdjNode));
    new_node->dest = v;
    new_node->next = adj_list[u];
    adj_list[u] = new_node;
}

// Limpa a memória da lista de adjacência (Evita Memory Leak entre casos de teste)
void free_adj_list(AdjNode *adj_list[]) {
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

// --- Algoritmo de Busca em Profundidade (DFS) ---

/**
 * @brief Executa DFS para verificar quais nós são alcançáveis a partir do nó 'u'.
 */
void dfs(AdjNode *adj_list[], int u, bool visited[]) {
    visited[u] = true;

    AdjNode *curr = adj_list[u];
    while (curr != NULL) {
        int v = curr->dest;
        if (!visited[v]) {
            dfs(adj_list, v, visited);
        }
        curr = curr->next;
    }
}

// --- Função Main (Loop de Casos de Teste) ---

int main() {
    
    int current_N, current_M;

    // Loop principal: Lê N e M, e continua enquanto não for 0 0
    while(scanf("%d %d", &current_N, &current_M) == 2 && (current_N != 0 || current_M != 0)) {
        
        // 1. Atribuição e Inicialização
        N = current_N; // Variável global N
        M = current_M; // Variável global M

        for (int i = 1; i <= N; i++) {
            adj_original[i] = NULL;
            adj_reverse[i] = NULL;
        }

        // 2. Leitura e Construção do Grafo (Original e Reverso)
        for (int i = 0; i < M; i++) {
            int V, W, P;
            if (scanf("%d %d %d", &V, &W, &P) != 3) break;

            // P=1: Mão única V -> W
            add_edge(adj_original, V, W);
            add_edge(adj_reverse, W, V); // Reverso: W -> V

            // P=2: Mão dupla V <-> W
            if (P == 2) {
                add_edge(adj_original, W, V);
                add_edge(adj_reverse, V, W); // Reverso: V -> W
            }
        }

        // 3. Verificação de Conexão Forte (Duas DFSs)
        
        bool is_strongly_connected = true;
        int pivot = 1; // Nó de partida arbitrário
        
        // --- A. Primeira DFS: Conexão de Saída (1 -> Todos) ---
        // Checa se o Pivô alcança TODOS os nós no grafo original.
        bool visited_out[MAX_NODES] = {false};
        dfs(adj_original, pivot, visited_out);
        
        for (int i = 1; i <= N; i++) {
            if (!visited_out[i]) {
                is_strongly_connected = false;
                break;
            }
        }
        
        if (is_strongly_connected) {
            // --- B. Segunda DFS: Conexão de Entrada (Todos -> 1) ---
            // Checa se o Pivô é alcançado por TODOS (rodando a DFS no Grafo Reverso).
            
            // Reinicializa o array visited
            bool visited_in[MAX_NODES] = {false};
            dfs(adj_reverse, pivot, visited_in);
            
            for (int i = 1; i <= N; i++) {
                if (!visited_in[i]) {
                    is_strongly_connected = false;
                    break;
                }
            }
        }
        
        // 4. Saída
        printf("%d\n", is_strongly_connected ? 1 : 0);

        // 5. Limpeza de Memória (essencial para evitar TLE/MLE em múltiplos casos)
        free_adj_list(adj_original);
        free_adj_list(adj_reverse);
    }
    
    return 0;
}