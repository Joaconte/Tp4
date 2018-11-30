#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "Nodo.h"
#include "ABB.h"
using namespace std;

//pre: recibe un puntero al arbol
//post: crea el arbol con los datos del archivo
void lecturaArchivo(Abb *ptrArbol);

//pre: recibe un puntero al arbol
//post: muestra en la pantalla el menu de opciones
void menu(Abb* ptrArbol);

//pre: recibe un puntero al arbol y el numero de opcion a ejecutar
//post: llama a la funcion que corresponde ejecutar
void opciones(char i,Abb* ptrArbol);

//pre: recibe un puntero al arbol
//post: muestra en la pantalla el menu de opciones de consulta
void menuConsulta(Abb *ptrArbol);

//pre: recibe un puntero al arbol y el numero de opcion a ejecutar
//post: llama a la funcion que corresponde ejecutar
void opcionesConsulta(char i, Abb *ptrArbol);

//pre: recibe un puntero al arbol
//post: agrega un aeropuerto al arbol
void darDeAlta(Abb *ptrArbol);

//pre: recibe un puntero al arbol
//post: elimina un aeropuerto del arbol
void darDeBaja(Abb *ptrArbol);

//pre: recibe un puntero al arbol
//post: devuelve la informacion del aeropuerto solicitado por codigo IATA
void consultaCodigo(Abb *ptrArbol);


//pre: recibe un puntero al arbol
//post: devuelve la informacion del aeropuerto solicitado por nombre del aeropuerto
void consultaNombre(Abb *ptrArbol);

//pre: recibe un puntero a nodo y un nombre a buscar
//post: imprime los datos del aeropuerto
void buscarNombre(Nodo* actual, Tipo dato);


//pre: recibe un puntero al arbol
//post: devuelve la informacion del aeropuerto solicitado por el nombre de la ciudad
void consultaCiudad(Abb *ptrArbol);

//pre: recibe un puntero a nodo y un nombre de ciudad a buscar
//post: imprime los datos del aeropuerto
void buscarCiudad(Nodo* actual, Tipo dato);

//pre: recibe un puntero al arbol
//post: devuelve la informacion del aeropuerto solicitado por el nombre del pais
void consultaPais(Abb *ptrArbol);

//pre: recibe un puntero a nodo y un nombre de pais a buscar
//post: imprime los datos del aeropuerto
void buscarPais(Nodo* actual, Tipo dato);

//pre: recibe un puntero a nodo
//post: imprime la informacion del aeropuerto
void mostrarDatos(Nodo* nodo);

//pre: recibe un puntero a string
//post: quita los guiones del string
void limpiarGuiones(string* dato);

//pre: recibe un puntero a string
//post: pone a mayusculas todos los caracteres
void datoAMayuscula(string* dato);

#endif // FUNCIONES_H_INCLUDED
