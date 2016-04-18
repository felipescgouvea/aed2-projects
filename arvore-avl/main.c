        /*
            Felipe Gouvea, 92399
               Algorítmo Arvore AVL com diversas funções porém não uma TAD
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

    void insere(TArvBin arv, TItem novo){
        arv->Item = novo;
        arv->esq = NULL;
        arv->dir = NULL;
    }
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
    B->fb = 0;
    (*A)->fb = 0;

    (*A)->esq = B->dir;
    B->dir = (*A);
    (*A) = B;
}
void RR(TArvBin *A){
    TArvBin B =  (*A)->dir;

    B->fb = 0;
    (*A)->fb = 0;

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
        if (fb_esq > 0){
            //printf("LL\n");
            LL(&(*A));
        }
        else if (fb_esq < 0){
            //printf("LR\n");
            LR(&(*A));
        }
    }
    if (fb < -1){
        if (fb_dir < 0){
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
            if (aumentou == TRUE){
                //printf("aumentou esq\n");
                return AtualizaFB(&(*aux), DIR);
            }
           else return FALSE;
           ///return (*aux)->fb;
           //printf("ALT = %d  NO = %d\n", (*aux)->alt,(*aux)->Item.Chave);

    }
    else {
        if (novo.Chave > (*aux)->Item.Chave) {
            aumentou = InsereAVL(&(*aux)->dir, novo);
            if (aumentou == TRUE){
                //printf("aumentou dir\n");
                return AtualizaFB(&(*aux), ESQ);
            }
           else return FALSE;
        }
        else{
            return 0;
        }
    }
//    if ((*aux)->fb > 1 || (*aux)->fb < 1) printf("XABLAU\n");

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
            if(RemoveAVL(&(*arv)->dir, aux->Item) == TRUE);
            //RemoveAVL(&(*arv)->esq, aux->Item);
            //DeletaNo(*arv, aux->Item);
   //         printf("%d\n",(*arv)->Item);
            //printf("%d", (*arv)->Item.Chave);
        }
}
int RemoveAVL (TArvBin *aux, TItem item){
    //printf("removendo...\n");
    if((*aux) == NULL) return 0;

    if((*aux)->Item.Chave == item.Chave) {
        DeletaNo(&(*aux), item);
        //printf("deletou!\n");
        return 1;
    }
    int diminuiu;
    if(item.Chave > (*aux)->Item.Chave){
        diminuiu = RemoveAVL(&(*aux)->dir, item);
        if(diminuiu == TRUE){
            return !AtualizaFB(&(*aux), DIR);
        }
        else {
            return FALSE;
        }
    }
    else if(item.Chave < (*aux)->Item.Chave){
        diminuiu = RemoveAVL(&(*aux)->esq, item);
        if(diminuiu == TRUE){
            return !AtualizaFB(&(*aux), DIR);
        }
        else {
            return FALSE;
        }
    }

}

int PesquisaABB(TArvBin *arv, TItem item){
    //printf("%d ", (*arv)->Item.Chave);
    if(*arv == NULL) {
        //printf("Nao encontrou\n");
        InsereAVL(&(*arv), item);
        return NAO_CONTEM;
    }
    if((*arv)->Item.Chave == item.Chave){
        //printf("Encontrou a chave!\n");
        RemoveAVL(&(*arv), item);
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
AtualizaFB(TArvBin *aux, int direction){

    if (direction == DIR){
        return AtualizaEsquerda(&(*aux));
    }
    else if (direction == ESQ){
        return AtualizaDireita(&(*aux));
         }

}
int AtualizaEsquerda(TArvBin *aux){
        if((*aux)->fb >= 1){
            //printf("ESQ 1\n");
            (*aux)->fb++;
            //return 1;
            return Balanca_No(&(*aux));
            //BALANÇAESQUERDA
        }
        if((*aux)->fb == 0){
            //printf("ESQ 0\n");
            (*aux)->fb = 1;
            return 1;
        }
        if((*aux)->fb == -1){
            //printf("ESQ -1\n");
            (*aux)->fb = 0;
            return 0;
        }

}
int AtualizaDireita(TArvBin *aux){
            if((*aux)->fb == 1){
                //printf("DIR 1\n");
                (*aux)->fb = 0;
                return 0;
            }
            if((*aux)->fb == 0){
                //printf("DIR 0\n");
                (*aux)->fb = -1;
                return 1;
            }
            if((*aux)->fb <= -1){
                //printf("DIR -1\n");
                (*aux)->fb--;
                //return 1;
                return Balanca_No(&(*aux));
            //BALANÇADIREITA
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

            //Balanca_Arv(&avl);
            //imprime(avl);
        }
        //imprime(avl);
        scanf("%d", &novo.Chave);
        //printf("%d\n", QuantidadeNos(abb));
        PesquisaABB(&avl, novo);
        //printf("\n");
        //ImprimeFB(avl);
        imprime(avl);
        //printf("\n");

        return 0;
    }
