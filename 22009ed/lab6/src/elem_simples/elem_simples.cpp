#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem_simples.h"

ElemSimples::ElemSimples() {
	chave = 0;
	info[0] = '\0';
}

ElemSimples::ElemSimples(int i, char *str) {
	chave = i;
	strcpy(info, str);
}

bool
ElemSimples::igual(ElemSimples *e) {
	return (chave == e->chave);
}

void
ElemSimples::setInfo(char *str) {
	strcpy(info, str);
}

void
ElemSimples::setChave(int x) {
	chave = x;
}

int
ElemSimples::getChave() {
	return chave;
}

char*
ElemSimples::getInfo() {
	return info;
}

void
ElemSimples::operator = (const ElemSimples &e) {
	chave = e.chave;
	strcpy(info, e.info);
}

/* especificamente para a implementacao inicial em que a comparacao e definida
 * pelo nmro da chave. 
 */

bool
ElemSimples::operator == (const ElemSimples &e) {
	if(chave == e.chave)
		return true;
	else
		return false;
}

bool
ElemSimples::operator != (const ElemSimples &e) {
	if(chave != e.chave)
		return true;
	else
		return false;
}
