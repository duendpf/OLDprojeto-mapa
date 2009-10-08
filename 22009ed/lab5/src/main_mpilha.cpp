#include <stdio.h>
#include <stdlib.h>

#include "elem.h"
#include "pilha.h"

int
main(int argc, char **argv) {
	char str[] = "testando";
	Pilha *p = new Pilha();
	Elem *e;

	printf("Tamanho inicial = %d\n", p->size());

	int i = 0;
	for(i; i < 1000000; i++) {
		e = new Elem(i+1, str);
		p->push(*e);
		printf("Inserido: %d %s\n", (p->top())->getChave(), (p->top())->getInfo());
		delete e;
	}

	printf("\nTamanho intermediario = %d\n", p->size());

	i = 0;
	for(i; i < 1000000; i++) {
		e = p->pop();
		printf("Removido: %d %s\n", e->getChave(), e->getInfo());
	}

	printf("\nTamanho final: %d\n", p->size());

	delete p;
	return(0);
}

	
