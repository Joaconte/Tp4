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

    if (!raiz)
        raiz= aeropuerto;
    else{
        if (aeropuerto->obtenerClave()<actual->obtenerClave()){
            if (!(actual->obtenerIzquierdo()))
                actual->asignarIzquierdo(aeropuerto);
            else
                agregarElemento(aeropuerto, actual->obtenerIzquierdo());
        }
        else{
            if (!(actual->obtenerDerecho()))
                actual->asignarDerecho(aeropuerto);
            else
                agregarElemento(aeropuerto, actual->obtenerDerecho());
        }
    }
}

bool Abb::eliminarElemento(Tipo clave){

    Nodo* padre= 0, *nodo, *actual;
    Tipo aux;
    aeropuerto* ptrAux;
    actual=raiz;

    if(!(raiz->obtenerIzquierdo()) && !(raiz->obtenerDerecho())){
        delete raiz;
        raiz=0;
        actual=0;
        return true;
    }
    while(actual){
        if(clave==actual->obtenerClave()){
            if (actual->esHoja()){
                if(padre){
                    if(padre->obtenerDerecho()==actual)
                        padre->asignarDerecho();
                    else if(padre->obtenerIzquierdo()==actual)
                        padre->asignarIzquierdo();
                }
                delete actual;
                actual=0;
                return true;
            }
            else{
                padre=actual;
                if (actual->obtenerDerecho()){
                    nodo=actual->obtenerDerecho();
                    while(nodo->obtenerIzquierdo()){
                        padre=nodo;
                        nodo=nodo->obtenerIzquierdo();
                    }
                }
                else{
                    nodo=actual->obtenerIzquierdo();
                    while(nodo->obtenerDerecho()){
                        padre=nodo;
                        nodo=nodo->obtenerDerecho();
                    }
                }
                aux=actual->obtenerClave();
                ptrAux=actual->obtenerDatos();
                actual->asignarClave(nodo->obtenerClave());
                actual->asignarDatos(nodo->obtenerDatos());
                nodo->asignarClave(clave);
                nodo->asignarDatos(ptrAux);
                actual=nodo;
            }
        }
        else{
            padre=actual;
            if(clave >actual->obtenerClave())
                actual = actual->obtenerDerecho();
            else
                actual = actual->obtenerIzquierdo();
        }
    }
    return false;
}

void Abb::inOrder(Nodo* actual, void(*funcion)(Nodo* actual, Tipo dato), Tipo dato){

    if (actual){
        inOrder(actual->obtenerIzquierdo(), funcion, dato);
        (*funcion)(actual, dato);
        inOrder(actual->obtenerDerecho(), funcion, dato);
    }
}

Nodo* Abb::buscar(const Tipo clave) {

    Nodo* actual = raiz;

    while(actual) {
        if(clave == actual->obtenerClave())
            return actual;
        else if(clave > actual->obtenerClave())
                actual = actual->obtenerDerecho();
            else
                actual = actual->obtenerIzquierdo();
    }

    return 0;
}

Abb::~Abb(){
    while(raiz){
        eliminarElemento(raiz->obtenerClave());
    }
}

