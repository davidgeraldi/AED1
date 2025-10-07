#include <stdio.h>

int main() {
    int x = 10;        // variável normal
    int *p;            // ponteiro para inteiro

    p = &x;            // p recebe o endereço de x

    int a[5], i, *n;

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", (void*)&x);
    printf("Valor de p (endereco guardado): %p\n", (void*)p);
    printf("Valor apontado por p (*p): %d\n", *p);

    // Alterando o valor de x através do ponteiro
    *p = 20;

    printf("\nDepois de alterar via ponteiro:\n");
    printf("Valor de x: %d\n", x);
    printf("Valor apontado por p (*p): %d\n", *p);

    printf("\n\nmaneira de preencher vetor de forma mais eficiente:\n");
    n=a;
    for(i=0;i<5;i++){
        *n=0;
        n++;
        printf("%d ", a[i]);
    }
    
    return 0;
}


