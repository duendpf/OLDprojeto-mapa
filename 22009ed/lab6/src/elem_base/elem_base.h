#ifndef ELEM_BASE_H
#define ELEM_BASE_H

/* base to elements of datastructures */
class ElemBase
{
public:
	virtual void operator= (const ElemBase&) = 0;
	virtual bool operator== (const ElemBase&) = 0;
	virtual bool operator!=(const ElemBase&) = 0;
	virtual bool operator<  (const ElemBase&) = 0;
	virtual bool operator> (const ElemBase&) = 0;
	virtual bool operator<= (const ElemBase&) = 0;
	virtual bool operator>= (const ElemBase&) = 0;
};

#endif
