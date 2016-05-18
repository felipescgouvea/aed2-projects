/*
    Felipe Gouvêa, 92399
    Tabela Hash com estratégia de Endereçamento Aberto
*/
#include <stdio.h>
int tam;
typedef int TChave;

typedef struct{
    TChave Chave;
} TItem;

typedef TChave TIndice;


typedef struct SHash{
    TItem *Item;
    int tamanho;
    int qtd;
    //TIndice m,n;
}THash;

void InsereHash(THash **tabela, int num){
    int nao_inseriu = 1;
    int i = 0;

    while(nao_inseriu){
        if((*tabela)->Item[(num + i) % (*tabela)->tamanho].Chave == -1){
            (*tabela)->Item[(num + i) % (*tabela)->tamanho].Chave = num;
            //(*tabela)->qtd++;
            return;
        }
        //printf("erro\n");
        i++;
    }
    //printf("Erro");
}

int PesquisaHash(THash **tabela, int num){
    int nao_inseriu = 1;
    int i = 0;
    while(i <= (*tabela)->tamanho){
        if((*tabela)->Item[(num + i) % (*tabela)->tamanho].Chave == num){
            return 1;
        }
        i++;
    }
    return 0;
}

void Imprime(THash *tabela){
    int cont;
    //printf("%d\n", tabela->tamanho);
    for(cont=0;cont<tabela->tamanho;cont++){
        printf("[%d] %d\n", cont, (tabela)->Item[cont].Chave);
    }
}
int FuncaoTransforma(int k){
    int hk;
    int m = tam;
    hk = k % m;
    return hk;
}

THash* Inicializa(int tam){
    THash *tabela = (THash*)malloc(sizeof(THash));
    tabela->Item = (TItem*)malloc(tam * sizeof(TItem));
    int cont;
    for(cont=0;cont<tam;cont++){
        tabela->Item[cont].Chave = -1;
    }
    tabela->qtd = 0;
    tabela->tamanho = tam;
    return tabela;
}
int main(void){
    int qtd_num;
    scanf("%d", &tam);
    scanf("%d", &qtd_num);
    int cont,num;
    THash *tab = Inicializa(tam);
    //Imprime(tab);

    for(cont = 0; cont < qtd_num ; cont++){
        scanf("%d", &num);
        InsereHash(&tab,num);
    }
    scanf("%d", &num);
    if(!PesquisaHash(&tab, num)){
        InsereHash(&tab,num);
    }
    Imprime(tab);
    //printf("%d", tab->Item[0].Chave);
    return 8;
}