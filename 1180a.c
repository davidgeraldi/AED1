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