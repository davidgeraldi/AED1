#include <stdio.h>
#include <string.h>

int verificar(char *texto) {
    int aberto = 0;
    texto[strcspn(texto, "\n")] = 0;
    
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '(') { aberto++; }
        else if (texto[i] == ')') { aberto--; }
        if (aberto < 0) { return -1; }
    }
    return aberto;
}

int main() {

    char expressao[1001], *texto;
    int verificador;
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        texto = expressao;
        verificador = verificar (texto);
        if (verificador == 0) { printf ("correct\n"); }
        else { printf ("incorrect\n"); }
    }

    return 0;
}