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


Nodo::~Nodo(){
    delete datos;
}

