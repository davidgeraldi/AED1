#include <stdio.h>
#include <stdlib.h>

// Definimos o tamanho máximo do array.
// Cuidado: 3,000,000 inteiros requerem cerca de 12 MB de memória RAM, 
// o que é aceitável, mas o tempo de execução será o problema.
#define MAX_N 3000000

// Função principal de ordenação: Insertion Sort
void insertionSort(int arr[], int n) {
    int i, chave, j;
    
    // Começa do segundo elemento (índice 1), pois o primeiro (índice 0) é considerado ordenado.
    for (i = 1; i < n; i++) {
        chave = arr[i]; // 'chave' é o elemento a ser inserido na sub-lista ordenada
        j = i - 1;

        // Move os elementos da sub-lista ordenada que são maiores que a chave
        // uma posição à frente de sua posição atual.
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // Insere a chave na sua posição correta
        arr[j + 1] = chave;
    }
}

void resolver() {
    int N; // Número de pessoas
    
    // 1. Leitura do tamanho do vetor N
    if (scanf("%d", &N) != 1) return;

    // Alocação dinâmica para lidar com o grande N (até 3 milhões)
    int *alturas = (int *)malloc(N * sizeof(int));
    if (alturas == NULL) return; // Erro de alocação

    // 2. Leitura dos elementos
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &alturas[i]) != 1) {
            free(alturas);
            return;
        }
    }

    // 3. Ordenação com Insertion Sort
    insertionSort(alturas, N);

    // 4. Impressão da Saída
    // Imprime todos os elementos na ordem crescente, separados por espaço
    for (int i = 0; i < N; i++) {
        printf("%d%s", alturas[i], (i == N - 1) ? "" : " ");
    }
    printf("\n");

    // 5. Liberação da memória
    free(alturas);
}

int main() {
    int NC; // Número de casos de teste
    
    // Leitura do número de casos de teste
    if (scanf("%d", &NC) != 1) return 0;

    while (NC--) {
        resolver();
    }

    return 0;
}