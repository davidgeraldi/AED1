#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 51

typedef struct {
    int linha, coluna;
} Celula;

Celula fila[MAX_TAM * MAX_TAM];
int inicio_fila, fim_fila;

int dlinha[] = {-1, 1, 0, 0}; 
int dcoluna[] = {0, 0, -1, 1}; 

char mapa[MAX_TAM][MAX_TAM];
int N, M;

int CelulaEhValida (int linha, int coluna) {
    return linha >= 0 && linha < N && coluna >= 0 && coluna < M;
}

void BuscaBFS () {
    inicio_fila = fim_fila = 0;
    
    for (int linha = 0; linha < N; linha++) {
        for (int coluna = 0; coluna < M; coluna++) {
            if (mapa[linha][coluna] == 'T') {
                fila[fim_fila++] = (Celula) { linha, coluna };
            }
        }
    }
    
    while (inicio_fila < fim_fila) {
        Celula atual = fila[inicio_fila++];
        int linha = atual.linha;
        int coluna = atual.coluna;
        
        for (int i = 0; i < 4; i++) {
            int nlin = linha + dlinha[i];
            int ncol = coluna + dcoluna[i];
            
            if (CelulaEhValida (nlin, ncol) && mapa[nlin][ncol] == 'A') {        
                mapa[nlin][ncol] = 'T';
                fila[fim_fila++] = (Celula) { nlin, ncol };
            }
        }
    }
    
    for (int linha = 0; linha < N; linha++) {
        for (int coluna = 0; coluna < M; coluna++) {
            printf ("%c", mapa[linha][coluna]);
        }
        printf ("\n");
    }
}

int main () {
    
    while (scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)) {
        
        for (int i = 0; i < N; i++) {
            if (scanf ("%s", mapa[i]) != 1) {
                return 1;
            }
        }
        BuscaBFS ();
        printf ("\n");
    }
    
    return 0;
}