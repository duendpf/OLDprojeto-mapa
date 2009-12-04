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

typedef struct {
        struct node_t *parent, *lchild, *rchild;
        elem_t *elem;
} node_t;

typedef struct {
        node_t *root;
        int nelem;
} bst_t;

bst_t *bst_define(void);
int bst_size(node_t *);

void bst_swap(bst_t *, node_t *, node_t *);

/* 
 * retorna um ponteiro para elem_t, pois quem chama essa funcao deve ter em
 * mente que tem a responsabilidade de desalocar toda a complexidade estrutural
 * alocada para o dado em si
 */

elem_t *bst_replace(bst_t *, node_t *, elem_t *);

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

#endif
