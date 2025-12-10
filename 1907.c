#include <stdio.h>

#define MAX 2005

char g[MAX][MAX];
int vis[MAX][MAX];
int sx[MAX*MAX], sy[MAX*MAX];

int main() {
    int n, m;
    int i, j;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (scanf("%d %d", &n, &m) == 2) {
        for (i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                vis[i][j] = 0;

        int ans = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (!vis[i][j] && g[i][j] == '.') {

                    int top = 0;
                    sx[top] = i;
                    sy[top] = j;
                    top++;
                    vis[i][j] = 1;

                    while (top > 0) {
                        top--;
                        int x = sx[top];
                        int y = sy[top];

                        int k;
                        for (k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                                if (!vis[nx][ny] && g[nx][ny] == '.') {
                                    vis[nx][ny] = 1;
                                    sx[top] = nx;
                                    sy[top] = ny;
                                    top++;
                                }
                            }
                        }
                    }

                    ans++;
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}