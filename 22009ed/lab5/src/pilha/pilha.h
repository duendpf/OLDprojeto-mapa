#ifndef PILHA_H
#define PILHA_H

class Lista;
class Elem;
/* a partir de agora, pretendo usar todos os nomes de funcoes e afins em ingles,
 * mas a implementacao da lista ta em portugues misturado com ingles, portanto
 * aqui, dentro das definicoes e implementacoes da pilha, ainda uso esses nomes
 * em portugues, mas somente eles.
 *
 * os comentarios continuam em portugues
 */

class Pilha {
	public:
		Pilha();
		~Pilha();

		bool push(Elem&);
		Elem* pop();
		Elem* top();
		int size();
		bool isEmpty();

	private:

		Lista *l;
};

#endif
