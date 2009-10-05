/* $Id: veia.c,v 1.4 2009/09/17 04:25:39 raitech Exp raitech $ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "veia.h"

/*
 * altera o estado do ultimo argumento, nas coordenadas passadas nos dois
 * primeiros argumentos, com o conteudo do terceiro argumento
 *
 * retorna:
 * 0 se alteracao valida
 * 1 se alteracao invalida
 *
 */
int
altera_estado(int x, int y, char sym, char est[][Y_MAX]) {
	if (x < 0 || x >= X_MAX) return (1);
	if (y < 0 || y >= Y_MAX) return (1);

	if (est[x][y] == '0') {
		est[x][y] = sym;
		return (0);
	} else
		return (1);
}

/*
 * checa se o primeiro argumento venceu no jogo do segundo argumento
 *
 *
 * retorna:
 * 0 se ralmente venceu
 * 1 se nao venceu
 */
int
checa_venceu(char sym, char est[][Y_MAX]) {
	int x = 0, y = 0, v = 0;

	/* linhas */
	for(x; x < X_MAX; x++) {
		y = 0;
		for(y; y < Y_MAX; y++) {
			if(est[x][y] == sym) {
				v++;
			}
		}
		if(v == X_MAX) return(0);
		v = 0;
	}

	/* colunas */
	x = 0; y = 0; v = 0;
	for(x; x < Y_MAX; x++) {
		y = 0;
		for(y; y < X_MAX; y++) {
			if(est[y][x] == sym) {
				v++;
			}
		}
		if(v == Y_MAX) return(0);
		v = 0;
	}

	/* diag. princ. */
	x = 0; v = 0;
	for(x; x < DIAG_MAX; x++) {
		if(est[x][x] == sym)
			v++;
	}

	if(v == DIAG_MAX) return(0);

	/* diag. sec. */
	x = 0; y = DIAG_MAX-1; v = 0;
	for(x, y; x < X_MAX && y >= 0; x++, y--) {
		if(est[x][y] == sym) v++;
	}
	if(v == DIAG_MAX) return(0);

	return (1);
}

/*
 * checa se deu velha no jogo passado
 *
 * retorna:
 * 0 se deu velha
 * 1 se nao deu
 */
int
checa_velha(int j) {
	if(j == 9) 
		return (0);
	else
		return (1);
	
}

/*
 * esta e o cerebro do jogo, a funcao que decide qual a melhor jogada a se fazer
 * o 1o pega o nmro da jogada, o 2o o simbolo do jogador, o 3o buffer que
 * recebera msgs e 4o o estado a ser alterado.
 * retorna:
 * 0 se jogada deu certo 
 * 1 se nao deu
 *
 * pensei primeiro em fazer do retorno um metodo de saber se venci ou se deu
 * velha, mas isso seria um mal uso das funcoes existentes, e tambem um mal
 * exemplo de modularizacao. Se nao deu pra fazer a jogada, e ou porque o
 * tabuleiro ta cheio, ou porque a posicao tentada foi invalida. Entao no buffer
 * ele sempre retorna a jogada que tentou fazer, e quem usou a funcao que se
 * vire pra saber o que aconteceu, usando a funcao que quiser
 *
 */

int
faz_jogada(int jog, char sym, char* buf, char est[][Y_MAX]) {

	int x = 0, y = 0;
	char op = '0';
	if ( sym == 'x') op = 'o';
	else op = 'x';
	/* se encurralado, joga no lugar recomendado */
	if(checa_encur(op, est, &x, &y) == 0) {
		/* e certeza que x,y ta vago */
		altera_estado(x, y, sym, est);
		sprintf(buf, "%d,%d;", x, y);
		return(0);
	} else if(checa_encur(sym, est, &x, &y) == 0) {
		altera_estado(x, y, sym, est);
		sprintf(buf, "%d,%d;", x, y);
		return(0);
	} else if(sym == 'o' && jog == 2) {
		if(altera_estado(1, 1, sym, est) == 0) {
			strcpy(buf, "1,1;\0");
			return(0);
		} else {
			altera_estado(0, 0, sym, est);
			strcpy(buf, "0,0;\0");
			return(0);
		}
	} else if(sym == 'x' && jog == 3) {
		if(altera_estado(2, 2, sym, est) == 0) {
			strcpy(buf, "2,2;\0");
			return(0);
		} else {
			altera_estado(2, 0, sym, est);
			strcpy(buf, "2,0;\0");
			return(0);
		} 
	} else if(sym == 'o' && jog == 4) {
		if(altera_estado(0, 1, sym, est) == 0) {
			strcpy(buf, "0,1;\0");
			return(0);
		} else if(altera_estado(1, 0, sym, est) == 0) {
			strcpy(buf, "1,0;\0");
			return(0);
		} else if(altera_estado(1, 2, sym, est) == 0) {
			strcpy(buf, "1,2;\0");
			return(0);
		} else {
			altera_estado(2, 1, sym, est);
			strcpy(buf, "2,1;\0");
			return(0);
		}
	} else if(sym == 'x' && jog == 5) {
		if(altera_estado(0, 2, sym, est) == 0) {
			strcpy(buf, "0,2;\0");
			return(0);
		} else if(altera_estado(2, 0, sym, est) == 0) {
			strcpy(buf, "2,0;\0");
			return(0);
		}
	} else {
		if(altera_estado(0, 0, sym, est) == 0) {
			sprintf(buf, "0,0;");
			return(0);
		} else if(altera_estado(2,0, sym, est) == 0) {
			sprintf(buf, "2,0;");
			return(0);
		} else if(altera_estado(0, 2, sym, est) == 0) {
			sprintf(buf, "0,2;");
			return(0);
		} else if(altera_estado(2, 2, sym, est) == 0) {
			sprintf(buf, "2,2;");
			return(0);
		} 

	}

	return(1);
}

/* esta funcao checa se esta encurralado
 * params: 1o simbolo que deve ou nao estar encurralado, 2o estado atual do
 * jogo, 3o ponteiro pra int da linha, 4o ponteiro pra int da coluna
 */
int
checa_encur(char sym, char est[][Y_MAX], int* x, int* y) {
	int i = 0, j = 0, tx = X_MAX, ty = Y_MAX, enc = 0;
	char op = 0;
	if (sym == 'x')
		op = 'o';
	else
		op = 'x';

	/* checa encurralado numa linha */
	for(i; i < X_MAX; i++) {
		j = 0;
		/* busca por um unico zero */
		for(j; j < Y_MAX; j++) {
			if(est[i][j] == '0') {
				tx = i; ty = j;
				break;
			}
		}

		if(tx >= 0 && tx < X_MAX && ty >= 0 && ty < Y_MAX) {
			j = 0;
			/* busca a igualdade de simbolo do op. */
			for(j; j < Y_MAX; j++) {
				if(est[i][j] == op) enc++;
			}
		}

		if(enc == 2) {
			*x = tx; *y = ty;
			return (0);
		}

		tx = X_MAX; ty = Y_MAX;
		enc = 0;
	}

	/* checa encurralado numa coluna */
	i = 0;
	for(i; i < Y_MAX; i++) {
		j = 0;
		/* busca por um unico zero */
		for(j; j < X_MAX; j++) {
			if(est[j][i] == '0') {
				tx = j; ty = i;
				break;
			}
		}

		if(tx >= 0 && tx < X_MAX && ty >= 0 && ty < Y_MAX) {
			j = 0;
			/* busca a igualdade de simbolo do op. */
			for(j; j < Y_MAX; j++) {
				if(est[j][i] == op) enc++;
			}
		}

		if(enc == 2) {
			*x = tx; *y = ty;
			return (0);
		}

		tx = X_MAX; ty = Y_MAX;
		enc = 0;
	}

	/* checa encurralado na diag. principal */
	i = 0; j = 0; enc = 0; tx = DIAG_MAX; ty = DIAG_MAX;
	/* busca por um unico zero */
	for(i; i < DIAG_MAX; i++) {
		if(est[i][i] == '0') {
			tx = ty = i;
			break;
		}
	}
	/* aqui, tx = ty */
	if(tx >= 0 && tx < DIAG_MAX) {
		i = 0;
		/* busca a igualdade de simbolo do op. */
		for(i; i < DIAG_MAX; i++) {
			if(est[i][i] == op) enc++;
		}
	}

	if(enc == 2) {
		*x = *y = tx;
		return(0);
	}

	/*checa encurralado na diag. secundaria */
	i = 0; j = DIAG_MAX-1; enc = 0; tx = ty = DIAG_MAX;
	/* busca por um unico zero */
	for(i, j; i < DIAG_MAX  && j >= 0; i++, j--) {
		if(est[i][j] == '0') {
			tx = i; ty = j;
			break;
		}
	}

	/* busca por igualdade de simbolo do op. */
	if(tx >= 0 && tx < DIAG_MAX && ty >= 0 && ty < DIAG_MAX) {
		i = 0; j = DIAG_MAX-1;
		for(i, j; i < DIAG_MAX && j >= 0; i++, j--) {
			if(est[i][j] == op) enc++;
		}
	}

	if(enc == 2) {
		*x = tx; *y = ty;
		return(0);
	}

	/* se chegou ate aqui, rapaz, e porque nenhuma checagem acima feita deu
	 * certo
	 *
	 * de duas uma: ou algo esta errado ou nao esta encurralado
	 */

	return(1);

}


/*
 * a simples funcao que imprime o estado do jogo
 */
int
imprime_estado(char est[][Y_MAX]) {
	int x = 0, y = 0;
	printf("\n");
	for(x; x < X_MAX; x++) {
		y = 0;
		for(y; y < Y_MAX; y++) {
			if(est[x][y] == '0')
				printf("| |");
			else printf("|%c|", est[x][y]);
		}
		printf("\n");
	}

	return (0);
}

 /*
 * recebe uma string que carrega o que deve ser verificado e o jogo onde
 * verificar
 */

void
parse_vitoria(char eusou, char op, char *buf, char est[][Y_MAX]) {
	int x, y;

	if(strncmp(buf, "W;", 2) == 0 || strncmp(buf, "w;", 2) == 0) {
		printf("\nAcreditando cegamente no oponente: \n");
		checa_encur(eusou, est, &x, &y);
		altera_estado(x, y, op, est);
		imprime_estado(est);
		printf("\nOp. ganhou ...\n");
	} else {
		x = buf[2]-'0'; y = buf[4]-'0';
		if(altera_estado(x, y, op, est) == 0) {
			if(checa_venceu(op, est) == 0) {
				printf("\nOp. venceu ... snif..\n");
				imprime_estado(est);
			 } else {
				printf("\nOp. blefou, ganhei!\n");
			}
		} else {
			printf("\nJogada impossivel em" 
				" (%d,%d)!! Ganhei!!\n", x, y);
		}
	}
}

/*  recebe uma string que carrega o que deve ser verificado e o jogo onde
 * verificar
 */

void
parse_velha(char eusou, char op, char *buf, char est[][Y_MAX], int jog) {
	int x, y;

	if(strncmp(buf, "D;", 2) == 0 || strncmp(buf, "d;", 2) == 0) {
		printf("\nAcreditando cegamente no oponente: \n");
		imprime_estado(est);
		printf("\nDeu veiaaa!!!!\n");
	} else {
		x = buf[2]-'0'; y = buf[4]-'0';
		if(altera_estado(x, y, op, est) == 0) {
			if(checa_velha(jog) == 0) {
				imprime_estado(est);
				printf("\nDeu veiaaa!!!!\n");
			 } else {
				printf("\nOp. blefou, ganhei!\n");
			}
		} else {
			printf("\nJogada impossivel em" 
				" (%d,%d)!! Ganhei!!\n", x, y);
		}
	}
}

