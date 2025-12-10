// Bibliotecas usadas no código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITO 1000000 // Constante usada para representar um valor inalcançável
                         // (maior que qualquer soma de pesos possível)

int main()
{
    int N, M, C, K;
    int u, v, p;

    int grafo[250][250];
    int distancia[250];
    int visitado[250];

    int i, j;
    int menor, atual; // Variáveis auxiliares para a lógica do Dijkstra

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N != 0 || M != 0 || C != 0 || K != 0))
    {

        for (i = 0; i < N; i++)
        {
            distancia[i] = INFINITO; // Inicia todas as distâncias como infinito
            visitado[i] = 0;         // Nenhuma cidade foi visitada ainda
            for (j = 0; j < N; j++)
            {
                grafo[i][j] = INFINITO; // Reseta as conexões do grafo
            }
        }

        for (i = 0; i < M; i++)
        {
            scanf("%d %d %d", &u, &v, &p);

            if (p < grafo[u][v])
            {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        distancia[K] = 0;

        for (i = 0; i < N; i++)
        {
            menor = INFINITO;
            atual = -1;

            // Loop para encontrar a cidade com a menor distância não visitada
            for (j = 0; j < N; j++)
            {
                if (visitado[j] == 0 && distancia[j] < menor)
                {
                    menor = distancia[j];
                    atual = j;
                }
            }

            if (atual == -1)
            {
                break;
            }

            visitado[atual] = 1;

            if (atual < C - 1)
            {

                if (grafo[atual][atual + 1] != INFINITO)
                {
                    if (distancia[atual] + grafo[atual][atual + 1] < distancia[atual + 1])
                    {
                        distancia[atual + 1] = distancia[atual] + grafo[atual][atual + 1];
                    }
                }
            }
            else
            {

                for (j = 0; j < N; j++)
                {
                    if (grafo[atual][j] != INFINITO)
                    { // Se existe estrada
                        if (distancia[atual] + grafo[atual][j] < distancia[j])
                        {
                            distancia[j] = distancia[atual] + grafo[atual][j];
                        }
                    }
                }
            }
        }

        printf("%d\n", distancia[C - 1]);
    }

    return 0;
}