#include "stdafx.h"
#include "OperadorExponencial.h"


OperadorExponencial::OperadorExponencial()
{
}


OperadorExponencial::~OperadorExponencial()
{
}


void OperadorExponencial::imprimir(ostream & out) {
	out << '^' << endl;
}

Elemento * OperadorExponencial::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	Operando * b = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(1));
	return new Operando(pow(a->getValor(), b->getValor()));
}

Elemento * OperadorExponencial::clonar() {
	return new OperadorExponencial();
}