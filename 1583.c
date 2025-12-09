#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 51

// Estrutura para representar as coordenadas de uma célula
typedef struct {
    int r, c;
} Cell;

// Fila para a BFS
Cell queue[MAX_SIZE * MAX_SIZE];
int head, tail;

// Direções de movimento (cima, baixo, esquerda, direita)
int dr[] = {-1, 1, 0, 0}; // Mudança na Linha (Row)
int dc[] = {0, 0, -1, 1}; // Mudança na Coluna (Column)

// O mapa original e o tamanho
char map[MAX_SIZE][MAX_SIZE];
int N, M;

// --- Funções Auxiliares ---

/**
 * @brief Verifica se a célula (r, c) está dentro dos limites do mapa.
 */
bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

// --- Algoritmo BFS ---

void solve_contamination() {
    // 1. Inicialização da Fila com Múltiplas Fontes
    head = tail = 0;
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (map[r][c] == 'T') {
                // Adiciona todas as fontes de contaminação ('T') à fila inicial
                queue[tail++] = (Cell){r, c};
            }
        }
    }
    
    // 2. Execução da BFS
    while (head < tail) {
        Cell current = queue[head++];
        int r = current.r;
        int c = current.c;
        
        // Explora os 4 vizinhos adjacentes
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Verifica se o vizinho é válido e contém água ('A')
            if (is_valid(nr, nc) && map[nr][nc] == 'A') {
                
                // Contamina a água
                map[nr][nc] = 'T';
                
                // Adiciona a célula contaminada à fila para propagar
                queue[tail++] = (Cell){nr, nc};
            }
            // Se for 'X' (rocha) ou 'T' (já contaminado), a contaminação para.
        }
    }
    
    // 3. Impressão do Mapa Contaminado
    for (int r = 0; r < N; r++) {
        // Imprime a linha inteira (M caracteres)
        for (int c = 0; c < M; c++) {
            printf("%c", map[r][c]);
        }
        printf("\n");
    }
}

// --- Função Principal (Loop de Casos de Teste) ---

int main() {
    
    // O loop continua lendo N e M até encontrar 0 0
    while (scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)) {
        
        // 1. Leitura do Mapa
        // Usa scanf com %s para ler a linha, pois é mais robusto que getc/fgetc
        for (int i = 0; i < N; i++) {
            if (scanf("%s", map[i]) != 1) {
                // Lidar com erro ou fim de arquivo inesperado
                return 1;
            }
        }
        
        // 2. Execução do Algoritmo
        solve_contamination();
        
        // 3. Linha em branco após o mapa (incluindo o último)
        printf("\n");
    }
    
    return 0;
}