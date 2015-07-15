// Proyecto_A11404.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Elemento.h"
#include "DoublyLinkedList.h"
#include "Arbol.h"
#include "Operando.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream myReadFile("operaciones.txt");

	DoublyLinkedList<Operacion *> op(myReadFile);
	cout << op << endl;

	ofstream myOutputFile("resultados.txt");
	for (int i = 0; i < op.getCantidadElementos(); i++) {

		Operacion * operacionActual = op->getValor();

		Arbol<Elemento *> arbol(operacionActual);
		arbol.descomponer();
		Operando * resultado = dynamic_cast<Operando *>(arbol.solucionar());
		myOutputFile << *resultado << endl;

		cout << i + 1 << ". " << *operacionActual << " = " << *resultado << endl;

		delete operacionActual;
	}

	myReadFile.close();
	myOutputFile.close();

	system("pause");

	return 0;
}

