#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_base/lista_base.h"
#include "lista_base/elem.h"

int
main(int argc, char *argv[]) {

	Lista *ls = new ListaDupla();
	char aux[20];
	Elem *tmp;

	int i = 0;
	for(i; i < 20; i++) {
		sprintf(aux, "Elem ins. %do.", i+1);
		tmp = new Elem(i+1, aux);
		if(i % 2 == 0) 
			ls->Inserir_frente(*tmp);
		else
			ls->Inserir_final(*tmp);

		delete tmp;
	}

	ls->Imprimir();

	printf("\nTamanho da lista: %d elementos\n", ls->Tamanho());
	int el = 10;
	printf("\no %do. el. existe? ", el);
	Elem *e = ls->Retornar(el);
	if(e == NULL)
		printf("Nao!\n");
	else {
		printf("\nSim!!! E contem:\n\tchave: %d\n\tinfo: %s\n",
				e->getChave(), e->getInfo());
	}

	delete e;

	i = 18;
	e = new Elem(i+40, "Elem torto!");
	printf("\nTentando inserir em %d: ", i+1);
	if(ls->Inserir(++i, *e)) {
		printf("deu certo!\n");
		ls->Imprimir();
	}
	else
		printf("nao deu certo, alguma condicao errada!\n");

	printf("\nPra finalizar: el. %d existe mesmo?: ", i+39);
	if((el = ls->Localizar(*e)) != 0) {
		printf("Sim, %d existe!\n", el);
	} else
		printf("Não existe ...\n");

	printf("\nRemovendo frente: \n");
	if(ls->Remover_frente())
		printf("Deu certo!\n");
	else
		printf("Nao deu certo!\n");

	ls->Imprimir();

	printf("\nRemovendo tras: \n");
	if(ls->Remover_final())
		printf("Deu certo!\n");
	else
		printf("Nao deu certo!\n");

	ls->Imprimir();

	printf("\nRemovendo frente (Remover()): \n");
	if(ls->Remover(1))
		printf("Deu certo!\n");
	else
		printf("Nao deu certo!\n");

	ls->Imprimir();

	printf("\nRemovendo tras (Remover()): \n");
	if(ls->Remover(ls->Tamanho()))
		printf("Deu certo!\n");
	else
		printf("Nao deu certo!\n");

	ls->Imprimir();

	printf("\nRemovendo 2o. (Remover()): \n");
	if(ls->Remover(2))
		printf("Deu certo!\n");
	else
		printf("Nao deu certo!\n");

	ls->Imprimir();

	return(0);
}

