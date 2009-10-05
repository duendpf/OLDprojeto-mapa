/*
 * resolucao do primeiro problema proposto para a aula de laboratorio de
 * Estrutura de Dados
 *
 * e o classico problema do monarca que pede auxilio a alguem com menor posicao
 * social, mas de alguma instrucao, e lhe da liberdade para escolher a forma de
 * pagamento pelo auxilio. 'Sabiamente', o ajudador escolhe receber a quantidade
 * de graos de trigo que cabem no tabuleiro de xadrez, com a seguinte regra: 1
 * grao na primeira casa, 2 na segunda, 4 na terceira, 8 na quarta e assim por
 * diante.
 *
 * O monarca nao prestando atencao ao preco, diz que pagara. Mas, como mostra
 * esse programa, e um numero tao alto que nem todas as colheitas de trigo
 * satisfariam tal valor.
 *
 * Como indicado, um saco de trigo pesa 60kg e, vazio, 0.3kg
 *
 * Eis a interpretacao usada nesse algoritmo:
 *
 * Se um saco cheio de trigo pesa 60kg, e porque o trigo dentro dele tem 60kg, e
 * ele proprio - o saco vazio - pesa 03kg.
 *
 *
 * OBS: este arquivo foi escrito dentro do linux, visando a maneira unix de
 * executar um programa: dentro de um terminal, nao necessitando de um getch()
 * ou getchar() no final do programa para deixar a janela aberta. Caso
 * precisar-se compilar este programa no Windows, tomar tal providencia, ou
 * executa-lo atraves da shell do mesmo. 
 *
 * OBS2: o tipo long double e identico ao double ma biblioteca padrao do C no
 * Windows. Referencia:
 *
 * http://msdn.microsoft.com/en-us/library/9cx8xs15.aspx
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char** argv){

	/* tomando kg como referencia */
	long double massa_grao = 3.2e-4,
	            massa_saco = 3.0e-1,
		    qtde_graos_saco = 6.0e1 / massa_grao,
		    massa_graos = 0e0,
		    qtde_graos = 1e0, /* 1 grao na primeira casa */
		    qtde_sacos = 0e0,
		    qtde_sacosr = 0e0, /* arredondado */
		    massa_sacos = 0e0,
		    i = 0e0; /* contador */

	for(i; i < 6.4e1; i++) {
		qtde_graos *= 2.0e0;
	}

	/* o resultado da PG e 2^64 - 1 */

	qtde_graos--;
	massa_graos = massa_grao * qtde_graos;

	/* a qtde de sacos e determinada pela quantidade de graos que cabe em
	 * cada saco, determinada acima pelo calculo da massa que cabe dentro de
	 * cada saco, desconsiderando a massa do proprio saco */

	qtde_sacos = qtde_graos / qtde_graos_saco;
	/* como a quantidade de sacos é sempre inteira, arredondar com
	 * floorl(long double) */
	/* isso e bom, mas a floorl retorna o 'floor' do no. passado, o inteiro
	 * mais proximo nao maior que o no. passado. Portanto se faz necessario
	 * adicionar um, verificando se o que sobra e nao nulo */
	if ((qtde_sacos - floorl(qtde_sacos)) != 0)
		qtde_sacosr = floorl(qtde_sacos) + 1;
	else qtde_sacosr = qtde_sacos;
	
	massa_sacos = massa_graos + (qtde_sacos * massa_saco);

	printf("Quantidade de graos: %llf\n"
		"Quantidade de sacos: %llf\n"
		"Massa total de graos: %llf kg\n"
		"Massa total de sacos: %llf kg\n", 
		qtde_graos, qtde_sacosr, massa_graos, massa_sacos);

	return (0);
}



