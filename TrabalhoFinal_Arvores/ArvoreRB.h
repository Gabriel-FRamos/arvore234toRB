#ifndef ARVORERB_H
#define	ARVORERB_H

typedef struct rb {
    int info;
    char cor;
    struct rb* esq;
    struct rb* dir;
    struct rb* pai;
} rb;

// Inicializa a árvore Rubro Negra, criando a sentinela com raiz = -1000 e cor preta. 
rb* rb_inicializaArvore();

// Insere o nó na árvore normalmente. Ao final, chama a função rb_balanceamentoInsercao. 
void rb_insereNo(rb* Arv, int valorNo);

//Rotação à esquerda
void rb_rotacaoEsq(rb* Arv, rb* noDesbalanceado);

//Rotação à direita
void rb_rotacaoDir(rb* Arv, rb* noDesbalanceado);

//Percorre a árvore em ordem.
// No caso da sentinela *Arv deve ser Arv->dir
// Mostrar a cor do nó
void rb_percorreOrdem(rb* Arv);

//Chama as rotações corretas para ajustar o balanceamento e faz o ajuste correto dos FBs
void rb_balanceamentoInsercao(rb* Arv, rb* noInserido);


// remove um nó da árvore e chama a função de rb_balanceamentoRemocao
// a função precisa guardar as seguintes informações:
//   - cor do nó removido (a função de balanceamento só é chamada em caso de remoção de nós pretos)
//   - o nó que ficou no lugar do nó removido (chamado de nó substituto)
//       - caso o substituto seja NULO, passar NULL para a função de balanceamento
//   - o pai do nó removido
void rb_removeNo(rb* Arv, int valor);

//Chama as rotações corretas para ajustar o balanceamento e faz o ajuste correto
// o 'noSubstituto' é o nó que ficou no lugar daquele que foi removido
// o valorRemovido servirá para saber se o noSubstituto está a esq ou dir do pai nos casos em que o 'noSubstituto' for Nulo
// implementar segundo as tabelas de referência
void rb_balanceamentoRemocao(rb* Arv, rb* noPai, rb* noSubstituto, int valorRemovido);


#endif	/* ARVORERB_H */

