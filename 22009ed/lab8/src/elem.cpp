#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elem.h"

Elem::Elem() {
	chave	= 0;
	info[0]	= '\0';
}

Elem::Elem(int c, const char* s) {
	chave	= c;
	if(sizeof(s) > 49) {
		strncpy(info, s, 49);
		info[49] = '\0';
	} else 
		strcpy(info, s);
}

Elem::Elem(const Elem& o) {
	chave	= o.chave;
	if(sizeof(o.info) > 49) {
		strncpy(info, o.info, 49);
		info[49] = '\0';
	} else 
		strcpy(info, o.info);
}


int
Elem::getChave() const { return(chave); }

void
Elem::setChave(int c) {
	chave	= c;
}

const char*
Elem::getInfo() const { return(info); }

void
Elem::setInfo(const char *s) {
	if(sizeof(s) > 49) {
		strncpy(info, s, 49);
		info[49] = '\0';
	} else
		strcpy(info, s);
}

Elem&
Elem::operator=(Elem& o) {
	chave	= o.chave;
	strcpy(info, o.info);

	return(*this);
}

bool
Elem::operator==(Elem& o) { return(this->chave == o.chave); }

bool
Elem::operator!=(Elem& o) { return(this->chave != o.chave); }

bool
Elem::operator>=(Elem& o) { return(this->chave >= o.chave); }

bool
Elem::operator<=(Elem& o) { return(this->chave <= o.chave); }

bool
Elem::operator>(Elem& o) { return(chave > o.chave); }

bool
Elem::operator<(Elem& o) { return(chave < o.chave); }

