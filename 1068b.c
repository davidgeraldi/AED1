#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expressao {
    char caractere;
    struct expressao *seg;
} expressao;

int EstaVazia (expressao *topoDaPilha) {
    return topoDaPilha == NULL;
}
void Inserir (expressao **topoDaPilha, char c) {
    expressao *novocaractere = (expressao*) malloc (sizeof (expressao));
    if (novocaractere == NULL) { return; }
    novocaractere->caractere = c;
    novocaractere->seg = *topoDaPilha;
    *topoDaPilha = novocaractere;
}
void Remover (expressao **topoDaPilha) {
    expressao *lixo = *topoDaPilha;
    *topoDaPilha = (*topoDaPilha)->seg;
    free (lixo);
}
void LiberarPilha (expressao **topoDaPilha) {
    while (!EstaVazia (*topoDaPilha)) {
        Remover (topoDaPilha); 
    }
}

int verificar (char *texto) {
    texto [strcspn (texto, "\n")] = 0;
    expressao *minhaPilha = NULL;
    int verifica = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '(') {
            Inserir (&minhaPilha, '(');
        }
        else if (texto[i] == ')') {
            if (EstaVazia (minhaPilha)) {
                verifica = -1;
                break;
            } 
            else { Remover (&minhaPilha); }
        }
    }

    if (verifica == 0 && !EstaVazia (minhaPilha)) { verifica = -1; }

    LiberarPilha (&minhaPilha);
    
    return verifica;
}

int main() {

    char expressao [1001], *texto;
    int verificador;

    while (fgets (expressao, sizeof (expressao), stdin) != NULL) {
        texto = expressao;
        verificador = verificar (texto);
        if (verificador == 0) { printf ("correct\n"); }
        else { printf ("incorrect\n"); }
    }
    return 0;
}