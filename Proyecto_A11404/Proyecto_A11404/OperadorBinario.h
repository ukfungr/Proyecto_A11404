#pragma once
#include "Operador.h"

class OperadorBinario :
	public Operador
{
/*public:
	OperadorBinario();
	virtual ~OperadorBinario();
	*/
protected:
	virtual void imprimir(ostream &) = 0;

public:
	virtual Elemento * operar(DoublyLinkedList<Elemento *>) = 0;
	virtual Elemento * clonar() = 0;
};

