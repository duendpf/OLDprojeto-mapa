/*
 * Declaracao da TAD mapa
 */

#ifndef _MAP_H_
#define _MAP_H_

#include "abb.h"

typedef struct {
	bst_t *mtree;
} map_t;

map_t *map_define();
bool map_insert(elem_t *, map_t *);
bool map_replace(elem_t *, map_t *);
elem_t *map_search(int, map_t *);
elem_t *map_remove(int, map_t *);

#endif
