#include <stdio.h>
#include <stdlib.h>

void Merge (int vetor[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; 
    int n2 = r - m;     

    int *L = malloc (n1 * sizeof (int));
    int *R = malloc (n2 * sizeof (int));
    if (L == NULL || R == NULL) {
        if (L) free (L);
        if (R) free (R);
        return;
    }

    for (i = 0; i < n1; i++) L[i] = vetor[l + i];
    for (j = 0; j < n2; j++) R[j] = vetor[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } 
        else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) vetor[k++] = L[i++];
    while (j < n2) vetor[k++] = R[j++];

    free (L);
    free (R);
}

void MergeSort (int vetor[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort (vetor, l, m);
        MergeSort (vetor, m + 1, r);
        Merge (vetor, l, m, r);
    }
}

void Resolver () {
    int N;
    if (scanf("%d", &N) != 1) return;

    int *alturas = malloc (N * sizeof(int));
    if (alturas == NULL) return;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &alturas[i]) != 1) { free (alturas); return; }
    }

    MergeSort (alturas, 0, N - 1); 

    for (int i = 0; i < N; i++) {
        printf ("%d%s", alturas[i], (i == N - 1) ? "" : " ");
    }
    printf ("\n");

    free (alturas);
}

int main () {
    int NC;
    if (scanf("%d", &NC) != 1) return 0;

    while (NC--) {
        Resolver ();
    }

    return 0;
}