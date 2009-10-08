#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "lista_base/lista_base.h"
#include "lista_base/elem.h"

int
main(int argc, char *argv[]) {

	timeval start, end, elap;
	int i = 0, j = 0;

	Lista *l;
	double ls_bench[12], ld_bench[12];
	char aux[20];
	sprintf(aux, "Testando");
	Elem tmpel(0, aux);

	/* pretendo testar todos os metodos da classe lista, fazendo com que
	 * fiquem guardados todos os valores de tempo obtidos, tanto pra lista
	 * simples quanto pra lista dupla.
	 * 
	 * nao ha o conceito de nodo na lista estatica, por isso nao a coloquei
	 * aqui. pra fazer um benchmark com ela e preciso modificar bastante a
	 * classe lista, de forma que comporte uma classe para lista estatica.
	 *
	 * a listagem dos metodos e a correspondencia no array de valores:
	 *
	 * 1 - virtual Nodo *Inserir_frente(Elem) = 0;
	 * 2 - virtual Elem *Remover_frente() = 0;
	 * 3 - virtual Nodo *Inserir_final(Elem) = 0;
	 * 4 - virtual Elem *Remover_final() = 0;
	 * 5 - virtual int Tamanho() = 0;
	 * 6 - virtual bool Inserir(int, Elem) = 0;
	 * 7 - virtual int Localizar(Elem) = 0;
	 * 8 - virtual Elem *Retornar(int) = 0;
	 *
	 * OBS:
	 * nao faz muito sentido que usuario tenha acesso a estrutura de nodos,
	 * pois ele nao tem que saber o que isso, so tem que saber que a lista
	 * existe e que os elementos existem; tem que ter como procurar um
	 * elemento com relacao a algum criterio e como inserir e remover um
	 * elemento

	 * X - virtual Nodo *Remover_apos(Nodo*, Elem) = 0;
	 * X - virtual Nodo *Inserir_apos(Nodo*) = 0;
	 *
	 * 9 - virtual Elem *Remover(int) = 0;
	 */

	/* 
	 * comecando o bench para lista simples
	 */

	l = new ListaSimples();
	sprintf(aux, "Testando");

	/* 
	 * 1 - virtual Nodo *Inserir_frente(Elem) = 0;
	 *
	 * vou inserir um elemento na frente da lista, nao importa de que tipo
	 * seja essa lista.
	 */

	i = 0;
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		l->Inserir_frente(tmpel);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 2 - virtual Elem *Remover_frente() = 0;
	 *
	 * remover o elemento da frente da lista preenchida anteriormente
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		Elem *el = l->Remover_frente();
		delete el;
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());


	i = 0;
	/*
	 * 3 - virtual Nodo *Inserir_final(Elem) = 0;
	 *
	 * preencher a lista pelo final dela
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		l->Inserir_final(tmpel);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 4 - virtual Elem *Remover_final() = 0;
	 *
	 * remover o elemento do final da lista preenchida anteriormente
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		Elem *el = l->Remover_final();
		delete el;
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 5 - virtual int Tamanho() = 0;
	 *
	 * so pra constar, tem que dar perto de zero aqui em qualquer uma das
	 * listas, pois � s� um retornar do nelem.
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		l->Tamanho();
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 6 - virtual bool Inserir(int, Elem) = 0;
	 *
	 * aqui e um pouco mais complicado. nao adianta so inserir no fim ou no
	 * comeco, fica sem graca e ja tem funcao pra fazer isso. portanto
	 * preciso achar um metodo de inserir sempre numa posicao dentro da
	 * lista.
	 *
	 * solucao encontrada (atraves de sugestao do prof. pelo aluno Andre
	 * Smaira): inserir 10000 elementos, sempre na posicao ((i+1)/2):
	 */
	int k = 0;
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		if(((k = l->Tamanho()) != 0) && ((k % 2) == 0)) {
			l->Inserir((k/2), tmpel);
		} else {
			l->Inserir(i+1, tmpel);
		}
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 7 - virtual int Localizar(Elem) = 0;
	 *
	 * com a lista preenchida anteriormente, posso fazer a localizacao de um
	 * elemento especifico. a lista anterior foi preenchida de sorte que os
	 * elementos nao estao ordenados atraves do numero da chave, ou seja, o
	 * localizar vai ter que percorrer boa parte da lista atras de um
	 * elemento.
	 *
	 * vou guardar o que a funcao retona num array especial, com 10000
	 * elementos, para usar na funcao de retornar o elemento na pos. i.
	 */
	int ret_pos[10000];
	memset(ret_pos, 11000, 10000);
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		ret_pos[i] = l->Localizar(tmpel);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	printf("Tamanho %d\n", l->Tamanho());
	//l->Imprimir();

	i = 0;
	/*
	 * 8 - virtual Elem *Retornar(int) = 0;
	 *
	 * com o array anterior, verificar, se algum deles retorna elemento NULL
	 * espero que isso nao acontece
	 */
	Elem *x;
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		if((x = l->Retornar(ret_pos[i])) == NULL)
			printf("I caraio .... ret_pos[%d] = %d\n", i, ret_pos[i]);
			
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 10000;
	/*
	 * X - virtual Nodo *Remover_apos(Nodo*, Elem) = 0;
	 *
	 * Bom, a lista t� cheia .... entao eu vou limpar a lista primeiro e
	 * depois inserir com essa ideia de apos
	 *
	 * ops, noa faz sentido testar isso como usuario da lista
	 */

	/*
	 * X - virtual Nodo *Inserir_apos(Nodo*) = 0;
	 *
	 * tambem nao faz sentido testar
	 */

	/*
	 * 9 - virtual Elem *Remover(int) = 0;
	 *
	 * Remover no mesmo estilo do Inserir: (i+1)/2
	 */
	gettimeofday(&start, NULL);
	/* opa! a contagem aqui e diferente, pois comeca com 10000 elementos e
	 * termina com a remocao do primeiro */
	for(i; i >= 1; i--) {
		if(((k = l->Tamanho()) != 0) && ((k % 2) == 0))
			l->Remover(k/2);
		else
			l->Remover(i);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ls_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ls_bench[j-1]);
	//l->Imprimir(); 
	printf("Tamanho %d\n", l->Tamanho());

	delete l;

	l = new ListaDupla();
	j = 0;
	
	printf("\nLista Dupla\n");
	i = 0;
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		l->Inserir_frente(tmpel);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 2 - virtual Elem *Remover_frente() = 0;
	 *
	 * remover o elemento da frente da lista preenchida anteriormente
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		Elem *el = l->Remover_frente();
		delete el;
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());


	i = 0;
	/*
	 * 3 - virtual Nodo *Inserir_final(Elem) = 0;
	 *
	 * preencher a lista pelo final dela
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		l->Inserir_final(tmpel);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 4 - virtual Elem *Remover_final() = 0;
	 *
	 * remover o elemento do final da lista preenchida anteriormente
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		Elem *el = l->Remover_final();
		delete el;
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 5 - virtual int Tamanho() = 0;
	 *
	 * so pra constar, tem que dar perto de zero aqui em qualquer uma das
	 * listas, pois � s� um retornar do nelem.
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		l->Tamanho();
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 6 - virtual bool Inserir(int, Elem) = 0;
	 *
	 * aqui e um pouco mais complicado. nao adianta so inserir no fim ou no
	 * comeco, fica sem graca e ja tem funcao pra fazer isso. portanto
	 * preciso achar um metodo de inserir sempre numa posicao dentro da
	 * lista.
	 *
	 * solucao encontrada (atraves de sugestao do prof. pelo aluno Andre
	 * Smaira): inserir 10000 elementos, sempre na posicao ((i+1)/2):
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		if(((k = l->Tamanho()) != 0) && ((k % 2) == 0)) {
			l->Inserir((k/2), tmpel);
		} else {
			l->Inserir(i+1, tmpel);
		}
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 0;
	/*
	 * 7 - virtual int Localizar(Elem) = 0;
	 *
	 * com a lista preenchida anteriormente, posso fazer a localizacao de um
	 * elemento especifico. a lista anterior foi preenchida de sorte que os
	 * elementos nao estao ordenados atraves do numero da chave, ou seja, o
	 * localizar vai ter que percorrer boa parte da lista atras de um
	 * elemento.
	 *
	 * vou guardar o que a funcao retona num array especial, com 10000
	 * elementos, para usar na funcao de retornar o elemento na pos. i.
	 */
	int ret_posd[10000];
	memset(ret_posd, 11000, 10000);
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		tmpel.setChave(i+1);
		ret_posd[i] = l->Localizar(tmpel);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	printf("Tamanho %d\n", l->Tamanho());
	//l->Imprimir();

	i = 0;
	/*
	 * 8 - virtual Elem *Retornar(int) = 0;
	 *
	 * com o array anterior, verificar, se algum deles retorna elemento NULL
	 * espero que isso nao acontece
	 */
	gettimeofday(&start, NULL);
	for(i; i < 10000; i++) {
		if((x = l->Retornar(ret_posd[i])) == NULL)
			printf("I caraio .... ret_posd[%d] = %d\n", i, ret_posd[i]);
			
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir();
	printf("Tamanho %d\n", l->Tamanho());

	i = 10000;
	/*
	 * X - virtual Nodo *Remover_apos(Nodo*, Elem) = 0;
	 *
	 * Bom, a lista t� cheia .... entao eu vou limpar a lista primeiro e
	 * depois inserir com essa ideia de apos
	 *
	 * ops, noa faz sentido testar isso como usuario da lista
	 */

	/*
	 * X - virtual Nodo *Inserir_apos(Nodo*) = 0;
	 *
	 * tambem nao faz sentido testar
	 */

	/*
	 * 9 - virtual Elem *Remover(int) = 0;
	 *
	 * Remover no mesmo estilo do Inserir: (i+1)/2
	 */
	gettimeofday(&start, NULL);
	/* opa! a contagem aqui e diferente, pois comeca com 10000 elementos e
	 * termina com a remocao do primeiro */
	for(i; i >= 1; i--) {
		if(((k = l->Tamanho()) != 0) && ((k % 2) == 0))
			l->Remover(k/2);
		else
			l->Remover(i);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &elap);
	ld_bench[j++] = (double) (elap.tv_sec + ((elap.tv_usec)/1000000.0));
	printf("\n%f\n", ld_bench[j-1]);
	//l->Imprimir(); 
	printf("Tamanho %d\n", l->Tamanho());

	char funcs[9][20] = {
		"Inserir_frente()",
		"Remover_frente()",
		"Inserir_final()",
		"Remover_final()",
		"Tamanho()",
		"Inserir()",
		"Localizar()",
		"Retornar()",
		"Remover()"
	};

	printf("\n\nTempos totais de exec. de cada funcao (em segundos):\n\n");
	printf("%-18s %-18s %-18s\n", "Funcao", "tempo lsimples", "tempo ldupla");
	i = 0;
	for(i; i < 9; i++) {
		printf("%18s %18f %18f\n", funcs[i], ls_bench[i], ld_bench[i]);
	}

	printf("\n\nTempos unitarios de exec. de cada funcao (em segundos):\n\n");
	printf("%-18s %-18s %-18s\n", "Funcao", "tempo lsimples", "tempo ldupla");
	i = 0;
	for(i; i < 9; i++) {
		printf("%18s %18f %18f\n", funcs[i], ls_bench[i]/1000.0, ld_bench[i]/1000.0);
	}


	printf("\n");


	return(0);
}
