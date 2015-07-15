#pragma once
#include "OperadorBinario.h"
#include "Operando.h"

class OperadorExponencial :
	public OperadorBinario
{
protected:
	virtual void imprimir(ostream &);

public:
	OperadorExponencial();
	virtual ~OperadorExponencial();
	virtual Elemento * operar(DoublyLinkedList<Elemento *>);
	virtual Elemento * clonar();
};

