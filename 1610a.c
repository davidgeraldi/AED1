#include <stdio.h>
#include <string.h>

#define MAX_NOS 501 

int mat_adj[MAX_NOS][MAX_NOS]; 
int N; 

int estados[MAX_NOS];
int tem_ciclo;

void BuscaDFS (int u) {
    estados[u] = 1;

    for (int v = 1; v <= N; v++) {
        if (mat_adj[u][v] == 1) { 
            if (estados[v] == 1) {
                tem_ciclo = 1;
                return;
            }
            
            if (estados[v] == 0) {
                BuscaDFS (v);
            }
            
            if (tem_ciclo) return;
        }
    }
    estados[u] = 2;
}

void Resolver () {
    int M;
    if (scanf("%d %d", &N, &M) != 2) return;
    if (N >= MAX_NOS) {
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
        }
        printf ("SIM\n"); 
        return;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            mat_adj[i][j] = 0;
        }
        estados[i] = 0;
    }
    tem_ciclo = 0;

    for (int i = 0; i < M; i++) {
        int A, B; 
        if (scanf("%d %d", &A, &B) != 2) return;
        mat_adj[A][B] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (estados[i] == 0 && !tem_ciclo) {
            BuscaDFS (i);
        }
    }

    if (tem_ciclo) {
        printf ("SIM\n");
    } 
    else {
        printf ("NAO\n");
    }
}

int main () {
    int T; 
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        Resolver ();
    }

    return 0;
}