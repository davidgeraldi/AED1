#include <stdio.h>
#include <stdlib.h>

// Função que intercala dois sub-arrays ordenados em um único array ordenado
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Tamanho do sub-array esquerdo
    int n2 = r - m;     // Tamanho do sub-array direito

    // Alocação de arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    if (L == NULL || R == NULL) {
        if (L) free(L);
        if (R) free(R);
        return;
    }

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Intercala os arrays temporários de volta para arr[l..r]
    i = 0; // Índice inicial do primeiro sub-array
    j = 0; // Índice inicial do segundo sub-array
    k = l; // Índice inicial do array intercalado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Função principal do Merge Sort (recursiva)
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void solve_mergesort() {
    int N;
    if (scanf("%d", &N) != 1) return;

    int *alturas = (int *)malloc(N * sizeof(int));
    if (alturas == NULL) return;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &alturas[i]) != 1) { free(alturas); return; }
    }

    // Chamada do Merge Sort
    mergeSort(alturas, 0, N - 1); 

    // Impressão da Saída
    for (int i = 0; i < N; i++) {
        printf("%d%s", alturas[i], (i == N - 1) ? "" : " ");
    }
    printf("\n");

    free(alturas);
}

int main() {
    int NC;
    if (scanf("%d", &NC) != 1) return 0;

    while (NC--) {
        solve_mergesort();
    }

    return 0;
}