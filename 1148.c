#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 505
#define INF 1000000000

int tempo_viagem[MAX_CIDADES][MAX_CIDADES];
int pode_alcancar[MAX_CIDADES][MAX_CIDADES];

void MenoresCaminhos (int n, int matriz[MAX_CIDADES][MAX_CIDADES]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (matriz[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (matriz[k][j] != INF && matriz[i][k] + matriz[k][j] < matriz[i][j]) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                }
            }
        }
    }
}

int main () {
    int num_cidades, num_acordos;

    while (scanf("%d %d", &num_cidades, &num_acordos) == 2 && (num_cidades != 0)) {
        
        for (int i = 1; i <= num_cidades; i++) {
            for (int j = 1; j <= num_cidades; j++) {
                tempo_viagem[i][j] = (i == j) ? 0 : INF;
                pode_alcancar[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (int i = 0; i < num_acordos; i++) {
            int u, v, horas;
            scanf("%d %d %d", &u, &v, &horas);
            tempo_viagem[u][v] = horas;
            pode_alcancar[u][v] = 1; 
        }

        MenoresCaminhos (num_cidades, pode_alcancar);

        for (int i = 1; i <= num_cidades; i++) {
            for (int j = 1; j <= num_cidades; j++) {
                if (pode_alcancar[i][j] != INF && pode_alcancar[j][i] != INF) {
                    tempo_viagem[i][j] = 0;
                }
            }
        }

        MenoresCaminhos (num_cidades, tempo_viagem);

        int consultas;
        scanf("%d", &consultas);
        while (consultas--) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            if (tempo_viagem[origem][destino] == INF) {
                printf ("Nao e possivel entregar a carta\n");
            }
            else {
                printf ("%d\n", tempo_viagem[origem][destino]);
            }
        }
        printf ("\n");
    }
    return 0;
}