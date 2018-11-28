#ifndef ABB_H
#define ABB_H
#include "Nodo.h"

class Abb{
	//atributos
	private:
		Nodo* raiz;

	public:
	//metodos
        Abb();
        Abb(Nodo* raiz);
        Nodo* obtenerRaiz();
        void agregarElemento(Nodo*aeropuerto, Nodo* actual);
        void inOrder(Nodo* actual);
        ~Abb();

};

#endif // ABB_H
