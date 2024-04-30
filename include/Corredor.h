/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Corredor.h
//
// Declaraciones de la clase Corredor del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef CORREDOR
#define CORREDOR


#include <string>

#include "Fecha.h"


using namespace std;

/*
	• Dorsal - tipo: int
	Número de dorsal para todo el circuito. Actúa como clave primaria (no puede
	estar repetido).

	• DNI - tipo: string
	Identificador administrativo del corredor.

	• Nombre - tipo: string
	Nombre del corredor.

	• Apellidos - tipo: string
	Apellidos del corredor.

	• FechaNacimiento - tipo: Fecha
	Fecha de nacimiento.

	• Sexo - tipo: char
	Sexo del corredor (valores permitidos: H y M).
*/

class Corredor{

private:

	// Datos principales, campos de la clase
	int Dorsal;
	string DNI, Nombre, Apellidos;
	Fecha FechaNacimiento;
	char Sexo;

	static const char DELIMITADOR = '*'; // separador de la cadena

public:

	/******************CONSTRUCTORES**********************/

	/***********************************************/
    /***********************************************/
    // Inicializa Corredor
    // Argumentos: 
    //      linea: cadena de donde saca la informacion de cada
    //              campo.
    //      delimitador: separadore entre los campos (por defecto
    //              el definido en la clase ":").
    // POST :
    //      Se han inicializado Dorsal, DNI, Nombre
   	//		Appelidos, FechaNacimiento y Sexo
	Corredor(string linea, char delimitador=DELIMITADOR);

	/***********************************************/
	/***********************************************/
	// Inicializa Corredor
	// Argumentos:
	//	  no tiene argumentos
	// POST : 
	//	  Se han inicializado Corredor vacío.
	Corredor();



	/******************GETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Leen el valor de cada uno de los campos.
    //
    // Devuelve:
    //      lo que valen  Dorsal, DNI, Nombre
   	//		Appelidos, FechaNacimiento y Sexo
	int GetDorsal(void) const;
	string GetDNI(void) const;
	Fecha GetFechaNacimiento(void)const;
	string GetNombre(void)const;
	string GetApellidos(void)const;
	char GetSexo(void)const;


	/******************SETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Cambian el valor de cada uno de los campos.
    //
    // POST:
    //      Cambian lo que valen DNI, Nombre
   	//		Appelidos, FechaNacimiento y Sexo
	void SetDorsal(int dorsal);
	void SetDNI(string dni);
	void SetFechaNacimiento(Fecha fecha_nacimiento);
	void SetNombre(string nombre);
	void SetApellidos(string apellidos);
	void SetSexo(char sexo);


	/******************TOSTRING**********************/

    /***********************************************/
    /***********************************************/
    // Imprime los campos de Corredor
    // no recibe nada pero usa los métodos de formateo de utils
    //
    // Devuelve:
    //      Corredor en formato string
	string ToString (void)const;	
	
};

#endif