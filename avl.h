#ifndef AVL_H
#define AVL_H

struct node_ {
	long long int data;
    long long int last_seen;
	char bal; // na verdade precisamos de 2-bits
    int altura;
	struct node_ *dir, *esq;
};

typedef struct node_ node;

typedef struct {
	node* raiz;
} avl;


// funções públicas

void inicializar( avl* arvore ); // inicializa uma árvore já alocada pelo usuário
void destruir( avl* arvore ); // desaloca toda memória alocada pelas funções públicas

void inserir( avl* arvore, long long int data, long long int second_data ); // insere data na árvore, sem repetição
long long int retornar( avl* arvore, long long int data ); // insere data na árvore, sem repetição

int altura(node *p);

#endif