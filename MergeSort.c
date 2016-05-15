        /*
        Felipe Gouvea, 92399
        Algoritmo para ordernar uma sequencia com o método mergesort.
        O mergesort se utiliza da estratégia de divisão e conquista.
        A ordenação ocorre em ordem O(n*log n)
        */
        
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <malloc.h>
    int result = 0;
     
    typedef struct{
        int chave;
    }TItem;
     
     
     
    void merge(TItem a[], int com, int fim){
        int *temp = (int*)malloc((fim-com+1)*sizeof(TItem)); 
        int i,j,k;
        int meio = (fim + com)/2;
        i=com;
        j=meio+1;
        k=0;    
        
        while (i <= meio || j <= fim ){ // Ao contrário do que foi feito no slide, aqui comparamos direto do vetor original
                                        //Colocando um apontador para p e outro para q+1 e os comparando
            if(i == meio+1){
                temp[k] = a[j].chave;
                k++;
                j++;
                
            }
            else {
                if (j == fim+1){
                    temp[k] = a[i].chave;
                    i++;
                    k++;
                    
                }            
                else {            
                    if(a[i].chave <= a[j].chave) {
                        temp[k] = a[i].chave;
                        i++;
                        k++;
                        
                    }
                    else {
                        temp[k] = a[j].chave;
                        j++;
                        k++;
                        
                    }
                }
            }
        }
        
            for(i=com;i<=fim;i++){
                 a[i].chave = temp[i-com];
            }
        free(temp);
        
    }
     
    void mergeSort(TItem a[], int com, int fim){
        
        int meio = (fim+com)/2;
        if (fim  == com) return;
        else {
            mergeSort(a, com, meio) ;
            mergeSort(a, meio+1, fim);
            merge(a, com,fim);
            }
     
    }
     
     
     
    void imprime(TItem a[], int tam){
        int i;
        for (i=0; i<tam; i++) printf("%d ", a[i].chave);
        printf("\n");
    }
     
    void preenche(TItem a[], int tam){
        srand(time(NULL));
        int i;
     
        for(i=0; i <= tam; i ++){
     
            while (a[i].chave <= 1){
                a[i].chave = rand() % 100000;
            }
     
        }
    }
     
     
    int main()
    {
        TItem *seq;
        int i,tam;
        scanf("%d", &tam);
        
        seq = (TItem*)malloc(tam*sizeof(TItem));
     
        for ( i = 0; i < tam; i++){
            scanf("%d", &seq[i]);
        }
     
        mergeSort(seq,0,tam-1);
        imprime(seq,tam);
     

        return 0;
    }