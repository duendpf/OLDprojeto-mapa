/* $Id: elem.cpp,v 1.1 2009/09/27 19:34:44 raitech Exp $ */

/* implementacao da classe elemento da lista estatica */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.hpp"

Elem::Elem() {
	chave = 0;
	info[0] = '\0';
}

Elem::Elem(int i, char *str) {
	chave = i;
	strcpy(info, str);
}

bool
Elem::igual(Elem *e) {
	return (chave == e->chave);
}

void
Elem::setInfo(char *str) {
	strcpy(info, str);
}

void
Elem::setChave(int x) {
	chave = x;
}

int
Elem::getChave() {
	return chave;
}

char*
Elem::getInfo() {
	return info;
}

void
Elem::operator = (const Elem &e) {
	chave = e.chave;
	strcpy(info, e.info);
}

/* especificamente para a implementacao inicial em que a comparacao e definida
 * pelo nmro da chave. 
 */

bool
Elem::operator == (const Elem &e) {
	if(chave == e.chave)
		return true;
	else
		return false;
}

