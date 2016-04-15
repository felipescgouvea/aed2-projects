#include <stdio.h>
#include <stdlib.h>
#define DIR 1
#define ESQ 0
#define NAO_CONTEM 0
#define CONTEM 1
typedef int TChave;

typedef struct {
   TChave Chave;
}TItem;

typedef struct SNo *TArvBin;

typedef struct SNo{
   TItem Item;
   TArvBin esq, dir;
}TNo;


void Inicializa(TArvBin *td){
        (*td) = NULL;
    }

TArvBin CriaNo(TItem novo){

    TArvBin no = (TArvBin)malloc(sizeof(TNo));
    no->Item = novo;
    no->dir = NULL;
    no->esq = NULL;
    return no;
}
void InsereABB (TArvBin *aux, TItem novo){
    //printf("%d\n", novo.Chave);
    if(*aux == NULL) {
        *aux = CriaNo(novo);
        return;
    }
    if (novo.Chave < (*aux)->Item.Chave) {
            InsereABB(&(*aux)->esq, novo);
    }
    else {
        if (novo.Chave > (*aux)->Item.Chave) {
            InsereABB(&(*aux)->dir, novo);
        }
        else{
            //printf("Elemento existente!!!! \n");

        }
    }
}
void RemoveABB (TArvBin *aux, TItem item){
    //printf("removendo...\n");
    if((*aux) == NULL) return;

    if((*aux)->Item.Chave == item.Chave) {
        DeletaNo(&(*aux), item);
        //printf("deletou!\n");
        return;
    }

    if(item.Chave > (*aux)->Item.Chave){
        RemoveABB(&(*aux)->dir, item);
    }
    else{
        RemoveABB(&(*aux)->esq, item);
    }


}
int qtd_filhos(TArvBin arv){
    int qtd = 0;
    if(arv->dir != NULL) qtd++;
    if(arv->esq != NULL) qtd++;
    return qtd;
}
void DeletaNo(TArvBin *arv, TItem item){

        TArvBin aux;
        TArvBin aux2;
        //printf("%d\n", (*arv)->Item.Chave);
        if(qtd_filhos(*arv) < 2){
            if((*arv)->dir == NULL){

                aux = (*arv);
                (*arv) = (*arv)->esq;
                free(aux);
                //retira esq
            }
            else{
                aux = (*arv);
                (*arv) = (*arv)->dir;
                free(aux);
                //retira dir
            }
        }
        else {
            //printf("poxa que legal\n");
            aux = (*arv)->dir;
            while ( aux->esq != NULL){
                aux = aux->esq;
            }

            (*arv)->Item = aux->Item;
            RemoveABB(&(*arv)->dir, aux->Item);
            RemoveABB(&(*arv)->esq, aux->Item);
            //DeletaNo(*arv, aux->Item);

   //         printf("%d\n",(*arv)->Item);


            //printf("%d", (*arv)->Item.Chave);
        }


}


void imprime (TArvBin arv){
    if(arv == NULL) {
        return;
    }

    //printf("(C");
    printf("%d ",arv->Item.Chave);
    if(arv->esq != NULL){
        imprime(arv->esq);

    }
    if(arv->dir != NULL){
        imprime(arv->dir);

    }
    //printf(")");

}

int PesquisaABB(TArvBin *arv, TItem item){
    //printf("%d ", (*arv)->Item.Chave);
    if(*arv == NULL) {
        //printf("Nao encontrou\n");
        InsereABB(&(*arv), item);
        return NAO_CONTEM;
    }
    if((*arv)->Item.Chave == item.Chave){
        //printf("Encontrou a chave!\n");
        RemoveABB(&(*arv), item);
        return CONTEM;
    }
    if(item.Chave > (*arv)->Item.Chave){
        PesquisaABB(&(*arv)->dir, item);
    }
    else{
        PesquisaABB(&(*arv)->esq, item);
    }
}

int QuantidadeNos(TArvBin arv){
    int X,Y;
    if(arv == NULL) return 0;
    else{
        X =  QuantidadeNos(arv->dir);
        Y =  QuantidadeNos(arv->esq);
    }
    return X + Y + 1;
}
int main()
{
    TArvBin abb;
    Inicializa(&abb);
    TItem novo;
    while (novo.Chave != -1){
        //printf("Entre com o numero\n");
        scanf("%d", &novo.Chave);
        if(novo.Chave == -1)break;
        InsereABB(&abb, novo);
        //imprime(abb);
    }
    //imprime(abb);
    scanf("\n%d", &novo.Chave);
    //printf("%d\n", QuantidadeNos(abb));
    PesquisaABB(&abb, novo);
    printf("%d\n", QuantidadeNos(abb));


    //printf("%d\n", QuantidadeNumeros(abb));
    //imprime(abb);

    return 0;
}
