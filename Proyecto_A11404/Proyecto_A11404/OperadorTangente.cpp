#include "stdafx.h"
#include "OperadorTangente.h"


OperadorTangente::OperadorTangente()
{
}


OperadorTangente::~OperadorTangente()
{
}


void OperadorTangente::imprimir(ostream & out)
{
	out << 't' << endl;
}


Elemento * OperadorTangente::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	return new Operando(tan(a->getValor()*3.14159265 / 180));
}


Elemento * OperadorTangente::clonar() {
	return new OperadorTangente();
}
