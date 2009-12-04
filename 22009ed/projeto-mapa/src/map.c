#include <stdlib.h>
#include <string.h>

#include "map.h"

map_t *map_define() {
	map_t *tmpmap = (map_t*) malloc(sizeof(map_t));

	tmpmap->mtree = bst_define();

	return(tmpmap);
}

bool map_insert(elem_t *e, map_t *m) {
	bstnode_t *thenode = bst_search(m->mtree->troot, e->key);

	if(thenode == NULL) {
		thenode = (bstnode_t*) malloc(sizeof(bstnode_t));
		thenode->elem = e;
		bst_insert(m->mtree, thenode);
		return(true);
	}

	return(false);
}
	
bool map_replace(elem_t *e, map_t *m) {
	bstnode_t *thenode = bst_search(m->mtree->troot, e->key);

	if(thenode == NULL) {
		return(false);
	}

	free(thenode->elem);
	thenode->elem = e;

	return(true);
}

elem_t *map_search(int k, map_t *m) {
	bstnode_t *thenode = bst_search(m->mtree->troot, k);

	if(thenode == NULL) {
		return(NULL);
	}

	return(thenode->elem);
}

elem_t *map_remove(int k, map_t *m) {
	bstnode_t *thenode = bst_search(m->mtree->troot, k);

	if(thenode == NULL) {
		return(NULL);
	}

	elem_t *tmpel = thenode->elem;
	bst_remove(m->mtree, thenode);
	free(thenode);

	return(tmpel);
}

