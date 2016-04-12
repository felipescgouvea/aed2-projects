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
            printf("Elemento existente!!!! \n");

		}
	}
}
void RemoveABB (TArvBin *aux, TItem item){
    printf("removendo...\n");
    if((*aux) == NULL) return;

    if(DeletaNo(&(*aux)) == 1) {
        printf("deletou!\n");
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
int DeletaNo(TArvBin *arv, TItem item){
    if(item.Chave == (*arv)->Item.Chave){
        printf("encontrou o no a ser deletado\n");
        return CONTEM;
    }
    else {
        printf("ainda não...\n");
        return NAO_CONTEM;
    }
}


int filho_existente(TArvBin arv){
    if(arv->dir == NULL) return ESQ;
    else return DIR;
}
void imprime (TArvBin arv){
    if(arv == NULL) {
        return;
    }

    //printf("(C");
    printf("%d ",arv->Item.Chave);

    imprime(arv->esq);
    imprime(arv->dir);
    //printf(")");

}

int PesquisaABB(TArvBin *arv, TItem item){
    if((*arv) == NULL) return NAO_CONTEM;
    if((*arv)->Item.Chave == item.Chave){
        printf("Encontrou a chave!\n");
        //RemoveABB(&(*arv), item);
        return CONTEM;
    }
    if(item.Chave > (*arv)->Item.Chave){
        PesquisaABB(&(*arv)->dir, item);
    }
    else{
        PesquisaABB(&(*arv)->dir, item);
    }
}

int QuantidadeNumeros(TArvBin arv){
    if(qtd_filhos(arv) == 0) return 1;
    else{
        return 1 + QuantidadeNumeros(arv->dir);
        return 1 + QuantidadeNumeros(arv->esq);
    }
}
int main()
{
    TArvBin abb;
    Inicializa(&abb);
    TItem novo;
    while (novo.Chave != -1){
        printf("Entre com o numero\n");
        scanf("%d", &novo.Chave);
        if(novo.Chave == -1)break;
        InsereABB(&abb, novo);
    }
    //printf("erro");
    imprime(abb);
    scanf("%d", &novo.Chave);
    if (PesquisaABB(&abb, novo) == NAO_CONTEM) InsereABB(&abb,novo);
    else RemoveABB(&abb,novo);
    printf("%d", QuantidadeNumeros(abb));
     imprime(abb);

    return 0;
}

