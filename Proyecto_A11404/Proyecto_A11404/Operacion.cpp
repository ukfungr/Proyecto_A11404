
#include "stdafx.h"
#include "Operacion.h"

const char Operacion::OPERADORES[Operacion::NUM_OPERADORES] = {'+', '-', '*', '/', '^', 'f', 's', 'c', 't', 'l'};

Operacion::Operacion(string operacion) {
	this->operacion = operacion;
	eliminarEspaciosEnBlanco();
	eliminarParentesisInnecesarios(this->operacion);
}

Operacion::~Operacion() {
}


NodoArbol<Elemento *> * Operacion::descomponer() {

	Elemento * resultado;
	NodoArbol<Elemento *> * resultadoNodo;
	int indice = indiceMenorPrecedencia(operacion);
	string cen = operacion.substr(indice, 1);
	if (indice == -1) {
		resultado = new Operando(stod(operacion));
		//return new NodoArbol<Elemento *>(resultado);
	}
	else {		
		if (cen == "f"){
			resultado = new OperadorFunction();
			string a = operacion.substr(indice + 2, operacion.length() - indice - 1);
			istringstream op(a);
			string operando;
			while (getline(op, operando, ',')){
				resultadoNodo->setNode(new NodoArbol<Elemento *>(resultado));
				return resultadoNodo;
			}
		}
		else {
			if (cen == "s" || cen == "c" || cen == "t" || cen == "l"){
				string a = operacion.substr(indice, 1);
				string b = operacion.substr(indice + 1, operacion.length() - indice - 1);

				switch (cen[0]) {
				case 's':
					resultado = new OperadorSeno();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);// debe agregar nuevo nodo que contenga la operacion
					break;
				case 'c':
					resultado = new OperadorCoseno();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				case 't':
					resultado = new OperadorTangente();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				case 'l':
					resultado = new OperadorLogNatural();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				default:
					resultado = NULL;
					break;
				}
				resultadoNodo->setNode(new NodoArbol<Elemento *>(procesarStringHijo(b)));
				return resultadoNodo;
			}
			else {
				string a = operacion.substr(0, indice);
				string b = operacion.substr(indice, 1);
				string c = operacion.substr(indice + 1, operacion.length() - indice - 1);

				switch (cen[0]) {
				case '+':
					resultado = new OperadorSuma();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				case '-':
					resultado = new OperadorResta();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				case'*':
					resultado = new OperadorMultiplicacion();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				case '/':
					resultado = new OperadorDivision();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				case '^':
					resultado = new OperadorExponencial();
					resultadoNodo = new NodoArbol<Elemento *>(resultado);
					break;
				default:
					resultado = NULL;
					break;
				}
				resultadoNodo->setNode(new NodoArbol<Elemento *>(procesarStringHijo(a)));
				resultadoNodo->setNode(new NodoArbol<Elemento *>(procesarStringHijo(c)));
			}
		}
	}
	return resultadoNodo;
}

void Operacion::eliminarEspaciosEnBlanco() {
	for (unsigned int i = 0; i < operacion.length(); ++i) {
		switch (operacion[i]) {
		case ' ':
		case '\t':
		case '\n':
			operacion.erase(i, 1);
			--i;
		default:
			break;
		}
	}
}

void Operacion::eliminarParentesisInnecesarios(string & string) {
	bool continuar = true;
	while (continuar) {
		continuar = false;
		if (string[0] == LEFT_PARENTHESIS && string[string.length() - 1] == RIGHT_PARENTHESIS) {
			int parentesis = 1;
			bool quitarParentesis = true;
			for (unsigned int i = 1; i < string.length() - 1 && quitarParentesis; ++i) {
				char c = string[i];
				if (c == LEFT_PARENTHESIS) {
					parentesis++;
				} else if (c == RIGHT_PARENTHESIS) {
					parentesis--;
				}
				if (parentesis < 1) {
					quitarParentesis = false;
				}
			}
			if (quitarParentesis) {
				string = string.substr(1, string.length() - 2);
				continuar = true;
			}
		}
	}
}


int Operacion::indiceMenorPrecedencia(string string) {
	int index = -1;
	int parentesis = 0;
	for (int k = 0; k < NUM_OPERADORES && index == -1; k++) {
		for (unsigned int i = 0; i < string.length() && index == -1; ++i) {
			char c = string[i];
			if (c == LEFT_PARENTHESIS) {
				parentesis++;
			} else if (c == RIGHT_PARENTHESIS) {
				parentesis--;
			} else if (parentesis == 0 && c == OPERADORES[k]) {
				index = i;
			}
		}
	}
	return index;
}


Elemento * Operacion::procesarStringHijo(string string) {
	Elemento * resultado;
	eliminarParentesisInnecesarios(string);
	if (indiceMenorPrecedencia(string) == -1) {
		resultado = new Operando(stod(string));
	} else {
		resultado = new Operacion(string);
	}
	return resultado;
}

string Operacion::getValor() {
	return operacion;
}

void Operacion::imprimir(ostream & out) {
	out << operacion;
}


Elemento * Operacion::clonar() {
	return new Operacion(this->operacion);
}

///falta parentesis cuadrados y sustitución de palabras como sen por s