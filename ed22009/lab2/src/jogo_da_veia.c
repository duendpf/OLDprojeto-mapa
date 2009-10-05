/* $Id: jogo_da_veia.c,v 1.6 2009/09/17 04:25:39 raitech Exp raitech $ */

/*
 * Implementacao do algoritmo para tentar ganhar ou empatar no jogo da velha
 * (tic tac toe).
 *
 * Elaborado pelo grupo KINDEROVO para o trabalho de laboratorio de no. 2.
 *
 * A utilização do programa:
 * compilar com 'make'
 *
 * deve gerar o executavel veia 
 * digite num terminal no diretorio em que esta esse executavel:
 *  
 *  ./veia 0|1 [t]
 *
 *  onde 0|1 indica que ou o 0 ou o 1 devem estar ali, sendo 0 para o processo
 *  que comea a jogar e 1 para o processo que da continuidade ao jogo; e [t]
 *  indica que o parametro t e opcional, e serve pra indicar que o processo tera
 *  controle manual, independente de ser o primeiro ou o segundo a jogar
 *
 *  caso o parametro t seja dado ao programa, toda vez que por pedido para
 *  entrar com a jogada, deve-se faze-lo no seguinte formato
 *
 *  X<ESPACO>Y<ENTER>
 *
 *  com x e y comecando em zero!
 *
 *  eis o tabuleiro:
 *
 *     0  1  2 
 *   0   |  | 
 *     _  _  _
 *   1   |  |
 *     _  _  _
 *   2   |  | 
 *
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#include "veia.h"

	int
	main(int argc, char *argv[]) {

		/* variaveis para pipes */
		int rdfd, wrfd, numread;
		char rdbuf[MAX];

		/* variaveis de controle do jogo */
		char jogo_possivel = 1; /*!= 0 se possivel*/
		char eusou, op, estado[X_MAX][Y_MAX];
		char x, y;
		int no_jog = 1, i =0;

		/* iniciando jogo com tudo 0 != \0 */
		memset(estado, '0', 9);
		printf("\nEstado inicial: ");
		imprime_estado(estado);


		/* checa por argumentos passados para o programa:
		 * se 0: abre os dois pipes
		 *  NP1 para escrever
		 *  NP2 para ler
		 * se 1: apenas usa os pipes
		 *  NP1 para ler
		 *  NP2 para escrever
		 */

		if(argc == 1) {
			printf("Erro: chame o programa passando 0 para iniciar ou 1"
				      " para esperar!\n");
			exit(1);
		}

		switch(argv[1][0]){
			case '0':
				/* cria pipes */
				mkfifo(NP1, 0666);
				mkfifo(NP2, 0666);
				/* abre pipes, retornando fds */
				rdfd = open(NP2, O_RDONLY);
				wrfd = open(NP1, O_WRONLY);
				op = 'o';
				eusou = 'x';
				break;
			case '1':
				/* apenas abre os pipes, na ordem inversa */
				wrfd = open(NP2, O_WRONLY);
				rdfd = open(NP1, O_RDONLY);
				op = 'x';
				eusou = 'o';
				break;
			default:
				printf("Erro: chame o programa passando 0 para iniciar ou 1"
				      " para esperar!\n");
				exit(1);
		}

		if(argc == 3 && argv[2][0] == 't') {
			char c;
			if(eusou == 'x') {
				printf("Faca 1a. jogada: ");
				scanf("%c %c%*c", &x, &y);
				while(altera_estado(x-'0', y-'0',
						eusou, estado) != 0) {
					printf("Faca 1a. jogada: ");
					scanf("%c %c%*c", &x, &y);
				}

				sprintf(rdbuf, "%c,%c;", x, y);
				imprime_estado(estado);
				write(wrfd, rdbuf, strlen(rdbuf));
				no_jog++;
			}

			while(jogo_possivel) {

				numread = read(rdfd, rdbuf, MAX);

				switch(rdbuf[0]) {
					case 'w':
						/* FALLTROUGH */
					case 'W':
						parse_vitoria(eusou, op, rdbuf,
								estado);
						jogo_possivel = 0;
						break;
						
					case 'd':
						/* FALLTROUGH */
					case 'D':
						parse_velha(eusou, op, rdbuf,
								estado,
								no_jog);
						jogo_possivel = 0;
						break;

					case '0':
						/* FALLTROUGH */
					case '1':
						/* FALLTROUGH */
					case '2':
					 x = rdbuf[0]; y = rdbuf[2];
					 if(altera_estado(x-'0', y-'0',
							 op, estado) != 0) {
						 printf("\nJogada op. impossivel!"
							"(%c,%c) Ganhei!\n", x, y);
						 printf("\nUltimo estado: \n");
						 imprime_estado(estado);
						 sprintf(rdbuf, "W;");
						 write(rdfd, rdbuf, strlen(rdbuf));
						 jogo_possivel = 0;
					 } else if(checa_venceu(op, estado)
							 == 0){
						 printf("\nOPA! O esquecidinho esqueceu"
							" de dizer que ganhou!! "
							"Portanto, EU GANHEI!!\n");
						 imprime_estado(estado);
						 sprintf(rdbuf, "W;");
						 write(wrfd, rdbuf, strlen(rdbuf));
						 jogo_possivel = 0;
					 } else if(checa_velha(no_jog)
							 == 0) {
						 /* deu veia? */
						 printf("\nOPA! O esquecidinho esqueceu"
							" de dizer que deu veiaaa!! "
							"Portanto, EU GANHEI!!\n");
						 imprime_estado(estado);
						 sprintf(rdbuf, "W;");
						 write(wrfd, rdbuf, strlen(rdbuf));
						 jogo_possivel = 0;
					 } else {
						 imprime_estado(estado);
						 no_jog++;
					 } 
					 break;
				}

				if(jogo_possivel == 0) break;

				/* faz jogada manual */

				int ex = 0, ey = 0;
				if(checa_encur(eusou, estado, &ex, &ey)
						== 0) {
					printf("\nRecomendado jogar em (%d,%d)!\n",
						ex, ey);
				}
				printf("Faca %da. jogada: ", no_jog);
				scanf("%c %c%*c", &x, &y);
				while(altera_estado(x-'0', y-'0',
						eusou, estado) != 0) {
					printf("Faca %da. jogada: ", no_jog);
					scanf("%c %c%*c", &x, &y);
				}
				imprime_estado(estado);
				if(checa_venceu(eusou, estado) == 0) {
					printf("\nVenci!\n");
					sprintf(rdbuf, "W;%c,%c;", x, y);
					write(wrfd, rdbuf, strlen(rdbuf));
					jogo_possivel = 0;
					break;
				}
					
				if(checa_velha(no_jog) == 0) {
					printf("\nDeu veiaaaaa!!!\n");
					sprintf(rdbuf, "D;%c,%c;", x, y);
					write(wrfd, rdbuf, strlen(rdbuf));
					jogo_possivel = 0;
					break;
				}

				sprintf(rdbuf, "%c,%c;", x, y);
				imprime_estado(estado);
				write(wrfd, rdbuf, strlen(rdbuf));

				no_jog++;
			}

			return(0);
			/* da main() */
		}

					  



		if(argv[1][0] == '0') {
				/* ja faz primeira jogada, pois ao chegar no loop,
				 * deve-se impreterivelmente esperar a jogada de op
				 */
				altera_estado(0, 0, eusou, estado);
				sprintf(rdbuf, "0,0;");
				printf("\n%da jogada, em (%d,%d)\n",
					no_jog, 0,0);
				imprime_estado(estado);
				write(wrfd, rdbuf, strlen(rdbuf));
				no_jog++;

		}

		while(jogo_possivel) {

			/* primeiro checar se ainda e possivel jogar, verificando o que
			 * ha no buffer do pipe de leitura */
			memset(rdbuf, 0, MAX);
			numread=read(rdfd, rdbuf, MAX);

			switch(rdbuf[0]){
				case 'w':
					/* FALLTROUGH */
				case 'W':
				/* faz muito mais sentido receber, depois de "w;", a
				 * posicao em que jogou e ganhou, muito mais honesto
				 *
			 * ficaria assim - e e o que se implementa aqui -
			 * "w;2,2;" caso a 2,2 seja a casa da vitoria, segundo o
			 * oponente
			 *
			 * MODIFCACAO: para jogar em sala, acreditando que o op.
			 * realmente venceu ou que realmente deu velha
			 *
			 * Se ele enviou um w; ou um d;, ele terminou o programa
			 * e nao tem porque escrever mais no pipe
			 */
					parse_vitoria(eusou, op, rdbuf, estado);
					jogo_possivel = 0;
					break;

			case 'd':
				/* FALLTROUGH */
			case 'D':
					parse_velha(eusou, op, rdbuf, estado,
							no_jog);
					jogo_possivel = 0;
					break;
			case '0':
				/* FALLTROUGH */
			case '1':

				/* FALLTROUGH */
			case '2':
			 /* tenta alerar estado do jogo, se conseguir,
			  * retorna zero, senao, algo diferente de zero
			  * e se deu certo, simplesmente continua o
			  * programa */
			 if(altera_estado(rdbuf[0]-'0',
					  rdbuf[2]-'0',
					  op,
					  estado) != 0) {
				 printf("\nJogada invalida! GAANHEEEI\n");
				 printf("%s", rdbuf);
				 imprime_estado(estado);
				 sprintf(rdbuf, "W;");
				 write(wrfd, rdbuf, strlen(rdbuf));
				 jogo_possivel = 0;
				 break;
			 } else if(checa_venceu(op, estado) == 0) {
				 printf("\nVENCI; op esqueceu que venceu!\n");
				 sprintf(rdbuf, "W;");
				 write(wrfd, rdbuf, strlen(rdbuf));
				 jogo_possivel = 0;
			} else {
				 /* incrimenta, pois op. jogou */
				printf("\n%da jogada, em (%c,%c)\n",
					no_jog, rdbuf[0], rdbuf[2]);
				imprime_estado(estado);
				no_jog++;
			 }

		}

		if(jogo_possivel == 0) break;
		/*  o que tinha no buffer era uma jogada valida
		 *
		 * entao, faz uma jogada, e a funcao que faz a jogada retorna
		 *
		 * 0 para jogada ok
		 * 1 para jogada nok
		 */

		memset(rdbuf, 0, MAX);
		if(faz_jogada(no_jog, eusou, rdbuf, estado) == 0) {
			if(checa_venceu(eusou, estado) == 0) {
				printf("\n%da jogada, em (%c,%c)\n",
					no_jog, rdbuf[0], rdbuf[2]);
				imprime_estado(estado);
				printf("\nVenci!");
				x = rdbuf[0]; y = rdbuf[2];
				sprintf(rdbuf, "W;%c,%c;", x, y);
				write(wrfd, rdbuf, strlen(rdbuf));
				jogo_possivel = 0;
				break;
			} else if(checa_velha(no_jog) == 0) {
				printf("\n%da jogada, em (%c,%c)\n",
					no_jog, rdbuf[0], rdbuf[2]);
				imprime_estado(estado);
				printf("\nDeu veiaaa!!!\n");
				x = rdbuf[0]; y = rdbuf[2];
				sprintf(rdbuf, "D;%c,%c;", x, y);
				write(wrfd, rdbuf, strlen(rdbuf));
				jogo_possivel = 0;
				break;
			} else { /* a jogada deu certo! */
				printf("\n%da jogada, em (%c,%c)\n",
					no_jog, rdbuf[0], rdbuf[2]);
				imprime_estado(estado);
				x = rdbuf[0]; y = rdbuf[2];
				sprintf(rdbuf, "%c,%c;", x, y);
				write(wrfd, rdbuf, strlen(rdbuf));
				no_jog++;
			}
		} else {
			printf("\nfaz_jogada() retornou 1!!!!\n");
			break;
		}
				
	}

	return (0);
}

