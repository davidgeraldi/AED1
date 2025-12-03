#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, me = 0, p = 0, *ponteiro;
    scanf("%d", &n);

    int *x;
    x = (int *) malloc(n * sizeof(int));

    if (x == NULL) {
        return 1;
    }
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    me = *x; 

    for (ponteiro = x; ponteiro < x + n; ponteiro++) {
        if (*ponteiro <= me) {
            me = *ponteiro;
            p = ponteiro - x;
        }
    }

    printf("Menor valor: %d\n", me);
    printf("Posicao: %d\n", p);

    free(x);

    return 0;
}