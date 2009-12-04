/*
 * Lucas Eduardo Visolli Sala - N.USP 6783652
 * Fisica Computacional - IFSC - USP
 */

#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

bst_t *bst_define(void) {
	tree_t *tmp = (tree_t*) malloc(sizeof(tree_t));
	tmp->root = NULL;
	tmp->nelem = 0;

	return(tmp);
}

/* 
 * codigo inspirado de:
 *
 * http://cslibrary.stanford.edu/110/BinaryTrees.html
 *
 * para bst_size()
 */
int bst_size(node_t *n) {
	if(n == NULL) {
		return(0);
	} else {
		return(bst_size(n->lchild) + 1 + bst_size(n->rchild));
	}
}



void bst_swap(bst_t *t, node_t *n1, node_t *n2) {
	if(t != NULL && n1 != NULL && n2 != NULL) {
		elem_t *aux;

		aux = n1->elem;
		n1->elem = n2->elem;
		n2->elem = aux;
	} else {
		printf("\nbst_swap(): NULL!\n");
		exit(1);
	}
}


/* 
 * retorna um ponteiro para elem_t, pois quem chama essa funcao deve ter em
 * mente que tem a responsabilidade de desalocar toda a complexidade estrutural
 * alocada para o dado em si
 */

elem_t *bst_replace(bst_t *t, node_t *n, elem_t *e) {
	if(t == NULL || n == NULL) {
		printf("\nbst_replace(): NULL!\n");
		exit(1);
	}

	elem_t *tmp = n->elem;
	n->elem = e;

	return(tmp);

bool bst_isempty(bst_t *);
bool bst_isinternal(bst_t *, node_t *);
bool bst_isexternal(bst_t *, node_t *);
bool bst_isroot(bst_t *, node_t *);


node_t *bst_root(bst_t *);
node_t *bst_parent(bst_t *, node_t *);
node_t *bst_leftchild(bst_t *, node_t *);
node_t *bst_rightchild(bst_t *, node_t *);
node_t *bst_sibling(bst_t *, node_t *);
node_t *bst_expandexternal(bst_t *, node_t *);
node_t *bst_removeaboveexternal(bst_t *, node_t *);
node_t *bst_insert(bst_t *, elem_t *);
node_t *bst_insertleft(bst_t *, node_t *, elem_t *);
node_t *bst_insertright(bst_t *, node_t *, elem_t *);
node_t *bst_search(bst_t *, node_t *, elem_t *);
node_t *bst_remove(bst_t *, node_t *);


