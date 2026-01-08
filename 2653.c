#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função de comparação para o qsort
int comparar(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    // Definimos um limite razoável. O enunciado diz que a soma dos tamanhos é 10^6.
    // Para simplificar, vamos usar um array que suporte as entradas.
    static char joias[1000000][200]; // static para não estourar a pilha (stack)
    int total_lido = 0;

    // Lendo cada joia até o final do arquivo (EOF)
    while (scanf("%s", joias[total_lido]) != EOF) {
        total_lido++;
    }

    // Se não houver joias, o resultado é 0
    if (total_lido == 0) {
        printf("0\n");
        return 0;
    }

    // Ordena todas as strings alfabeticamente
    qsort(joias, total_lido, sizeof(joias[0]), comparar);

    // Conta quantos tipos diferentes existem
    int tipos_distintos = 1; // Começa em 1 se houver ao menos uma joia
    for (int i = 1; i < total_lido; i++) {
        // Se a joia atual for diferente da anterior, temos um novo tipo
        if (strcmp(joias[i], joias[i-1]) != 0) {
            tipos_distintos++;
        }
    }

    printf("%d\n", tipos_distintos);

    return 0;
}