#ifndef ELEM_H
#define ELEM_H

/* elemento da lista */
class Elem
{
	int chave;
	char info[50];
	
	public:
	
	Elem();
	Elem(int, char*);

	bool
	igual(Elem*);

	void
	setInfo(char*);
	void
	setChave(int);

	int
	getChave();
	char*
	getInfo();

	void
	operator= (const Elem&);
	bool
	operator== (const Elem&);
	bool
	operator!=(const Elem&);
	bool
	operator<  (const Elem&);
};

#endif
