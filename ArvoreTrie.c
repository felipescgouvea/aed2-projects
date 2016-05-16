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
	if( *pRaiz == NULL){
		printf("ERRO");
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
		//Imprime(pRaiz->Dir);
	}
	
}
int main()
{
	// Implemente o seu programa principal aqui!
	TArvBin raiz;
	TItem x;
	x.Chave = 5;
	Insere(&raiz,x);
	printf("%d", raiz->Item.Chave);
	//Imprime(raiz);
	return 0;
}
