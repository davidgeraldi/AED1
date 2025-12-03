#include <stdio.h>

int main() {
    int n, me = 0, p = 0;
    scanf("%d", &n);
    int x[n];
    for(int i = 0; i < n; i++){
        scanf("%d ", &x[i]);
        
    }
    me = x[0];
    for(int j = 0; j < n; j++){
        if(x[j] <= me){
            me = x[j];
            p = j;
        }
    }
    printf("Menor valor: %d\n", me);
    printf("Posicao: %d\n", p);
    
    return 0;
}