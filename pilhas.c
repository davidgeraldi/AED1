/*pilhas são como pilhas na vida real, pode ir empilando elementos
pilhas são do tipo LiFo - Last-in, First-Out */

/*declaração da celula*/
struct cel {
    int dado;
    struct cel *seg; // ponteiro para a próxima celula
};

typedef struct cel celula;

/*pilhas tem dois comandos, push e pop, que são empilhar e desempilhar respectivamente
e sempre quem é alterado é o topo*/

//Empilhar(PUSH) elemento:
void Empilhar (int novoDado, celula *pilha) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->dado = novoDado;
    nova->seg = pilha->seg;
    pilha->seg = nova;
}

//Desempilhar(POP) e retorna o elemeto retirado:
int Desempilhar (celula *pilha) {
    celula *topo;
    int dadoRetirado;
    topo = pilha->seg;
    dadoRetirado = topo->dado;
    pilha->seg = topo->seg;
    free(topo);
    return dadoRetirado;
}