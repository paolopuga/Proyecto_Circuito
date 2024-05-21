/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Resultado.h
//
// Declaraciones de la clase Resultado del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/
#ifndef RESULTADO
#define RESULTADO


#include <string>

#include "Tiempo.h"


using namespace std;

/*
	• Posicion - tipo: int
	Posición en la carrera.

	• Dorsal - tipo: int
	Número de dorsal del corredor. Actúa como clave primaria 
	(no puede estar repetido).

	• TiempoCarrera - tipo: Tiempo
	Tiempo empleado en la carrera.
*/

class Resultado{

private:

	// Datos principales, campos de la clase
	int Posicion, Dorsal;
	Tiempo TiempoCarrera;

	static const char DELIMITADOR = '*';  // separador de la cadena

public:

	/******************CONSTRUCTORES**********************/

	/***********************************************/
    /***********************************************/
    // Inicializa Resultado
    // Argumentos: 
    //      linea: cadena de donde saca la informacion de cada
    //              campo.
    //      delimitador: separadore entre los campos (por defecto
    //              el definido en la clase ":").
    // POST :
    //      Se han inicializado Posicion, Dorsal y TiempoCarrera
	Resultado(string linea, char delimitador=DELIMITADOR);

    /***********************************************/
	/***********************************************/
	// Inicializa Resultado
	// Argumentos:
	//	  no tiene argumentos
	// POST : 
	//	  Se han inicializado Resultado vacío.
	Resultado();
	
	/******************GETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Leen el valor de cada uno de los campos.
    //
    // Devuelve:
    //      lo que valen  Dorsal, Posicion y TiempoCarrera
	int GetDorsal(void) const;
	int GetPosicion(void) const;
	Tiempo GetTiempoCarrera(void) const;


	/******************SETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Cambian el valor de cada uno de los campos.
    //
    // POST:
    //      Cambian lo que valen Posicion y TiempoCarrera
	void SetDorsal(int dorsal);
	void SetPosicion(int posicion);
	void SetTiempoCarrera(Tiempo tiempo_carrera);


	/******************TOSTRING**********************/

    /***********************************************/
    /***********************************************/
    // Imprime los campos de Resultado
    // no recibe nada pero usa los métodos de formateo de utils
    //
    // Argumentos:
	//      nombre: nombre del resultado
    // Devuelve:
    //      Carrera en formato string
	string ToString (const string nombre = "") const;
	
	/***********************************************/
    // Operador >>
    // Argumentos:
    //      objeto: objeto a inicilizar
    // Inicializa los campos
    friend istream & operator >> (istream & in, Resultado & objeto);

    /**********************************************/
    // Operatos <<
    // Argumentos:
    //      objeto: objeto a mostrar
    // devuelve un flujo con el objeto
    friend ostream & operator << (ostream &out, Resultado & objeto);
	
};

#endif