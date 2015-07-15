
#include "stdafx.h"
#include "OperadorResta.h"

OperadorResta::OperadorResta() {
}

OperadorResta::~OperadorResta() {
}

void OperadorResta::imprimir(ostream & out) {
	out << '-' << endl;
}

Elemento * OperadorResta::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	Operando * b = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(1));
	return new Operando(a->getValor() - b->getValor());
}

Elemento * OperadorResta::clonar() {
	return new OperadorResta();
}