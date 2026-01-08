#include <stdio.h>

#define MAX 2005

char desenho[MAX][MAX];
int vis[MAX][MAX];
int coordX[MAX*MAX], coordY[MAX*MAX];

int main () {
    int N, M;
    int i, j;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (scanf("%d %d", &N, &M) == 2) {
        for (i = 0; i < N; i++) {
            scanf("%s", desenho[i]);
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                vis[i][j] = 0;
            }
        }
        int cont = 0;

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                if (!vis[i][j] && desenho[i][j] == '.') {

                    int topo = 0;
                    coordX[topo] = i;
                    coordY[topo] = j;
                    topo++;
                    vis[i][j] = 1;

                    while (topo > 0) {
                        topo--;
                        int x = coordX[topo];
                        int y = coordY[topo];

                        int k;
                        for (k = 0; k < 4; k++) {
                            int proxX = x + dx[k];
                            int proxY = y + dy[k];

                            if (proxX >= 0 && proxX < N && proxY >= 0 && proxY < M) {
                                if (!vis[proxX][proxY] && desenho[proxX][proxY] == '.') {
                                    vis[proxX][proxY] = 1;
                                    coordX[topo] = proxX;
                                    coordY[topo] = proxY;
                                    topo++;
                                }
                            }
                        }
                    }
                    cont++;
                }
            }
        }

        printf ("%d\n", cont);
    }

    return 0;
}