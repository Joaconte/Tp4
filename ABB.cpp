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


void Abb::eliminarElemento(Tipo clave){

    Nodo* padre= 0, *nodo, *actual;
    Tipo aux;
    aeropuerto* ptrAux;
    actual=raiz;

    while(!(actual==0)){
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
}

void Abb::inOrder(Nodo* actual){

    if (actual!=0){
        inOrder(actual->obtenerIzquierdo());
        cout << actual->obtenerClave() << endl;
        inOrder(actual->obtenerDerecho());
    }
}

Nodo* Abb::buscar(const Tipo clave) {

    Nodo* actual = raiz;

    while(actual != 0) {
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
    delete raiz;
}
