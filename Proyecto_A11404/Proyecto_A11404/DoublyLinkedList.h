#pragma once
#include "Elemento.h"
#include "Operacion.h"
#include "NodoLista.h"

#include <iostream>

using namespace std;

template<class T>
class DoublyLinkedList
{
	template<class T>
	friend ostream & operator<<(ostream &, DoublyLinkedList<T> &);

private:
	NodoLista<T> * head;
	NodoLista<T> * tail;
	int nElements;

public:
	/*DoublyLinkedList();
	DoublyLinkedList(istream &);
	virtual ~DoublyLinkedList();
	void insertarElemento(Elemento *);
	void insertarElementoInicio(Elemento *);
	void insertarElementoFinal(Elemento *);
	void insertarElementoCualquiera(Elemento *, int);
	int getCantidadElementos();
	Elemento * getCopy(int);*/

	DoublyLinkedList::DoublyLinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
	}


	DoublyLinkedList::DoublyLinkedList(istream & myReadFile) : Lista() {
		while (!myReadFile.eof()){
			string temp;
			getline(myReadFile, temp);
			Operacion * operacion = new Operacion(temp);
			if (operacion->getValor() != "") {
				insertarElemento(operacion);
			}
			else {
				delete operacion;
			}
		}
	}


	DoublyLinkedList::~DoublyLinkedList()
	{
		Elemento * actual = head;
		while (actual != NULL) {
			Elemento * tmp = actual;
			actual = actual->getNext();
			delete tmp;
		}
	}


	void DoublyLinkedList::insertarElemento(T elemento) {
		NodoLista<T> * nodo = new Nodo<T>(elemento);
		if (head == NULL){
			head = nodo;
			tail = nodo;
			nElements++;
		}
		else {
			insertarElementoFinal(nodo);
		}
	}


	NodoLista<T> * getPosicionCualquiera(int k){
		NodoLista<T> * temp = head;
		//NodoLista<T> * previous = NULL;
		int i = 1;
		while (i < k){
			temp = temp->getNext();
			i++;
		}
		return temp;
	}


	int DoublyLinkedList::getCantidadElementos() {
		return nElements;
	}

	/*void Lista::insertar(Elemento * nuevoElemento) {
	if (cabeza == NULL) {
	this->cabeza = nuevoElemento;
	this->cola = nuevoElemento;
	} else {
	this->cola->setProximo(nuevoElemento);
	this->cola = nuevoElemento;
	}
	cantidadElementos++;
	}*/

	NodoLista<T> * DoublyLinkedList::getCopy(int i) {
		NodoLista<T> * actual = head;
		while (actual != NULL && i != 0) {
			actual = actual->getNext();
			i--;
		}
		return actual->clonar();
	}


	void DoublyLinkedList::insertarElementoInicio(NodoLista<T> * elemento) {
		NodoLista<T> * temp = elemento;
		temp->setNext(head);
		head = temp;
		nElements++;
	}


	void DoublyLinkedList::insertarElementoCualquiera(NodoLista<T> * nodoActual, int k) {
		NodoLista<T> * temp = head;
		NodoLista<T> * anterior = NULL;
		int cont = 0;
		while (cont != k - 1){
			anterior = temp;
			temp = temp->getNext();
			cont++;
		}
		anterior->setNext(nodoActual);
		nElements++;
		anterior->getNext()->setNext(temp);
	}


	void DoublyLinkedList::insertarElementoFinal(NodoLista<T> * nodoActual) {
		NodoLista<T> * temp = head;
		while (temp->getNext() != NULL){
			temp = temp->getNext();
		}
		temp->setNext(nodoActual);
		tail = temp->getNext();
		nElements++;
	}
	

	int getSizeList(){
		return nElements;
	}

	/*ostream & operator<<(ostream & out, Lista & l) {
	l.imprimir(out);
	return out;
	}

	void Lista::imprimir(ostream& out) {
	Elemento * print = head;
	int i = 0;
	while (print != NULL){
	out << *print << "->" << i << endl;
	print = print->getNext();
	i++;
	}
	}*/


	ostream& operator<<(ostream & out, DoublyLinkedList<T> & lista) {
		NodoLista<T> * actual = lista.head;
		int c = 0;
		while (actual != NULL) {
			out << ++c << ". " << *actual << endl;
			actual = actual->getNext();
		}
		return out << endl;
	}
};

//ostream & operator<<(ostream &, DoublyLinkedList &);
