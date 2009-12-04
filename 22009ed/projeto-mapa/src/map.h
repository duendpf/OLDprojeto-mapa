/*
 * Declaracao da TAD mapa
 */

#ifndef _MAP_H_
#define _MAP_H_

#include "abb.h"

typedef struct {
	Tree *mtree;
} Map;

Map *map_create();
bool map_insert(tipo_elem*, Map*);
bool map_replace(tipo_elem*, Map*);
tipo_elem* map_search(int, Map*);
tipo_elem* map_remove(int, Map*);
bool map_destroy(Map*);

#endif
