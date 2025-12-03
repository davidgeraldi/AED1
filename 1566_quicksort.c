#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Otimização: Seleciona o pivô como a Mediana de Três (low, mid, high)
int median_of_three(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    
    // Garantindo que arr[low] <= arr[mid]
    if (arr[low] > arr[mid]) swap(&arr[low], &arr[mid]);
    
    // Garantindo que arr[low] <= arr[high]
    if (arr[low] > arr[high]) swap(&arr[low], &arr[high]);
    
    // Garantindo que arr[mid] <= arr[high]
    if (arr[mid] > arr[high]) swap(&arr[mid], &arr[high]);

    // O arr[mid] agora é a mediana. Trocamos ele para a posição 'high'
    // para que a função partition possa usá-lo como pivô.
    swap(&arr[mid], &arr[high]);
    return arr[high]; // O valor do pivô agora está em arr[high]
}


// Função de particionamento usando o pivô mediano
int partition_optimized(int arr[], int low, int high) {
    // A função median_of_three garante que o pivô (agora em arr[high])
    // é um bom valor.
    int pivot = median_of_three(arr, low, high); 
    
    int i = (low - 1);     
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    // Coloca o pivô (que está em arr[high]) em sua posição final
    swap(&arr[i + 1], &arr[high]);
    
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_optimized(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void solve() {
    int N;
    if (scanf("%d", &N) != 1) return;

    int *alturas = (int *)malloc(N * sizeof(int));
    if (alturas == NULL) return;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &alturas[i]) != 1) { free(alturas); return; }
    }

    // Chamada do Quick Sort Otimizado
    quickSort(alturas, 0, N - 1); 

    // Impressão
    for (int i = 0; i < N; i++) {
        printf("%d%s", alturas[i], (i == N - 1) ? "" : " ");
    }
    printf("\n");

    free(alturas);
}

int main() {
    int NC;
    if (scanf("%d", &NC) != 1) return 0;

    // Aumenta a velocidade de I/O (Embora não seja padronizado em C, ajuda em alguns juízes)
    // setvbuf(stdout, NULL, _IOFBF, 0); 
    
    while (NC--) {
        solve();
    }

    return 0;
}