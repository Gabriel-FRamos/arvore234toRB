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
void a234_insere(a234 *a, int info);
void a234_remove(a234 *a, int info);
void a234_imprimir(a234 *a);
void converte234toRB();

#endif	/* ARVORE234_H */

