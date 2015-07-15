#include "stdafx.h"
#include "OperadorSeno.h"


OperadorSeno::OperadorSeno()
{
}


OperadorSeno::~OperadorSeno()
{
}


void OperadorSeno::imprimir(ostream & out) 
{
	out << 's' << endl;
}


Elemento * OperadorSeno::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	return new Operando(sin(a->getValor()*3.14159265 / 180));
}


Elemento * OperadorSeno::clonar() {
	return new OperadorSeno();
}