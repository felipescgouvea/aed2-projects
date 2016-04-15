/*
    Felipe Gouvêa, 92399
    Algorítmo para busca sequencial dado uma entrada com N elementos
*/

#include <stdio.h>
#include <stdlib.h>
typedef int TChave;

typedef struct{
    TChave Chave;
}TItem;

typedef struct SNo *TDicionario;

typedef struct SNo{
   TItem Item;
   TDicionario prox;
}TNo;




void inicializa(TDicionario *D){
//    (*D)->Item = NULL;
    (*D) = NULL;

}
TDicionario CriaItem(TItem novo){

    TDicionario no = (TDicionario)malloc(sizeof(TNo));
    no->Item = novo;
    no->prox = NULL;
    return no;
}
void InsereDicionario(TDicionario *D, TItem novo){
	//printf("%d\n", novo.Chave);
	if(*D == NULL) {
        (*D) = CriaItem(novo);
	}
	else InsereDicionario(&(*D)->prox, novo);

}

void RemoveDicionario(TDicionario *D, TItem novo){
    if ((*D)->prox == NULL) (*D) = NULL;
    else {
        TDicionario aux;
        aux = (*D);
        (*D) = (*D)->prox;
        free(aux);
    }
}
void PesquisaDicionario(TDicionario *D, TItem novo){
    if((*D) == NULL){
        //printf("Nao encontrou!");
        InsereDicionario(&(*D), novo);
        return;
    }
    if((*D)->Item.Chave == novo.Chave){
        //printf("Encontrou\n");
        RemoveDicionario(&(*D), novo);
        return;
    }
    PesquisaDicionario(&(*D)->prox, novo);
}
void imprime (TDicionario D){
    if(D == NULL) {
        return;
    }    //printf("(C");
    printf("%d ",D->Item.Chave);

    imprime(D->prox);

    //printf(")");

}
int tamanho(TDicionario D){
    int tam = 0;
    while (D != NULL){
        D = D->prox;
        tam++;
    }
    return tam;
}
int main()
{
    TDicionario D;
    inicializa(&D);

    TItem novo;
    while (novo.Chave != -1){
        //printf("Entre com o numero\n");
        scanf("%d", &novo.Chave);
        if(novo.Chave == -1)break;
        InsereDicionario(&D, novo);
    }
    scanf("%d", &novo.Chave);
    PesquisaDicionario(&D, novo);
    //imprime(D);
    printf("%d", tamanho(D));
    return 0;
}
