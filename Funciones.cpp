#include "Funciones.h"

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
		cout << "Ingrese 3 para dar de baja un aeropuerto." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
		opciones(i, ptrArbol);
		sleep(2);
    	}
    }


void opciones(char i, Abb *ptrArbol){

    switch (i){
        case '0':
            break;
        case '1': menuConsulta(ptrArbol);
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


void menuConsulta(Abb *ptrArbol){

    char i = '1';
    while (i != '0'){
        cout << "Ingrese 0 para volver al menu principal"<<endl;
		cout << "Ingrese 1 para consultar por codigo IATA (La consulta mas rapida)." <<endl;
		cout << "Ingrese 2 para consultar por nombre." <<endl;
		cout << "Ingrese 3 para consultar por ciudad." <<endl;
		cout << "Ingrese 4 para consultar por pais." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
		opcionesConsulta(i, ptrArbol);
		sleep(2);
    	}
    }


void opcionesConsulta(char i, Abb *ptrArbol){

    switch (i){
        case '0':
            break;
        case '1': consultaCodigo(ptrArbol);
            break;
        case '2': consultaNombre(ptrArbol);
            break;
        case '3': consultaCiudad(ptrArbol);
            break;
        case '4': consultaPais(ptrArbol);
            break;
        default: cout << "Dato ingresado invalido" << endl;
        }
        cout<< endl;
    }

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
        <<"que tiene una superficie de " << aeropuertoBuscado->superficie <<" km^2" <<endl <<aeropuertoBuscado->cantidadTerminales
        <<" terminales, " << aeropuertoBuscado->destinosNacionales <<" destinos nacionales y " << aeropuertoBuscado->destinosInternacionales <<
        " internacionales" <<endl;
    }
    else
        cout << "El aeropuerto no esta incluido"<< endl;
    }

void consultaNombre(Abb *ptrArbol){

    Tipo nombre;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    ptrArbol->inOrder(ptrArbol->obtenerRaiz(), buscarNombre, nombre);
}

void buscarNombre(Nodo* actual, Tipo nombre){

    if(actual->obtenerDatos()->nombre == nombre)
        mostrarDatos(actual);
}

void consultaCiudad(Abb *ptrArbol){

    Tipo ciudad;
    cout << "Ingrese la ciudad: ";
    cin >> ciudad;
    ptrArbol->inOrder(ptrArbol->obtenerRaiz(), buscarCiudad, ciudad);
}

void buscarCiudad(Nodo* actual, Tipo ciudad){

    if(actual->obtenerDatos()->ciudad == ciudad)
        mostrarDatos(actual);
}

void consultaPais(Abb *ptrArbol){

    Tipo pais;
    cout << "Ingrese el pais: ";
    cin >> pais;
    ptrArbol->inOrder(ptrArbol->obtenerRaiz(), buscarPais, pais);
}

void buscarPais(Nodo* actual, Tipo pais){

    if(actual->obtenerDatos()->pais == pais)
        mostrarDatos(actual);
}

void mostrarDatos(Nodo* nodo){
    aeropuerto* aeropuerto = nodo->obtenerDatos();
    cout<< "Aeropuerto " << aeropuerto->nombre << ", codigo: " <<  nodo->obtenerClave() << ", de "<< aeropuerto->ciudad<<", " << aeropuerto->pais<<endl
        <<"que tiene una superficie de " << aeropuerto->superficie <<" km^2, con" <<endl <<aeropuerto->cantidadTerminales
        <<" terminales, " << aeropuerto->destinosNacionales <<" destinos nacionales y " << aeropuerto->destinosInternacionales <<
        " internacionales" <<endl<<endl;
}
