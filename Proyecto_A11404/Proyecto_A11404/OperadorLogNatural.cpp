#include "stdafx.h"
#include "OperadorLogNatural.h"


OperadorLogNatural::OperadorLogNatural()
{
}


OperadorLogNatural::~OperadorLogNatural()
{
}


void OperadorLogNatural::imprimir(ostream & out)
{
	out << 'l' << endl;
}


Elemento * OperadorLogNatural::operar(DoublyLinkedList<Elemento *> listaOperandos) {
	Operando * a = dynamic_cast<Operando *>(listaOperandos.getPosicionCualquiera(0));
	return new Operando(log(a->getValor()));
}


Elemento * OperadorLogNatural::clonar() {
	return new OperadorLogNatural();
}