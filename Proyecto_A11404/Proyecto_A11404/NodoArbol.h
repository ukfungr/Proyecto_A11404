#pragma once
//#include "Arbol.h"
#include "DoublyLinkedList.h"
//#include "NodoLista.h"

using namespace std;

template<class T>
class NodoArbol
{
	template<class T>
	friend ostream & operator<<(ostream &, NodoArbol<T> &);

private:
	T actual;
	NodoArbol<T> * padre;
	NodoArbol<T> * nodo;

	DoublyLinkedList<T> * leaf; 

	//virtual void imprimir(ostream &) = 0;

public:
	NodoArbol(T elemento)
	{
		this->actual = elemento;
		this->nodo = elemento;
		padre = NULL;
	}


	~NodoArbol()
	{
	}


	T & NodoArbol::getActual() {
		return actual;
	}


	NodoArbol<T> *& NodoArbol::getNodoLista(int index)
	{
		return leaf->getPosicionCualquiera(index);
	}


	void NodoArbol::setNode(NodoArbol<T> * elemento)
	{
		leaf->insertarElementoFinal(elemento);
	}


	NodoArbol<T> *& NodoArbol::getNode()
	{
		return nodo;
	}


	DoublyLinkedList<T> *& NodoArbol::getLeaf()
	{
		return leaf;
	}


	/*void DoublyLinkedList<T>::setNext(DoublyLinkedList<T> * e)
	{
		this->next = e;
	}*/


	ostream& operator<<(ostream & out, NodoArbol<T> & node)
	{
		node.imprimir(out);
		return out;
	}
};

