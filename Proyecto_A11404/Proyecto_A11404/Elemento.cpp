
#include "stdafx.h"
#include "Elemento.h"


Elemento::Elemento() 
{
	//this->next = NULL;
	//this->hIzq = NULL;
	//this->hDer = NULL;
}


Elemento::~Elemento() 
{
}


/*Elemento * Elemento::getNext() 
{
	return next;
}


Elemento *& Elemento::getHIzq() 
{
	return hIzq;
}


Elemento *& Elemento::getHDer()
{
	return hDer;
}


void Elemento::setNext(Elemento * e) 
{
	this->next = e;
}


void Elemento::setHIzq(Elemento * e)
{
	this->hIzq = e;
}


void Elemento::setHDer(Elemento * e) 
{
	this->hDer = e;
}
*/

ostream& operator<<(ostream & out, Elemento & elemento) 
{
	elemento.imprimir(out);
	return out;
}
