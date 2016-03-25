    /*
    Felipe Gouvea, 92399
    Algoritmo para ordernar uma sequencia [1,tamanho] contando cada movimentação
    Atendendo ao objetivo da tarefa 1.
    A ordenação ocorre em ordem O(n) pois o exercício nos fornece informações sobre as entradas,
    então conseguimos deduzir suas posições a partir dessas informações.
    */
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <malloc.h>
    
    int trocas = 0; //Variável global de contagem
     
    void sort(int seq[], int tam){
         int ultima_posicao = tam - 1;
        int i,n=0, aux;
            i=0;
            while(i<=ultima_posicao){
                /*
                 Se o número de determinado índice não for compatível com o índice,
                 então trocamos com o número que corresponde o índice
                */
                
                if(seq[i] != i+1){    
                    aux = seq[i];
                    seq[i] = seq[aux-1];
                    seq[aux-1] = aux;
                    
                    trocas++;  
                   }
                   else i++; //O índice só é incrementado após realizar todas as trocas necessária para colocar o elemento do índice i em seu local.
            }    
        
 
        if (trocas % 2 == 0) printf("Carlos");
        else printf("Marcelo");
     
}
     
    void imprime(int a[], int tam){
        int i;
        for (i=0; i<tam; i++) printf("%d ", a[i]);
        printf("\n");
    }
     
 
     
    int main()
    {
        int *seq;
        int i,tam;
        scanf("%d", &tam);
     
        seq = (int*)malloc(tam*sizeof(int));
     
        for ( i = 0; i < tam; i++){
            scanf("%d", &seq[i]);
        }
        sort(seq, tam);
        //imprime(seq, tam);
     
     
     
        return 0;
    }
