#include <stdlib.h>
#include <string.h>

#include "map.h"

Map *map_create() {
	Map *tmpmap = (Map*) malloc(sizeof(Map));

	tmpmap->mtree = define();

	return(tmpmap);
}

bool map_insert(tipo_elem* e, Map* m) {

bool map_replace(tipo_elem*, Map*);
tipo_elem* map_search(int, Map*);
tipo_elem* map_remove(int, Map*);
bool map_destroy(Map*);


