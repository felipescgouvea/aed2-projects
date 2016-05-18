    /*
            Felipe Gouvêa, 92399
            Tabela Hash com estratégia de Encadeamento Aberto
            A tabela foi baseada em listas, como não havia a TAD pronta de lista, construi as funções de lista dentro das de Hash
    */
        #include <stdio.h>
    #define ENCONTROU 1
    #define NAO_ENCONTROU 0
    typedef int TChave;
    typedef struct{
        TChave Chave;
    } TItem;
     
    typedef struct SNo *TApontador;
    typedef struct SNo{
        TItem Item;
        TApontador ant, prox;
    } TNo;
     
    typedef struct{
        TApontador Inicio, Fim;
    }TLista;
     
    typedef int TIndice;
    typedef struct{
        TLista *Lista;
        int tam;
        int qtd;
    }THash;
     
     
     void Inicializa(THash *Hash, int tam){
        Hash->Lista = (TLista*)malloc(tam*sizeof(TLista));
        int i;
        for(i=0;i<tam;i++){
            InicializaLista(&Hash->Lista[i]);
        }
        Hash->tam = tam;
        Hash->qtd = 0;
    }
     
    void InicializaLista(TLista *lista){
        lista->Fim = NULL;
        lista->Inicio = NULL;
    }
     
     
    void InsereHash(THash *tabela, int num){
            TNo *aux2 = (TNo*)malloc(sizeof(TNo));
            aux2->Item.Chave = num;
            aux2->prox = NULL;
     
            if(tabela->Lista[num % tabela->tam].Inicio == NULL){
                tabela->Lista[num % tabela->tam].Inicio = aux2;
                tabela->Lista[num % tabela->tam].Fim = aux2;
            }
            else {
                TNo *aux = tabela->Lista[num % tabela->tam].Inicio;
                while(aux->prox != NULL){
                    aux = aux->prox;
                    //printf("erro");
                }
                aux->prox =  aux2;
                tabela->Lista[num % tabela->tam].Fim =  aux2;
                //tabela->qtd++;
            }
     
            //printf("Erro");
    }
    void RemoveHash(THash *tabela, int num){
     
        if(tabela->Lista[num % tabela->tam].Inicio != NULL){
     
                if(tabela->Lista[num % tabela->tam].Inicio->Item.Chave == num){
                    //printf("CERTO");
                    TNo *aux = tabela->Lista[num % tabela->tam].Inicio;
                    tabela->Lista[num % tabela->tam].Inicio = tabela->Lista[num % tabela->tam].Inicio->prox;
                    free(aux);
                    tabela->qtd--;
                    return;
                }
                if(tabela->Lista[num % tabela->tam].Fim->Item.Chave == num){
                    TNo *aux = tabela->Lista[num % tabela->tam].Inicio;
                    while(aux->prox->prox != NULL){
                        aux = aux->prox;
                    }
                    TNo *aux2 = aux->prox;
                    aux->prox = NULL;
                    tabela->Lista[num % tabela->tam].Fim = aux;
                    free(aux2);
                    tabela->qtd--;
                    return;
                }
                else{
                    TNo *aux = tabela->Lista[num % tabela->tam].Inicio;
                    while(aux->prox->prox != NULL){
                        if(aux->prox->Item.Chave == num) break;
                        aux = aux->prox;
     
                    }
                    TNo *aux2 = aux->prox;
                    aux->prox = aux->prox->prox;
                    free(aux2);
                    tabela->qtd--;
                }
        }
    }
    int PesquisaHash(THash *tabela, int num){
            int i;
            TNo *aux= tabela->Lista[num % tabela->tam].Inicio;
            while(aux != NULL){
                //printf("erro");
                if(aux->Item.Chave == num) return ENCONTROU;
                aux = aux->prox;
     
            }
            return NAO_ENCONTROU;
    }
     
     
    void Imprime(THash *tabela){
            int cont;
            for (cont=0; cont < tabela->tam; cont++){
                TNo *aux = tabela->Lista[cont].Inicio;
                printf("[%d] ", cont);
                while ( aux != NULL){
                    printf("%d ",aux->Item.Chave);
                    aux = aux->prox;
                }
                printf("\n");
            }
     
    }
     
     
    int main(void){
            int qtd_num;
            int tam;
            scanf("%d", &tam);
            scanf("%d", &qtd_num);
            int cont,num;
            THash tab;
            Inicializa(&tab, tam);
            //Imprime(tab);
     
            for(cont = 0; cont < qtd_num ; cont++){
                scanf("%d", &num);
                InsereHash(&tab,num);
            }
            //printf("%d",tab.Lista[num % tab.tam].Inicio->Item.Chave);
            scanf("%d", &num);
            if(PesquisaHash(&tab, num) == ENCONTROU){
                RemoveHash(&tab,num);
            }
            else InsereHash(&tab,num);
            Imprime(&tab);
            //printf("%d", tab->Item[0].Chave);
            return 0;
        }