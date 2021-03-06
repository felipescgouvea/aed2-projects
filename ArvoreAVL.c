        /*
            Felipe Gouvea, 92399
            Algorítmo Arvore AVL com funções de inicialização, inserção, remoção e pesquisa.
        */

    #include <stdio.h>
    #include <stdlib.h>
    #define FALSE 0
    #define TRUE 1
    #define ESQ 0
    #define DIR 1
    #define DESBALANCEADA 0
    #define BALANCEADA 1
    #define INSERT 0
    #define REMOVE 1
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
        int fb;
    }TNo;
   ///printf("%d \n", arv->Item.Chave);
    //Balanceamento pós ordem, dir, esq, nó
    ///(C3(C2(C1()())())(C4()(C9(C5()(C8()()))())))

int Fator_Balanceamento(TArvBin arv){
    if(arv == NULL) return 0;
    return arv->fb;
}
int Verifica_AVL(TArvBin arv){
    int FB = Fator_Balanceamento(arv);
    if ((FB > 1 )|| (FB < -1)){
        return DESBALANCEADA;
    }
    else {
        Verifica_AVL(arv->esq);
        Verifica_AVL(arv->dir);
        return BALANCEADA;
    }

}
void Inicializa(TArvBin *td){
        (*td) = NULL;
    }
void imprime (TArvBin arv){
    if(arv == NULL) {
        printf("()");
        return;
    }

    printf("(C");
    printf("%d",arv->Item.Chave);

    imprime(arv->esq);
    imprime(arv->dir);
    printf(")");

}

void LL(TArvBin *A){
    TArvBin B =  (*A)->esq;
    if(B->fb == 0){
        (*A)->fb =1;
        B->fb = -1;
    }
    else{
        (*A)->fb = 0;
        B->fb = 0;
    }


    (*A)->esq = B->dir;
    B->dir = (*A);
    (*A) = B;
}
void RR(TArvBin *A){
    TArvBin B =  (*A)->dir;

    if(B->fb == 0){
        (*A)->fb = -1;
        B->fb = 1;
    }
    else{
        (*A)->fb = 0;
        B->fb = 0;
    }

    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A) = B;
}
void LR(TArvBin *A){

    TArvBin B =  (*A)->esq;
    TArvBin C = B->dir;

    B->dir = C->esq;
    C->esq = B;

    (*A)->esq = C->dir;
    C->dir = *A;
    if(Fator_Balanceamento(C) == -1){
        B->fb = 1;
    } else B->fb = 0;
    if(Fator_Balanceamento(C) == 1){
        (*A)->fb = -1;
    } else (*A)->fb = 0;
    C->fb = 0;
    (*A) = C;
}
void RL(TArvBin *A){

    TArvBin B = (*A)->dir;
    TArvBin C = B->esq;

    B->esq = C->dir;
    C->dir = B;

    (*A)->dir = C->esq;

    C->esq = (*A);
    if(Fator_Balanceamento(C) == -1){
        B->fb = 1;
    } else B->fb = 0;
    if(Fator_Balanceamento(C) == 1){
        (*A)->fb = -1;
    } else (*A)->fb = 0;
    C->fb = 0;
    (*A) = C;
}

int Balanca_Arv(TArvBin *A){
    if(*A != NULL){
    Balanca_Arv(&(*A)->dir);
    Balanca_Arv(&(*A)->esq);
//    printf("%d %d- ", ()->Item.Chave, Fator_Balanceamento(A));
    return Balanca_No(A);
    }

}
int Balanca_No(TArvBin *A){
    //printf("balançando no %d\n", (*A)->Item.Chave);
    int fb = Fator_Balanceamento(*A);
    int fb_dir = Fator_Balanceamento((*A)->dir);
    int fb_esq = Fator_Balanceamento((*A)->esq);
    //int fb = 2;
    //int fb_dir = 2;
    //int fb_esq = 1;
    if (fb > 1){
        //printf("ENTROU \n");
		if (fb_esq >= 0){
            //printf("LL\n");
            LL(&(*A));
        }
        else if (fb_esq < 0){
            //printf("LR\n");
            LR(&(*A));
        }

    }
    if (fb < -1){
        if (fb_dir <= 0){
           //printf("RR\n");
            RR(&(*A));
        }
        else if (fb_dir > 0){
            //printf("RL\n");
            RL(&(*A));
        }
    }

    return 0;
}
int qtd_filhos(TArvBin arv){
    int qtd = 0;
    if(arv->dir != NULL) qtd++;
    if(arv->esq != NULL) qtd++;
    return qtd;
}
TArvBin CriaNo(TItem novo){

    TArvBin no = (TArvBin)malloc(sizeof(TNo));
    no->Item = novo;
    no->dir = NULL;
    no->esq = NULL;
    no->fb = 0;
    return no;
}
int InsereAVL (TArvBin *aux, TItem novo){
    //printf("%d\n", novo.Chave);
    if(*aux == NULL) {
        *aux = CriaNo(novo);
        return 1;
    }

    int aumentou;

    if (novo.Chave < (*aux)->Item.Chave) {
            aumentou = InsereAVL(&(*aux)->esq, novo);
            //printf("fb %d\n", (*aux)->fb);
            if (aumentou == TRUE){
                //printf("aumentou esq\n");
                    if((*aux)->fb == -1){
						(*aux)->fb = 0;
						return 0;
                    }

                    if((*aux)->fb == 0){
						(*aux)->fb = 1;
						return 1;
                    }
                    if((*aux)->fb == 1){
						return !BalancaEsq(&(*aux));
                    }

            }
           else return FALSE;
           ///return (*aux)->fb;
           //printf("ALT = %d  NO = %d\n", (*aux)->alt,(*aux)->Item.Chave);

    }
    else {
        if (novo.Chave > (*aux)->Item.Chave) {
            aumentou = InsereAVL(&(*aux)->dir, novo);
            //printf("fb %d\n", (*aux)->fb);
            if (aumentou == TRUE){
                //printf("aumentou dir\n");
                    if((*aux)->fb == 1){
						(*aux)->fb = 0;
						return 0;
                    }
					if((*aux)->fb == 0){
						(*aux)->fb = -1;
						return 1;
                    }
					else if ((*aux)->fb == -1){
						return !BalancaDir(&(*aux));
                    }

            }
           else return FALSE;
        }
        else{
            return 0;
        }
    }
//    if ((*aux)->fb > 1 || (*aux)->fb < 1) printf("XABLAU\n");

}

int DeletaNo(TArvBin *arv, TItem item){
        TArvBin aux;
        TArvBin aux2;
        //printf("%d\n", (*arv)->Item.Chave);
        if(qtd_filhos(*arv) < 2){
            if((*arv)->dir == NULL){

                aux = (*arv);
                (*arv) = (*arv)->esq;
                free(aux);
                return TRUE;
            }
            else{
				 //retira dir
                aux = (*arv);
                (*arv) = (*arv)->dir;
                free(aux);
                return TRUE;
            }
        }
        else {
			int diminuiu;
            diminuiu = Substituto(&(*arv), &(*arv)->dir);
			//printf("diminuiu %d", diminuiu);
			//printf("FB = %d  NO = %d", (*arv)->fb, (*arv)->Item.Chave );

            if(diminuiu == TRUE){

				if((*arv)->fb == 1) {
                    return BalancaEsq(&(*arv));
				}
				if((*arv)->fb == 0){
					(*arv)->fb = 1;
					return 0;

				}
				if((*arv)->fb == -1){
					(*arv)->fb = 0;
					return 1;
				}
            }
            else return FALSE;
        }
}
int Substituto(TArvBin *arv, TArvBin *arv_dir){
	if((*arv_dir)->esq != NULL){
		int prox = Substituto(&(*arv), &(*arv_dir)->esq);
		if (prox == TRUE){
				if((*arv_dir)->fb == -1) {
					return BalancaDir(&(*arv_dir));
				}
				if((*arv_dir)->fb == 0){
					(*arv_dir)->fb = -1;
					return 0;
				}
				if((*arv_dir)->fb == 1){
					(*arv_dir)->fb = 0;
					return 1;
				}
		}
		else return FALSE;
	}
	else {
		(*arv)->Item = (*arv_dir)->Item;
		//*arv = *arv_dir;
		*arv_dir = (*arv_dir)->dir;
		return TRUE;

	}
}

int RemoveAVL (TArvBin *aux, TItem item){
    //printf("removendo...\n");
    if((*aux) == NULL) return 0;
	else if (item.Chave < (*aux)->Item.Chave){
        int result = RemoveAVL(&(*aux)->esq, item);
		if(result == TRUE){
				if((*aux)->fb == 1){
					(*aux)->fb = 0;
					return 1;
					}
				if((*aux)->fb == 0){
					(*aux)->fb = -1;
					return 0;
					}
                if((*aux)->fb == -1){
					return BalancaDir(&(*aux));
                }
		}
		else return FALSE;
	}
	else if (item.Chave > (*aux)->Item.Chave){
		if(RemoveAVL(&(*aux)->dir, item)){
				if((*aux)->fb == -1){
					(*aux)->fb = 0;
					return 1;
					}
				if((*aux)->fb == 0){
					(*aux)->fb = 1;
					return 0;
                }
				else if ((*aux)->fb == 1){
					return BalancaEsq(&(*aux));
                }

		}
		else return FALSE;

	}
	else {
		return DeletaNo(&(*aux), item);
	}
}

int PesquisaABB(TArvBin *arv, TItem item){
    //printf("%d ", (*arv)->Item.Chave);
    if(*arv == NULL) {
        //printf("Nao encontrou\n");
        //InsereAVL(&(*arv), item);
        return NAO_CONTEM;
    }
    if((*arv)->Item.Chave == item.Chave){
        //printf("Encontrou a chave!\n");
        //RemoveAVL(&(*arv), item);
        return CONTEM;
    }
    if(item.Chave > (*arv)->Item.Chave){
        PesquisaABB(&(*arv)->dir, item);
    }
    else{
        PesquisaABB(&(*arv)->esq, item);
    }
}


void ImprimeFB(TArvBin arv){
    if(arv == NULL) {
        //printf("");
        return;
    }
    printf("NO = %d  FB = %d\n" ,arv->Item.Chave,arv->fb);
     ImprimeFB(arv->esq);
     ImprimeFB(arv->dir);
}
int BalancaEsq(TArvBin *aux){
	int fb = Fator_Balanceamento((*aux)->esq);
	if(fb > 0){
		LL(&(*aux));
		return 1;
	}
	if(fb < 0){
		LR(&(*aux));
		return 1;
	}
	else {
		LL(&(*aux));
		return 0;
	}
}
int BalancaDir(TArvBin *aux){
	int fb = Fator_Balanceamento((*aux)->dir);
	if(fb > 0){
		RL(&(*aux));
		return 1;
	}
	if(fb < 0){
		RR(&(*aux));
		return 1;
	}
	else {
		LL(&(*aux));
		return 0;
	}
}
int main(){
        TArvBin td;
        TArvBin avl;
        Inicializa(&avl);
        TItem novo;
        int entrada;
        scanf("%d", &entrada);
        while (entrada >  0){
            //printf("Entre com o numero\n");
            scanf("%d", &novo.Chave);
            InsereAVL(&avl, novo);
            entrada--;
            //printf("\n");
            ImprimeFB(avl);
            imprime(avl);
            //Balanca_Arv(&avl);

        }
        //imprime(avl);
        //ImprimeFB(avl);

        scanf("%d", &novo.Chave);
        //printf("%d\n", QuantidadeNos(abb));
        int result = PesquisaABB(&avl, novo);
        if(result ==CONTEM){
            RemoveAVL(&avl, novo);
            //printf("REMOVEU\n");
        }
        else if(result == NAO_CONTEM){
            InsereAVL(&avl, novo);
            //printf("INSERIU\n");
        }

        //printf("\n");
        //ImprimeFB(avl);
        imprime(avl);
        //printf("\n");

        return 0;
    }
