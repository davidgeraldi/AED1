#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void QuickSort (int v[], int esquerda, int direita) {
    int i = esquerda;
    int j = direita;
    int pivo = v[(esquerda + direita) / 2];

    while (i <= j) {
        while (v[i] > pivo) {
            i++;
        }
        while (v[j] < pivo) {
            j--;
        }

        if (i <= j) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    if (esquerda < j) {
        QuickSort (v, esquerda, j);
    }
    if (i < direita) {
        QuickSort (v, i, direita);
    }
}

int main () {
    int N, contador;
    scanf("%d", &N);

    while (N--) {
        contador = 0;
        int M;
        scanf("%d", &M);

        int fila[M], FilaNova[M];

        for (int i = 0; i < M; i++) {
            scanf("%d", &fila[i]);
            FilaNova[i] = fila[i];
        }

        QuickSort (FilaNova, 0, M - 1);

        for (int i = 0; i < M; i++) {
            if (fila[i] == FilaNova[i]){
                contador++;
            }
        }
        printf ("%d\n", contador);
    }

    return 0;
}