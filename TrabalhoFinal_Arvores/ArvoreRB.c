#include <stdlib.h>
#include <stdio.h>
#include "ArvoreRB.h"

rb* rb_inicializaArvore() {
	rb* sentinela; 
	sentinela = (rb*) calloc(1, sizeof(rb)); 	
	sentinela->info = 1000; 
	sentinela->cor = 'p'; 		// O nó sentinela é preto. 
	sentinela->esq = NULL;
	sentinela->dir = NULL;
	sentinela->pai = NULL; 

	return sentinela; 
}
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
void rb_rotacaoEsq(rb* Arv, rb* noDesbalanceado);

void rb_rotacaoDir(rb* Arv, rb* noDesbalanceado);

void rb_percorreOrdem(rb* Arv);

void rb_balanceamentoInsercao(rb* Arv, rb* noInserido);

void rb_removeNo(rb* Arv, int valor);

void rb_balanceamentoRemocao(rb* Arv, rb* noPai, rb* noSubstituto, int valorRemovido);
