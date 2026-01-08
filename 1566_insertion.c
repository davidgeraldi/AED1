#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3000000

void InsertionSort (int vetor[], int n) {
    int i, chave, j;
    
    for (i = 1; i < n; i++) {
        chave = vetor[i]; 
        j = i - 1;
        
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        
        vetor[j + 1] = chave;
    }
}

void Resolver () {
    int N;
    
    if (scanf("%d", &N) != 1) return;

    int *alturas = malloc (N * sizeof (int));
    if (alturas == NULL) return; 

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &alturas[i]) != 1) {
            free (alturas);
            return;
        }
    }

    InsertionSort (alturas, N);

    for (int i = 0; i < N; i++) {
        printf("%d", alturas[i]); 
        if (i == N - 1) {
            printf (""); 
        } 
        else {
            printf (" "); 
        }
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