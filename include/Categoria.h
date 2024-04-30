/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Categoria.h
//
// Declaraciones de la clase Categoria del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/
#ifndef CATEGORIA
#define CATEGORIA


#include <string>

#include "Fecha.h"


using namespace std;

/*
	• IdCategoria - tipo: int
	Número de categoría. Actúa como clave primaria (no puede estar repetido).

	• Denominacion - tipo: string
	Etiqueta descriptiva / denominación de la categoría.

	• Sexo - tipo: char
	Sexo (valores permitidos: H y M).

	• FechaInicial - tipo: Fecha
	Fecha más antigua asociada a la categoría.

	• FechaFinal - tipo: Fecha
	Fecha más reciente asociada a la categoría.
*/

class Categoria{

private:

	// Datos principales, campos de la clase
	int IdCategoria;
	string Denominacion;
	char Sexo;
	Fecha FechaInicial, FechaFinal;

	static const char DELIMITADOR = '*'; // separador de la cadena

public:

	/******************CONSTRUCTORES**********************/

	/***********************************************/
    /***********************************************/
    // Inicializa Categoria
    // Argumentos: 
    //      linea: cadena de donde saca la informacion de cada
    //              campo.
    //      delimitador: separadore entre los campos (por defecto
    //              el definido en la clase ":").
    // POST :
    //      Se han inicializado IdCategoria, Denomicacion, Sexo
   	//		FechaInicial, FechaFinal
	Categoria(string linea, char delimitador=DELIMITADOR);

	/***********************************************/
	/***********************************************/
	// Inicializa Categoria
	// Argumentos:
	//	  no tiene argumentos
	// POST : 
	//	  Se han inicializado Categoria vacía.
	Categoria();

	/******************GETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Leen el valor de cada uno de los campos.
    //
    // Devuelve:
    //      lo que valen  IdCategoria, Denomicacion, Sexo
   	//		FechaInicial, FechaFinal
	int GetIdCategoria(void)const;
	string GetDenominacion(void)const;
	char GetSexo(void)const;
	Fecha GetFechaInicial(void)const;
	Fecha GetFechaFinal(void)const;


	/******************SETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Cambian el valor de cada uno de los campos.
    //
    // POST:
    //      Cambian lo que valen Denomicacion, Sexo
   	//		FechaInicial, FechaFinal
	void SetIdCategoria(int id_categoria);
	void SetDenominacion(string denominacion);
	void SetSexo(char sexo);
	void SetFechaInicial(Fecha fecha_inicial);
	void SetFechaFinal(Fecha fecha_final);


	/******************TOSTRING**********************/

    /***********************************************/
    /***********************************************/
    // Imprime los campos de Categoria
    // no recibe nada pero usa los métodos de formateo de utils
    //
    // Devuelve:
    //      Categoria en formato string
	string ToString (void)const;
	
};

#endif