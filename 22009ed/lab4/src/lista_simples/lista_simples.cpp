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
	~NodoSimples();

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
	char str[3];
	strcpy(str, "\0");
	elem.setInfo(str);
}

NodoSimples::NodoSimples(Elem &e, Nodo *n = NULL) {
	elem = e;
	next = n;
}

NodoSimples::~NodoSimples() {
	next = NULL;
	/* redundante fazer isso, pois o compilador já elemina tudo isso */
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

ListaSimples::~ListaSimples() {
	while(nelem != 0) {
		Remover_frente();
	}
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
	if(head == NULL)
		return(NULL);

	Elem *x = new Elem();
	Nodo *pa = head;
	if(head == tail) {
		*x = pa->getElem();
		delete pa;
		head = tail = NULL;
		nelem--;
		return(x);
	}
	head = pa->getNext();
	*x = pa->getElem();
	delete pa;
	nelem--;
	return x;
}

Nodo *ListaSimples::Inserir_final(Elem x) {
	if (head == NULL) {
		Nodo *Pa = new NodoSimples();
		Pa->setElem(x);
		head = tail = Pa;
		nelem++;
		return(Pa);
	}
	return(Inserir_apos(tail, x));
}

Elem *ListaSimples::Remover_final() {
	if(head == NULL)
		return(NULL);

	Elem *x = new Elem();
	Nodo *Pa;
	Pa = head;
	if (head->getNext() == NULL) {
		/* Lista com 1 elemento */
		tail = NULL;
		head = NULL;
		nelem--;
	} else {
		while(Pa->getNext() != tail) Pa = Pa->getNext();
		Pa = Remover_apos(Pa);
	}
	*x = Pa->getElem();
	delete Pa;
	return x;
}
/* inserir x apos *p */
Nodo *ListaSimples::Inserir_apos(Nodo *p, Elem x) {
	if(p == NULL) 
		return(NULL);

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
	Nodo *tmp = p->getNext();
	Pa->setNext(tmp);
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
		nelem--;
		return(Pa);
	} else
		p->setNext(Pa->getNext());
	nelem--;
	return Pa;
}

void ListaSimples::Imprimir() {
	Nodo *Pa = head;
	int i = 1;
	while(Pa != NULL) {
		printf("pos. %d: ", i);
		Pa->Imprimir();
		Pa = Pa->getNext();
		i++;
	}
}

int ListaSimples::Tamanho() {
	return nelem;
}

bool ListaSimples::Inserir(int x, Elem e) {
	Nodo *Pa;
	/* so insere apos o tamanho atual se for exatamente um apos nelem */
	if(x < 1 || x > (nelem+1))
		return(false);

	if(x == 1) {
		Inserir_frente(e);
		return(true);
	} /*else if(x >  2 && head == tail)
		return(false);*/

	/* posso inserir em 1 mesmo que a lista tenha mais de 1 elem. */
	int i = 1;
	Nodo *tmp = head;
	for(i; i < x-1; i++) {
		tmp = tmp->getNext();
	}
	if(Inserir_apos(tmp, e))
		return(true);

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
	for(i; i < x-1; i++)
		tmp = tmp->getNext();

	Elem *te = new Elem((tmp->getElem()).getChave(), (tmp->getElem()).getInfo());
	delete tmp;
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
			Pa = Remover_apos(tmp);
			Elem *e = new Elem(Pa->getElem().getChave(), Pa->getElem().getInfo());
			delete Pa;
			return(e);
		}

		tmp = tmp->getNext();
	}

	return(NULL);
}
