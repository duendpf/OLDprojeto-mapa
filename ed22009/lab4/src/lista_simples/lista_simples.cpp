/* $Id$ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lista_base/lista_base.h"
#include "../lista_base/elem.h"

/* representa um no que carrega o elemento consigo */
class NodoSimples : public Nodo {
	public:

	NodoSimples();
	NodoSimples(Elem&, Nodo*);

	Nodo *getNext();
	Elem getElem();
	void setNext(Nodo*);
	void setElem(Elem&);

	void Imprimir();

	void setPrev(Nodo*) {};
	Nodo* getPrev() {};

	private:

	Elem elem;
	Nodo *next;

};

NodoSimples::NodoSimples() {
	next = NULL;
	elem.setChave(0);
	elem.setInfo("\0");
}

NodoSimples::NodoSimples(Elem &e, Nodo *n = NULL) {
	elem = e;
	next = n;
}

Nodo *NodoSimples::getNext() {
	return(next);
}

Elem NodoSimples::getElem() {
	return(elem);
}

void NodoSimples::setNext(Nodo *n) {
	next = n;
}

void NodoSimples::setElem(Elem &e) {
	elem = e;
}

void NodoSimples::Imprimir() {
	printf("chave: %d; info: %s\n", elem.getChave(), elem.getInfo());
}

ListaSimples::ListaSimples() {
	nelem = 0;
	head = NULL;
	tail = NULL;
}

Nodo *ListaSimples::Inserir_frente(Elem x) {
	Nodo *pa;
	pa = new NodoSimples();
	pa->setElem(x);
	pa->setNext(head);
	head = pa;
	if(tail == NULL) 
		tail = head;
	nelem++;
	return pa;
}

Elem *ListaSimples::Remover_frente() {
	Elem *x = new Elem();
	Nodo *pa = head;
	head = pa->getNext();
	if (head == NULL)
		tail = NULL;
	*x = pa->getElem();
	delete pa;
	nelem--;
	return x;
}

Nodo *ListaSimples::Inserir_final(Elem x) {
	Nodo *Pa = new NodoSimples();
	Pa->setElem(x);
	Pa->setNext(NULL);
	if (head == NULL) head = Pa;
	else (tail)->setNext(Pa);
	tail = Pa;
	nelem++;
	return Pa;
}

Elem *ListaSimples::Remover_final() {
	Elem *x = new Elem();
	Nodo *Pa;
	Pa = head;
	if ((head)->getNext() == NULL) {
		/* Lista com 1 elemento */
		tail = NULL;
		head = NULL;
	} else {
		while (Pa->getNext() != tail) Pa = Pa->getNext();
		tail = Pa;
		Pa = Pa->getNext();
		(tail)->setNext(NULL);
	}
		*x = Pa->getElem();
		delete Pa;
		nelem--;
		return x;
}
/* inserir x apos *p */
Nodo *ListaSimples::Inserir_apos(Nodo *p, Elem x) {
	Nodo *Pa = new NodoSimples();
	Pa->setElem(x);
	if(p == tail) {
		p->setNext(Pa);
		Pa->setNext(NULL);
		tail = Pa;
		nelem++;
		return Pa;
	}

	/* se p == head, nao importa! inserir-se-a apos!!! */
	Pa->setNext(p->getNext());
	p->setNext(Pa);
	nelem++;
	return Pa;
}


Nodo *ListaSimples::Remover_apos(Nodo *p) {
	Nodo *Pa = p->getNext();
	if(p == tail)
		return NULL;
	else if(Pa == tail) {
		tail = p;
		p->setNext(NULL);
		return(Pa);
	}
	p->setNext(Pa);
	nelem--;
	return Pa;
}

void ListaSimples::Imprimir() {
	Nodo *Pa = head;
	while(Pa != NULL) {
		Pa->Imprimir();
		Pa = Pa->getNext();
	}
}

int ListaSimples::Tamanho() {
	return nelem;
}

bool ListaSimples::Inserir(int x, Elem e) {
	/* na minha lista, só pode inserir em posicoes ja existentes na lista,
	 * ou seja, passou de nelem nao insere */
	if(x < 1 || x > nelem) 
		return(false);
	
	Nodo *Pa;

	if(head == NULL) {
		Pa = new NodoSimples(e, NULL);
		head = tail = Pa;
		nelem++;
		return(true);
	}
	/* posso querer inserir na 1a pos. mesmo se tail != head */
	if(head == tail || x == 1) {
		Pa = new NodoSimples(e, head);
		head = Pa;
		nelem++;
		return(true);
	}

	/* chega aqui com x >= 2 */
	Pa = new NodoSimples(e);
	Nodo *tmp = head;
	int i = 1;
	for(i; i <= nelem; i++) {
		if(i == x-1) {
			/* contempla o caso de ser pos x == pos tail */
			Pa->setNext(tmp->getNext());
			tmp->setNext(Pa);
			nelem++;
			return(true);
		}
		tmp = tmp->getNext();
	}

	/* se chegar aqui ... epa!!! erro hein!!! */
	return(false);
}

int ListaSimples::Localizar(Elem e) {
	
	if(nelem == 0)
		return 0;

	int i = 1;
	Nodo *tmp = head;
	for(i; i <= nelem && (tmp->getElem()) != e; i++)
		tmp = tmp->getNext();
	return(i);
}

Elem *ListaSimples::Retornar(int x) {
	if(x < 1 || x > nelem)
		return(NULL);

	int i = 1;
	Nodo *tmp = head;
	for(i; i != x; i++)
		tmp = tmp->getNext();
	if(i > x)
		return(NULL);

	Elem *te = new Elem(tmp->getElem().getChave(), tmp->getElem().getInfo());
	return(te);
}

Elem *ListaSimples::Remover(int x) {
	if(x < 1 || x > nelem)
		return(NULL);

	if(head == NULL)
		return(NULL);

	if(x == 1)
		return(Remover_frente());

	if(x == nelem)
		return(Remover_final());
		

	int i = 1;
	Nodo *tmp = head, *Pa;
/* este loop falha para x = nelem, por isso testado antes */
	for(i; i < x; i++) {
		if(i == x-1) {
			Pa = tmp->getNext();
			Elem *e = new Elem(Pa->getElem().getChave(), Pa->getElem().getInfo());
			tmp->setNext(Pa->getNext());
			delete Pa;
			return(e);
		}

		tmp = tmp->getNext();
	}

	return(NULL);
}
