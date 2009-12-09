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

	char nome[100];
	elem_t *oelem = (elem_t*) malloc(sizeof(elem_t));

	char *tmpnome;
	elem_t *tmpe;

	printf("Digite uma chave (int): ");
	scanf("%d", &oelem->key);
	printf("Digite um nome (max 99): ");
	oelem->payload = nome;
	scanf("%s", nome);

	map_t *amap = map_define();
	map_insert(oelem, amap);

	tmpnome = (char*) malloc(sizeof(char)*100);
	tmpe	= (elem_t*) malloc(sizeof(elem_t));
	printf("Digite uma chave (int): ");
	scanf("%d", &tmpe->key);
	printf("Digite um nome (max 99): ");
	scanf("%s", tmpnome);
	tmpe->payload = tmpnome;

	map_insert(tmpe, amap);

	tmpnome = (char*) malloc(sizeof(char)*100);
	tmpe	= (elem_t*) malloc(sizeof(elem_t));
	printf("Digite uma chave (int): ");
	scanf("%d", &tmpe->key);
	printf("Digite um nome (max 99): ");
	scanf("%s", tmpnome);
	tmpe->payload = tmpnome;

	map_insert(tmpe, amap);


	printf("\nDigite uma chave: ");
	int i = 0;
	scanf("%d", &i);
	if(tmpe = map_search(i, amap)) {
		printf("%s", tmpe->payload);
	} else {
		printf("... nothing, at alll ....\n");
	}

	if(tmpe = map_remove(i, amap)) {
		printf("\nRemovida chave %d contendo %s\n", i, tmpe->payload);
	} else {
		printf("\nremovido nada!!!! NAAADAAAAAAAAA!!!!\n");
	}
	if(tmpe = map_search(i, amap)) {
		printf("%s", tmpe->payload);
	} else {
		printf("... nothing, at alll ....\n");
	}


	printf("\n\t ---==={FIM  TESTE MAPA}===---\n\n");
	/* *** fim teste Mapa *** */
	return(0);
}

