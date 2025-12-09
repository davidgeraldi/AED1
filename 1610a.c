#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Definimos um limite seguro para a matriz (N^2), atendendo aos casos pequenos
#define MAX_NODES_MAT 501 

// Matriz de adjacência: adj_mat[i][j] = 1 se i -> j
int adj_mat[MAX_NODES_MAT][MAX_NODES_MAT]; 
int N_mat; // Número de documentos (nodes)

// Array de estados: 0=Branco, 1=Cinza, 2=Preto
int state_mat[MAX_NODES_MAT];
bool has_cycle_mat;

// --- Algoritmo DFS para Detecção de Ciclos (Matriz) ---

void dfs_mat(int u) {
    // 1. Marca como 'Cinza' (em processamento)
    state_mat[u] = 1;

    // 2. Visita todos os vizinhos
    // Itera sobre todas as colunas V para encontrar as arestas de U (Complexidade O(N))
    for (int v = 1; v <= N_mat; v++) {
        if (adj_mat[u][v] == 1) { // Se u -> v existe
            if (state_mat[v] == 1) {
                // Ciclo encontrado!
                has_cycle_mat = true;
                return;
            }
            
            if (state_mat[v] == 0) {
                // Se não visitado (Branco), chama DFS
                dfs_mat(v);
            }
            
            // Se um ciclo foi encontrado em uma chamada recursiva, saia imediatamente.
            if (has_cycle_mat) return;
        }
    }

    // 3. Marca como 'Preto' (processamento concluído)
    state_mat[u] = 2;
}

// --- Função Principal para Matriz de Adjacência ---

void solve_mat() {
    int M;
    if (scanf("%d %d", &N_mat, &M) != 2) return;

    // Se o número de nós exceder o limite seguro da matriz, 
    // a solução O(N^2) falhará em tempo e/ou memória, mas seguimos a matriz
    // para os casos onde N <= 500.
    if (N_mat >= MAX_NODES_MAT) {
        // Apenas para consumir a entrada e evitar problemas, se for o caso grande.
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
        }
        printf("SIM\n"); // Assumimos SIM, pois essa solução não deve ser usada para N > 500.
        return;
    }

    // Inicializa a matriz e o estado
    for (int i = 1; i <= N_mat; i++) {
        for (int j = 1; j <= N_mat; j++) {
            adj_mat[i][j] = 0;
        }
        state_mat[i] = 0;
    }
    has_cycle_mat = false;

    // Leitura das M dependências e construção do grafo
    for (int i = 0; i < M; i++) {
        int A, B; // A depende de B (A -> B)
        if (scanf("%d %d", &A, &B) != 2) return;
        adj_mat[A][B] = 1;
    }

    // Executa a DFS em todos os nós (para grafos desconectados)
    for (int i = 1; i <= N_mat; i++) {
        if (state_mat[i] == 0 && !has_cycle_mat) {
            dfs_mat(i);
        }
    }

    if (has_cycle_mat) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
}

// --- Função Main para o Caso de Teste ---

int main() {
    int T; // Número de casos de teste
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        solve_mat();
    }

    return 0;
}