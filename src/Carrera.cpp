/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Carrera.cpp
//
// Definiciones de la clase Carrera del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>

#include "Carrera.h"



/******************CONSTRUCTORES**********************/

/***********************************************/
/***********************************************/
// Inicializa Carrera
// Argumentos: 
//      linea: cadena de donde saca la informacion de cada
//              campo.
//      delimitador: separadore entre los campos (por defecto
//              el definido en la clase ":").
// POST :
//      Se han inicializado IdCarrera, Distancia
//		FechaCarrera y Nombre
Carrera::Carrera(string linea, char delimitador) {

	// Declaro un string para campo
	string campo1, campo2, campo3, campo4;
	
	// Usamos flujos para separar los campos
    istringstream iss(linea);
	
	getline(iss, campo1, delimitador);
	getline(iss, campo2, delimitador);
	getline(iss, campo3, delimitador);
	getline(iss, campo4, delimitador);
	
	/*********************************************/
	// Inicializo los campos nuemericos con stoi
	IdCarrera = stoi(campo1);
	Distancia = stod(campo2);


	/*********************************************/
	// Inicializo los campos de tipo Fecha
	FechaCarrera = Fecha(campo3);
	
	
	/*********************************************/
	// Inicializo el campo Nombre con flujo aux
	istringstream iss2(campo4);
	
	while (iss2 >> campo4) {
		Nombre += campo4 + " ";
	}
	Nombre.pop_back();

}


/***********************************************/
/***********************************************/
// Inicializa Carrera
// Argumentos:
//	  no tiene argumentos
// POST : 
//	  Se han inicializado Carrera vacía.
Carrera::Carrera():FechaCarrera(Fecha())
{
	IdCarrera = 0;
	Distancia = 0;
	Nombre = "";
}

/******************GETTERS**********************/

/***********************************************/
/***********************************************/
// Leen el valor de cada uno de los campos.
//
// Devuelve:
//      lo que valen  IdCarrera, Distancia
//		FechaCarrera y Nombre	
int Carrera::GetIdCarrera() const{
    return IdCarrera;
}

double Carrera::GetDistancia() const {
    return Distancia;
}

Fecha Carrera::GetFechaCarrera()const {
    return FechaCarrera;
}

string Carrera::GetNombre()const {
    return Nombre;
}



/******************SETTERS**********************/

/***********************************************/
/***********************************************/
// Cambian el valor de cada uno de los campos.
//
// POST:
//      Cambian lo que valen Distancia
//		FechaCarrera y Nombre
void Carrera::SetIdCarrera(int id_carrera) {
	IdCarrera = id_carrera;
}
void Carrera::SetDistancia(double distancia) {
    Distancia = distancia;
}

void Carrera::SetFechaCarrera(Fecha fecha_carrera) {
    FechaCarrera = fecha_carrera;
}

void Carrera::SetNombre(string nombre) {
    Nombre = nombre;
}



/******************TOSTRING**********************/

/***********************************************/
/***********************************************/
// Imprime los campos de Carrera
// no recibe nada pero usa los métodos de formateo de utils
//
// Argumentos:
//      nombre: nombre de la carrera
// Devuelve:
//      Carrera en formato string
string Carrera::ToString (const string nombre) const
{
	// inicialio el flujo de salida
	ostringstream oss;

	// Establezco las flags
	oss.setf(ios::fixed);
	oss.setf(ios::showpoint);
	oss.precision(3);
	
	// Imprimo los campos
	oss << setw(3) << IdCarrera <<" ";
	oss << setw(40) << left << Nombre << " ";
	oss << setw(5) << Distancia << " ";
	oss << FechaCarrera.ToString() ;

	return oss.str(); // Devuelvo el flujo formato string
}

/***********************************************/
// Operador >>
// Argumentos:
//      objeto: objeto a inicilizar
// Inicializa los campos
istream & operator >> (istream & in, Carrera & objeto)
{
	string linea;
	getline(in, linea);
	objeto = Carrera(linea);
	return in;
}

/**********************************************/
// Operator <<
// Argumentos:
//      objeto: objeto a mostrar
// devuelve un flujo con el objeto
ostream & operator << (ostream &out, Carrera & objeto)
{
	out << objeto.IdCarrera << objeto.DELIMITADOR;
	out << objeto.Distancia<< objeto.DELIMITADOR;
	out << objeto.FechaCarrera << objeto.DELIMITADOR;
	out << objeto.Nombre << objeto.DELIMITADOR;

	return out;
}

