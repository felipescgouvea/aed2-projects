#include <stdio.h>
#include <stdlib.h>
typedef struct TItem{
    int chave;
}TItem;
void quickSort(int seq[], int esq, int dir){
    int pivo, aux;
    int i,j;
    pivo = seq[0];
    i=esq;
    j=dir;

    while ( i < j){

            while (pivo > seq[i]){
                i++;
            }

            while (seq[j] > pivo){
                j--;
            }

            if (i<=j){
                aux = seq[j];
                seq[j] = seq[i];
                seq[i] = aux;
                i++;
                j--;
            }
    }
    if (j > esq) quickSort(seq, esq, j);
    if (i < dir) quickSort(seq,i,dir);

}
void imprime(int a[], int fim){
    int i;
    for (i = 0; i < fim; i++) printf("%d ", a[i]);
}
void preenche(int a[], int fim){
    int i;
    for(i=0;i<fim;i++) scanf("%d", &a[i]);
}
int main(){
    int tam;
    scanf("%d", &tam);

    int *seq[tam];
    preenche(seq,tam);
    quickSort(seq,0,tam-1);
    imprime(seq,tam);


    return 0;
}
