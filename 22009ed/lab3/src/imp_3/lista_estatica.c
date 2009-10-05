/* $Id: lista_estatica.c,v 1.3 2009/09/28 02:51:42 raitech Exp raitech $ */

/* lab3 de ED:
 *
 * implementacao da TAD de lista estatica sequencial
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_estatica.h"

/* define uma lista */
void
definir_lista(lista *l) {
	l->nelem = 0;
	/* inicializa primeira celula para controle, ela de fato nao armazena um
	 * elemento da lista
	 */
	l->A[0].chave = 0; 
	l->A[0].info[0] = '\0';
}

/* retorna o tamanho de uma lista */
int
tamanho_lista(lista *l) {
	return(l->nelem);
}

/* retorna posicao do fim da lista */
int
fim_lista(lista *l) {
	return(l->nelem + 1);
}

/* retorna se a lista esta vazia */
bool
lista_vazia(lista *l) {
	return (l->nelem == 0);
}

/* retorna se a lista esta cheia */
bool
lista_cheia(lista *l) {
	return (l->nelem == MAX);
}

/* insere um elemento na posicao passada pelo 2o argumento da lista */
bool
inserir_el(elem *el, lista *l) {
	int atual;
	if(lista_cheia(l))
		return (FALSE);

	if(lista_vazia(l)) {
		l->A[l->nelem+1] = *el;
		l->nelem++;
		return (TRUE);
	} else {
	/*	for(atual = l->nelem; atual >= x; atual--) 
			l->A[atual+1] = l->A[atual];
	*/
		
		/* para um primeiro teste, vou inserir um elemento no final da
		 * lista, que tem custo baixo, e vou mandar qsort ordenar
		 */
		atual = fim_lista(l);
		l->A[atual] = *el;
		l->nelem++;
		/* precisei somar um ao tamanho, para percorrer toda a lista ...
		 */
		qsort(l->A, tamanho_lista(l)+1, sizeof(elem), igual_el);
		return (TRUE);
	}
}

/* localiza um elemento dentro da lista e retorna sua posicao, se nao encontrar,
 * retorna 0 
 */
int
localizar_el(elem *el, lista *l) {
	int atual = 1;
	if(!lista_vazia(l)) {
		while(atual <= l->nelem) {
			if(igual_el(&(l->A[atual]), el) == 0)
				return (atual);
			else 
				atual++;
		}
	}

	return (0);
}

/* define a comparacao entre dois elementos da lista, retornando nos coformes da
 * strcasecmp()
 */
int
igual_el(void *el1, void *el2) {
	elem *e1 = el1, *e2 = el2;
	return (strcasecmp(e1->info, e2->info));
}

/* retorna o  ponteiro pro elemento da posicao passada na lista, se existir */
elem*
retornar_el(int x, lista *l) {
	if(x >= fim_lista(l) || x < 1 || lista_vazia(l))
		return NULL;
	else return (&(l->A[x]));
}

/* remove o elemento da posicao dada da lista */
bool
remover_el(int x, lista *l) {
	int atual;

	/* remover e como inserir, deve-se mover todos os elementos, pois a
	 * lista e estatica e sequencial
	 */
	if(x >= fim_lista(l) || x < 1 || lista_vazia(l))
		return (FALSE);
	else {
		for(atual = x+1; atual <= l->nelem; atual++)
			l->A[atual-1] = l->A[atual];
		l->nelem--;
	}

	return (TRUE);
}


/* funcao que imprime toda a lista */
void 
imprimir_lista(lista *l) {
	/* esta funcao o professor pediu que existisse quando estavamos no
	 * laboratorio, pois simplifica a impressao da lista, caso tenhamos de
	 * fazer isso por mais de uma vez. e uma extensao ao que ja existe na
	 * TAD
	 *
	 * esta funcao imprime a chave do elemento e a string info
	 */

	if(lista_vazia(l)) 
		printf("\nlista vaiza!\n");
	else {
		int atual = 1;
		printf("\n");
		for(atual; atual <= l->nelem; atual++)
			printf("Chave: %d; Info: %s\n", l->A[atual].chave, l->A[atual].info);
	}
}



