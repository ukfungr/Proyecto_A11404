#pragma once
#include "OperadorUnario.h"
#include "Operando.h"

class OperadorSeno :
	public OperadorUnario
{
protected:
	virtual void imprimir(ostream &);

public:
	OperadorSeno();
	virtual ~OperadorSeno();
	virtual Elemento * operar(DoublyLinkedList<Elemento *>);
	virtual Elemento * clonar();
};

