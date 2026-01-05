#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CIDADES 501
#define INF 1000000000 // Representa infinito para o tempo

// Matrizes globais para as duas etapas:
// 1. Matriz de Adjacência de Tempo (para cálculo final)
int tempo_adj[MAX_CIDADES][MAX_CIDADES];

// 2. Matriz de Adjacência de Conectividade (para identificar países)
int conex_adj[MAX_CIDADES][MAX_CIDADES];

// --- Algoritmo de Floyd-Warshall ---

/**
 * brief Aplica o algoritmo de Floyd-Warshall na matriz 'matriz'.
 * param N Número de cidades.
 * param matriz A matriz de distâncias/tempos.
 */
void floyd_warshall(int N, int matriz[MAX_CIDADES][MAX_CIDADES]) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // Apenas relaxa se os caminhos intermediários não forem infinitos
                if (matriz[i][k] != INF && matriz[k][j] != INF) {
                    if (matriz[i][k] + matriz[k][j] < matriz[i][j]) {
                        matriz[i][j] = matriz[i][k] + matriz[k][j];
                    }
                }
            }
        }
    }
}

// --- Função Principal ---

int main() {
    int N, E; // N: Cidades, E: Acordos (rotas impressas)
    int casos = 0;
    
    // Loop principal para múltiplos casos de teste. Finaliza com N=E=0.
    while (scanf("%d %d", &N, &E) == 2 && (N != 0 || E != 0)) {
        
        // Inicialização: INF para todos os caminhos. 0 para i -> i.
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                tempo_adj[i][j] = conex_adj[i][j] = (i == j) ? 0 : INF;
            }
        }

        // 1. Leitura dos Acordos e Construção Inicial das Matrizes
        for (int i = 0; i < E; i++) {
            int X, Y, H;
            if (scanf("%d %d %d", &X, &Y, &H) != 3) break;
            
            // O custo de H horas (impresso) é o tempo máximo.
            if (H < tempo_adj[X][Y]) {
                tempo_adj[X][Y] = H;
            }
            
            // Para conectividade, usamos custo 1 (apenas para verificar se há caminho)
            conex_adj[X][Y] = 1;
        }

        // --- ETAPA 1: Identificação de Países ---
        
        // Rodar Floyd-Warshall na matriz de conectividade
        floyd_warshall(N, conex_adj);
        
        // --- ETAPA 2: Aplicação da Regra de Tempo Zero ---
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                
                // Se A e B estão no mesmo país:
                // Há caminho de A->B (conex_adj[i][j] < INF) E
                // Há caminho de B->A (conex_adj[j][i] < INF).
                if (conex_adj[i][j] != INF && conex_adj[j][i] != INF) {
                    
                    // Comunicação é instantânea (0 horas) em ambas as direções.
                    // Isso domina o tempo de envio da carta impressa H.
                    tempo_adj[i][j] = 0;
                    tempo_adj[j][i] = 0;
                }
            }
        }

        // --- ETAPA 3: Cálculo do Caminho Mínimo Final ---
        
        // Rodar Floyd-Warshall na matriz de tempo
        floyd_warshall(N, tempo_adj);
        
        // --- Processamento das Consultas ---
        
        int K; // Número de consultas
        if (scanf("%d", &K) != 1) break;
        
        for (int k = 0; k < K; k++) {
            int O, D; // O: Origem, D: Destino
            if (scanf("%d %d", &O, &D) != 2) break;
            
            int tempoMinimo = tempo_adj[O][D];
            
            // Saída
            if (tempoMinimo >= INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", tempoMinimo);
            }
        }
        
        // Imprime uma linha em branco após cada caso de teste.
        printf("\n");
        casos++;
    }

    return 0;
}