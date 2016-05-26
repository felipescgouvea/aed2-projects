/*############################################
	Felipe Gouvêa, 92399
	TAD Arvore Trie

############################################*/
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

int retornaDigito(TChave x, int digito) {
	return ((x >> digito) & 1);
}
TArvBin *Cria(TItem novo) {
	TNo *pRaiz;
	(pRaiz) = (TArvBin)malloc(sizeof(TNo));
	(pRaiz)->Dir = NULL;
	(pRaiz)->Esq = NULL;
	(pRaiz)->Item = novo;

	return pRaiz;

}

TArvBin *CriaNoExterno(int digito, TArvBin *novo, TArvBin *velho) {
	TItem nulo;
	nulo.Chave = -1;
	TArvBin interno = Cria(nulo);
	int digito_novo = retornaDigito((*novo)->Item.Chave, digito);
	int digito_arvore = retornaDigito((*velho)->Item.Chave, digito);

	if(digito_novo == digito_arvore){
		if(digito_novo == 1){
			(interno)->Dir = CriaNoExterno(digito+1, novo, velho);
		}
		else (interno)->Esq = CriaNoExterno(digito+1, novo, velho);
	}
	else{
		if(digito_novo == 1){
			(interno)->Dir = *novo;
			(interno)->Esq = *velho;
		}
		else{
			(interno)->Esq = *novo;
			(interno)->Dir = *velho;
		}
	}

	//printf("FOI ");
	return interno;
}


TArvBin PesquisaRecursiva(TArvBin Raiz, TChave x, int digito){
	if(Raiz == NULL) return NULL;
	else{
		if(Raiz->Dir == NULL && Raiz->Esq == NULL){
			if(x == Raiz->Item.Chave){
				return Raiz;
			}
			else return NULL;
		}
		else{
			if(retornaDigito(x,digito) == 1) PesquisaRecursiva(Raiz->Dir, x, digito+1);
			else PesquisaRecursiva(Raiz->Esq, x , digito+1);
		}
	}
}
TArvBin Pesquisa(TArvBin Raiz, TChave x) {
	// Implemente o seu metodo aqui!
	TArvBin result = PesquisaRecursiva(Raiz, x, 0);
	return result;
}


void Insere(TArvBin *pRaiz, TItem x) {
	InsereRecursivo(pRaiz, x, 0);

}
int InsereRecursivo(TArvBin *pRaiz, TItem x, int digito) {
	// Implemente o seu metodo aqui!
	int digito_arvore;
	int digito_novo;
   	digito_novo = retornaDigito(x.Chave, digito);
	//digito_arvore = retornaDigito((*pRaiz)->Item.Chave, digito);
	//printf("erro");
	if( (*pRaiz) == NULL) {
		//rintf("%d", (*pRaiz)->Item.Chave);
		//printf("ERRO");
		(*pRaiz) = 	Cria(x);
	} else {
		if ( (*pRaiz)->Dir == NULL && (*pRaiz)->Esq == NULL ) {
            if(x.Chave != (*pRaiz)->Item.Chave){
                TArvBin novo = Cria(x);
                (*pRaiz) = CriaNoExterno(digito, &novo, pRaiz);
            }


			//printf("Dividiu %d\n", (*pRaiz)->Item.Chave);

			return 0;
		} else {
			if(digito_novo == 1) {
				InsereRecursivo(&(*pRaiz)->Dir, x, digito+1);
			} else InsereRecursivo(&(*pRaiz)->Esq, x, digito+1);
		}


	}

	return 0;
}



int Retira(TArvBin *pRaiz, TChave x) {
	// Implemente o seu metodo aqui!
	RetiraRecursivo(pRaiz, x, 0);
}
int RetiraRecursivo(TArvBin *pRaiz, TChave x, int digito) {
	// Implemente o seu metodo aqui!
	//printf("p RAIZ %d\n", (*pRaiz)->Item.Chave);
	if(*pRaiz == NULL) return NULL;
	else{
		if((*pRaiz)->Dir == NULL && (*pRaiz)->Esq == NULL){
			//printf("externo\n");
			if(x == (*pRaiz)->Item.Chave){
				TArvBin aux = (*pRaiz);
				(*pRaiz) = NULL;
				free(aux);

				return 2;
			}
			else return 0;

		}
		else{
			//printf("interno\n");
			if(retornaDigito(x,digito) == 1) {
				//printf("dir\n");
				int result = RetiraRecursivo(&(*pRaiz)->Dir, x, digito+1);
				if(result == 2){
				//	printf("removeu");
					if((*pRaiz)->Dir == NULL){
                        if((*pRaiz)->Esq->Esq == NULL && (*pRaiz)->Esq->Dir == NULL){
                            //printf("no %d, ", (*pRaiz)->Item.Chave);
                            TArvBin aux = (*pRaiz);
                            (*pRaiz) = (*pRaiz)->Esq;
                            free (aux);
                            return 1;
                        }
                        else return 0;
					}
					else return 0;
				}
				else if(result == 1){
                        if((*pRaiz)->Dir == NULL){
                            //printf("no %d, ", (*pRaiz)->Item.Chave);
                            TArvBin aux = (*pRaiz);
                            (*pRaiz) = (*pRaiz)->Esq;
                            free (aux);
                            return 1;
                        }
                        else return 0;
				}
				else return 0;
			}
			else{
				//printf("esq\n");
				int result = RetiraRecursivo(&(*pRaiz)->Esq, x, digito+1);
				if(result == 2){
					//printf("removeu");
					if((*pRaiz)->Esq == NULL){
						if((*pRaiz)->Dir->Esq == NULL && (*pRaiz)->Dir->Dir == NULL){
                            //printf("no %d, ", (*pRaiz)->Item.Chave);
                            TArvBin aux = (*pRaiz);
                            (*pRaiz) = (*pRaiz)->Esq;
                            free (aux);
                            return 1;
						}
						else return 0;
					}
					else return 0;
				}
				else if(result == 1){
                        if((*pRaiz)->Esq == NULL){
                            //printf("no %d, ", (*pRaiz)->Item.Chave);
                            TArvBin aux = (*pRaiz);
                            (*pRaiz) = (*pRaiz)->Esq;
                            free (aux);
                            return 1;
                        }
                        else return 0;
                }
				else return 0;
			}
			//printf("bug");
		}
	}
}

void Imprime(TArvBin pRaiz) {
	if (pRaiz == NULL) printf("()");
	else{
		if(pRaiz->Item.Chave == -1) printf("(");
		else printf("(C%d", pRaiz->Item.Chave);
		Imprime(pRaiz->Esq);
		Imprime(pRaiz->Dir);
		printf(")");
	}



}
int main() {
	// Implemente o seu programa principal aqui!
	int qtd_num;
	int tam;
	scanf("%d", &qtd_num);
	int cont;
	TItem num;

	TArvBin raiz;
	raiz = NULL;

	for(cont = 0; cont < qtd_num ; cont++) {
		scanf("%d", &num.Chave);
		Insere(&raiz, num);
	}

	scanf("%d", &num.Chave);
	if(Pesquisa(raiz, num.Chave) != NULL){
		//printf("Retirou %d", num.Chave);
		Retira(&raiz, num.Chave);
	}
	else Insere(&raiz, num);

	Imprime(raiz);

	/*
	int teste = 5;
	printf("%d %d %d %d", retornaDigito(teste,0),retornaDigito(teste,1),retornaDigito(teste,2),retornaDigito(teste,3));
	*/
	return 0;
}
