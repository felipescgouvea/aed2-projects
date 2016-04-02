#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int TChave;
typedef struct {
    TChave chave;
} TItem;

void preenche(TItem *A, int tam){
    srand(time(NULL));
    int i;
    for(i=0; i < tam; i ++){
            scanf("%d", &A[i].chave);
    }
}

void imprime(TItem *A, int tam){
    int i;
    for (i=0; i<tam; i++) printf("%d ", A[i].chave);
    printf("\n");
}

void conta_registro(TItem *A, TItem *B, int tam_a, int tam_b){
    int i,j;
    int troca_parcial = 0
        , troca_total = 0;
    int menor_tam, maior_tam;
    if (tam_a<tam_b) {
        menor_tam = tam_a;
        maior_tam = tam_b;
        remove_duplicata(A, tam_a);
    }
    else {
        menor_tam = tam_b;
        maior_tam = tam_a;
        remove_duplicata(B, tam_b);

    }

    troca_total = menor_tam;

    for(i=0; i<menor_tam-1; i++){
        while(A[i].chave == -1) i++;
        printf("%d ", i);
        for(j=0; j<maior_tam;j++){
            if(A[i].chave == B[j].chave){
                troca_total--;
            }
        }
    }
    printf("%d", troca_total);
}

void remove_duplicata(TItem *A, int tam){

    int i;
    for (i=0;i<tam-1; i++){
        if(A[i].chave == A[i+1].chave) A[i].chave = -1;
    }
}
int main()
{
    TItem *A,*B;
    int tam_a, tam_b;
    //scanf("%d", &tam_a);
    //scanf("%d", &tam_b);
    tam_a = 10;
    tam_b = 9;
    A = (TItem*)malloc(tam_a * sizeof(TItem));
    B = (TItem*)malloc(tam_b * sizeof(TItem));

    A[0].chave = 1;
    A[1].chave = 1;
    A[2].chave = 2;
    A[3].chave = 3;
    A[4].chave = 5;
    A[5].chave = 7;
    A[6].chave = 8;
    A[7].chave = 8;
    A[8].chave = 9;
    A[9].chave = 15;

    B[0].chave = 2;
    B[1].chave = 2;
    B[2].chave = 2;
    B[3].chave = 3;
    B[4].chave = 4;
    B[5].chave = 6;
    B[6].chave = 10;
    B[7].chave= 11;
    B[8].chave = 11;
    //preenche(A,tam_a);
    //preenche(B,tam_b);


    imprime(A,tam_a);
    imprime(B,tam_b);
    conta_registro(A,B,tam_a,tam_b);


}
