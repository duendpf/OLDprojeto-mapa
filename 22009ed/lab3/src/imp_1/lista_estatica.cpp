/* $Id: lista_estatica.cpp,v 1.1 2009/09/27 19:34:44 raitech Exp raitech $ */

/* lab3 de ED:
 *
 * implementacao da TAD de lista estatica sequencial
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_estatica.hpp"

/* define uma lista */
Lista::Lista() {
	nelem = 0;
	/* inicializa primeira celula para controle, ela de fato nao armazena um
	 * elemento da lista
	 */
	/* o construtor padrao ficou encarregado de fazer o seguinte:
	 *
	A[0].setChave(0);
	A[0].setInfo('\0');
	*/
}

/* retorna o tamanho de uma lista */
int
Lista::tamanho() {
	return(nelem);
}

/* retorna posicao do fim da lista */
int
Lista::fim() {
	return(nelem + 1);
}

/* retorna se a lista esta vazia */
bool
Lista::vazia() {
	return (nelem == 0);
}

/* retorna se a lista esta cheia */
bool
Lista::cheia() {
	return (nelem == MAX);
}

/* insere um elemento na posicao passada pelo 2o argumento da lista */
bool
Lista::inserir(Elem *el, int x) {
	int atual;
	if(cheia())
		return (FALSE);
	/* checando limites para insercao do novo elemento */
	else if(x > fim() || x < 1)
		return (FALSE);
	/* se passar pelos testes, entao insere elemento */
	else {
		for(atual = nelem; atual >= x; atual--) 
			A[atual+1] = A[atual];

		A[x] = *el; /* bit copy? */
		nelem++;
		return (TRUE);
	}
}

/* localiza um elemento dentro da lista e retorna sua posicao, se nao encontrar,
 * retorna 0 
 */
int
Lista::localizar(Elem *el) {
	int atual = 1;
	if(!vazia()) {
		while(atual <= nelem) {
			if(A[atual] == *el)
				return (atual);
			else 
				atual++;
		}
	}

	return (0);
}

/* retorna o  ponteiro pro elemento da posicao passada na lista, se existir */
Elem*
Lista::retornaEl(int x) {
	if(x >= fim() || x < 1 || vazia())
		return NULL;
	else return (&(A[x]));
}

/* remove o elemento da posicao dada da lista */
bool
Lista::removeEl(int x) {
	int atual;

	/* remover e como inserir, deve-se mover todos os elementos, pois a
	 * lista e estatica e sequencial
	 */
	if(x >= fim() || x < 1 || vazia())
		return (FALSE);
	else {
		for(atual = x+1; atual <= nelem; atual++)
			A[atual-1] = A[atual];
		nelem--;
	}

	return (TRUE);
}


/* funcao que imprime toda a lista */
void 
Lista::imprimir() {
	/* esta funcao o professor pediu que existisse quando estavamos no
	 * laboratorio, pois simplifica a impressao da lista, caso tenhamos de
	 * fazer isso por mais de uma vez. e uma extensao ao que ja existe na
	 * TAD
	 *
	 * esta funcao imprime a chave do elemento e a string info
	 * 
	 * a implementacao em C colocava a posicao do elemento dentro da string
	 * info, mas isso nao e interessante, ja que a posicao pode variar
	 * conforme as remocoes e insercoes
	 *
	 * portanto vou imprimir a posicao real na implementacao C++
	 */

	if(vazia()) 
		printf("\nlista vaiza!\n");
	else {
		int atual = 1;
		printf("\n");
		for(atual; atual <= nelem; atual++)
			printf("el. %d:\nChave: %d; Info: %s\n", atual, A[atual].getChave(), A[atual].getInfo());
	}
}



