            /*
                Felipe Gouvea, 92399
                Algorítmo Arvore RN com funções de inserção e verificação da validade da RN
            */
    #include <stdio.h>
    #include <stdlib.h>
    #define N 1
    #define R 0
    #define EHARVORE 1
    #define NAOEHARVORE 0
     
    typedef int TChave;
     
    typedef struct {
            TChave Chave;
    }TItem;
     
    typedef struct SNo *TArvBin;
     
    typedef struct SNo{
        TItem Item;
        TArvBin esq, dir;
        int cor;
    }TNo;
     
    void TrocaCores(TArvBin *arv){
        InverteCores(&(*arv));
        InverteCores(&(*arv)->dir);
        InverteCores(&(*arv)->esq);
    }
    void InverteCores(TArvBin *arv){
            if((*arv) != NULL){
            if((*arv)->cor == N) (*arv)->cor = R;
            else (*arv)->cor = N;
        }
    }
    void RotacaoDireita(TArvBin *arv){
        TArvBin aux;
        aux = (*arv)->esq;
        (*arv)->esq = aux->dir;
        aux->dir = (*arv);
        (*arv) = aux;
    }
    void RotacaoEsquerda(TArvBin *arv){
        TArvBin aux;
        aux = (*arv)->dir;
        (*arv)->dir = aux->esq;
        aux->esq = (*arv);
        (*arv) = aux;
    }
     
    int BalancaEsq(TArvBin *avo, TArvBin *pai, TArvBin *filho){
        //printf("Balança Esquerda\n");
        if((qualcor(*filho) == R) && (qualcor(*pai) == R) && (avo != NULL)){
            if(qualcor((*avo)->dir) == N){
                if((*pai)->dir == *filho){
                    RotacaoEsquerda(&(*pai));
                }
                InverteCores(&(*pai));
                InverteCores(&(*avo));
                RotacaoDireita(&(*avo));
            }
            else{
                TrocaCores(&(*avo));
                 
            }
        }
    }
     
    int BalancaDir(TArvBin *avo, TArvBin *pai, TArvBin *filho){
        //printf("Balança Direita\n");
        
        if((qualcor(*filho) == R) && (qualcor(*pai) == R) && (avo != NULL)){
            
            //printf("primeiroif\n");
            if(qualcor((*avo)->esq) ==     N){
                //printf("segundoif\n");
                if((*pai)->esq == *filho){
                    RotacaoDireita(&(*pai));
                }
                InverteCores(&(*pai));
                InverteCores(&(*avo));
                RotacaoEsquerda(&(*avo));
                
            } else{
                //printf("terceitorif\n");    
                 TrocaCores(&(*avo));    
                }
        }
    }
     
    void Inicializa(TArvBin *td){
            (*td) = NULL;
    }
    int qualcor(TArvBin arv){
        if(arv == NULL) return N;
        if(arv->cor == N){
            //printf("NEGRO\n");
            return N;
        } else return R;
    }
    int AlturaNegra(TArvBin arv){
        int alturadir,alturaesq;
        if(arv != NULL){
            int cor_no = (qualcor(arv));
            alturadir = AlturaNegra(arv->dir);
            alturaesq = AlturaNegra(arv->esq);
            if(alturaesq > alturadir){
                if(cor_no != N){
                    //printf("NEGROe\n");
                    return alturaesq;
                }
                else return ++alturaesq;
            }
            else{
                if(cor_no != N){
                    //printf("NEGROd\n");
                    return alturadir;
                }
                else return ++alturadir;
            }
        }
        else {
            return 0;
        }
    }
    void imprime(TArvBin arv){
        if (arv != NULL) {
            if(qualcor(arv) == R){
                printf("(R");    
            }
            else printf("(N");
            
            printf("%d",  arv->Item.Chave);
            imprime(arv->esq);
            imprime(arv->dir);
            printf(")");
        }
        else printf("()");
    }
    int VerificaARN(TArvBin arv){
        if(arv == NULL){
            return EHARVORE;
        }
        
        if(AlturaNegra(arv->esq) != AlturaNegra(arv->dir)){
            return NAOEHARVORE;
        }
    }
     
     
    TArvBin CriaNo(TItem novo){
        TArvBin no = (TArvBin)malloc(sizeof(TNo));
        no->Item = novo;
        no->dir = NULL;
        no->esq = NULL;
        no->cor = R;
        return no;
     
    }
    void InsereRecursivoRN(TArvBin *avo, TArvBin *pai, TItem novo){
        
        //printf("%d\n", novo.Chave);
        TArvBin filho;
        if(*pai == NULL) {
            //printf("CriaNo\n");
            *pai = CriaNo(novo);
            BalancaDir(&(*avo), &(*pai), &(*pai)->dir);
            
        }
     
        if (novo.Chave < (*pai)->Item.Chave) {
               //printf("AVO %d PAI %d \n",(*avo)->Item.Chave,(*pai)->Item.Chave);
            InsereRecursivoRN(&(*pai),&(*pai)->esq,novo);
            if(avo != NULL){
                if((*avo)->esq == *pai) {
                    BalancaEsq(&(*avo),&(*pai), &(*pai)->esq);
                }
                else {
                    BalancaDir(&(*avo), &(*pai), &(*pai)->esq);
                }
            }
            
        }
     
        else {
            if (novo.Chave > (*pai)->Item.Chave) {
                //printf("AVO %d PAI %d \n",(*avo)->Item.Chave,(*pai)->Item.Chave);
                InsereRecursivoRN(&(*pai),&(*pai)->dir,novo);
                if(avo != NULL){
                    
                    if((*avo)->esq == *pai) {
                        //printf("be\n");
                        BalancaEsq(&(*avo), &(*pai), &(*pai)->dir);    
                    }
                    else{
                        //printf("bd\n");
                        BalancaDir(&(*avo), &(*pai), &(*pai)->dir);    
                    }
                }
            }    
        }
     
    }
    void InsereRN(TArvBin *arv, TItem novo){
        InsereRecursivoRN(NULL, arv, novo);
        (*arv)->cor = N;
        //imprime(*arv);
    }
     
     
     
    main(){
            TArvBin rn;
            Inicializa(&rn);
            TItem novo;
            int entrada;
            scanf("%d", &entrada);
            int result;
            while (entrada > 0){
                //printf("Entre com o numero\n");
                scanf("%d", &novo.Chave);
                entrada--;
                //printf("\n");
                InsereRN(&rn, novo);
                //ImprimeFB(rn);
                //imprime(rn);
                
            }
            
                
            printf("%d", AlturaNegra(rn));
            printf("\n");
            imprime(rn);
            return 0;
        }