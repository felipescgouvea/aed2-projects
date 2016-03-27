
    /*
    Felipe Gouvea, 92399
    Algoritmo para ordernar uma sequencia com o método counting sort
    A ordenação ocorre em ordem O(n)
    */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

TChave maiorChave(TItem *A, int n)
{
	TChave max;
	int i;

	max = 0;
	for (i = 0; i < n; i++)
		if (A[i].Chave > max)
			max = A[i].Chave;

	return max;
}

int numeroDigitos(TChave numero)
{
	return (int)ceil(log10(numero));
}

int retornaDigito(TChave numero, int indice)
{
	return (numero / (int)pow(10, indice)) % 10;
}
void zera(TItem *C, TChave k){// Zera o vetor de índices
    int i;
    for (i=0;i<k;i++) C[i].Chave = 0;
}

void Ordena(TItem *A, int n, TChave k)
{
    TItem *B = (TItem*)malloc((n+1)*sizeof(TItem));
    TItem *C = (TItem*)malloc((k+1)*sizeof(TItem));
    zera(C,k);
    int j;
    //Monta o vetor C com o número de chaves de A
    for (j=0;j<=n;j++){
        C[A[j].Chave].Chave++;
    }

    for (j=1;j<=k;j++){
        C[j].Chave += C[j-1].Chave;
    }


    for (j=n;j>=0;j--){
        if(C[A[j].Chave].Chave > 0){
            B[C[A[j].Chave].Chave - 1].Chave = A[j].Chave;
            C[A[j].Chave].Chave--;
        }
    }

	for ( j = 0; j <= n; j++){
        A[j].Chave = B[j].Chave;
	}

}

void imprime(TItem *A, int n){
    int i;
    for (i=0;i<=n;i++) printf("%d ", A[i].Chave);
    printf("\n");

}

int main()
{
	TItem *A; 	// Arranjo com registros a serem ordenados
	TChave k; 	// Maior chave encontrada no arranjo A
	int d;		// Numero de digitos da maior chave k
	int n;		// Numero de registros do arranjo A
    n = 5;
    scanf("%d", &n);
    A = (TItem*)malloc(n*sizeof(TItem));
	// Implemente a entrada de dados aqui!
    int i;


    for ( i = 0; i < n; i++){
        scanf("%d", &A[i].Chave);
    }

	k = maiorChave(A, n); // Use como parametro do CountingSort

	Ordena(A, n-1, k); // Ajuste o parametro do seu metodo aqui!

	imprime(A,n-1);

	return 0;
}
