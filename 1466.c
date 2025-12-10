#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *l, *r;
} no;

no* ins(no *t, int x) {
    if (!t) {
        t = (no*) malloc(sizeof(no));
        t->v = x;
        t->l = t->r = NULL;
        return t;
    }
    if (x < t->v) t->l = ins(t->l, x);
    else t->r = ins(t->r, x);
    return t;
}

typedef struct {
    no *d[2000];
    int i, f;
} fila;

void pf(no *t, int c) {
    fila q;
    q.i = q.f = 0;

    q.d[q.f++] = t;

    printf("Case %d:\n", c);

    int first = 1;
    while (q.i < q.f) {
        no *x = q.d[q.i++];

        if (first) {
            printf("%d", x->v);
            first = 0;
        } else {
            printf(" %d", x->v);
        }

        if (x->l) q.d[q.f++] = x->l;
        if (x->r) q.d[q.f++] = x->r;
    }
    printf("\n\n");
}

int main() {
    int c, n, x, i;
    scanf("%d", &c);

    for (int k = 1; k <= c; k++) {
        scanf("%d", &n);

        no *t = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            t = ins(t, x);
        }

        pf(t, k);
    }

    return 0;
}