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
void a234_insere(a234 *a, int info){
    printf("\nIncompleta\n");
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

