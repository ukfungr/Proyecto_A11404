
#include "stdafx.h"
#include "OperadorSuma.h"

OperadorSuma::OperadorSuma() {
}

OperadorSuma::~OperadorSuma() {
}

void OperadorSuma::imprimir(ostream & out) {
	out << '+' << endl;
}

Elemento * OperadorSuma::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	Operando * b = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(1));
	return new Operando(a->getValor() + b->getValor());
}

Elemento * OperadorSuma::clonar() {
	return new OperadorSuma();
}
