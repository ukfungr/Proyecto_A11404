#pragma once
#include "DoublyLinkedList.h"

using namespace std;

template<class T>
class NodoLista
{
	template<class T>
	friend ostream & operator<<(ostream &, NodoLista<T> &);

protected:
	T actual;
	NodoLista<T> * previous;
	NodoLista<T> * next;

	virtual void imprimir(ostream &) = 0;

public:
	NodoLista::NodoLista(T elemento) {
		actual = elemento;
		previous = NULL;
		next = NULL;
	}


	NodoLista::~NodoLista() {
	}


	T NodoLista::setActual(T actual) {
		this->actual = actual;
	}


	T NodoLista::getActual() {
		return this->actual;
	}


	NodoLista<T> * NodoLista::getPrevious() {
		return previous;
	}


	void NodoLista::setPrevious(NodoLista<T> * e) {
		this->previous = e;
	}


	NodoLista<T> * NodoLista::getNext() {
		return next;
	}


	void NodoLista::setNext(NodoLista<T> * e) {
		this->next = e;
	}

	virtual NodoLista<T> * clonar() = 0;
};

template<class T>
ostream & operator<<(ostream & out, NodoLista<T> & e)
{
	return out << e.actual;
}