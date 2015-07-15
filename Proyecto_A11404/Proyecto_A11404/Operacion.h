
#pragma once

#include "Elemento.h"
#include "NodoArbol.h"
#include "DoublyLinkedList.h"
#include "Operando.h"
#include "Operador.h"
#include "OperadorUnario.h"
#include "OperadorBinario.h"
#include "OperadorTernario.h"
#include "OperadorSuma.h"
#include "OperadorResta.h"
#include "OperadorDivision.h"
#include "OperadorMultiplicacion.h"
#include "OperadorExponencial.h"
#include "OperadorSeno.h"
#include "OperadorCoseno.h"
#include "OperadorTangente.h"
#include "OperadorLogNatural.h"
#include "OperadorFunction.h"

using namespace std;

class Operacion : public Elemento {
private:

	static const int NUM_OPERADORES = 10;
	static const char OPERADORES[NUM_OPERADORES];
	static const char LEFT_PARENTHESIS = '(';
	static const char RIGHT_PARENTHESIS = ')';
	static const char LEFT_CORCHETE = '[';
	static const char RIGHT_CORCHETE = ']';

	string operacion;
	
	virtual void imprimir(ostream&);
	void eliminarEspaciosEnBlanco();
	void eliminarParentesisInnecesarios(string &);
	int indiceMenorPrecedencia(string);
	Elemento * procesarStringHijo(string);

public:
	Operacion(string);
	virtual ~Operacion();

	
	NodoArbol<Elemento *> * descomponer();
	string getValor();

	
	virtual Elemento * clonar();
};

