#include "stdafx.h"
#include "OperadorFunction.h"


OperadorFunction::OperadorFunction()
{
}


OperadorFunction::~OperadorFunction()
{
}


void OperadorFunction::imprimir(ostream & out) {
	out << 'f' << endl;
}

Elemento * OperadorFunction::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	Operando * b = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(1));
	Operando * c = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(2));
	return new Operando(a->getValor() + b->getValor() + c->getValor());
}

Elemento * OperadorFunction::clonar() {
	return new OperadorFunction();
}