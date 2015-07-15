#pragma once
#include "Operador.h"


class OperadorUnario :
	public Operador
{
/*public:
	OperadorUnario();
	virtual ~OperadorUnario();
*/
protected:
	virtual void imprimir(ostream &) = 0;

public:

	virtual Elemento * operar(DoublyLinkedList<Elemento *>) = 0;
	virtual Elemento * clonar() = 0;
};

