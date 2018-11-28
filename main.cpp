#include <iostream>
#include <fstream>
#include <unistd.h>
#include "nodo.h"
#include "ABB.h"
using namespace std;

void lecturaArchivo();
void menu();
void opciones(char i);
void menuConsulta();
void opcionesConsulta(char i);
void darDeAlta();
void darDeBaja();
void consultaCodigo();
void consultaNombre();
void consultaCiudad();
void consultaPais();

int main(){

    lecturaArchivo();
    //menu();

}

void lecturaArchivo(){
    ifstream archivo;
    archivo.open("aeropuertos.txt");
    string datoString, clave;
    float datoFloat;
    int datoInt;
    Nodo *ptrNodo;
    aeropuerto *ptrAeropuerto, aeropuerto;
    ptrAeropuerto = &aeropuerto;
    Abb Arbol;
    while (archivo >> clave){

        archivo >> datoString;
        ptrAeropuerto->nombre = datoString;
        archivo >> datoString;
        ptrAeropuerto->ciudad = datoString;
        archivo >> datoString;
        ptrAeropuerto->pais = datoString;
        archivo >> datoFloat;
        ptrAeropuerto->superficie = datoFloat;
        archivo >> datoInt;
        ptrAeropuerto->cantidadTerminales = datoInt;
        archivo >> datoInt;
        ptrAeropuerto->destinosNacionales = datoInt;
        archivo >> datoInt;
        ptrAeropuerto->destinosInternacionales = datoInt;
        Nodo nodo(clave, ptrAeropuerto);
        ptrNodo= &nodo;
        Arbol.agregarElemento(ptrNodo, Arbol.obtenerRaiz());

    }
    archivo.close();
    Arbol.inOrder(Arbol.obtenerRaiz());
}



/* void menu(){

    char i = '1';
    while (i != '0'){
        cout << "Ingrese 0 para cerrar el menu." <<endl;
		cout << "Ingrese 1 para consultar por un aeropuerto." <<endl;
		cout << "Ingrese 2 para dar de alta un nuevo aeropuerto." <<endl;
		cout << "Ingrese 3 para dar de baja un nuevo aeropuerto." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
		opciones(i);
		sleep(2);
    	}
    }


void opciones(char i){

    switch (i){
        case '0':
            break;
        case '1': menuConsulta();
            break;
        case '2': darDeAlta();
            break;
        case '3': darDeBaja();
            break;
        default: cout << "Dato ingresado invalido" << endl;
        }
        cout<< endl;
    }

    void menuConsulta(){

    char i = '1';
    while (i != '0'){
		cout << "Ingrese 1 para consultar por codigo IATA." <<endl;
		cout << "Ingrese 2 para consultar por nombre." <<endl;
		cout << "Ingrese 3 para consultar por ciudad." <<endl;
		cout << "Ingrese 4 para consultar por pais." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
		opcionesConsulta(i);
		sleep(2);
    	}
    }


void opcionesConsulta(char i){

    switch (i){
        case '1': consultaCodigo();
            break;
        case '2': consultaNombre();
            break;
        case '3': consultaCiudad();
            break;
        case '4': consultaPais();
            break;
        default: cout << "Dato ingresado invalido" << endl;
        }
        cout<< endl;
    }
*/
