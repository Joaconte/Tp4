#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
typedef string Tipo;

struct aeropuerto{
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidadTerminales;
    int destinosNacionales;
    int destinosInternacionales;

};

class Nodo {
	//atributos
	private:
		Tipo clave;
		aeropuerto* datos;
		Nodo* izquierdo;
		Nodo* derecho;

    //metodos
	public:
        Nodo(Tipo clave, aeropuerto* datos);
        Tipo obtenerClave();
        aeropuerto* obtenerDatos();
        Nodo* obtenerIzquierdo();
        Nodo* obtenerDerecho();
        void asignarIzquierdo(Nodo* punteroNodo);
        void asignarDerecho(Nodo* punteroNodo);
        ~Nodo();
};

#endif // NODO_H
