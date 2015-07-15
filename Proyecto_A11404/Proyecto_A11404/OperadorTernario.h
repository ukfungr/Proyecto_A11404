#pragma once
#include "Operador.h"


class OperadorTernario :
	public Operador
{
/*public:
	OperadorTernario();
	virtual ~OperadorTernario();
*/
protected:
	virtual void imprimir(ostream &) = 0;

public:
	virtual Elemento * operar(DoublyLinkedList<Elemento *>) = 0;
	virtual Elemento * clonar() = 0;
};

