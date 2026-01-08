#include <stdio.h>
#include <string.h>

int verificar (char *texto) {
    texto [strcspn(texto, "\n")] = 0;

    int aberto = 0, cont = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '<') {
            aberto++;
        }
        else if (texto[i] == '>') {
            if (aberto > 0) {
                cont++;
                aberto--;
            }
        }
    }
    return cont;
}

int main () {

    int n;
    scanf ("%d", &n);
    getchar();

    char expressao [1001], *texto;

    for (int i = 0; i < n; i++) {
        if (fgets (expressao, sizeof (expressao), stdin) == NULL) break;
        texto = expressao; 
        int verificador = verificar (texto);
        printf ("%d\n", verificador);
    }

    return 0;
}