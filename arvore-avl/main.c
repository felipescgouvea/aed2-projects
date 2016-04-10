                /*
            Felipe Gouvea, 92399
               Algorítmo Arvore AVL com diversas funções porém não uma TAD
            */

    #include <stdio.h>
    #include <stdlib.h>
    #define FALSE 0
    #define TRUE 1
    typedef int TChave;

    typedef struct {
        TChave Chave;
    }TItem;

    typedef struct SNo *TArvBin;

    typedef struct SNo{
        TItem Item;
        TArvBin esq, dir;
    }TNo;

    void insere(TArvBin arv, TItem novo){
        arv->Item = novo;
        arv->esq = NULL;
        arv->dir = NULL;
    }

    TArvBin ConstroiArvore(){
        char c;
        char c2;

        //printf("Insira parenteses\n");
        scanf("%c", &c);
        //getchar();
        if ( c == '('){

            //printf("Insira o C \n");
            scanf("%c", &c2);
            //getchar();

            if(c2 == 'C'){
              TArvBin arv =(TArvBin)malloc(sizeof(TNo));

              TItem n;
              //printf("Insira o numero\n");
              scanf("%d", &n.Chave);
              //getchar();


              insere(arv, n);
              //printf("%d\n", arv->Item.Chave);
              //imprime(arv);

              arv->esq = ConstroiArvore();
              arv->dir = ConstroiArvore();

              scanf("%c", &c);
              //getchar();

              return arv;
            }
            else{
                //scanf("%c", &c);
                return NULL;
            }
        }
            else{
                //scanf("%c", &c);
                return NULL;
            }
    }
    ///printf("%d \n", arv->Item.Chave);
    //Balanceamento pós ordem, dir, esq, nó
    ///(C3(C2(C1()())())(C4()(C9(C5()(C8()()))())))

int Altura(TArvBin raiz){
    if(raiz == NULL){
        return -1;
    }
    if ((raiz->dir == NULL) && (raiz->esq == NULL)) {
        return 0;
    }
    return 1 + Maior_Altura(Altura(raiz->esq), Altura(raiz->dir));
}
int Maior_Altura(a,b){
    if (a > b){
        return a;
    }
    else return b;

}
int Fator_Balanceamento(TArvBin arv){
    if(arv == NULL) return 0;
    int fb;
    fb = (Altura(arv->esq) - Altura(arv->dir));
    return fb;
}
int Verifica_AVL(TArvBin arv){
    int FB = Fator_Balanceamento(arv);
    if ((FB > 1 )|| (FB < -1)){
        return FALSE;
    }
    else {
        Verifica_AVL(arv->esq);
        Verifica_AVL(arv->dir);
        return TRUE;
    }

}
void inicializa(TArvBin *td){
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
    (*A)->esq = B->dir;
    B->dir = (*A);
    (*A) = B;
}

void RR(TArvBin *A){

    TArvBin B =  (*A)->dir;
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
    (*A) = C;
}

void RL(TArvBin *A){

    TArvBin B = (*A)->dir;
    TArvBin C = B->esq;

    B->esq = C->dir;
    C->dir = B;

    (*A)->dir = C->esq;

    C->esq = (*A);

    (*A) = C;
}

void Balanca_Arv(TArvBin *A){
    if(*A != NULL){
    Balanca_Arv(&(*A)->dir);
    Balanca_Arv(&(*A)->esq);
//    printf("%d %d- ", ()->Item.Chave, Fator_Balanceamento(A));
    Balanca_No(A);
    }

}
void Balanca_No(TArvBin *A){
    int fb = Fator_Balanceamento(*A);
    int fb_dir = Fator_Balanceamento((*A)->dir);
    int fb_esq = Fator_Balanceamento((*A)->esq);
    //int fb = 2;
    //int fb_dir = 2;
    //int fb_esq = 1;
    if (fb > 1){
        if (fb_esq > 0){
            LL(&(*A));
        }
        else if (fb_esq < 0){
            LR(&(*A));
        }
    }
    if (fb < -1){
        if (fb_dir < 0){
            RR(&(*A));
        }
        else if (fb_dir > 0){
            RL(&(*A));
        }
    }
}

int main()
    {
        TArvBin td;
        td = ConstroiArvore();
        printf("%d\n", Altura(td));
        //printf("FATOR BALANCEAMENTO %d\n", Fator_Balanceamento(td));
        //printf("É AVL OU NAO %d\n", Verifica_AVL(td));
        //imprime(td);
        Balanca_Arv(&td);
        printf("%d\n", Altura(td));
        //printf("FATOR BALANCEAMENTO %d\n", Fator_Balanceamento(td));
        //printf("É AVL OU NAO %d\n", Verifica_AVL(td));

        imprime(td);


        return 0;
    }
