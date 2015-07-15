#pragma once
#include "OperadorUnario.h"
#include "Operando.h"

class OperadorTangente :
	public OperadorUnario
{
protected:
	virtual void imprimir(ostream &);

public:
	OperadorTangente();
	virtual ~OperadorTangente();
	virtual Elemento * operar(DoublyLinkedList<Elemento *>);
	virtual Elemento * clonar();
};

