#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

bst_t *bst_define() {
	bst_t *tmpt = (bst_t*) malloc(sizeof(bst_t));
	tmpt->troot = NULL;

	return(tmpt);
}

/* parametros:
 *
 * 1o: no para inicio da busca
 * 2o: chave a se buscar
 */
bstnode_t *bst_search(bstnode_t *n, int k) {
	if(n == NULL || k == n->elem->key) {
		return(n);
	}

	if(k < n->elem->key) {
		return(bst_search(n->lchild, k));
	} else {
		return(bst_search(n->rchild, k));
	}
}

/* parametros:
 *
 * 1o: no para iniciar busca pela menor chave da abb
 */
bstnode_t *bst_minimum(bstnode_t *n) {
	while(n->lchild != NULL) {
		n = n->lchild;
	}

	return(n);
}

/* parametros:
 *
 * 1o: no para iniciar busca pela maior chave da abb
 */
bstnode_t *bst_maximum(bstnode_t *n) {
	while(n->rchild != NULL) {
		n = n->rchild;
	}

	return(n);
}

/* parametros:
 *
 * 1o: no para retornar o seu sucessor, com relacao a chave
 */
bstnode_t *bst_successor(bstnode_t *n) {
	if(n->rchild != NULL) {
		return(bst_minimum(n->rchild));
	} else {
		bstnode_t *y = n->parent;
		while(y != NULL && n == y->rchild) {
			n = y;
			y = y->parent;
		}

		return(y);
	}
}
	
/* parametros:
 *
 * 1o: arvore na qual se quer inserir
 * 2o: no a ser inserido
 *
 * ou seja: usuario tem de montar o no
 */
void bst_insert(bst_t *t, bstnode_t *n) {
	bstnode_t *y = NULL;
	bstnode_t *x = t->troot;
	while(x != NULL) {
		y = x;
		if(n->elem->key < x->elem->key) {
			x = x->lchild;
		} else {
			x = x->rchild;
		}
	}

	n->parent = y;

	if(y == NULL) {
		t->troot = n;
	} else if(n->elem->key < y->elem->key) {
		y->lchild = n;
	} else {
		y->rchild = n;
	}
}

/*parametros:
 *
 * 1o: arvore da qual se quer remover
 * 2o: no a ser removido
 */
bstnode_t *bst_remove(bst_t *t, bstnode_t *n) {
	bstnode_t *y = NULL, *x = NULL;

	if(n->lchild == NULL || n->rchild == NULL) {
		y = n;
	} else {
		y = bst_successor(n);
	}

	if(y->lchild != NULL) {
		x = y->lchild;
	} else {
		x = y->rchild;
	}

	if(x != NULL) {
		x->parent = y->parent;
	}

	if(y->parent == NULL) {
		t->troot = x;
	} else if(y == y->parent->lchild) {
		y->parent->lchild = x;
	} else {
		y->parent->rchild = x;
	}

	if(y != n) {
		n->elem = y->elem;
	}

	return(y);
}

