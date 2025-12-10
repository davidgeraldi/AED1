#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10005

int vis[MAX];
int q[MAX];
int d[MAX];

int inverte(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int bfs(int a, int b) {
    int head = 0, tail = 0;

    for (int i = 0; i < MAX; i++) vis[i] = 0;

    q[tail] = a;
    d[tail] = 0;
    tail++;
    vis[a] = 1;

    while (head < tail) {
        int u = q[head];
        int dist = d[head];
        head++;

        if (u == b) return dist;

        // operação +1
        if (u + 1 < MAX && !vis[u+1]) {
            vis[u+1] = 1;
            q[tail] = u + 1;
            d[tail] = dist + 1;
            tail++;
        }

        // operação invert
        int v = inverte(u);
        if (v < MAX && !vis[v]) {
            vis[v] = 1;
            q[tail] = v;
            d[tail] = dist + 1;
            tail++;
        }
    }

    return -1;
}

int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    return 0;
}