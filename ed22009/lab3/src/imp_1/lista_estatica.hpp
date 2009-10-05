/* $Id: lista_estatica.hpp,v 1.1 2009/09/27 19:34:44 raitech Exp raitech $ */

#ifndef LISTA_ESTATICA_HPP
#define LISTA_ESTATICA_HPP

#include "elem.hpp"

#define TRUE 1
#define FALSE 0
#define MAX 100

/* a lista! */
class Lista
{
	int nelem;
	Elem A[MAX+1];

	public:

	/* define uma lista */
	Lista();

	/* retorna o tamanho de uma lista */
	int
	tamanho();

	/* retorna posicao do fim da lista */
	int
	fim();

	/* retorna se a lista esta vazia */
	bool
	vazia();

	/* retorna se a lista esta cheia */
	bool
	cheia();

	/* insere um elemento na posicao passada pelo 2o argumento da lista */
	bool
	inserir(Elem*, int);

	/* localiza um elemento dentro da lista e retorna sua posicao, se nao encontrar,
	 * retorna 0 
	 */
	int
	localizar(Elem*);


	/* retorna o  ponteiro pro elemento da posicao passada na lista, se existir */
	Elem*
	retornaEl(int);

	/* remove o elemento da posicao dada da lista */
	bool
	removeEl(int);

	/* funcao que imprime toda a lista */
	void 
	imprimir();
};

#endif
