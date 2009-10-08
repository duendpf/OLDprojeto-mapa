#include <stdlib.h>

#include "elem.h"
#include "lista_base.h"

#include "pilha.h"

Pilha::Pilha() {
	l = new ListaSimples();
}

Pilha::~Pilha() {
	delete l;
}

bool Pilha::push(Elem &e) {
	if(l->Inserir_frente(e))
		return(false);
	else
		return(true);
}

Elem *Pilha::pop() {
	if(l->Tamanho() != 0)
		return(l->Remover_frente());
	else
		return(NULL);
}

Elem *Pilha::top() {
	if(l->Tamanho() != 0)
		return(l->Retornar(1));
	else
		return(NULL);
}

int Pilha::size() {
	return(l->Tamanho());
}

bool Pilha::isEmpty() {
	if(l->Tamanho() != 0)
		return(false);
	else
		return(true);
}

