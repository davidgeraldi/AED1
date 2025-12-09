#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Tamanho do tabuleiro (8x8)
#define BOARD_SIZE 8

// Fila para a BFS
typedef struct {
    int r, c; // Coordenadas (linha, coluna)
    int dist; // Distância (número de movimentos)
} QueueItem;

QueueItem queue[BOARD_SIZE * BOARD_SIZE];
int head, tail;

// Array para armazenar a menor distância (movimentos)
// dist[r][c] = menor número de movimentos para alcançar (r, c)
int dist[BOARD_SIZE + 1][BOARD_SIZE + 1];

// Array de movimentos possíveis do Cavalo (dr, dc)
// [dr, dc]
int moves[8][2] = {
    {-2, -1}, {-2, 1}, // Duas para cima, uma para os lados
    {-1, -2}, {-1, 2}, // Uma para cima, duas para os lados
    { 1, -2}, { 1, 2}, // Uma para baixo, duas para os lados
    { 2, -1}, { 2, 1}  // Duas para baixo, uma para os lados
};

// --- Funções Auxiliares ---

// Converte a coordenada do xadrez (ex: "a1") para (linha, coluna 1-base)
void parse_coord(const char *s, int *r, int *c) {
    // Coluna: 'a' (97) -> 1, 'h' (104) -> 8
    *c = s[0] - 'a' + 1;
    // Linha: '1' (49) -> 1, '8' (56) -> 8
    *r = s[1] - '0';
}

// Verifica se uma coordenada é válida (dentro do tabuleiro)
bool is_valid(int r, int c) {
    return r >= 1 && r <= BOARD_SIZE && c >= 1 && c <= BOARD_SIZE;
}

// --- Algoritmo BFS ---

int bfs(int start_r, int start_c, int end_r, int end_c) {
    if (start_r == end_r && start_c == end_c) {
        return 0;
    }

    // Inicializa distâncias (INF) e Fila
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            dist[i][j] = -1; // -1 significa não visitado
        }
    }
    head = tail = 0;

    // Adiciona o nó inicial à fila
    queue[tail++] = (QueueItem){start_r, start_c, 0};
    dist[start_r][start_c] = 0;

    while (head < tail) {
        QueueItem current = queue[head++];
        int r = current.r;
        int c = current.c;
        int d = current.dist;

        // Verifica se o destino foi alcançado
        if (r == end_r && c == end_c) {
            return d;
        }

        // Explora os 8 movimentos possíveis do Cavalo
        for (int i = 0; i < 8; i++) {
            int next_r = r + moves[i][0];
            int next_c = c + moves[i][1];

            if (is_valid(next_r, next_c) && dist[next_r][next_c] == -1) {
                // Marca como visitado e adiciona à fila
                dist[next_r][next_c] = d + 1;
                queue[tail++] = (QueueItem){next_r, next_c, d + 1};
            }
        }
    }

    // Deve ser sempre alcançável em um tabuleiro 8x8, mas por segurança
    return -1; 
}

// --- Função Principal ---

int main() {
    char start_str[3], end_str[3];

    // O loop continua lendo pares de coordenadas até EOF
    while (scanf("%s %s", start_str, end_str) == 2) {
        int start_r, start_c;
        int end_r, end_c;

        parse_coord(start_str, &start_r, &start_c);
        parse_coord(end_str, &end_r, &end_c);

        int min_moves = bfs(start_r, start_c, end_r, end_c);

        printf("To get from %s to %s takes %d knight moves.\n", start_str, end_str, min_moves);
    }

    return 0;
}