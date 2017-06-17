#ifndef ARVORE234_H
#define	ARVORE234_H


struct a234{
    int valor[3];
    int numChaves;
    struct a234 *filho[4];
    struct a234 *pai;
};
typedef struct a234 a234;

a234* a234_inicializaArvore();
a234 *a234_busca(a234 *a, int info, int *tam, int *aux);
int a234_buscaBinaria(a234 *a, int info);
a234 *a234_insereBusca(a234 *a, int info, int *tam, int *aux);
void a234_insereChave(a234 *a, int info, a234 *filho);
a234 *a234_insere(a234 *a, int info);
void a234_remove(a234 *a, int info);
void a234_imprimir(a234 *a);
void converte234toRB();

#endif	/* ARVORE234_H */

