#include <stdlib.h>
#include <stdio.h>
#include "E-S_dados.h"

void lerArquivo(a234 *A){ 
    printf("Incompleta");
}
void gerarDados(){
    FILE *arq;
    arq = fopen("dados.txt", "w");
    if(arq == NULL){
        printf("Problema na abertura de arquivo\n");
        exit(0);
    }
    for(int j = 0; j < 10; j++){
        fprintf(arq, "%d\n", rand()%50+1);
    }
    fclose(arq);
    return;
}

