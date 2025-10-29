#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int matriz[9][9];
    int aux, N, confereLinha[9], confereColuna[9], segmento[9][9], contador[9], sucesso = 0;     
    char buffer[1000]; 
    scanf("%d", &N); 
    getchar();

    for (int i = 0; i < N; i++) { // loop geral
        for (int z = 0; z < 9; z++) { //inicializa os contador com valor zero
            contador[z] = 0;
        }

        for (int j = 0; j < 9; j++) { // ler cada linha da matriz
            aux = 0;
            fgets(buffer, sizeof(buffer), stdin); // linha do usuário
            char *texto = strtok(buffer, " "); // separar a string a cada espaço
            while (texto != NULL) {
                matriz[j][aux] = atoi(texto); // Converte o número de char para int e armazena no vetor matriz
                texto = strtok(NULL, " ");
                aux++;
            }
        }

        for (int j = 0; j < 9; j++) { 
            for (int k = 0; k < 9; k++) { 
                int linha = j / 3; 
                int coluna = k / 3;
                segmento[(linha * 3) + coluna][contador[(linha * 3) + coluna]] = matriz[j][k];
                contador[(linha * 3) + coluna]++; 
                for (int w = 0; w < k; w++) { // conferir cada linha e coluna da matriz
                    if (matriz[j][k] == confereLinha[w] || matriz[k][j] == confereColuna[w]) {
                        sucesso = 1;
                    }
                }
                confereLinha[k] = matriz[j][k]; 
                confereColuna[k] = matriz[k][j]; 
            }
        }

        for (int j = 0; j < 9; j++) { 
            for (int k = 0; k < 9; k++) { 
                for (int w = 0; w < k; w++) {
                    if (segmento[j][w] == segmento[j][k]) {
                        sucesso = 1;
                    }
                }
            }
        }

        if (sucesso == 1) {printf("Instancia %d\nNAO\n\n", i + 1);}
        else{printf("Instancia %d\nSIM\n\n", i + 1);}
        sucesso = 0;
    } // fim loop geral

    return 0;
}