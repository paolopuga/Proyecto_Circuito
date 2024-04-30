/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: TodosResultados.h
//
// Declaraciones de la clase TodosResultados del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef TODOSRESULTADOS_H
#define TODOSRESULTADOS_H

#include <iostream>
#include <string>

#include "Resultados.h"

using namespace std;

class TodosResultados
{

private:


	Resultados * datos;
	const int capacidad;
	int usados;


public:
	
	

	/***********************************************/
	/***********************************************/
	// Constructor de copia
	// Descripción: Crea un nuevo objeto TodosResultados a partir de otro.
	// Argumentos:
	//      otro: Objeto TodosResultados del cual se copian los datos.
	TodosResultados(const TodosResultados& otro);

	/***********************************************/
	/***********************************************/
	// Constructor con capacidad inicial
	// Descripción: Crea un objeto TodosResultados con una capacidad inicial.
	// Argumentos:
	//      capacidad_inicial: Capacidad inicial deseada.
	TodosResultados(const int capacidad_inicial);

	/***********************************************/
	/***********************************************/
	// Destructor
	// Descripción: Libera memoria y recursos utilizados por el objeto.
	~TodosResultados(void);

	/***********************************************/
	/***********************************************/
	// getCapacidad
	// Descripción: Devuelve la capacidad actual del objeto.
	int Capacidad(void);

	/***********************************************/
	/***********************************************/
	// getUsados
	// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
	int Usados(void);

	/***********************************************/
	/***********************************************/
	// EstaVacio
	// Descripción: Comprueba si el objeto está vacío.
	bool EstaVacio(void);

	/***********************************************/
	/***********************************************/
	// EliminaTodos
	// Descripción: Elimina todos los elementos, dejándolo vacío.
	void EliminaTodos(void);

	/***********************************************/
	/***********************************************/
	// Aniade
	// Descripción: Añade un objeto Resultados al final del objeto.
	// Argumentos:
	//      objeto: Objeto Resultados que se añade al final.
	void Aniade(const Resultados objeto);

	/***********************************************/
	/***********************************************/
	// Inserta
	// Descripción: Inserta un objeto Resultados en una posición específica.
	// Argumentos:
	//      objeto: Objeto Resultados que se inserta.
	//      num_casilla: Índice de la casilla en la que se inserta.
	void Inserta(const Resultados objeto, const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Elimina
	// Descripción: Elimina un objeto Resultados en una posición específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto que se elimina.
	void Elimina(const int num_casilla);

	

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	Resultados & operator[](const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	Resultados & operator()(const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Operador de asignación
	// Descripción: Asigna los datos de otro objeto a este objeto.
	// Argumentos:
	//      otro: Objeto TodosResultados del cual se copian los datos.
	// Devuelve: Una referencia al objeto actual después de la asignación.
	TodosResultados& operator=(const TodosResultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador de acceso sobrecargado
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla1: Índice de la casilla de Resultados deseado.
	//      num_casilla2: Índice de la casilla del Resultado deseado.
	// Devuelve: Una referencia al Resultado en la posición especificada.
	Resultado & operator()(const int num_casilla1, const int num_casilla2);
	
	
	/***********************************************/
	/***********************************************/
	// ToString()
	// Descripción: Convierte el objeto en una cadena de caracteres.
	// Devuelve: Una cadena de caracteres que representa los datos del objeto.
	string ToString();

	
private:	
	
	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.

	void ReservarMemoria (const TodosResultados& otro);

	/************************************************************/
	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const TodosResultados& otro);

	/************************************************************/
	/************************************************************/
	// Libera memoria

	void LiberarMemoria (void);	
	
	/************************************************************/
	/************************************************************/
	// ValorCasilla
	// Descripción: Devuelve el valor de una casilla específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla deseada.
	// Devuelve: El objeto Resultados en la posición especificada.
	// PRE: 0 <= num_casilla < usados
	Resultados& ValorCasilla(const int num_casilla) const;
	

};

#endif