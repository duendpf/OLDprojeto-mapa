#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lista_estatica.h"

int
main(int argc, char **argv) {
	lista *l = (lista*) malloc(sizeof(lista));

	elem *el = NULL; 
	char tmp[50];

	int i =0;
	for(i; i < MAX; i++) {
		el = (elem*) malloc(sizeof(elem));
		el->chave = i+1;
		sprintf(tmp, "Eu sou el-> %d", i+1);
		strcpy(el->info, tmp);

		inserir_el(el, i+1, l);
		free(el);
	}

	/* verificando tamanho da lista */
	printf("\nTamanho da lista: %d\n", tamanho_lista(l));
	imprimir_lista(l);

	printf("\nModificando lista, removendo itens:\n");
	/* como remover intens nao e a mesma coisa que alterar esses itens, as
	 * strings de informacao continuarao com o index anterior 
	 */

	remover_el(10, l);
	/* verificando tamanho da lista */
	printf("\nTamanho da lista: %d\n", tamanho_lista(l));
	imprimir_lista(l);

	/* localizando um elemento. isso e feito atraves da chave dele, mas eu
	 * so preciso saber disso para me organizar. apesar de que preciso
	 * fornecer a funcao que compara se os elementos da lista sao ou nao
	 * iguais
	 */
	/* o elemento 1 esta na lista? */
	el = (elem*) malloc(sizeof(elem));
	el->chave = 1;
	if(localizar_el(el, l))
		printf("\nElemento 1 esta na lista!\n");
	else printf("\nElemento 1 nao esta na lista!\n");

	/* el 10 esta na lista? */
	el->chave = 10;
	if(localizar_el(el, l))
		printf("\nElemento 10 esta na lista!\n");
	else printf("\nElemento 10 nao esta na lista!\n");

	free(el);

	return(0);
}

		
