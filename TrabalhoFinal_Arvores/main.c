#include <stdio.h>
#include <stdlib.h>
#include "Arvore234.h"
#include "ArvoreRB.h"
#include "E-S_dados.h"

int main() {
    int flagMenu = 0, escolha1 = 0, escolha2 = 0;
    int a234_dado, rb_dado;
    a234* Arvore234 = a234_inicializa();
    gerarDados();
    //lerArquivo(Arvore234);
    printf("\tArvore 2-3-4\n");
    a234_imprimir(Arvore234);
    
    while(flagMenu == 0){
        printf("[1] Inserir novo elemento na árvore 2-3-4\n");
        printf("[2] Remover elemento da árvore 2-3-4\n");
        printf("[3] Imprimir árvore 2-3-4\n");
        printf("[4] Converter em uma árvore rubro-negra\n");
        printf("[5] Sair\n");
        scanf("%d", &escolha1);
        
        switch(escolha1){
            case 1:
                //Função que insere elemento na 2-3-4
                printf("Digite o elemento a ser inserido na Arvore 2-3-4: ");
                scanf("%d", &a234_dado);
                //a234_insere(Arvore234, a234_dado);
                system("clear");
                break;
            case 2:
                //Função que remove elemento da 2-3-4
                printf("Digite o elemento a ser removido da Arvore 2-3-4: ");
                scanf("%d", &a234_dado);
                //a234_remove(Arvore234, a234_dado);
                system("clear");
                break;
            case 3:
                //Função que imprime a arvore 2-3-4
                a234_imprimir(Arvore234);
                break;
            case 4:
                //Chama a função que converte
                //converte234toRB();
                printf("\tArvore 2-3-4 convertida em Rubro-Negra");
                flagMenu = 1;
                //imprimirArvoreRB();
                break;
            case 5:
                exit(1);
                break;
        }
        while(flagMenu == 1){
            printf("\n[1] Inserir novo elemento na árvore Rubro-Negra\n");
            printf("[2] Remover elemento da árvore Rubro-Negra\n");
            printf("[3] Imprimir árvore Rubro-Negra\n");
            printf("[4] Sair\n");
            scanf("%d", &escolha2);
        
        switch(escolha2){
            case 1:
                //Função que insere elemento na rubro-negra
                printf("Digite o elemento a ser inserido na Arvore Rubro-Negra: ");
                scanf("%d", &rb_dado);
                //insereArvoreRB();
                system("clear");
                break;
            case 2:
                //Função que remove elemento na rubro-negra
                printf("Digite o elemento a ser removido da Arvore Rubro-Negra: ");
                scanf("%d", &rb_dado);
                //removeArvoreRB();
                system("clear");
                break;
            case 3:
                //Função que imprime a rubro-negra
                //imprimirArvoreRB();
                break;
            case 4:
                escolha1 = 5;
                exit(1);
                break;
            }
        }
    }
    return 0;
}

