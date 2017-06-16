#include <stdlib.h>
#include <stdio.h>
#include "ArvoreRB.h"

void rb_insereNo(rb* A, int valorNo){ // Todo nó inserido chama a função de balancemaento! 
    // Aloca novo nó. 
    rb* novoNo;
    novoNo = (rb*) calloc(1, sizeof(rb));
    novoNo->info = valorNo;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->pai = NULL; 
    novoNo->cor = 'v'; // Todo nó novo inserido é vermelho; 

    // Procura na árvore o local de inserção do novo nó criado
    rb* noAtual = A->dir; 
    rb* noPai = A; 

    while(noAtual != NULL) {
        if(noAtual != NULL) {
            if(valorNo > noAtual->info) {
                noPai = noAtual;
                noAtual = noAtual->dir; 
            }else{
                noPai = noAtual;
                noAtual = noAtual->esq;
            }
        }
    }
    // Insere o novo nó no local correto
    if(valorNo > noPai->info) {
        noPai->dir = novoNo;
    }else{
        noPai->esq = novoNo; 
    }
    novoNo->pai = noPai; 

    // Ao contrário da AVL (if noPai != A), Todo nó inserido chama a função de balanceamento, pois pode ocorrer a quebra da regra (Nó vermelho só tem filho preto)
    rb_balanceamentoInsercao(A, novoNo); // Na inserção passa o nó inserido, na remoção passa o pai. 

    return; 
}
void removeArvoreRB(){
    printf("o");
}
void converteRBto234(){
    printf("o");
}

