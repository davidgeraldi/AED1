#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10005

int vis[MAX];
int fila[MAX];
int dist[MAX];

int Inverter (int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int BuscaBFS (int a, int b) {
    int inicio_fila = 0, fim_fila = 0;

    for (int i = 0; i < MAX; i++) {
        vis[i] = 0;
    } 

    fila[fim_fila] = a;
    dist[fim_fila] = 0;
    fim_fila++;
    vis[a] = 1;

    while (inicio_fila < fim_fila) {
        int atual = fila[inicio_fila];
        int distancia = dist[inicio_fila];
        inicio_fila++;

        if (atual == b) return distancia;

        if (atual + 1 < MAX && !vis[atual+1]) {
            vis[atual+1] = 1;
            fila[fim_fila] = atual + 1;
            dist[fim_fila] = distancia + 1;
            fim_fila++;
        }

        int invertido = Inverter (atual);
        if (invertido < MAX && !vis[invertido]) {
            vis[invertido] = 1;
            fila[fim_fila] = invertido;
            dist[fim_fila] = distancia + 1;
            fim_fila++;
        }
    }

    return -1;
}

int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf ("%d %d", &A, &B);
        printf ("%d\n", BuscaBFS (A, B));
    }
    return 0;
}