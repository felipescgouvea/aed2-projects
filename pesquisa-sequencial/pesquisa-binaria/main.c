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
    TDicionario aux = (*D)->prox;
	//printf("%d\n", novo.Chave);
	if(aux->Item.Chave == NULL) {
        (*D) = CriaItem(novo);
	}
	if (aux->Item.Chave < novo.Chave){
        InsereDicionario(&(*D)->prox, novo);
	}
	else {
        (*D)->prox = CriaItem(novo);
        (*D)->prox->prox = aux;3
	}



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
