#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	TChave Chave;
	/* outros compomentes */
} TItem;

void bubblesort(TItem *A, int n, TChave k)
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

void Ordena(TItem *A, int n, int d) // Ajuste o parametro do seu metodo aqui!

    int i,aux[n];
    printf("\n");
    for ( i = 0 ; i < d ; i++){

        aux[i] = A[i].Chave % 10;
        bubblesort(A,n,k);

    }
	// Implemente o seu metodo aqui!
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
    int i;
    scanf("%d", &n);

    A = (TItem*)malloc(n*sizeof(TItem));

    for ( i = 0; i < n; i++){
        scanf("%d", &A[i].Chave);
    }

    k = maiorChave(A, n);
	d = numeroDigitos(k); // Use como parametro do RadixSort
	printf("%d %d", k, d);
	Ordena(A, n, d); // Ajuste o parametro do seu metodo aqui!

	// Implemente a saida de dados aqui!

	return 0;
}
