#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BORDA 8

typedef struct {
    int lin, col; 
    int dist; 
} Fila;

Fila tabuleiro [TAM_BORDA * TAM_BORDA];
int inicio_fila, fim_fila;

int dist [TAM_BORDA + 1][TAM_BORDA + 1];

int movimentos[8][2] = {
    {-2, -1}, {-2, 1}, 
    {-1, -2}, {-1, 2}, 
    { 1, -2}, { 1, 2}, 
    { 2, -1}, { 2, 1}  
};

void ConverteStr (const char *s, int *lin, int *col) {
    *col = s[0] - 'a' + 1;
    *lin = s[1] - '0';
}

int EhValida (int lin, int col) {
    return lin >= 1 && lin <= TAM_BORDA && col >= 1 && col <= TAM_BORDA;
}

int BuscaBFS (int inicio_lin, int inicio_col, int fim_lin, int fim_col) {
    if (inicio_lin == fim_lin && inicio_col == fim_col) {
        return 0;
    }

    for (int i = 1; i <= TAM_BORDA; i++) {
        for (int j = 1; j <= TAM_BORDA; j++) {
            dist[i][j] = -1; 
        }
    }
    inicio_fila = fim_fila = 0;

    tabuleiro[fim_fila++] = (Fila) { inicio_lin, inicio_col, 0 };
    dist[inicio_lin][inicio_col] = 0;

    while (inicio_fila < fim_fila) {
        Fila atual = tabuleiro[inicio_fila++];
        int linha = atual.lin;
        int coluna = atual.col;
        int distancia = atual.dist;

        if (linha == fim_lin && coluna == fim_col) {
            return distancia;
        }

        for (int i = 0; i < 8; i++) {
            int prox_lin = linha + movimentos[i][0];
            int prox_col = coluna + movimentos[i][1];

            if (EhValida (prox_lin, prox_col) && dist[prox_lin][prox_col] == -1) {
                dist[prox_lin][prox_col] = distancia + 1;
                tabuleiro[fim_fila++] = (Fila) { prox_lin, prox_col, distancia + 1 };
            }
        }
    }

    return -1; 
}

int main () {
    char inicio_str[3], fim_str[3];

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