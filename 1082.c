#include <stdio.h>

int g[30][30];
int vis[30];
int v, e;

int comp_nodes[30];
int comp_sz;

void dfs_collect(int u) {
    vis[u] = 1;
    comp_nodes[comp_sz++] = u;
    for (int i = 0; i < v; i++) {
        if (g[u][i] && !vis[i]) dfs_collect(i);
    }
}

void sort_comp(int n) {
    /* insertion sort - n <= 26 */
    for (int i = 1; i < n; i++) {
        int key = comp_nodes[i];
        int j = i - 1;
        while (j >= 0 && comp_nodes[j] > key) {
            comp_nodes[j + 1] = comp_nodes[j];
            j--;
        }
        comp_nodes[j + 1] = key;
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    for (int cs = 1; cs <= t; cs++) {
        scanf("%d %d", &v, &e);

        for (int i = 0; i < v; i++) {
            vis[i] = 0;
            for (int j = 0; j < v; j++) g[i][j] = 0;
        }

        for (int i = 0; i < e; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int x = a - 'a';
            int y = b - 'a';
            g[x][y] = g[y][x] = 1;
        }

        printf("Case #%d:\n", cs);

        int comps = 0;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                comp_sz = 0;
                dfs_collect(i);

                /* ordenar e imprimir */
                sort_comp(comp_sz);
                for (int k = 0; k < comp_sz; k++) {
                    printf("%c,", comp_nodes[k] + 'a');
                }
                printf("\n");
                comps++;
            }
        }

        printf("%d connected components\n\n", comps);
    }

    return 0;
}