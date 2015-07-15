
#include "stdafx.h"
#include "OperadorDivision.h"

OperadorDivision::OperadorDivision() {
}

OperadorDivision::~OperadorDivision() {
}

void OperadorDivision::imprimir(ostream & out) {
	out << '/' << endl;
}

Elemento * OperadorDivision::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	Operando * b = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(1));
	return new Operando(a->getValor() / b->getValor());
}


Elemento * OperadorDivision::clonar() {
	return new OperadorDivision();
}