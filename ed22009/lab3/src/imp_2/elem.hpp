#ifndef ELEM_HPP
#define ELEM_HPP

#define TRUE 1
#define FALSE 0
#define MAX 100

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
	operator<  (const Elem&);

};

#endif
