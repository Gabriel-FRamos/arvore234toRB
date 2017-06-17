#include <stdlib.h>
#include <stdio.h>
#include "E-S_dados.h"

void lerArquivo(a234 *A){ 
    int i;
    FILE *file;
    if(!(file = fopen("dados.txt","r"))) exit(0);
    while(! feof(file)){
        fscanf(file, "%d",&i);
        a234_insere(A, i);
    }
    fclose(file);
}
void gerarDados(){
    FILE *arq;
    arq = fopen("dados.txt", "w");
    if(arq == NULL){
        printf("Problema na abertura de arquivo\n");
        exit(0);
    }
    for(int j = 0; j < 10; j++){
        fprintf(arq, "%d\n", rand()%100+1);
    }
    fclose(arq);
    return;
}

