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

        //pre: recibe un puntero a nodo
        // post: asigna ese puntero como derecho
        void asignarDerecho(Nodo* punteroNodo);


        void asignarIzquierdo();
        void asignarDerecho();
        void asignarClave(Tipo clave);
        void asignarDatos(aeropuerto* datos);
        bool esHoja();

        //destructor
        ~Nodo();
};

#endif // NODO_H
