#ifndef ELEM_BASE_H
#define ELEM_BASE_H

/* elemento da lista */
class ElemBase
{
	public:
	
	virtual void operator= (const Elem&) = 0;
	virtual bool operator== (const Elem&) = 0;
	virtual bool operator!=(const Elem&) = 0;
	virtual bool operator<=(const Elem&) = 0;
	virtual bool operator>=(const Elem&) = 0;
	virtual bool operator<  (const Elem&) = 0;
	virtual bool operator> (const Elem&) = 0;

};

#endif
