#include <stdio.h>
#include <stdlib.h>
 
int N; //Linhas
int M; //Colunas
int numero_de_pesquisas;
 
int maior_numero(int linha, int coluna){
    if( (N-linha) < (M-coluna)) return N-linha;
    else return M-coluna;
}
int maior_area( int propriedades_da_regiao[N][M], int linha, int coluna, int maior_num){
    int tam = 0;
    int restricao = maior_numero(linha,coluna);
    while((linha < N) && (coluna < M) && (tam <=restricao)){
        //printf("TAM:%d\n",tam);
        if(propriedades_da_regiao[linha][coluna] <= maior_num){
            tam++;
            linha++;
            coluna++;
            //printf("maior_tam %d\n", tam);
        }
        else break;
 
 
    }
    return tam;
}
 
int pesquisa(int propriedades_da_regiao[N][M], int menor, int maior){
    int linha, coluna;
    int maior_tam = 0;
    int tam;
    for(linha = 0; linha < N; linha++){
        for(coluna = 0; coluna < M; coluna++){
            //printf("C ");
            //printf("LINHA: %d      COLUNA: %d\n", linha, coluna);
 
            if(menor <= propriedades_da_regiao[linha][coluna] && maior >= propriedades_da_regiao[linha][coluna]){
                 tam = maior_area(propriedades_da_regiao, linha, coluna, maior);
 
                 if (tam > maior_tam) maior_tam = tam;
 
                 break;
                //return maior_area(maior_tam, propriedades_da_regiao, linha, coluna, maior);
 
            }
 
        }
    }
 
    return maior_tam;
}
 
 
 
int main(int argc, char *argv[]) {
    scanf("%d %d\n", &N, &M);
    //printf("%d %d", N, M);
 
    int propriedades_da_regiao[N][M];
    int N_ENTRADA, M_ENTRADA;
    for(N_ENTRADA = 0; N_ENTRADA < N; N_ENTRADA++){
 
        for(M_ENTRADA = 0; M_ENTRADA < M; M_ENTRADA++){
 
            scanf("%d", &propriedades_da_regiao[N_ENTRADA][M_ENTRADA]);
 
        }
 
    }
 
    scanf("%d", &numero_de_pesquisas);
    int entrada;
    int range_menor[numero_de_pesquisas];
    int range_maior[numero_de_pesquisas];
    int resultado[numero_de_pesquisas];
    //printf("NUMERO DE PESQUISAS %d\n ", numero_de_pesquisas);
    for(entrada = 0; entrada < numero_de_pesquisas; entrada++){
        scanf("%d", &range_menor[entrada]);
        scanf("%d", &range_maior[entrada]);
 
        resultado[entrada] = pesquisa(propriedades_da_regiao, range_menor[entrada], range_maior[entrada]);
 
    }
 
    for(entrada = 0; entrada < numero_de_pesquisas; entrada++){
        printf("%d\n", resultado[entrada]);
    }
 
 
 
}