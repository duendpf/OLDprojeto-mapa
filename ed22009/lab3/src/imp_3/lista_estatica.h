/* $Id: lista_estatica.h,v 1.3 2009/09/28 02:51:42 raitech Exp raitech $ */

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
inserir_el(elem*, lista*);

/* localiza um elemento dentro da lista e retorna sua posicao, se nao encontrar,
 * retorna 0 
 */
int
localizar_el(elem*, lista*);

/* define a comparacao entre dois elementos da lista, retornando
 * < 0: se primeiro menor que segundo
 * = 0: se primeiro igual a segundo
 * > 0: se primeiro maior que segundo
 */
int
igual_el(void*, void*);

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
