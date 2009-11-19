#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.h"
#include "arvore_binaria.h"

int
main(int argc, char** argv) {

	// initalizing the bin.tree: to this, init a element pointer and a node
	// pointer, and only with these pointers do the party!!!
	
	// first: the root
	Elem *el = new Elem(1, "gatinha");
	BTNode<Elem> *node = new BTNode<Elem>(NULL, *el);
	BinTree<Elem> *bt = new BinTree<Elem>(node);

	//second: the left
	el = new Elem(2, "carne fresca");
	BTNode<Elem> *actual = bt->root();
	bt->insertLeft(actual, *el);

	//and so on...
	el = new Elem(3, "vinho branco");
	bt->insertRight(actual, *el);
	actual = actual->getLeft();

	el = new Elem(4, "de vaca");
	bt->insertLeft(actual, *el);

	el = new Elem(5, "de gente");
	bt->insertRight(actual, *el);
	actual = actual->getRight();

	el = new Elem(6, "morta");
	actual = bt->insertLeft(actual, *el);
	
	el = new Elem(7, "podre");
	bt->insertLeft(actual, *el);
	actual = bt->root()->getRight();

	el = new Elem(8, "de uvas");
	actual = bt->insertLeft(actual, *el);

	el = new Elem(9, "nao maduras");
	bt->insertLeft(actual, *el);

	el = new Elem(10, "verdes");
	bt->insertRight(actual, *el);
	actual = bt->parent(actual);

	el = new Elem(11, "de gente");
	bt->insertRight(actual, *el);

	el = new Elem(8, "xxxx");
	node = bt->root();
	if(node == NULL)
		printf("root null\n");
	actual = bt->search(node, *el);

	if(actual == NULL)
		printf("actual null\n");

	return(0);
}



