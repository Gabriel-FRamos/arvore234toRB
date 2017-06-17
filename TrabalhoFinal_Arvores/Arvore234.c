#include <stdlib.h>
#include <stdio.h>
#include "Arvore234.h"

a234* a234_inicializaArvore(){
    a234* sentinela;
    sentinela = (a234*)calloc(1, sizeof(a234));
    sentinela->pai = NULL;
    sentinela->numChaves = 0;
    sentinela->filho[0] = NULL;
    sentinela->valor[0] = -1000; 
    
    return sentinela;
}
a234* a234_insere(a234 *a, int info){
    int tam;
    int aux, i;
    a234 *filho, *novoNo;	
    filho = a234_busca(a,info,&tam,&aux);
    if (tam){
        novoNo = (a234*)malloc(sizeof(a234));
        novoNo->numChaves = 1;
        novoNo->valor[0] = aux;
        novoNo->filho[0] = a;
        novoNo->filho[1] = filho;
        for(i=2; i<=3;i++){
            novoNo->filho[i] = NULL;
        }
            return(novoNo);
    }else{
        return (a);
    }
}
a234 *a234_busca(a234 *a, int info, int *tam, int *aux){
    int i , pos, med;
    a234 *temp, *filho;	
    if (a == NULL){
        *tam = 1;
        *aux = info;
        return(NULL);
    }else{
        pos = a234_buscaBinaria(a,info);
        if (a->numChaves > pos && a->valor[pos] == info){
            printf("Erro: Valor ja esta contido.\n");
            *tam = 0;
            }else{	
                filho = a234_busca(a->filho[pos],info, tam,aux);
                if(*tam){
                    if (a->numChaves < 3){
                        a234_insereChave(a,*aux,filho);
                        *tam = 0;
                        }else{
                            temp = (a234*)malloc(sizeof(a234));
                            temp->numChaves = 0;
                            for (i=0; i< 3; i++){
                                temp->filho[i] = NULL;
                            }
                            med = a->valor[1];
                            temp->filho[0] = a->filho[2];
                            for (i= 2; i<3;i++){
                                a234_insereChave(temp,a->valor[i],a->filho[i+1]);
                            }
                            for (i=1;i<3;i++){
                                a->valor[i] = 0;
                                a->filho[i+1]=NULL;
                            }
                            a->numChaves = 1;
                            if(pos <= 1){
                                a234_insereChave(a,*aux,filho);
                            }else{
                                a234_insereChave(temp,*aux,filho);
                            }
                    *aux = med;
                    return (temp);
                }
            }
        }
    }
    return a;
}
int a234_buscaBinaria(a234 *a, int dado){
    int meio, i, f;
    i= 0;
    f= a->numChaves-1;
    while (i<= f){
        meio = (i+f)/2;
        if (a->valor[meio] == dado)
        return (meio);	//Encontrou a posição que a chave está
        else if (a->valor[meio] > dado)
        f = meio - 1;
        else 
        i = meio + 1;
    }
    return (i);	
}
void a234_insereChave(a234 *a, int dado, a234 *filho){
    int k, pos;	
    pos= a234_buscaBinaria(a,dado);
    k = a->numChaves;
    while (k > pos && dado < a->valor[k-1]){
        a->valor[k] = a->valor[k-1];
        a->filho[k+1] = a->filho[k];
        k--;
    }
    a->valor[pos] = dado;
    a->filho[pos+1]= filho;
    a->numChaves++;
}
void a234_remove(a234 *a, int info){
    printf("\nIncompleta\n");
}
void a234_imprimir(a234 *A){
    int i;
    if (A != NULL){
        for (i = 0; i < A->numChaves; i++){
            a234_imprimir(A->filho[i]);
            printf("\n%d", A->valor[i]);
      	}
	a234_imprimir(A->filho[i]);
    }
}
void converte234toRB(){
    printf("\nIncompleta\n");
}

