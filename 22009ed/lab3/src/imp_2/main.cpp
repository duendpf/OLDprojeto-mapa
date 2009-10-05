#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "elem.hpp"
#include "lista_estatica.hpp"



char AGUIA[7][30] = {
	"guta",
	"rebordosa",
	"eletronica",
	"acabada pra sempre",
	"nem que a vaca tussa",
	"verdadeiramente aguia",
	"ah para oh!"
};


int
main(int argc, char **argv) {


	Lista *lista = new Lista();
	int i, el;
	char tmp[50];
	
	/* teste da Lista::imprimir() */
	lista->imprimir();
	
	Elem *e;
	/* a lista tem espaco para MAX elementos, mas ela so tem espaco para
	 * isso, e preciso que esses espacos sejam preenchidos
	 */
	i = 0;
	while(i < MAX)  {
		srand(time(0));
		sprintf(tmp,"Eu sou uma aguia %s", AGUIA[int(6 * (rand() / (RAND_MAX + 1.0)))]);

		srand(time(0)+1);
		e = new Elem(int(5 * MAX * (rand()/(RAND_MAX + 1.0))), tmp);

		if(lista->vazia())
			lista->inserir(e, i+1);
		else if( (el = lista->localizar(e)) == 0) {
			lista->inserir(e, i+1);
			printf("\ninserido %d\n", i+1);
			i++;
		} 

		delete e;
	}

	lista->imprimir();

	e = new Elem();
	printf("\nReovendo el. pos. 50: ");
	*e = lista->removeEl(50);
	printf("nao sei se foi removido ...\n");
	printf("El removido:\n\tchave: %d\n\tInfo: %s\n",
			e->getChave(), e->getInfo());
	delete e;

	e = new Elem();
	printf("\nReovendo el. pos. 304: ");
	*e = lista->removeEl(304);
	printf("nao sei se foi removido ...\n");
	printf("El removido:\n\tchave: %d\n\tInfo: %s\n",
			e->getChave(), e->getInfo());
	delete e;


	printf("\nBuscando el. chave = 23: ");
	strcpy(tmp, "xxx");
	e = new Elem(23, tmp);	
	if(lista->localizar(e))
		printf("encontrado!\n");
	else
		printf("nao encontrado ...\n");

	delete e;

	lista->imprimir();

	return (0);
}

