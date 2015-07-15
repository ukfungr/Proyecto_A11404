#include "stdafx.h"
#include "OperadorCoseno.h"


OperadorCoseno::OperadorCoseno()
{
}


OperadorCoseno::~OperadorCoseno()
{
}


void OperadorCoseno::imprimir(ostream & out)
{
	out << 'c' << endl;
}


Elemento * OperadorCoseno::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	return new Operando(cos(a->getValor()*3.14159265 / 180));
}


Elemento * OperadorCoseno::clonar() {
	return new OperadorCoseno();
}
