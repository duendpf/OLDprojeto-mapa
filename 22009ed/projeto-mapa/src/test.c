/*
 * programa de teste para ABB e Mapa sobre ABB do grupo
 * KINDEROVO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
/* map.h inclui abb.h */


int main (void){
	bst_t* T = bst_define();
	elem_t *el;
	char aux[10];
	bstnode_t* v;

	/* *** inicio teste ABB *** */
	printf("\n\t ---==={INICIO TESTE ABB}===---\n\n");

	/* Cria elemento */
	el = (elem_t*) malloc(sizeof(elem_t));
	el->key = 5;
	strcpy(aux,"ElementoA");
	el->payload = (char *) malloc(strlen(aux));
	strcpy(el->payload, aux);

	//Adiciona o elemento na arvore
	v = (bstnode_t*) malloc(sizeof(bstnode_t));
	v->elem = el;
	bst_insert(T, v);

	el = (elem_t*) malloc(sizeof(elem_t));
	el->key = 3;
	strcpy(aux,"ElementoB");
	el->payload = (char *) malloc(strlen(aux));
	strcpy(el->payload, aux);

	v = (bstnode_t*) malloc(sizeof(bstnode_t));
	v->elem = el;
	bst_insert(T, v);

	el = (elem_t*) malloc(sizeof(elem_t));
	el->key = 7;
	strcpy(aux,"ElementoC");
	el->payload = (char *) malloc(strlen(aux));
	strcpy(el->payload, aux);

	v = (bstnode_t*) malloc(sizeof(bstnode_t));
	v->elem = el;
	bst_insert(T, v);

	el = (elem_t*) malloc(sizeof(elem_t));
	el->key = 2;
	strcpy(aux,"ElementoD");
	el->payload = (char *) malloc(strlen(aux));
	strcpy(el->payload, aux);

	v = (bstnode_t*) malloc(sizeof(bstnode_t));
	v->elem = el;
	bst_insert(T, v);

	el = (elem_t*) malloc(sizeof(elem_t));
	el->key = 4;
	strcpy(aux,"ElementoE");
	el->payload = (char *) malloc(strlen(aux));
	strcpy(el->payload, aux);

	v = (bstnode_t*) malloc(sizeof(bstnode_t));
	v->elem = el;
	bst_insert(T, v);

	el = (elem_t*) malloc(sizeof(elem_t));
	el->key = 10;
	strcpy(aux,"ElementoF");
	el->payload = (char *) malloc(strlen(aux));
	strcpy(el->payload, aux);

	v = (bstnode_t*) malloc(sizeof(bstnode_t));
	v->elem = el;
	bst_insert(T, v);

	el = (elem_t*) malloc(sizeof(elem_t));
	el->key = 8;
	strcpy(aux,"ElementoG");
	el->payload = (char *) malloc(strlen(aux));
	strcpy(el->payload, aux);

	v = (bstnode_t*) malloc(sizeof(bstnode_t));
	v->elem = el;
	bst_insert(T, v);

	v = bst_search(T->troot, 8);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s\n", v->elem->payload);
	}

	v = bst_search(T->troot, 10);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s\n", v->elem->payload);
	}

	v = bst_search(T->troot, 4);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s\n", v->elem->payload);
	}

	v = bst_search(T->troot, 2);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s\n", v->elem->payload);
	}

	v = bst_search(T->troot, 7);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s\n", v->elem->payload);
	}

	v = bst_search(T->troot, 3);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s\n", v->elem->payload);
	}

	v = bst_search(T->troot, 5);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s\n", v->elem->payload);
	}

	v = bst_search(T->troot, 3);
	bstnode_t *alter_v = bst_remove(T, v);
	if(alter_v == NULL) {
		printf("\nFucking hell!!!! Nao removeu ...\n");
	} else {
		printf("\nHUHUULLLL: %s %i\n", alter_v->elem->payload, alter_v->elem->key);
	}

	v = bst_search(T->troot, 3);
	if(v == NULL) {
		printf("\nIsso mesmo, nao achou 3 pq nao tem mais!\n");
	} else {
		printf("\n0_o corree!!! Tem fantasma na arvore!\n");
	}
	v = bst_search(T->troot, 2);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s %i\n", v->elem->payload, v->elem->key);
	}

	v = bst_search(T->troot, 4);
	if(v == NULL) {
		printf("\nFucking hell!!!! Nao achou ...\n");
	} else {
		printf("\nHUHUULLLL: %s %i\n", v->elem->payload, v->elem->key);
	}
	printf("\n\t ---==={FIM TESTE ABB}===---\n\n");
	/* *** fim teste ABB *** */

	/* *** inicio teste Mapa *** */
	printf("\n\t ---==={INICIO TESTE MAPA}===---\n\n");
	printf("\n\t ---==={FIM  TESTE MAPA}===---\n\n");
	/* *** fim teste Mapa *** */

	return(0);
}

