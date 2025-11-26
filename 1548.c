#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int v[], int esquerda, int direita) {
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

        if (i <= j){
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    }

    if (esquerda < j)
        quicksort(v, esquerda, j);

    if (i < direita)
        quicksort(v, i, direita);
}

int main() {
    int N, contador;
    scanf("%d", &N);

    while (N--){
        contador = 0;
        int M;
        scanf("%d", &M);

        int fila[M], nova_fila[M];

        for (int i = 0; i < M; i++){
            scanf("%d", &fila[i]);
            nova_fila[i] = fila[i];
        }

        quicksort(nova_fila, 0, M - 1);

        for (int i = 0; i < M; i++){
            if (fila[i] == nova_fila[i]){
                contador++;
            }
        }
        printf("%d\n", contador);
    }

    return 0;
}