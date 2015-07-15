#pragma once
#include "OperadorTernario.h"
#include "Operando.h"

class OperadorFunction :
	public OperadorTernario
{
protected:
	virtual void imprimir(ostream &);

public:
	OperadorFunction();
	virtual ~OperadorFunction();
	virtual Elemento * operar(DoublyLinkedList<Elemento *>);
	virtual Elemento * clonar();
};

