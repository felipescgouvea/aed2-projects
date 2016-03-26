    /*
    Felipe Gouvea, 92399
    Algoritmo para ordernar uma sequencia com o método quick
    O quick se utiliza da estratégia de divisão e conquista.
    A ordenação ocorre em ordem O(n*log n)
    */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int chave;
}TItem;
/*
Particiona escolhe o ultimo elemento e o coloca no índice em que os menores estejam a esquerda
e os maiores elementos estejam a direita
*/
int particiona(TItem seq[], int esq, int dir){

    int pivo, aux;
    int i,j;
    pivo = seq[dir].chave;

    i=esq-1;
    j=esq;


    while ( j < dir+1){
            if ( pivo < seq[j].chave){
                j++;
                }
            else {
                aux = seq[i+1].chave;
                seq[i+1].chave = seq[j].chave;
                seq[j].chave = aux;
                i++;
                j++;
            }
    }
    return i;
}

/*
quickSort coloca um arranjo em ordem crescente, particionando até que tenha apenas 1 elemento.
*/
void quickSort(TItem seq[], int esq, int dir){

    if (esq == dir) return;

    int pivo;
    pivo = seq[dir].chave;

    int meio = particiona(seq,esq,dir);
    if (esq < dir) {
        quickSort(seq, esq, meio-1);
        quickSort(seq, meio+1, dir);
        }
}

void imprime(TItem seq[], int fim){
    int i;
    for (i = 0; i < fim; i++) printf("%d ", seq[i].chave);
    printf("\n");
}

int main(){
    int tam,i;
    scanf("%d", &tam);

    //int *seq[5] = {1,3,2,0,5};
    //int *seq[5] = {5,4,3,2,1};
    //int *seq[] = {25,40,55,20,44,35,38,99,10,65,50};
    TItem *seq;
    seq = (TItem*)malloc(tam*sizeof(TItem));



    for(i=0;i<tam;i++) {
        scanf("%d", &seq[i]);

    }
    particiona(seq,0,tam -1);
    imprime(seq,tam);
    quickSort(seq, 0, tam -1);
    imprime(seq,tam);


    return 0;
}
