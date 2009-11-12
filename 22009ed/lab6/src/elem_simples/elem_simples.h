#ifndef ELEM_SIMPLES_H
#define ELEM_SIMPLES_H

#include "elem_base.h"

class ElemSimples : public ElemBase 
{
public:
	ElemSimples();
	ElemSimples(int, char *);

	bool igual(ElemSimples *);
	void setInfo(char *);	
	void setChave(int);
	int getChave();
	char *getInfo();
	void operator= (const ElemSimples &);
	bool operator== (const ElemSimples &);
	bool operator!= (const ElemSimples &);
	bool operator<  (const ElemBase&) {};
	bool operator> (const ElemBase&) {};
	bool operator<= (const ElemBase&) {};
	bool operator>= (const ElemBase&) {};

private:
	int chave;
	char info[50];
}; 
#endif
