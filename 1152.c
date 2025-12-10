#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b, w;
} E;

int p[200000];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

int cmp(const void *x, const void *y) {
    return ((E*)x)->w - ((E*)y)->w;
}

int main() {
    int n, m, i;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        E v[m];
        long long tot = 0;

        for (i = 0; i < n; i++)
            p[i] = i;

        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &v[i].a, &v[i].b, &v[i].w);
            tot += v[i].w;
        }

        qsort(v, m, sizeof(E), cmp);

        long long mst = 0;
        int x, y;

        for (i = 0; i < m; i++) {
            x = find(v[i].a);
            y = find(v[i].b);
            if (x != y) {
                p[x] = y;
                mst += v[i].w;
            }
        }

        printf("%lld\n", tot - mst);
    }
    return 0;
}