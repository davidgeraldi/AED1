#include <stdio.h>

int main() {
    int n, menor = 0, p = 0;
    scanf ("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);   
    }
    menor = x[0];
    for (int j = 1; j < n; j++) {
        if(x[j] <= menor){
            menor = x[j];
            p = j;
        }
    }
    printf ("Menor valor: %d\n", menor);
    printf ("Posicao: %d\n", p);
    
    return 0;
}