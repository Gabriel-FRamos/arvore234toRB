#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "E-S_dados.h"

a234* lerArquivo(){ 
    int i;
    FILE *file;
    a234* A = NULL; 
    if(!(file = fopen("dados.txt","r"))) exit(0);
    while(! feof(file)){
        fscanf(file, "%d",&i);
        A = a234_insere(A, i);
    }
    fclose(file);
    return A;
}
/*void gerarDados(){
    int aux = 0;
    FILE *arq;
    arq = fopen("dados.txt", "w");
    if(arq == NULL){
        printf("Problema na abertura de arquivo\n");
        exit(0);
    }
    for(int j = 0; j < 10; j++){
        fprintf(arq, "%d\n", rand());
    }
    fclose(arq);
    return;
}
 * */

