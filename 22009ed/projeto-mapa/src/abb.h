/*
 * declaracoes de uma Arvore Binaria de Busca - especcialmente projetada para
 * suportar um mapa
 */

#ifndef _ABB_H_
#define _ABB_H_

#define true 1
#define false 0

#define bool int

typedef struct{
       int key;
       void *payload;
} elem_t;

typedef struct bstn_t {
        struct bstn_t *parent;
	struct bstn_t *lchild;
	struct bstn_t *rchild;
        elem_t *elem;
} bstnode_t;

typedef struct {
	bstnode_t *troot;
} bst_t;

bst_t *bst_define();

/* parametros:
 *
 * 1o: no para inicio da busca
 * 2o: chave a se buscar
 */
bstnode_t *bst_search(bstnode_t *, int);

/* parametros:
 *
 * 1o: no para iniciar busca pela menor chave da abb
 */
bstnode_t *bst_minimum(bstnode_t *);

/* parametros:
 *
 * 1o: no para iniciar busca pela maior chave da abb
 */
bstnode_t *bst_maximum(bstnode_t *);

/* parametros:
 *
 * 1o: no para retornar o seu sucessor, com relacao a chave
 */
bstnode_t *bst_successor(bstnode_t *);

/* parametros:
 *
 * 1o: arvore na qual se quer inserir
 * 2o: no a ser inserido
 *
 * ou seja: usuario tem de montar o no
 */
void bst_insert(bst_t *, bstnode_t *);

/*parametros:
 *
 * 1o: arvore da qual se quer remover
 * 2o: no a ser removido
 */
bstnode_t *bst_remove(bst_t *, bstnode_t *);

#endif
