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

#ifndef TodosResultados_H
#define TodosResultados_H

#include <iostream>
#include <string>

#include "Resultados.h"

using namespace std;

class TodosResultados{

private:

	// Tamanio del bloque para redimensionar
	static const int TAM_BLOQUE = 5;

	Resultados * datos;
	int capacidad;
	int usados;


public:
	
	
	/***********************************************/
	/***********************************************/
	// Constructor predeterminado
	// Descripción: Crea un objeto TodosResultados vacío.
	TodosResultados(void);

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
	TodosResultados(int capacidad_inicial);

	/***********************************************/
	/***********************************************/
	// Destructor
	// Descripción: Libera memoria y recursos utilizados por el objeto.
	~TodosResultados(void);

	/***********************************************/
	/***********************************************/
	// getCapacidad
	// Descripción: Devuelve la capacidad actual del objeto.
	int Capacidad(void) const;

	/***********************************************/
	/***********************************************/
	// getUsados
	// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
	int Usados(void) const;

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
	// Inserta 
	// Descripción: Inserta un objeto Resultados en una posición específica.
	// Argumentos:
	//      objeto: Objeto Resultados que se inserta.
	//      num_casilla: Índice de la casilla en la que se inserta.
	void Inserta(const Resultados& objeto, const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Elimina 
	// Descripción: Elimina un objeto Resultados en una posición específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto que se elimina.
	void Elimina(const int num_casilla);

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
	// Devuelve la posición en una colección de un Resultados,
	// dado su dorsal. Si no está registrado devuelve -1.
	int NumOrdenTodosResultados (const Resultados resultados) const;

	/***********************************************/
	/***********************************************/
	// ToString()
	// Descripción: Convierte el objeto en una cadena de caracteres.
	// Devuelve: Una cadena de caracteres que representa los datos del objeto.
	string ToString(const string titulo="") const;

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 1 <= num_casilla <= usados
	Resultados& operator[](const int num_casilla);
	Resultados operator[](const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 1 <= num_casilla <= usados
	Resultados& operator()(const int num_casilla);
	Resultados operator()(const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de acceso sobrecargado
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla1: Índice de la casilla del objeto deseado.
	//      num_casilla2: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 1 <= num_casilla1 <= usados. 1<= num_casilla2 <= usados
	Resultado & operator()(const int num_casilla1, const int num_casilla2);
	Resultado & operator()(const int num_casilla1, 
			const int num_casilla2)const;


	/***********************************************/
	/***********************************************/
	// Operador de comparación ==
	// Descripción: Compara dos objetos TodosResultados.
	// Argumentos:
	//      otro: Objeto TodosResultados con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool operator==(const TodosResultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación !=
	// Descripción: Compara dos objetos TodosResultados.
	// Argumentos:
	//      otro: Objeto TodosResultados con el que se compara.
	// Devuelve: true si son distintos, false en caso contrario.
	bool operator!=(const TodosResultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación <
	// Descripción: Compara dos objetos TodosResultados.
	// Argumentos:
	//      otro: Objeto TodosResultados con el que se compara.
	// Devuelve: true si el objeto actual es menor que el otro.
	bool operator<(const TodosResultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación >
	// Descripción: Compara dos objetos TodosResultados.
	// Argumentos:
	//      otro: Objeto TodosResultados con el que se compara.
	// Devuelve: true si el objeto actual es mayor que el otro.
	bool operator>(const TodosResultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación <=
	// Descripción: Compara dos objetos TodosResultados.
	// Argumentos:
	//      otro: Objeto TodosResultados con el que se compara.
	// Devuelve: true si el objeto actual es menor o igual que el otro.
	bool operator<=(const TodosResultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación >=
	// Descripción: Compara dos objetos TodosResultados.
	// Argumentos:
	//      otro: Objeto TodosResultados con el que se compara.
	// Devuelve: true si el objeto actual es mayor o igual que el otro.
	bool operator>=(const TodosResultados& otro) const;
	
	/***********************************************/
	/***********************************************/
	// Operador binario *
	// Descripción: Realiza la intersección de dos objetos TodosResultados.
	// Argumentos:
	//      uno: primer objeto TodosResultados.
	//      otro: segundo objeto TodosResultados.
	// Devuelve: Un objeto TodosResultados con los elementos comunes.
	friend TodosResultados operator*(const TodosResultados uno, 
			const TodosResultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 1) [TodosResultados] && [TodosResultados]
	// Descripción: Devuelve true si el primer objeto TodosResultados 
	//				contiene al segundo. 
	// Argumentos:
	//        uno: primer objeto TodosResultados.
	//		  otro: segundo objeto TodosResultados.
	// Devuelve: true si el primer objeto contiene al segundo.
	friend bool operator&&( const TodosResultados& uno , 
			const TodosResultados otro); 

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 2) [TodosResultados] && [Resultados]
	// Descripción: Devuelve true si el primer objeto TodosResultados
	//				contiene un Resultados 
	// Argumentos:
	//		  uno: Primer objeto TodosResultados.
	//        otro: Resultados a buscar.
	// Devuelve: true si el primer objeto contiene al Resultados.
	friend bool operator&&(const TodosResultados& uno , 
			const Resultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 3) [Resultados] && [TodosResultados]
	// Descripción: Devuelve true si el primer objeto Resultados 
	//              esta contenido en en TodosResultados
	// Argumentos:
	//        Resultados: Resultados a buscar.
	//        uno: Primer objeto TodosResultados.
	// Devuelve: true si el Resultados esta en el primer objeto.
	friend bool operator&&(const Resultados& Resultados, 
			const TodosResultados& uno);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 4) [TodosResultados] && [int]
	// Descripción: Devuelve true si el primer objeto TodosResultados
	//            Contiene un Resultados con el dorsal dado.
	// Argumentos:
	//		  uno: Primer objeto TodosResultados.
	//        num_dorsal: Dorsal a buscar.
	// Devuelve: true si el primer objeto contiene al Resultados.
	friend bool operator&&(const TodosResultados& uno, const int num_dorsal);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 5) [int] && [TodosResultados]
	// Descripción: Devuelve true si el primer parametro dorsal
	//            esta contenido en en TodosResultados
	// Argumentos:
	//        num_dorsal: Dorsal a buscar.
	//        uno: Primer objeto TodosResultados.
	// Devuelve: true si el Resultados esta en el primer objeto.
	friend bool operator&&(const int num_dorsal, const TodosResultados& uno);
	
	/***********************************************/
	/***********************************************/
	// Operador binario + (version 1) [TodosResultados] + [TodosResultados]
	// Descripción: Concatena dos datos TodosResultados en uno nuevo. 
	//		Los valores delsegundo (operando de la derecha) se añaden 
	//		(en el mismo orden) en una copia del primero.
	// Argumentos:
	//        uno: primer objeto TodosResultados.
	//		  otro: segundo objeto TodosResultados.
	// Devuelve: Un objeto TodosResultados con los elementos concatenados.
	friend TodosResultados operator+(const TodosResultados uno, 
			const TodosResultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 2) [TodosResultados] + [Resultados]
	// Descripción: Añade un Resultados al final de una copia del 
	//				objeto TodosResultados.
	// Argumentos:
	//        uno: primer objeto TodosResultados.
	//		  otro: Resultados a añadir.
	// Devuelve: Un objeto TodosResultados con el Resultados añadido.
	friend TodosResultados operator+(const TodosResultados uno, 
			const Resultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 3) [Resultados] + [TodosResultados]
	// Descripción: Añade un Resultados al principio de una copia del
	//				objeto TodosResultados.
	// Argumentos:
	//        uno: Resultados a añadir.
	//		  otro: primer objeto TodosResultados.
	// Devuelve: Un objeto TodosResultados con el Resultados añadido.
	friend TodosResultados operator+(const Resultados& uno, 
			const TodosResultados otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 1) [TodosResultados] += [TodosResultados]
	// Descripción: Añade los elementos de un objeto TodosResultados al final.
	// Argumentos:
	//        uno: primer objeto TodosResultados.
	// Devuelve: Un objeto TodosResultados con los elementos añadidos.
	TodosResultados& operator+=(const TodosResultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 2) [TodosResultados] += [Resultados]
	// Descripción: Añade un Resultados al final del objeto TodosResultados.
	// Argumentos:
	//        uno: primer objeto TodosResultados.
	// Devuelve: Un objeto TodosResultados con el Resultados añadido.
	TodosResultados& operator+=(const Resultados& otro);


private:

	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.

	void ReservarMemoria (const TodosResultados& otro);

	/************************************************************/
	/************************************************************/
	// Pide memoria dado la capacidad
	// Parámetros: capacidad, capacidad deseada. Por defecto, TAM_BLOQUE
	
	void ReservarMemoria (int capacidad_inicial=TAM_BLOQUE);

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

	/***********************************************/
	/***********************************************/
	// Reajusta la capacidad del objeto para adaptarla al número de elementos.
	void Reajusta(void);

	/***********************************************/
	/***********************************************/
	// Redimensiona el objeto para aumentar su capacidad.
	void Redimensiona(void);

	/***********************************************/
	/***********************************************/
	// Valor Casilla
	// Descripción: Devuelve el valor de una casilla específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla deseada.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 0 <= num_casilla < usados
	Resultados& ValorCasilla(const int num_casilla) const;


	/***********************************************/
	/***********************************************/
	// EsIgualA
	// Descripción: Compara dos objetos TodosResultados.
	// Argumentos:
	//      otro: Objeto TodosResultados con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool EsIgualA(const TodosResultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Aniade
	// Descripción: Añade un objeto Resultados al final del objeto.
	// Argumentos:
	//      objeto: Objeto Resultados que se añade al final.
	void Aniade(const Resultados& objeto);

};

#endif