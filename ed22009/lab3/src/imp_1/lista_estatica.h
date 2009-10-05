/* $Id: lista_estatica.h,v 1.2 2009/09/25 23:19:14 raitech Exp raitech $ */

#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#define TRUE 1
#define FALSE 0
#define bool int
#define MAX 100

/* elemento da lista */
struct {
	int chave;
	char info[50];
} typedef elem;

/* a lista! */
struct {
	int nelem;
	elem A[MAX+1];
} typedef lista;

/* define uma lista */
void
definir_lista(lista*);

/* retorna o tamanho de uma lista */
int
tamanho_lista(lista*);

/* retorna posicao do fim da lista */
int
fim_lista(lista*);

/* retorna se a lista esta vazia */
bool
lista_vazia(lista*);

/* retorna se a lista esta cheia */
bool
lista_cheia(lista*);

/* insere um elemento na posicao passada pelo 2o argumento da lista */
bool
inserir_el(elem*, int, lista*);

/* localiza um elemento dentro da lista e retorna sua posicao, se nao encontrar,
 * retorna 0 
 */
int
localizar_el(elem*, lista*);

/* define a comparacao entre dois elementos da lista, retornando  se sao ou nao
 * iguais
 */
bool
igual_el(elem*, elem*);

/* retorna o  ponteiro pro elemento da posicao passada na lista, se existir */
elem*
retornar_el(int, lista*);

/* remove o elemento da posicao dada da lista */
bool
remover_el(int, lista*);

/* funcao que imprime toda a lista */
void 
imprimir_lista(lista*);

#endif
