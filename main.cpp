#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "Nodo.h"
#include "ABB.h"
using namespace std;

void lecturaArchivo(Abb *ptrArbol);
void menu(Abb* ptrArbol);
void opciones(char i,Abb* ptrArbol);
void menuConsulta();
void opcionesConsulta(char i);
void darDeAlta(Abb *ptrArbol);
void darDeBaja(Abb *ptrArbol);
void consultaCodigo(Abb *ptrArbol);
void consultaNombre();
void consultaCiudad();
void consultaPais();

int main(){
    Abb *ptrArbol, arbol;
    ptrArbol=&arbol;
    lecturaArchivo(ptrArbol);
    ptrArbol->inOrder(ptrArbol->obtenerRaiz());
	menu(ptrArbol);


}

void lecturaArchivo(Abb *ptrArbol){
    ifstream archivo;
    archivo.open("aeropuertos.txt");
    string datoString, clave;
    float datoFloat;
    int datoInt;
    Nodo *ptrNodo;
    aeropuerto *ptrAeropuerto;
    while (archivo >> clave){

        ptrAeropuerto= new aeropuerto();
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
        ptrNodo= new Nodo(clave, ptrAeropuerto);
        ptrArbol->agregarElemento(ptrNodo, ptrArbol->obtenerRaiz());

    }
	archivo.close();

}




void menu(Abb *ptrArbol){

    char i = '1';
    while (i != '0'){
        cout << "Ingrese 0 para cerrar el menu." <<endl;
		cout << "Ingrese 1 para consultar por un aeropuerto." <<endl;
		cout << "Ingrese 2 para dar de alta un nuevo aeropuerto." <<endl;
		cout << "Ingrese 3 para dar de baja un nuevo aeropuerto." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
		opciones(i, ptrArbol);
		sleep(2);
    	}
    }


void opciones(char i,Abb *ptrArbol){

    switch (i){
        case '0':
            break;
        case '1': consultaCodigo(ptrArbol);
            break;
        case '2': darDeAlta(ptrArbol);
            break;
        case '3': darDeBaja(ptrArbol);
            break;
        default: cout << "Dato ingresado invalido" << endl;
        }
        cout<< endl;
    }

    void darDeAlta(Abb *ptrArbol){
        string datoString, clave;
        int datoInt;
        float datoFloat;
        Nodo *ptrNodo;
        aeropuerto *ptrAeropuerto;
        ptrAeropuerto= new aeropuerto();
        cout << "Ingrese el codigo IATA: ";
        cin >> clave;
        cout <<"Ingrese el nombre del aeropuerto: ";
        cin >> datoString;
        ptrAeropuerto->nombre = datoString;
        cout <<"Ingrese el nombre de la ciudad: ";
        cin >> datoString;
        ptrAeropuerto->ciudad = datoString;
        cout <<"Ingrese el del pais: ";
        cin >> datoString;
        ptrAeropuerto->pais = datoString;
        cout <<"Ingrese la superficie: ";
        cin >> datoFloat;
        ptrAeropuerto->superficie = datoFloat;
        cout <<"Ingrese la cantidad de terminales: ";
        cin >> datoInt;
        ptrAeropuerto->cantidadTerminales = datoInt;
        cout <<"Ingrese la cantidad de destinos nacionales: ";
        cin >>  datoInt;
        ptrAeropuerto->destinosNacionales = datoInt;
        cout <<"Ingrese la cantidad de destinos internacionale: ";
        cin >> datoInt;
        ptrAeropuerto->destinosInternacionales = datoInt;
        ptrNodo= new Nodo(clave, ptrAeropuerto);
        ptrArbol->agregarElemento(ptrNodo, ptrArbol->obtenerRaiz());
    }

    void darDeBaja(Abb *ptrArbol){
        Tipo codigo;
        cout << "Ingrese codigo IATA del aeropuerto que quiere eliminar: ";
        cin >> codigo;
        for (unsigned i=0 ; i < codigo.length() ; i++){
            codigo[i]=toupper(codigo[i]);
            }
        ptrArbol->eliminarElemento(codigo);
    }


/*
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

void consultaCodigo(Abb *ptrArbol){
    Tipo codigo;
    cout << "Ingrese el codigo IATA: ";
    cin >> codigo;
     for (unsigned i=0 ; i < codigo.length() ; i++){
            codigo[i]=toupper(codigo[i]);
            }
    if (Nodo* buscado = ptrArbol->buscar(codigo)){
        aeropuerto* aeropuertoBuscado = buscado->obtenerDatos();
        cout<< "El codigo ingresado corresponde al aeropuerto de "<<aeropuertoBuscado->ciudad <<", " << aeropuertoBuscado->pais<<endl
        <<"que tiene una superficie de " << aeropuertoBuscado->superficie <<" km²" <<endl <<aeropuertoBuscado->cantidadTerminales
        <<" terminales, " << aeropuertoBuscado->destinosNacionales <<" destinos nacionales y " << aeropuertoBuscado->destinosInternacionales <<
        " internacionales" <<endl;
        }
    else
        cout << "El aeropuerto no esta incluido"<< endl;
    }
