#ifndef ELEM_H
#define ELEM_H

/* elemento da lista */
class Elem : public ElemBase
{
	public:
	Elem();
	Elem(int, char *);
	
	void 	operator=(const Elem&);
	bool 	operator== (const Elem&);
	bool 	operator!=(const Elem&);
	bool 	operator<=(const Elem&);
	bool 	operator>=(const Elem&);
	bool 	operator<(const Elem&);
	bool 	operator>(const Elem&);

	private:

	int	chave;
	char	info[50];
};

#endif
