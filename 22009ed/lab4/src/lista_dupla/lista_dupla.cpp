/* $Id$ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lista_base/lista_base.h"
#include "../lista_base/elem.h"

/* representa um no que carrega o elemento consigo */
class NodoDuplo : public Nodo {
	public:

	NodoDuplo();
	NodoDuplo(Elem&, Nodo*, Nodo*);

	Nodo *getNext();
	Nodo *getPrev();
	Elem getElem();

	void setNext(Nodo*);
	void setPrev(Nodo*);
	void setElem(Elem&);

	void Imprimir();

	private:

	Elem elem;
	Nodo *next;
	Nodo *prev;
};

NodoDuplo::NodoDuplo() {
	next = NULL;
	prev = NULL;
	elem.setChave(0);
	char str[3];
	strcpy(str, "\0");
	elem.setInfo(str);
}

NodoDuplo::NodoDuplo(Elem &e, Nodo *p = NULL, Nodo *n = NULL) {
	elem = e;
	prev = p;
	next = n;
}

Nodo *NodoDuplo::getNext() {
	return(next);
}

Nodo *NodoDuplo::getPrev() {
	return(prev);
}

Elem NodoDuplo::getElem() {
	return(elem);
}

void NodoDuplo::setNext(Nodo *n) {
	next = n;
}

void NodoDuplo::setPrev(Nodo *p) {
	prev = p;
}

void NodoDuplo::setElem(Elem &e) {
	elem = e;
}

void NodoDuplo::Imprimir() {
	printf("chave: %d; info: %s\n", elem.getChave(), elem.getInfo());
}

ListaDupla::ListaDupla() {
	nelem = 0;
	head = NULL;
	tail = NULL;
}

ListaDupla::~ListaDupla() {
	while(nelem != 0) {
		Remover_frente();
	}
}

Nodo *ListaDupla::Inserir_frente(Elem x) {
	Nodo *Pa;
	Pa = new NodoDuplo();
	Pa->setElem(x);
	Pa->setPrev(NULL);
	Pa->setNext(head);
	head = Pa;
	if(tail == NULL) 
		tail = head;
	else 
		(head->getNext())->setPrev(Pa);
	nelem++;
	return Pa;
}

Elem *ListaDupla::Remover_frente() {
	Elem *x = new Elem();
	Nodo *Pa = head;
	head = Pa->getNext();
	if (head == NULL)
		tail = NULL;
	else
		head->setPrev(NULL);
	/* se nao esvaziar a lista, head->prev = NULL */
	*x = Pa->getElem();
	delete Pa;
	nelem--;
	return x;
}

Nodo *ListaDupla::Inserir_final(Elem x) {
	Nodo *Pa = new NodoDuplo();
	Pa->setElem(x);
	Pa->setNext(NULL);
	if (head == NULL) head = Pa;
	else (tail)->setNext(Pa);
	Pa->setPrev(tail);
	tail = Pa;
	nelem++;
	return Pa;
}

Elem *ListaDupla::Remover_final() {
	Elem *x = new Elem();
	Nodo *Pa;
	Pa = head;
	/* se e head, prev ja deve ser NULL */
	if (head->getNext() == NULL) {
		/* Lista com 1 elemento */
		tail = NULL;
		head = NULL;
	} else {
		while (Pa->getNext() != tail) Pa = Pa->getNext();
		tail = Pa;
		Pa = Pa->getNext();
		/* so preciso setar o next do novo tail, o prev ja deve estar setado */
		(tail)->setNext(NULL);
	}
		*x = Pa->getElem();
		delete Pa;
		nelem--;
		return x;
}
/* inserir x apos *p */
Nodo *ListaDupla::Inserir_apos(Nodo *p, Elem x) {
	Nodo *Pa = new NodoDuplo();
	Pa->setElem(x);
	if(p == tail) {
		p->setNext(Pa);
		Pa->setPrev(p);
		Pa->setNext(NULL);
		tail = Pa;
		nelem++;
		return Pa;
	}

	/* se p == head, nao importa! inserir-se-a apos!!! */
	Pa->setNext(p->getNext());
	Pa->setPrev(p);
	p->setNext(Pa);
	nelem++;
	return Pa;
}


Nodo *ListaDupla::Remover_apos(Nodo *p) {
	Nodo *Pa = p->getNext();
	if(p == tail)
		return NULL;
	else if(Pa == tail) {
		/* p sera novo tail */
		tail = p;
		p->setNext(NULL);
		return(Pa);
	}

	/* Pa e o prox depois de p */
	p->setNext(Pa->getNext());
	(Pa->getNext())->setPrev(p);
	nelem--;
	return Pa;
}

void ListaDupla::Imprimir() {
	Nodo *Pa = head;
	while(Pa != NULL) {
		Pa->Imprimir();
		Pa = Pa->getNext();
	}
}

int ListaDupla::Tamanho() {
	return nelem;
}

bool ListaDupla::Inserir(int x, Elem e) {
	/* na minha lista, só pode inserir em posicoes ja existentes na lista,
	 * ou seja, passou de nelem nao insere */
	if(x < 1 || x > (nelem+1)) 
		return(false);

	if(x == 1) {
		Inserir_frente(e);
		return(true);
	}
	/* posso querer inserir na 1a pos. mesmo se tail != head */
	if(head == tail || x == 1) {
		Nodo *Pa = new NodoDuplo(e);
		Pa = new NodoDuplo(e, NULL, head);
		head = Pa;
		nelem++;
		return(true);
	}

	Nodo *tmp = head;
	int i = 1;
	for(i; i < x-1; i++) {
		tmp = tmp->getNext();
	}

/*
	Nodo *Pa = new NodoDuplo(e);
	Pa->setPrev(tmp);
	Pa->setNext(tmp->getNext());
	tmp->setNext(Pa);
	Pa->getNext()->setPrev(Pa);
	nelem++;
*/
	if(Inserir_apos(tmp, e))
		return(true);

	/* se chegar aqui ... epa!!! erro hein!!! */
	return(false);
}

int ListaDupla::Localizar(Elem e) {
	
	if(nelem == 0)
		return 0;

	int i = 1;
	Nodo *tmp = head;
	for(i; i <= nelem && (tmp->getElem()) != e; i++)
		tmp = tmp->getNext();
	return(i);
}

Elem *ListaDupla::Retornar(int x) {
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

Elem *ListaDupla::Remover(int x) {
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
	for(i; i < x-1; i++) {
		tmp = tmp->getNext();
	}
	if(Pa = Remover_apos(tmp)) {
		Elem *e = new Elem(Pa->getElem().getChave(), Pa->getElem().getInfo());
		delete Pa;
		return(e);
	}

	return(NULL);
}

