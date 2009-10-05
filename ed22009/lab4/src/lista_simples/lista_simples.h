/* $Id$ */
#ifndef LISTA_SIMPLES_H
#define LISTA_SIMPLES_H

#include "../lista_base/lista_base.h"
#include "../lista_base/elem.h"

/* representa um no que carrega o elemento consigo */
class Nodo {
	public:

	Nodo();
	Nodo(Elem&, Nodo*);

	Nodo *getNext();
	Elem getElem();
	void setNext(Nodo*);
	void setElem(Elem&);

	void Imprimir();

	private:

	Elem elem;
	Nodo *next;

};

class ListaSimples : public Lista {
	public:
	
	ListaSimples();

	Nodo *Inserir_frente(Elem);
	Elem *Remover_frente();
	Nodo *Inserir_final(Elem);
	Elem *Remover_final();
	Nodo *Inserir_apos(Nodo*, Elem);
	Nodo *Remover_apos(Nodo*);

	void Imprimir();
	
	int Tamanho();
	bool Inserir(int, Elem);
	int Localizar(Elem);
	Elem *Retornar(int);
	Elem *Remover(int);
	
	private:

	int nelem;
	Nodo *head, *tail;
};

#endif
