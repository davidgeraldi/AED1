#include <stdio.h>
#include <stdlib.h>

void AtualizarVetor(int v[], int tamanho) {
    int aux = 0;
    aux = v[1];

    for (int j = 1; j < tamanho; j++) {
        v[j - 1] = v[j];
    }

    v[tamanho - 1] = v[0];

    for (int j = 1; j < tamanho; j++) {
        v[j - 1] = v[j];
    }
}

int main() {

    int tamanho, tam = 1, qtdDescartados = 0;
    int vetor[50], descartados[50];

    while (tam != 0) { 
        for (int i = 0; i < 50; i++) {
            descartados[i] = 0;
        }
        qtdDescartados = 0;

        scanf("%d", &tamanho);
        tam = tamanho;

        if (tam != 0) {
            for (int i = 0; i < tamanho; i++) {
                vetor[i] = i + 1;
            }

            while (tamanho > 1) {
                descartados[qtdDescartados] = vetor[0]; 
                qtdDescartados++;
                AtualizarVetor(vetor, tamanho);
                tamanho--;
            }
            
            printf("Discarded cards: ");
            for (int i = 0; i < qtdDescartados; i++) {
                if (i < (qtdDescartados - 1)) {
                    printf("%d, ", descartados[i]);
                }
                else {
                    printf("%d\n", descartados[i]);
                }
            }
            printf("Remaining card: %d\n", vetor[0]);
        }
    }

    return 0;
}