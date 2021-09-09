#include <stdlib.h>
#include "avl.h"
#include "queue.h"

void inicializar( avl* arvore ) {
	arvore->raiz = 0;
}

void destruir_privado( node *p ) {
    // implementar
    if (p->esq)
        destruir_privado(p->esq);
    if (p->dir)
        destruir_privado(p->dir);
    free(p);

}

void destruir( avl* arvore ) {
    destruir_privado(arvore->raiz);
}

node* rotEE( node* A ) { 
    // implementar
    node* B = A->esq;
    A->esq = B->dir;
    B->dir = A;

    A->bal = 0;
    B->bal = 0;
    return B;
}

node* rotDD( node* A ) {
	// implementar
    node* B = A->dir;
    A->dir = B->esq;
    B->esq = A;

    A->bal = 0;
    B->bal = 0;
    return B;
}

node* rotED( node* A ) {
	// implementar
    node* B = A->esq;
    node* C = B->dir;
    B->dir = C->esq;
    C->esq = B;
    A->esq = C->dir;
    C->dir = A;
    if (C->bal == -1) {
        A->bal = 0;
        B->bal = 1;
        C->bal = 0;
    } else if (C->bal == 1) {
        A->bal = -1;
        B->bal = 0;
        C->bal = 0;
    } else { // C->bal == 0
        A->bal = 0;
        B->bal = 0;
    }
    return C;
}

node* rotDE( node* A ) {
	// implementar
    node* B = A->dir;
    node* C = B->esq;
    B->esq = C->dir;
    C->dir = B;
    A->dir = C->esq;
    C->esq = A;
    if (C->bal == -1) {
        A->bal = 1;
        B->bal = 0;
        C->bal = 0;
    } else if (C->bal == 1) {
        A->bal = 0;
        B->bal = -1;
        C->bal = 0;
    } else { // C->bal == 0
        A->bal = 0;
        B->bal = 0;
    }
    return C;
}

node* inserir_privado( node* p, long long int data, long long int second_data, int *mudouAltura) {
	if(!p) {
		node* novo = (node*)malloc(sizeof(node));
		novo->data = data;
        novo->last_seen = second_data;
		novo->bal = 0;
        novo->altura = 0;
		novo->dir = novo->esq = 0;
		*mudouAltura = 1;
		return novo;
	}
	
    // implementar
    // Insert
    int mudarAltura = 0;

    // Already exists
    if (data == p->data) {
        p->last_seen = second_data;
        return p;
    }

    // Insert left
    if (data < p->data) {
        p->esq = inserir_privado(p->esq, data, second_data, &mudarAltura);
        if (mudarAltura) {p->bal -= 1;}
    
    // Insert right
    } else if (data > p->data) {
        p->dir = inserir_privado(p->dir, data, second_data, &mudarAltura);
        if (mudarAltura) {p->bal += 1;}
    }

    // If this insert was unbalanced, report height change
    if (p->bal != 0)
        *mudouAltura = 1;
    
    // Correct tree if too unbalanced
    if (p->bal >= 2) {
        if (p->dir->bal >= 1) {
            p = rotDD(p);
        } else if (p->dir->bal <= -1) {
            p = rotDE(p);
        }
        
    } else if (p->bal <= -2) {
        if (p->esq->bal >= 1) {
            p = rotED(p);
        } else if (p->esq->bal <= -1) {
            p = rotEE(p);
        }
    }

    return p;
}


void inserir( avl* arvore, long long int data, long long int second_data) {
	int mudouAltura = 0;
	arvore->raiz = inserir_privado( arvore->raiz, data, second_data, &mudouAltura );
	
}


long long int retornar_privado(node *p, long long int data) {
    if (p->data == data)
        return p->last_seen;

    if (data < p->data && p->esq) {
        return retornar_privado(p->esq, data);
    }
    
    if (p->data < data && p->dir) {
        return retornar_privado(p->dir, data);
    }

    return -1;
}


long long int retornar(avl* arvore, long long int data) {
    return retornar_privado(arvore->raiz, data);
}


int altura(node *p) {
    if (p->bal >= 0) {
        if (p->esq)
            return 1+altura(p->esq);
        else
            return 1;
    } else {
        if (p->dir)
            return 1+altura(p->dir);
        else
            return 1;
    }
}

void calcula_bal(node* p) {
    if (p->esq) {
        calcula_bal(p->esq);
        p->altura = p->esq->altura + 1;
    } 
    
    if (p->dir) {
        calcula_bal(p->dir);
        p->altura = (p->dir->altura + 1 > p->altura) * (p->dir->altura + 1);
    }

    p->bal = p->dir->altura - p->esq->altura;

}

