#ifndef _ELEM_H_
#define _ELEM_H_

class Elem {
	public:
		Elem();
		Elem(int, const char*);
		Elem(const Elem&);

		int		getChave() const;
		void		setChave(int);
		const char*	getInfo() const;
		void		setInfo(const char *);

		Elem&		operator=(Elem&);
		bool		operator==(Elem&);
		bool		operator!=(Elem&);
		bool		operator>=(Elem&);
		bool		operator<=(Elem&);
		bool		operator>(Elem&);
		bool		operator<(Elem&);

	private:
		int		chave;
		char		info[50];
};


#endif

