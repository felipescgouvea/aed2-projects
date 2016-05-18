#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

typedef struct SNo *TArvBin;

typedef struct SNo {
	TItem Item;
	TArvBin Esq, Dir;
} TNo;

int retornaDigito(TChave x, int digito){
	return ((x >> digito) & 1);
}

TArvBin Pesquisa(TArvBin Raiz, TChave x){
	// Implemente o seu metodo aqui!
}

int Insere(TArvBin *pRaiz, TItem x){
	// Implemente o seu metodo aqui!
	if( (*pRaiz) != NULL){
		//rintf("%d", (*pRaiz)->Item.Chave);
		//printf("ERRO");
		(*pRaiz) = (TArvBin)malloc(sizeof(TNo));
		(*pRaiz)->Dir = NULL;
		(*pRaiz)->Esq = NULL;
		(*pRaiz)->Item = x;
	}
}

int Retira(TArvBin *pRaiz, TChave x){
	// Implemente o seu metodo aqui!
}
void Imprime(TArvBin pRaiz){
	if(pRaiz != NULL){
		printf("%d", pRaiz->Item.Chave);
		Imprime(pRaiz->Esq);
		Imprime(pRaiz->Dir);
	}

}
int main()
{
	// Implemente o seu programa principal aqui!
    int qtd_num;
    int tam;
    scanf("%d", &qtd_num);
    int cont;
    TItem num;

    TArvBin raiz;
    //Imprime(tab);

    for(cont = 0; cont < qtd_num ; cont++){
        scanf("%d", &num.Chave);
        Insere(&raiz, num);
    }
    /*
    //printf("%d",tab.Lista[num % tab.tam].Inicio->Item.Chave);
    scanf("%d", &num);
    if(PesquisaHash(&tab, num) == ENCONTROU){
        RemoveHash(&tab,num);
    }
    else InsereHash(&tab,num);
    */
    Imprime(raiz);
	return 0;
}
