                    /*
                    Felipe Gouvea, 92399, 5º termo
                    Algorítmo para construir e ordenar um heap

                    */

                        #include <stdio.h>
                        #include <stdlib.h>



                        void consertaHeap (int seq[], int tam, int pos_pai){

                            int maior_filho, filho_esq, filho_dir, pai;
                            //Verifica se o heap está vázio


                                //Caso contenha elementos, em cada um deles busca a condição de heap indicado em l. 3-5

                                pai = seq[pos_pai];


                                while (2*pos_pai + 1 < tam){

                                    filho_esq = 2*pos_pai + 1;
                                    filho_dir = 2*pos_pai + 2 ;

                                    if (filho_dir < tam){

                                        if(seq[filho_esq] > seq[filho_dir]) maior_filho = filho_esq;
                                        else maior_filho = filho_dir;

                                    }
                                    else maior_filho = filho_esq;


                                    if(seq[maior_filho] >= pai){

                                        seq[pos_pai] = seq[maior_filho];
                                        seq[maior_filho] = pai;
                                        pos_pai = maior_filho;

                                    }
                                    else {
                                        break;
                                    }
                                }

                        }

                        void imprime(int seq[], int tam){
                            int i;
                            for (i = 0; i< tam; i++){
                                if (i == tam-1){

                                    printf("%d\n", seq[i]);
                                    return;

                                }
                                printf("%d ", seq[i]);


                            }

                        }

                        void heapSort(int seq[], int tam){
                            int pos=0,aux, tam_real;
                            tam_real = tam - 1;

                            while (pos < tam - 1){
                                aux = seq[0];
                                seq[0] = seq[tam_real];
                                seq[tam_real] = aux;



                                consertaHeap(seq, tam_real, 0);
                                tam_real--;
                                pos++;
                            }
                        }

                        void constroi(int seq[], int tam){
                            int i, pos, pos_att;
                            pos = tam/2;
                                while (pos >= 0){

                                    consertaHeap(seq,tam,pos);
                                    pos--;
                                }

                        }

                        int main()
                        {
                            int *seq;
                            int tam, i;
                            scanf("%d", &tam);
                            seq = (int*)malloc(tam*sizeof(int));
                            for (i = 0; i < tam; i++){

                                    scanf("%d", &seq[i]);

                            }


                            consertaHeap(seq,tam,0);
                            imprime(seq,tam);

                            constroi(seq, tam);
                            imprime(seq, tam);


                            heapSort(seq, tam);
                            imprime(seq, tam);



                            return 0;
                        }
