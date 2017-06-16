#include <stdlib.h>
#include <stdio.h>
#include "Arvore234.h"

void a234_criaNo(){
    printf("Incompleta");
}
void a234_insere(){
    printf("Incompleta");
}
void a234_remove(){
    printf("Incompleta");
}
void converte234toRB(){
    printf("Incompleta");
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

