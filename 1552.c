#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 505
#define MAX_ARESTA (MAX_N * (MAX_N - 1) / 2)

typedef struct {
    int x, y;
} Pessoa;

typedef struct {
    int u, v;     
    double peso; 
} Aresta;

Pessoa pessoa[MAX_N];
Aresta arestas[MAX_ARESTA];
int pai[MAX_N];

double Distancia (int i, int j) {
    double dx = (double)pessoa[i].x - pessoa[j].x;
    double dy = (double)pessoa[i].y - pessoa[j].y;
    return sqrt((double)(dx * dx + dy * dy));
}

void QuickSort (int inicio, int fim) {
    int i = inicio, j = fim;
    double pivo = arestas[(inicio + fim) / 2].peso;
    Aresta aux;

    while (i <= j) {
        while (arestas[i].peso < pivo) i++;
        while (arestas[j].peso > pivo) j--;
        
        if (i <= j) {
            aux = arestas[i];
            arestas[i] = arestas[j];
            arestas[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j) QuickSort (inicio, j);
    if (i < fim) QuickSort (i, fim);
}

int EncontrarRaiz (int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = EncontrarRaiz (pai[i]);
}

int UnirGrupos (int i, int j) {
    pai[i] = j;
}

double BuscaMST (int n, int num_arestas) {
    for (int i = 0; i < n; i++) pai[i] = i;
    
    if (num_arestas > 0) QuickSort (0, num_arestas - 1);    

    double custo_total = 0.0;
    int arestas_conectadas = 0;

    for (int i = 0; i < num_arestas && arestas_conectadas < n - 1; i++) {
        int raiz_u = EncontrarRaiz (arestas[i].u);
        int raiz_v = EncontrarRaiz (arestas[i].v);

        if (raiz_u != raiz_v) {
            UnirGrupos (raiz_u, raiz_v);
            custo_total += arestas[i].peso;
            arestas_conectadas++;
        }
    }

    return custo_total; 
}

void Resolver () {
    int n; 
    if (scanf("%d", &n) != 1) return;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pessoa[i].x, &pessoa[i].y);
    }

    int cont_aresta = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            arestas[cont_aresta].u = i;
            arestas[cont_aresta].v = j;
            arestas[cont_aresta].peso = Distancia (i, j);
            cont_aresta++;
        }
    }

    double resultado_cm = BuscaMST (n, cont_aresta);
    
    double resultado_m = resultado_cm / 100.0;

    printf("%.2f\n", resultado_m);
}

int main() {
    int C;
    if (scanf("%d", &C) != 1) return 0;
    
    for (int c = 0; c < C; c++) {
        Resolver ();
    }

    return 0;
}