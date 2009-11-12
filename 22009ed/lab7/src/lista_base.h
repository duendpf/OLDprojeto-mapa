#ifndef LISTA_BASE_H
#define LISTA_BASE_H

#define MAX 10000

class Elem;
class ListaSimples;
class ListaDupla;

/* classe necessaria para abstrair o nodo e ter possibilidade de linkar
 * as implementacoes sem maiores complicacoes */
class NodoBase {
	public:
	
	virtual Nodo *getNext() = 0;
	virtual Nodo *getPrev() = 0;
	virtual Elem getElem() = 0;
	virtual void setElem(Elem&) = 0;
	virtual void setNext(Nodo*) = 0;
	virtual void setPrev(Nodo*) = 0;
	virtual void Imprimir() = 0;
};

/* TAD do professor para implementar lista ligada */
class Lista {
	public:

	virtual Nodo *Inserir_frente(Elem) = 0;
	virtual Elem *Remover_frente() = 0;
	virtual Nodo *Inserir_final(Elem) = 0;
	virtual Elem *Remover_final() = 0;
	virtual int Tamanho() = 0;
	virtual bool Inserir(int, Elem) = 0;
	virtual int Localizar(Elem) = 0;
	/* o mesmo que o Buscar() do professor */
	virtual Elem *Retornar(int) = 0;
	
	virtual Nodo *Inserir_apos(Nodo*, Elem) = 0;
	virtual Nodo *Remover_apos(Nodo*) = 0;
	virtual Elem *Remover(int) = 0;
	virtual void Imprimir() = 0;
};

#endif
