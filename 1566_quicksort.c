#include <stdio.h>
#include <stdlib.h>

void Trocar (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Dividir (int vetor[], int baixo, int alto) {
    int pivo = vetor[alto]; 
    
    int i = (baixo - 1); 
    
    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j] <= pivo) {
            i++; 
            Trocar (&vetor[i], &vetor[j]);
        }
    }

    Trocar (&vetor[i + 1], &vetor[alto]);
    
    return (i + 1);
}

void QuickSort (int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = Dividir (vetor, baixo, alto);
        QuickSort (vetor, baixo, pi - 1);
        QuickSort (vetor, pi + 1, alto);
    }
}

void Resolver () {
    int N;
    if (scanf("%d", &N) != 1) return;

    int *alturas = malloc (N * sizeof (int));
    if (alturas == NULL) return;

    for (int i = 0; i < N; i++) {
        scanf("%d", &alturas[i]);
    }

    QuickSort (alturas, 0, N - 1); 

    for (int i = 0; i < N; i++) {
        printf("%d%s", alturas[i], (i == N - 1) ? "" : " ");
    }
    printf ("\n");

    free (alturas);
}

int main() {
    int NC;
    if (scanf("%d", &NC) != 1) return 0;
    
    while (NC--) {
        Resolver ();
    }

    return 0;
}