#ifndef ABB_H
#define ABB_H
#include "Nodo.h"

class Abb{
	//atributos
	private:
		Nodo* raiz;

	public:
	//metodos

        //constructor sin parametros
        //pre: -
        //post: construye el ABB con raiz = 0
        Abb();

        //constructor con parametros
        //pre: recibe el puntero a la raiz
        //post: construye el ABB con la raiz recibida
        Abb(Nodo* raiz);

        //pre: -
        //post: devuelve la raiz
        Nodo* obtenerRaiz();

        //pre: recibe un nuevo aeropuerto y el nodo actual
        //post: agrega el aeropuerto en la posicion correspondiente
        void agregarElemento(Nodo* aeropuerto, Nodo* actual);

        void eliminarElemento(Tipo clave);

        //pre: recibe el nodo actual
        //post: recorre el arbol de manera inOrder
        void inOrder(Nodo* actual);

	
	Nodo* buscar(const Tipo clave);

        //destructor
        ~Abb();


};

#endif // ABB_H
