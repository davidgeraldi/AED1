#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b; 
    int p;    // peso da aresta
} Aresta;

int p[200000];

void QuickSort (Aresta v[], int esq, int dir) {
    int i = esq, j = dir;
    int pivo = v[(esq + dir) / 2].p;
    Aresta aux;

    while (i <= j) {
        while (v[i].p < pivo) i++; 
        while (v[j].p > pivo) j--; 
        
        if (i <= j) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if (esq < j) QuickSort (v, esq, j);
    if (i < dir) QuickSort (v, i, dir);
}

int Busca (int x) {
    if (p[x] == x) return x;
    return p[x] = Busca (p[x]);
}

int main () {
    int n, m, i;

    while (1) {
        if (scanf ("%d %d", &n, &m) != 2 || (n == 0 && m == 0)) break;

        Aresta v[m];          
        double tot = 0; 

        for (i = 0; i < n; i++) {
            p[i] = i;
        }

        for (i = 0; i < m; i++) {
            scanf ("%d %d %d", &v[i].a, &v[i].b, &v[i].p);
            tot += v[i].p; 
        }

        if (m > 0) {
            QuickSort (v, 0, m - 1);
        }

        double pesoMST = 0; 
        int x, y;

        for (i = 0; i < m; i++) {
            x = Busca (v[i].a);
            y = Busca (v[i].b);

            if (x != y) {
                p[x] = y;      
                pesoMST += v[i].p; 
            }
        }

        printf ("%.0f\n", tot - pesoMST);
    }
    return 0;
}