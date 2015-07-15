#pragma once

#include "NodoArbol.h"

template<class T>
class Iterador {
private:
	NodoArbol<T> * anterior;
	NodoArbol<T> * actual;

public:

	Iterador(NodoArbol<T> * actual) {
		this->anterior = actual;
		this->actual = actual;
	}

	~Iterador() {
	}

	// Preincremento
	Iterador<T>& operator++() {
		bool continuar = true;
		while (continuar && actual != 0) {
			continuar = false;
			NodoArbol<T> * tmp = actual;
			if (actual != NULL && anterior == actual->getNode()) {
				if (actual->getNode() != NULL) {
					actual = actual->getNode();
				} else {
					actual = actual->padre;
					continuar = true;
				}
			}
			else if (actual != NULL && anterior == actual->getNode()) {
				actual = actual->padre;
				continuar = true;
			}
			else if (actual->getNode() != NULL) {
				actual = actual->getNode();
			} else {
				actual = actual->padre;
				continuar = true;
			}
			anterior = tmp;
		}
		return *this;
	}

	// Posincremento
	Iterador<T> operator++(int) {
		Iterador<T> tmp(this->actual);
		++(*this);
		return tmp;
	}

	T operator*() {
		return actual->getNode();
	}

	bool operator!=(Iterador<T> & otro) {
		return this->actual != otro.actual;
	}

	bool operator==(Iterador<T> & otro) {
		return this->actual == otro.actual;
	}

};

