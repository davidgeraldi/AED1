/*Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e a sua posição dentro do vetor, mostrando esta informação.

Entrada
A primeira linha de entrada contem um único inteiro N (1 < N < 1000), indicando o número de elementos que deverão ser lidos em seguida para o vetor X[N] de inteiros. A segunda linha contém cada um dos N valores, separados por um espaço. Vale lembrar que nenhuma entrada haverá números repetidos.

Saída
A primeira linha apresenta a mensagem “Menor valor:” seguida de um espaço e do menor valor lido na entrada. A segunda linha apresenta a mensagem “Posicao:” seguido de um espaço e da posição do vetor na qual se encontra o menor valor lido, lembrando que o vetor inicia na posição zero.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n, x[1000], i, *p, maior, menor, posicaoMaior, posicaoMenor;

    do{
        printf("Tamanho vetor: ");
        scanf("%d", &n);
    }while(n<1 || n>1000);

    srand((unsigned)time(NULL)); //incializa o gerador de numeros aleatorios
    printf("\n\n");
    p=x;
    for(i=0; i<n;i++){
        *p=rand() % 500+1;
        printf("%d ", *p);
        if(i==0){maior=menor=*p;}
        else{
            if(*p>maior){
                maior=*p;
                posicaoMaior=i;
            }
            else if(*p<menor){
                menor=*p;
                posicaoMenor=i;
            }
        }
        p++;
    }

    printf("\n\nMenor valor: %d Posicao: %d\nMaior valor: %d  Posicao: %d", menor, posicaoMenor, maior, posicaoMaior);







    return 0;
}