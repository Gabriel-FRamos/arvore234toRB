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

void rb_insereNo(rb* Arv, int valorNo);

void rb_rotacaoEsq(rb* Arv, rb* noDesbalanceado);

void rb_rotacaoDir(rb* Arv, rb* noDesbalanceado);

void rb_percorreOrdem(rb* Arv);

void rb_balanceamentoInsercao(rb* Arv, rb* noInserido);

void rb_removeNo(rb* Arv, int valor);

void rb_balanceamentoRemocao(rb* Arv, rb* noPai, rb* noSubstituto, int valorRemovido);
