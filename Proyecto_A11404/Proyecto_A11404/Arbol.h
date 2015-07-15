
#pragma once

#include "Elemento.h"
#include "NodoArbol.h"
#include "Operador.h"
#include "Operacion.h"

template<class T>
class Arbol {
private:
	NodoArbol<Elemento *> * raiz;


public:
	Arbol(NodoArbol<T> * nodo/*T operacion*/) {
		raiz = nodo;	
	}

	~Arbol() {
		destruirRec(raiz);
	}

	void destruirRec(NodoArbol<T> * actual) {
		if (actual->getActual() != NULL) {
			destruirRec(actual->getActual());
		}
		if (actual->getActual() != NULL) {
			destruirRec(actual->getActual());
		}
		delete actual;
	}

	void descomponer() {
		descomponerRec(raiz);
	}

	void descomponerRec(NodoArbol<T> *& actual) {
		Operacion * operacion = dynamic_cast<Operacion *>(actual->getActual());//Tiene que pedir lo que contiene el nodoArbol de ese actual
		if (operacion != NULL) {

			NodoArbol<T> * tmp = actual;
			actual = operacion->descomponer();
			delete tmp;

			//if (izq != NULL) {
				//descomponerRec(actual->getHIzq());
			//}
			//if (der != NULL) {
				//descomponerRec(actual->getHDer());
			//}

			DoublyLinkedList<T> listaNodos = actual->getLeaf();// tiene que pedir lista contenida en el nodo árbol y comenzar a recorrerla para descomponer
			for (int i = 0; i < listaNodos.getCantidadElementos(); i++){
				NodoArbol<T> * temp = actual->getNode(i);
				descomponerRec(temp);
				//eliminar temporal
			}
		}
	}

	NodoArbol<T> * solucionar() {
		descomponerRec(raiz);
		solucionarRec(raiz);
		return raiz->getActual();
	}

	void solucionarRec(NodoArbol<T> *& actual) {
		//NodoArbol<T> * izq = actual->getActual();
		//Elemento * der = actual->getHDer();
		Operador * op = dynamic_cast<Operador*>(actual->getActual());
		if (op != NULL) {
			DoublyLinkedList<T> listaNodos = actual->getLeaf();
			if (listaNodos.getSizeList() != NULL) {
				for (int i = 0; i < listaNodos.getCantidadElementos(); i++){
					NodoArbol<Elemento *T> * temp = actual->getNode(i);
					solucionarRec(temp);
					//eliminar temporal
					//}

					//solucionarRec(actual->getActual());
				}
				Operador * op1 = dynamic_cast<Operador*>(actual->getActual());
				Elemento * solucion = op->operar(listaNodos/*, actual->getHDer()*/);
				delete actual;
				actual = solucion;//construir un nuevo nodo en la solución
			}
		}
	}
};