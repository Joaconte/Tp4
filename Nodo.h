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
	    //constructor
	    //pre: recibe la clave del aeropuerto y un puntero al resto de los datos
	    //post: construye el nodo
        Nodo(Tipo clave, aeropuerto* datos);

        //pre: -
        //post: devuelve la clave
        Tipo obtenerClave();

        //pre: -
        //post: devuelve los datos del aeropuerto
        aeropuerto* obtenerDatos();

        //pre: -
        //post: devuelve un puntero al nodo izquierdo
        Nodo* obtenerIzquierdo();

        //pre: -
        //post: devuelve un puntero al nodo derecho
        Nodo* obtenerDerecho();

        //pre: recibe un puntero a nodo
        // post: asigna ese puntero como izquierdo
        void asignarIzquierdo(Nodo* punteroNodo);

        //pre: -
        //post: asigna izquierdo = 0
        void asignarIzquierdo();

        //pre: recibe un puntero a nodo
        // post: asigna ese puntero como derecho
        void asignarDerecho(Nodo* punteroNodo);

        //pre: -
        //post: asigna derecho = 0
        void asignarDerecho();

        //pre: recibe la clave
        //post: le asigna la clave al nodo
        void asignarClave(Tipo clave);

        //pre: recibe los datos
        //post: le asigna los datos al nodo
        void asignarDatos(aeropuerto* datos);

        //pre: -
        //post: devuelve true si el nodo es hoja, false en caso contrario
        bool esHoja();

        //destructor
        ~Nodo();
};

#endif // NODO_H
