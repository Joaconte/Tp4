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

    if (raiz==0)
        raiz= aeropuerto;
    else{
        if (aeropuerto->obtenerClave()<actual->obtenerClave()){
            if (actual->obtenerIzquierdo()==0)
                actual->asignarIzquierdo(aeropuerto);
            else
                agregarElemento(aeropuerto, actual->obtenerIzquierdo());
        }
        else{
            if (actual->obtenerDerecho()==0)
                actual->asignarDerecho(aeropuerto);
            else
                agregarElemento(aeropuerto, actual->obtenerDerecho());
        }
    }
}

void Abb::inOrder(Nodo* actual){

    if (actual!=0){
        inOrder(actual->obtenerIzquierdo());
        cout << actual->obtenerClave() << endl;
        inOrder(actual->obtenerDerecho());
    }
}

Abb::~Abb(){
    delete raiz;
}
