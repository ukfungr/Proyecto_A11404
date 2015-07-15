
#include "stdafx.h"
#include "OperadorMultiplicacion.h"

OperadorMultiplicacion::OperadorMultiplicacion() {
}

OperadorMultiplicacion::~OperadorMultiplicacion() {
}

void OperadorMultiplicacion::imprimir(ostream & out) {
	out << '*' << endl;
}

Elemento * OperadorMultiplicacion::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	Operando * b = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(1));
	return new Operando(a->getValor() * b->getValor());
}

Elemento * OperadorMultiplicacion::clonar() {
	return new OperadorMultiplicacion();
}
