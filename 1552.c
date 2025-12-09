#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 505
#define MAX_EDGES (MAX_N * (MAX_N - 1) / 2)

// Estrutura para as coordenadas das pessoas
typedef struct {
    int x, y;
} Person;

// Estrutura para representar uma aresta (cabo de teia)
typedef struct {
    int u, v;     // Pessoas (vértices) conectadas
    double weight; // Distância euclidiana (peso)
} Edge;

Person people[MAX_N];
Edge edges[MAX_EDGES];

// Variáveis para a estrutura Union-Find
int parent[MAX_N];
int num_components;

// --- Funções Auxiliares ---

/**
 * @brief Calcula a distância euclidiana entre duas pessoas.
 */
double distance(int i, int j) {
    long long dx = (long long)people[i].x - people[j].x;
    long long dy = (long long)people[i].y - people[j].y;
    // O resultado está em centímetros
    return sqrt((double)(dx * dx + dy * dy));
}

/**
 * @brief Função de comparação para qsort (ordem crescente de peso).
 */
int compare_edges(const void *a, const void *b) {
    double w1 = ((Edge *)a)->weight;
    double w2 = ((Edge *)b)->weight;
    
    if (w1 < w2) return -1;
    if (w1 > w2) return 1;
    return 0;
}

// --- Funções Union-Find (Conjuntos Disjuntos) ---

/**
 * @brief Inicializa a estrutura Union-Find.
 */
void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Cada pessoa é seu próprio pai
    }
    num_components = n;
}

/**
 * @brief Encontra o representante (raiz) do conjunto ao qual o elemento 'i' pertence.
 * @param i O elemento.
 * @return O representante do conjunto.
 */
int find_set(int i) {
    if (parent[i] == i)
        return i;
    // Compressão de caminho (Path compression)
    return parent[i] = find_set(parent[i]);
}

/**
 * @brief Une os conjuntos que contêm 'i' e 'j'.
 * @return true se a união foi realizada (estavam em conjuntos diferentes), false caso contrário.
 */
bool union_sets(int i, int j) {
    int root_i = find_set(i);
    int root_j = find_set(j);

    if (root_i != root_j) {
        // Une os dois conjuntos
        parent[root_i] = root_j;
        num_components--; // Um componente a menos
        return true;
    }
    return false;
}

// --- Algoritmo de Kruskal ---

double kruskal_mst(int n, int num_edges) {
    // 1. Inicializa o Union-Find
    make_set(n);
    
    // 2. Ordena as arestas por peso (distância)
    qsort(edges, num_edges, sizeof(Edge), compare_edges);
    
    double min_total_length = 0.0;
    int edges_in_mst = 0;

    // 3. Percorre as arestas ordenadas
    for (int i = 0; i < num_edges && edges_in_mst < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // Verifica se incluir a aresta (u, v) não forma um ciclo
        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
            min_total_length += edges[i].weight;
            edges_in_mst++;
        }
    }

    return min_total_length; // Retorna o comprimento total em centímetros
}

// --- Função Principal de Solução ---

void solve_case() {
    int n; // Número de pessoas
    if (scanf("%d", &n) != 1) return;

    // 1. Leitura das Coordenadas
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &people[i].x, &people[i].y) != 2) return;
    }

    // 2. Criação de Todas as Arestas
    int edge_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[edge_count].u = i;
            edges[edge_count].v = j;
            edges[edge_count].weight = distance(i, j);
            edge_count++;
        }
    }

    // 3. Execução do Algoritmo de Kruskal
    // O resultado é em centímetros.
    double min_length_cm = kruskal_mst(n, edge_count);
    
    // 4. Conversão para Metros e Saída
    // Conversão: 1 metro = 100 centímetros
    double min_length_m = min_length_cm / 100.0;

    // Imprime com precisão de duas casas decimais, usando '.' como separador.
    printf("%.2f\n", min_length_m);
}

int main() {
    int C; // Quantidade de casos de teste
    if (scanf("%d", &C) != 1) return 0;
    
    for (int c = 0; c < C; c++) {
        solve_case();
    }

    return 0;
}