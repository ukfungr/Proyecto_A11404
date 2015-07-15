#pragma once
#include "OperadorUnario.h"
#include "Operando.h"

class OperadorLogNatural :
	public OperadorUnario
{
protected:
	virtual void imprimir(ostream &);

public:
	OperadorLogNatural();
	virtual ~OperadorLogNatural();
	virtual Elemento * operar(DoublyLinkedList<Elemento *>);
	virtual Elemento * clonar();
};

