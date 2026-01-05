#include <stdio.h>

int g[30][30];
int vis[30];
int v, e;

int comp_nos[30]; // Armazena temporariamente os nós de uma componente encontrada.
int qtdNos; // Quantos nós existem na componente atual

void BuscaDFS (int u) {
    vis[u] = 1;
    comp_nos[qtdNos++] = u;
    for (int i = 0; i < v; i++) {
        if (g[u][i] && !vis[i]) BuscaDFS (i);
    }
}

void OrdenInser (int n) { //insertion sort
    for (int i = 1; i < n; i++) {
        int chave = comp_nos[i];
        int j = i - 1;
        while (j >= 0 && comp_nos[j] > chave) {
            comp_nos[j + 1] = comp_nos[j];
            j--;
        }
        comp_nos[j + 1] = chave;
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    for (int caso = 1; caso <= t; caso ++) {
        scanf ("%d %d", &v, &e);

        for (int i = 0; i < v; i++) {
            vis[i] = 0;
            for (int j = 0; j < v; j++) g[i][j] = 0;
        }

        for (int i = 0; i < e; i++) {
            char a, b;
            scanf (" %c %c", &a, &b);
            int x = a - 'a';
            int y = b - 'a';
            g[x][y] = g[y][x] = 1;
        }

        printf ("caso #%d:\n", caso);

        int comps = 0;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                qtdNos = 0;
                BuscaDFS (i);
                OrdenInser (qtdNos);
                for (int k = 0; k < qtdNos; k++) {
                    printf ("%c,", comp_nos[k] + 'a');
                }
                printf ("\n");
                comps++;
            }
        }

        printf ("%d connected components\n\n", comps);
    }

    return 0;
}