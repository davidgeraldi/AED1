#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N;
    scanf("%d", &N);

    int fila[N];

    for (int i = 0; i < N; i++){
        scanf("%d", &fila[i]);
    }

    int M;
    scanf("%d", &M);

    int saidas[M];

    for (int i = 0; i < M; i++){
        scanf("%d", &saidas[i]);
    }

    int tam = N;

    for (int i = 0; i < M; i++){
        int alvo = saidas[i];
        for (int j = 0; j < tam; j++){
            if (fila[j] == alvo){
                for (int k = j; k < tam - 1; k++){
                    fila[k] = fila[k + 1];
                }
                tam--;
                break;
            }
        }
    }

    for (int i = 0; i < tam; i++){
        if (i == tam - 1)
            printf("%d\n", fila[i]);
        else
            printf("%d ", fila[i]);
    }

    return 0;
}