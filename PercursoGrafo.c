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

typedef struct SGrafo *TGrafo;
typedef struct SGrafo{
    TLista *lista;
    TGrafo ProxNo;
    int codigo;
}STGrafo;



void Inicializa(TGrafo *G, int QuantidadeNos){
    int i;
    (*G)  = (TGrafo)malloc(sizeof(STGrafo));
    TGrafo aux = (*G);
    if (aux == NULL) printf("NULO");
    for(i = 1; i<= QuantidadeNos; i++){
        if((aux)->ProxNo == NULL){
            //printf("nulo");
            (aux)->ProxNo = (TGrafo)malloc(sizeof(STGrafo));
        }
        aux->lista = (TLista*)malloc(sizeof(TLista));
        InicializaLista(aux->lista);

        (aux)->codigo = i;
        (aux) = (aux)->ProxNo;

    }
}

void InicializaLista(TLista *lista){
    lista->Fim = NULL;
    lista->Inicio = NULL;
}
void Imprime(TGrafo G){

    TGrafo aux = G;
    TApontador aux2;
    while (aux->ProxNo != NULL){
        aux2 = aux->lista->Inicio;
        printf("[%d]: ", aux->codigo);
        while(aux2 != NULL){
            printf("%d ", aux2->Item.Chave);
            aux2 = aux2->prox;
        }
        printf("\n");
        aux = aux->ProxNo;
    }
}
void InsereGrafo(TGrafo *T, int origem, int destino, int tipoRua){
    if(*T == NULL) return;
    else{
        if(tipoRua == 1){
            //printf("Tipo 1     ");
            InsereRecursivo(T, origem, destino);
        }
        if(tipoRua == 2){
           //printf("Tipo 2     ");
            InsereRecursivo(T, origem, destino);
            InsereRecursivo(T, destino, origem);
        }
    }
}
void InsereRecursivo(TGrafo *T, int origem, int destino){
    TGrafo aux = (*T);
    while (aux != NULL){
        if((aux)->codigo == origem){
            //printf("Vertice %d", aux->codigo);
            InsereLista((aux)->lista, destino);
            //printf("Inseriu\n");
            return;
        }
        //printf("Erro ");
        aux = aux->ProxNo;
    }
}
void InsereLista(TLista *l, int info){
    TApontador aux = (*l).Fim;
    if(l == NULL)printf("Lista Nula");
    if(aux == NULL){
        TApontador novo = (TApontador)malloc(sizeof(TNo));
        novo->Item.Chave = info;
        novo->prox = NULL;

        aux = novo;
        l->Inicio = aux;
        l->Fim = aux;

        //printf("Inseriu na lista %d\n", info);
    }
    else{
        TApontador novo = (TApontador)malloc(sizeof(TNo));
        novo->Item.Chave = info;
        novo->prox = NULL;

        l->Fim->prox = novo;
        l->Fim = novo;
    }
}

void BuscaLargua(){

}

int main(void){
    int quantidadeNos;
    int quantidadeArestas;
    scanf("%d", &quantidadeNos);
    scanf("%d", &quantidadeArestas);
    int cont;
    int origem;
    int destino;
    int tipoRua;
    TGrafo G;
    G = NULL;
    Inicializa(&G, quantidadeNos);



    for(cont = 0; cont < quantidadeArestas ; cont++){
        scanf("%d", &origem);
        scanf("%d", &destino);
        scanf("%d", &tipoRua);
        InsereGrafo(&G, origem, destino, tipoRua);
    }
    printf("\n\nImpressao:\n");
    Imprime(G);
    return 0;
}
