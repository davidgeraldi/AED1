#include <stdio.h>
#include <stdlib.h>
/*Estrutura de uma celula:*/
struct cel {
    int conteudo;
    struct cel *seg; //seguinte
};
/*definindo tipo celula:*/
typedef struct cel celula;

/*imprimir lista sem cabeça:*/
void ImprimeSemCabeca (celula *lst) {
    celula *p;
    for(p=lst; p!=NULL; p->seg){
        printf("%d\n", p->conteudo);
    }
}

/*imprimir lista com cabeça:*/
void ImprimeComCabeca (celula *lst) {
    celula *p;
    for(p = lst->seg; p!=NULL; p->seg){
        printf("%d\n", p->conteudo);
    }
}

/*busca de um vaçor x em alguma celula da lista e retorna a celula:*/
celula *Buscar (int x, celula *lst){
    celula *p;
    p = lst->seg;
    while (p!=NULL && p->conteudo!=x) {
        p = p->seg;
    }
    return p;
}

/*versao recursiva de buscar elemento x:*/
celula *Buscar (int x, celula *lst) {
    if (lst->seg == NULL) {return NULL;}
    if (lst->seg->conteudo == x) {return lst->seg;}
    return Buscar(x, lst->seg);
}

/*remover celula sucessor de p:*/
void Remover (celula *p) {
    celula *lixo;
    lixo = p->seg; /*lixo recebe a celula sucessora de p*/
    p->seg = lixo->seg; /*depois de p recebe o resto da lista que foi salva em lixo, depois da celula que esta em lixo*/
    free (lixo);
}

/*inserir nova celula com valor y após p:*/
void Inserir (int y, celula *p) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = y;
    nova->seg = p->seg; /*prox. celula de nova recebe a lista toda após p*/
    p->seg = nova; /*sucessor de p recebe a celula nova*/
}

/*buscar valor x na lista com cabeça e remover celula q contem:*/
void BuscarERemover (int x, celula *lst) {
    celula *p, *q;
    p = lst;
    q = lst->seg;
    while (q != NULL && q != x) {
        p = q;
        q = q->seg;
    }
    if(q != NULL){
        p->seg = q->seg; /*prox. celula depois de p recebe a proxima depois de q*/
        free (q); /*libera o espaço de memoria de q, que era a celula que continha x*/
    }
    
}

/*recebe lista c/ cabeça e insere celula cm valor y antes da celula com valor x*/
void BuscarEInserir (int x, int y, celula *lst) {
    celula *p, *q, *nova;
    p = lst;
    q = lst->seg;
    nova = malloc (sizeof(celula));
    nova->conteudo = y;
    while (q != NULL && q->conteudo != x) {
        p = q;
        q = q->seg;
    }
    nova->seg = q;
    p->seg = nova;
}