#include <stdio.h>
#include <stdlib.h>

void Trocar (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void TransformarEmHeap (int vetor[], int n, int i) {
    int maior = i;       
    int esq = 2 * i + 1; 
    int dir = 2 * i + 2; 

    if (esq < n && vetor[esq] > vetor[maior]) maior = esq;
    if (dir < n && vetor[dir] > vetor[maior]) maior = dir;

    if (maior != i) {
        Trocar (&vetor[i], &vetor[maior]);
        TransformarEmHeap (vetor, n, maior); 
    }
}

void HeapSort (int vetor[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        TransformarEmHeap (vetor, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        Trocar (&vetor[0], &vetor[i]); 
        TransformarEmHeap (vetor, i, 0);  
    }
}

void ResolverHeapSort () {
    int N;
    if (scanf("%d", &N) != 1) return;

    int *alturas = malloc (N * sizeof (int));
    if (alturas == NULL) return;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &alturas[i]) != 1) { free(alturas); return; }
    }

    HeapSort (alturas, N); 

    for (int i = 0; i < N; i++) {
        printf ("%d%s", alturas[i], (i == N - 1) ? "" : " ");
    }
    printf ("\n");

    free (alturas);
}

int main() {
    int NC;
    if (scanf("%d", &NC) != 1) return 0;

    while (NC--) {
        ResolverHeapSort ();
    }

    return 0;
}