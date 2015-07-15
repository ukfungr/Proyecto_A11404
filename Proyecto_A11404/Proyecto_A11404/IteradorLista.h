#pragma once
#include "NodoLista.h"

using namespace std;

template<class T>
class IteradorLista
{
private:
	NodoLista<T> * actual;

public:
	IteradorLista(NodoLista<T> * actual) {
		this->actual = actual;
	}


	~Iterador() {

	}


	//Preincremento
	IteradorLista<T>& operator++() {
		bool continuar = true;
		while (continuar && actual != 0) {
			continuar = false;
			if (actual != NULL){
				if (actual->getNext() != NULL){
					actual = actual->getNext();
				}
				else {
					actual = actual->getNext();
					continuar = true;
				}
			}
		}
		return *this;
	}


	//Posincremento
	IteradorLista<T> operator++(int) {
		IteradorLista<T> tmp(this->actual);
		++(*this);
		return tmp;
	}


	T operator*(){
		return actual->getActual();
	}


	bool operator!=(IteradorLista<T> & otro){
		return this->actual != otro.actual;
	}


	bool operator==(IteradorLista<T> & otro) {
		return this->actual == otro.actual;
	}
};

