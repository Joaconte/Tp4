#include "Nodo.h"
#include "ABB.h"


Abb::Abb(){
    raiz=0;
}

Abb::Abb (Nodo* raiz) {
	this->raiz = raiz;
}

Nodo* Abb::obtenerRaiz() {
	return raiz;
}



void Abb::agregarElemento(Nodo* aeropuerto, Nodo* actual){

    if (actual==0)
        actual=aeropuerto;
    else if (actual==0){
        actual= aeropuerto;
        }
    else{
        if (aeropuerto->obtenerClave()>actual->obtenerClave()){
            agregarElemento(aeropuerto, actual->obtenerIzquierdo());
        }
        else{
            agregarElemento(aeropuerto, actual->obtenerDerecho());
        }
    }
}

void Abb::inOrder(Nodo* actual){

    if (actual==0)
    else{
        inOrder(actual->obtenerIzquierdo());
        cout << actual->obtenerClave() << endl;
        inOrder(actual->obtenerDerecho());
    }
}

Abb::~Abb(){
    delete raiz;
}
