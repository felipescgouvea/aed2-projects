#include <stdio.h>
#include <stdlib.h>

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
            InsereABB((*aux)->esq, novo);
    }
    else {
        if (novo.Chave > (*aux)->Item.Chave) {
            InsereABB((*aux)->dir, novo);
        }
		else{
            printf("Elemento existente!!!! \n");

		}
	}
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
    printf("erro");
    //imprime(abb);

    return 0;
}
