
#pragma once

using namespace std;

class Elemento {

	friend ostream & operator<<(ostream &, Elemento &);

protected:
	//Elemento * next; //todo pasa por nodoArbol y nodoLista, por lo que estas funciones no son necesarias
	//Elemento * hIzq;
	//Elemento * hDer;

	virtual void imprimir(ostream &) = 0;

public:

	Elemento();
	virtual ~Elemento();

	//Elemento * getNext();
	//Elemento *& getHIzq();
	//Elemento *& getHDer();

	//void setNext(Elemento *);
	//void setHIzq(Elemento *);
	//void setHDer(Elemento *);

	//virtual Elemento * clonar() = 0;
};

ostream& operator<<(ostream &, Elemento &);
