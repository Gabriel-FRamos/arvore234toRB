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
void rb_rotacaoEsq(rb* Arv, rb* noDesbalanceado) {
	// Declaração de variáveis auxiliares para auxílio na alteração dos ponteiros pertinentes à rotação
	rb* filhoDir = noDesbalanceado->dir;		// Filho à dir. do nó desbalanceado 
	rb* netoEsq = filhoDir->esq;				// Neto à esquerda da sad do nó desbalanceado
	rb* avo = noDesbalanceado->pai; 

	// Realização da rotação
	noDesbalanceado->dir = netoEsq;			// Neto à esquerda se torna filho à direita do nó desbalanceado. Se neto à esq for NULL (não existir), não é preciso tratar.  

	if(netoEsq) { 	// Tratamento caso o neto à esq não seja nulo
		netoEsq->pai = noDesbalanceado; 	// Atualiza-se o campo pai do ex-neto à esquerda
	}

	filhoDir->esq = noDesbalanceado; 		// Pai/Nó desbalanceado vira filho à esq (do seu filho a dir). A partir daqui, filhoDir não tem mais ligação com neto à esq. 
	filhoDir->pai = avo; 					// O filho à dir. do nó desbalanceado vira a nova raiz da subárvore: Atualização do pai do filho à dir
	noDesbalanceado->pai = filhoDir; 		// Atualiza o pai da antiga raiz: filho a direita vira pai da antiga raiz/nó desbalanceado
	
	// 'filhoDir->pai' agora aponta (ou tem o mesmo endereço que) o nó 'avo'
	
	/*  Antes da rotação, não é possível saber se o nó desbalanceado era filho à dir ou esq do seu pai. 
	Como após a rotação a posição do nó desbalanceado muda, é necessário atualizar um dos ponteiros de filho do seu pai original, fazendo-o apontar para o nó filho adequado/atualizado após a rotação. 
	Isso é feito verificando-se o princípio de ordenação da árvore Rubro Negra (que também é uma árvore binária de busca).  
	*/
	if(avo->info <= filhoDir->info) {		// Á area que foi balanceada está na sad do pai inicial/original do nó desbalanceado
	    filhoDir->pai->dir = filhoDir;
	} else {
	    filhoDir->pai->esq = filhoDir; 		// Á area que foi balanceada está na sae do pai inicial/original do nó desbalanceado
	}

	// Ao contrário do que ocorre na Árvore AVL, não é necessário alterar o balanceamento de nós na rotação.
	return; 
} // Fim da função 'rb_rotacaoEsq(rb* Arv, rb* noDesbalanceado)'

void rb_rotacaoDir(rb* Arv, rb* noDesbalanceado) {
	// Declaração de variáveis auxiliares para auxílio na alteração dos ponteiros pertinentes à rotação
	rb* filhoEsq = noDesbalanceado->esq;		// Filho à esq. do nó desbalanceado 
	rb* netoDir = filhoEsq->dir;				// Neto à direita da sae do nó desbalanceado
	rb* avo = noDesbalanceado->pai; 

	// Realização da rotação
	noDesbalanceado->esq = netoDir;			// Neto à direita se torna filho à esquerda do nó desbalanceado. Se neto à dir for NULL (não existir), não é preciso tratar.  

	if(netoDir) { 	// Tratamento caso o neto à dir não seja nulo
		netoDir->pai = noDesbalanceado; 	// Atualiza-se o campo pai do ex-neto à direita
	}

	filhoEsq->dir = noDesbalanceado; 		// Pai/Nó desbalanceado vira filho à dir (do seu filho a esq). A partir daqui, filhoEsq não tem mais ligação com neto à dir. 
	filhoEsq->pai = avo; 					// O filho à esq. do nó desbalanceado vira a nova raiz da subárvore: Atualização do pai do filho à esq
	noDesbalanceado->pai = filhoEsq; 		// Atualiza o pai do nó desbalanceado: filho a direita, agora raiz da subárvore corrente, vira pai do nó desbalanceado
	
	// 'filhoEsq->pai' agora aponta (ou tem o mesmo endereço que) o nó 'avo'
	
	/*  Antes da rotação, não é possível saber se o nó desbalanceado era filho à dir ou esq do seu pai. 
	Como após a rotação a posição do nó desbalanceado muda, é necessário atualizar um dos ponteiros de filho do avô (pai original do nó desbalanceado), fazendo-o apontar para o nó filho adequado/atualizado após a rotação. 
	Isso é feito verificando-se o princípio de ordenação da árvore Rubro Negra (que também é uma árvore binária de busca).  
	*/
	if(avo->info <= filhoEsq->info) {		// Á area que foi balanceada está na sad do pai inicial/original do nó desbalanceado
	    filhoEsq->pai->dir = filhoEsq;		// FilhoEsq está a direita do 'avô'
	} else {								// FilhoEsq está à esquerda do avô (pois os valores de FilhoEsq são menores que a raiz/avô )
	    filhoEsq->pai->esq = filhoEsq; 		// Á area que foi balanceada está na sae do pai inicial/original do nó desbalanceado
	}

	// Ao contrário do que ocorre na Árvore AVL, não é necessário alterar o balanceamento de nós na rotação.
	return; 
}

void rb_percorreOrdem(rb* Arv);

void rb_balanceamentoInsercao(rb* Arv, rb* noInserido);

void rb_removeNo(rb* Arv, int valor);

void rb_balanceamentoRemocao(rb* Arv, rb* noPai, rb* noSubstituto, int valorRemovido);
