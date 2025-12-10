#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200000     // máximo bem seguro
#define L   60         // tamanho máx da string

char v[MAX][L];

int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int n = 0;

    while (scanf("%s", v[n]) != EOF) {
        n++;
    }

    qsort(v, n, L, cmp);

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (strcmp(v[i], v[i-1]) != 0) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}