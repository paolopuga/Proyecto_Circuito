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


#include "Carrera.h"
#include "utils.h"


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
	
	/**********************************************************/
    // Busco la posicion del delimitador para separar la cadena
    size_t pos1 = linea.find(delimitador);
    campo1 = linea.substr(0,pos1); // separo el campo 
    rem_se_ext(campo1); // quito los espacios en blanco
    linea = linea.substr(pos1+1); // renuevo la linea quitando el separador

    //Repito el primer proceso para todos los campos

	size_t pos2 = linea.find(delimitador);
	campo2 = linea.substr(0,pos2);
	rem_se_ext(campo2);
	linea = linea.substr(pos2+1);

	size_t pos3 = linea.find(delimitador);
	campo3 = linea.substr(0,pos3);
	rem_se_ext(campo3);
	linea = linea.substr(pos3+1);

	size_t pos4 = linea.find(delimitador);
	campo4 = linea.substr(0,pos4);
	rem_se_ext(campo4);

	
	/*********************************************/
	// Inicializo los campos
	IdCarrera = stoi(campo1);
	Distancia = stod(campo2);
	FechaCarrera = Fecha(campo3);
	Nombre = campo4;

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
// Devuelve:
//      Carrera en formato string
string Carrera::ToString() const{

	// Formateo los campos
	string campo_1 = FormatInt(IdCarrera, 4) + " ";
	string campo_2 = FormatString(Nombre, 40) + " ";
	string campo_3 = FormatDouble(Distancia,6,3) + " km ";
	string campo_4 = FechaCarrera.ToString(true);

	// Devuelvo la concatenacion
	return campo_1 + campo_2 + campo_3 + campo_4;

}
