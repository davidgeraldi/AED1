#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que transforma o sub-array enraizado no índice i em um Max-Heap
void heapify(int arr[], int n, int i) {
    int maior = i;       // Inicializa o maior como a raiz
    int esq = 2 * i + 1; // Índice do filho esquerdo
    int dir = 2 * i + 2; // Índice do filho direito

    if (esq < n && arr[esq] > arr[maior]) maior = esq;
    if (dir < n && arr[dir] > arr[maior]) maior = dir;

    // Se o maior não for a raiz
    if (maior != i) {
        swap(&arr[i], &arr[maior]);
        heapify(arr, n, maior); // Chama recursivamente
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int n) {
    // 1. Constrói o Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 2. Extrai elementos um por um
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move a raiz (o maior) para o final
        heapify(arr, i, 0);      // Chama heapify no heap reduzido (tamanho i)
    }
}

void solve_heapsort() {
    int N;
    if (scanf("%d", &N) != 1) return;

    int *alturas = (int *)malloc(N * sizeof(int));
    if (alturas == NULL) return;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &alturas[i]) != 1) { free(alturas); return; }
    }

    // Chamada do Heap Sort
    heapSort(alturas, N); 

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
        solve_heapsort();
    }

    return 0;
}