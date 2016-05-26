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
    TLista *Inicio;
    TGrafo ProxNo;
    int codigo;
}STGrafo;



void Inicializa(TGrafo *G, int QuantidadeNos){
    int i;
    //(*G)  = (TGrafo)malloc(sizeof(STGrafo));
    for(i = 0; i< QuantidadeNos; i++){
        printf("i : %d", i);
        (*G)->codigo = i;
        (*G)->ProxNo = (TGrafo)malloc(sizeof(STGrafo));
    }

}

void InicializaLista(TLista *lista){
    lista->Fim = NULL;
    lista->Inicio = NULL;
}
void Imprime(TGrafo G){

    TGrafo aux = G;
    while (aux != NULL){
        printf("%d", aux->codigo);
        aux = aux->ProxNo;
    }
}
int main(void){
        int quantidadeNos;
        int quantidadeVertices;
        //scanf("%d", &quantidadeNos);
        //scanf("%d", &quantidadeVertices);
        int cont,num;
        TGrafo G;
        G = NULL;
        Inicializa(&G, 5);
        //if(G == NULL) printf("G NULO");
        Imprime(G);
        //Inicializa(&G, quantidadeNos);
        //Imprime(tab);
        /*
        for(cont = 0; cont < QuantidadeVertices ; cont++){
            scanf("%d", &num);
            InsereGrafo(&tab,num);
        }
        //printf("%d",tab.Lista[num % tab.tam].Inicio->Item.Chave);
        scanf("%d", &num);
        if(PesquisaHash(&tab, num) == ENCONTROU){
            RemoveHash(&tab,num);
        }
        else InsereHash(&tab,num);
        Imprime(&tab);
        //printf("%d", tab->Item[0].Chave);
        */
        return 0;
    }
