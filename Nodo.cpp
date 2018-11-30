#include "Nodo.h"


Nodo::Nodo ( Tipo clave, aeropuerto* datos) {
	this->clave = clave;
	this->datos = datos;
	izquierdo = 0;
	derecho = 0;
}

Tipo Nodo::obtenerClave() {
	return clave;
}

Nodo* Nodo::obtenerIzquierdo(){
	return izquierdo;
}

Nodo* Nodo::obtenerDerecho(){
	return derecho;
}

aeropuerto* Nodo::obtenerDatos(){
    return datos;
}

void Nodo::asignarIzquierdo( Nodo* punteroNodo) {
	izquierdo = punteroNodo;
}

void Nodo::asignarDerecho( Nodo* punteroNodo) {
	derecho = punteroNodo;
}

void Nodo::asignarIzquierdo(){
    izquierdo=0;
}

void Nodo::asignarDerecho(){
    derecho=0;
}

void Nodo::asignarClave(Tipo clave){
    this->clave=clave;
}

void Nodo::asignarDatos(aeropuerto* datos){
    this->datos=datos;
}

bool Nodo:: esHoja(){
    return (derecho==0 && izquierdo==0);
}

Nodo::~Nodo(){
    if (datos)
        delete datos;
    if (izquierdo)
        delete izquierdo;
    if (derecho)
        delete derecho;
}


