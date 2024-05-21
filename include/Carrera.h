/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Carrera.h
//
// Declaraciones de la clase Carrera del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef CARRERA
#define CARRERA

#include <iostream>
#include <string>

#include "Fecha.h"

using namespace std;
/*	
	• IdCarrera - tipo: int
	Identificador/número de la carrera. Actúa como clave primaria 
	(no puede estarrepetido).

	• Distancia - tipo: double
	Distancia (en kilómetros) de la carrera.

	• FechaCarrera - tipo: Fecha
	Fecha de celebración de la carrera.

	• Nombre - tipo: string
	Nombre de la carrera 
*/
class Carrera{

private:

	// Datos principales, campos de la clase
	int IdCarrera;
	double Distancia;
	Fecha FechaCarrera;
	string Nombre;

	static const char DELIMITADOR = '*'; // separador de la cadena

public:

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
	Carrera(string linea, char delimitador=DELIMITADOR);

	/***********************************************/
	/***********************************************/
	// Inicializa Carrera
	// Argumentos:
	//	  no tiene argumentos
	// POST : 
	//	  Se han inicializado Carrera vacía.
	Carrera();
	
	/******************GETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Leen el valor de cada uno de los campos.
    //
    // Devuelve:
    //      lo que valen  IdCarrera, Distancia
   	//		FechaCarrera y Nombre
	int GetIdCarrera(void) const;
	double GetDistancia(void) const;
	Fecha GetFechaCarrera(void) const;
	string GetNombre(void) const;

	
	/******************SETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Cambian el valor de cada uno de los campos.
    //
    // POST:
    //      Cambian lo que valen Distancia
   	//		FechaCarrera y Nombre
	void SetIdCarrera(int id_carrera);
	void SetDistancia(double distancia);
	void SetFechaCarrera(Fecha fecha_carrera);
	void SetNombre(string nombre);


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
	string ToString (const string nombre="") const;
	
	/***********************************************/
    // Operador >>
    // Argumentos:
    //      objeto: objeto a inicilizar
    // Inicializa los campos
    friend istream & operator >> (istream & in, Carrera & objeto);

    /**********************************************/
    // Operatos <<
    // Argumentos:
    //      objeto: objeto a mostrar
    // devuelve un flujo con el objeto
    friend ostream & operator << (ostream &out, Carrera & objeto) ;
};

#endif