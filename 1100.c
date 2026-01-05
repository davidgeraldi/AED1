#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_BORDA 8

// Fila para a BuscaBFS
typedef struct {
    int lin, col; // Coordenadas (linha, coluna)
    int dist; // Distância (número de movimentos)
} Fila;

Fila tabuleiro [TAM_BORDA * TAM_BORDA];
int cabeca, cauda;

// Array para armazenar a menor distância (movimentos)
// dist[r][c] = menor número de movimentos para alcançar (r, c)
int dist [TAM_BORDA + 1][TAM_BORDA + 1];

// Array de movimentos possíveis do Cavalo (dr, dc)
// [dr, dc]
int movimentos[8][2] = {
    {-2, -1}, {-2, 1}, // Duas para cima, uma para os lados
    {-1, -2}, {-1, 2}, // Uma para cima, duas para os lados
    { 1, -2}, { 1, 2}, // Uma para baixo, duas para os lados
    { 2, -1}, { 2, 1}  // Duas para baixo, uma para os lados
};

// --- Funções Auxiliares ---

// Converte a coordenada do xadrez (ex: "a1") para (linha, coluna 1-base)
void ConverteStr (const char *s, int *lin, int *col) {
    // Coluna: 'a' (97) -> 1, 'h' (104) -> 8
    *col = s[0] - 'a' + 1;
    // Linha: '1' (49) -> 1, '8' (56) -> 8
    *lin = s[1] - '0';
}

// Verifica se uma coordenada é válida (dentro do tabuleiro)
bool EhValida (int lin, int col) {
    return lin >= 1 && lin <= TAM_BORDA && col >= 1 && col <= TAM_BORDA;
}

// --- Algoritmo BuscaBFS ---

int BuscaBFS (int inicio_lin, int inicio_col, int fim_lin, int fim_col) {
    if (inicio_lin == fim_lin && inicio_col == fim_col) {
        return 0;
    }

    // Inicializa distâncias (INF) e Fila
    for (int i = 1; i <= TAM_BORDA; i++) {
        for (int j = 1; j <= TAM_BORDA; j++) {
            dist[i][j] = -1; // -1 significa não visitado
        }
    }
    cabeca = cauda = 0;

    // Adiciona o nó inicial à fila
    tabuleiro[cauda++] = (Fila) { inicio_lin, inicio_col, 0 };
    dist[inicio_lin][inicio_col] = 0;

    while (cabeca < cauda) {
        Fila atual = tabuleiro[cabeca++];
        int linha = atual.lin;
        int coluna = atual.col;
        int distancia = atual.dist;

        // Verifica se o destino foi alcançado
        if (linha == fim_lin && coluna == fim_col) {
            return distancia;
        }

        // Explora os 8 movimentos possíveis do Cavalo
        for (int i = 0; i < 8; i++) {
            int prox_lin = linha + movimentos[i][0];
            int prox_col = coluna + movimentos[i][1];

            if (EhValida (prox_lin, prox_col) && dist[prox_lin][prox_col] == -1) {
                // Marca como visitado e adiciona à fila
                dist[prox_lin][prox_col] = distancia + 1;
                tabuleiro[cauda++] = (Fila) { prox_lin, prox_col, distancia + 1 };
            }
        }
    }

    // Deve ser sempre alcançável em um tabuleiro 8x8, mas por segurança
    return -1; 
}

// --- Função Principal ---

int main() {
    char inicio_str[3], fim_str[3];

    // O loop continua lendo pares de coordenadas até EOF
    while (scanf ("%s %s", inicio_str, fim_str) == 2) {
        int inicio_lin, inicio_col;
        int fim_lin, fim_col;

        ConverteStr (inicio_str, &inicio_lin, &inicio_col);
        ConverteStr (fim_str, &fim_lin, &fim_col);

        int min_movimentos = BuscaBFS (inicio_lin, inicio_col, fim_lin, fim_col);

        printf ("To get from %s to %s takes %d knight movimentos.\n", inicio_str, fim_str, min_movimentos);
    }

    return 0;
}