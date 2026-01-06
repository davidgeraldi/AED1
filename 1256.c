#include <stdio.h>

int tabela[1000][1000];
int tamanho[1000] = {0};

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, C;
        scanf ("%d %d", &M, &C);


        for (int i = 0; i < M; i++) {
            tamanho[i] = 0;    
        }
        for (int j = 0; j < C; j++) {
            int x;
            scanf ("%d", &x);

            int h = x % M;

            tabela[h][tamanho[h]++] = x;
        }

        for (int i = 0; i < M; i++) {
            printf ("%d ->", i);
            for (int j = 0; j < tamanho[i]; j++) {
                printf (" %d ->", tabela[i][j]);
            }
            printf (" \\\n");
        }

        if (T > 0) {
            printf ("\n");
        }
    }

    return 0;
}