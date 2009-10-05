/* $Id: veia.h,v 1.2 2009/09/16 10:42:28 raitech Exp raitech $ */

#ifndef VEIA_H
#define VEIA_H

#define NP1 "/tmp/velha0"
#define NP2 "/tmp/velha1"
#define MAX 255
#define X_MAX 3
#define Y_MAX X_MAX
#define DIAG_MAX X_MAX

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
altera_estado(int, int, char, char [][Y_MAX]);

/*
 * checa se o primeiro argumento venceu no jogo do segundo argumento
 *
 * retorna:
 * 0 se ralmente venceu
 * 1 se nao venceu
 */
int
checa_venceu(char, char [][Y_MAX]);

/*
 * checa se deu velha de acordo com a roda atual
 *
 * retorna:
 * 0 se deu velha
 * 1 se nao deu
 */
int
checa_velha(int);

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
faz_jogada(int, char, char*, char [][Y_MAX]);

/* esta funcao checa se esta encurralado
 * params: 1o simbolo que deve ou nao estar encurralado, 2o estado atual do
 * jogo, 3o ponteiro pra int da linha, 4o ponteiro pra int da coluna
 */
int
checa_encur(char, char [][Y_MAX], int*, int*);


/*
 * a simples funcao que imprime o estado do jogo
 */
int
imprime_estado(char [][Y_MAX]);

/* 
 * recebe uma string que carrega o que deve ser verificado e o jogo onde
 * verificar, os dois primeiros sao o simbolo do jogador e o simbolo do
 * oponente, nessa ordem
 */

void
parse_vitoria(char, char, char*, char[][Y_MAX]);

/* 
 * recebe uma string que carrega o que deve ser verificado e o no da jogada
 * verificar, os dois primeiros parametros sao o simbolo do jogador e o do
 * oponente, nesse ordem
 */
void
parse_velha(char, char, char*, char [][Y_MAX], int);


#endif
