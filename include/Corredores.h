/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Corredores.h
//
// Declaraciones de la clase Corredores del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef CORREDORES_H
#define CORREDORES_H

#include <iostream>
#include <string>

#include "Corredor.h"

using namespace std;

class Corredores{

private:

	// Tamanio del bloque para redimensionar
	static const int TAM_BLOQUE = 5;

	Corredor * datos;
	int capacidad;
	int usados;


public:
	
	
	/***********************************************/
	/***********************************************/
	// Constructor predeterminado
	// Descripción: Crea un objeto Corredores vacío.
	Corredores(void);

	/***********************************************/
	/***********************************************/
	// Constructor de copia
	// Descripción: Crea un nuevo objeto Corredores a partir de otro.
	// Argumentos:
	//      otro: Objeto Corredores del cual se copian los datos.
	Corredores(const Corredores& otro);

	/***********************************************/
	/***********************************************/
	// Constructor con capacidad inicial
	// Descripción: Crea un objeto Corredores con una capacidad inicial.
	// Argumentos:
	//      capacidad_inicial: Capacidad inicial deseada.
	Corredores(int capacidad_inicial);

	/***********************************************/
	/***********************************************/
	// Destructor
	// Descripción: Libera memoria y recursos utilizados por el objeto.
	~Corredores(void);

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
	// Aniade
	// Descripción: Añade un objeto Corredor al final del objeto.
	// Argumentos:
	//      objeto: Objeto Corredor que se añade al final.
	void Aniade(const Corredor& objeto);

	/***********************************************/
	/***********************************************/
	// Inserta 
	// Descripción: Inserta un objeto Corredor en una posición específica.
	// Argumentos:
	//      objeto: Objeto Corredor que se inserta.
	//      num_casilla: Índice de la casilla en la que se inserta.
	void Inserta(const Corredor& objeto, const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Elimina 
	// Descripción: Elimina un objeto Corredor en una posición específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto que se elimina.
	void Elimina(const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Operador de asignación
	// Descripción: Asigna los datos de otro objeto a este objeto.
	// Argumentos:
	//      otro: Objeto Corredores del cual se copian los datos.
	// Devuelve: Una referencia al objeto actual después de la asignación.
	Corredores& operator=(const Corredores& otro);


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un corredor,
	// dado su dorsal. Si no está registrado devuelve -1.
	int NumOrdenCorredor (const int num_dorsal) const;


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un corredor,
	// dado su DNI. Si no está registrado devuelve -1.
	int NumOrdenCorredor (const string el_DNI_buscado) const;


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
	Corredor& operator[](const int num_casilla);
	Corredor operator[](const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 1 <= num_casilla <= usados
	Corredor& operator()(const int num_casilla);
	Corredor operator()(const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación ==
	// Descripción: Compara dos objetos Corredores.
	// Argumentos:
	//      otro: Objeto Corredores con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool operator==(const Corredores& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación !=
	// Descripción: Compara dos objetos Corredores.
	// Argumentos:
	//      otro: Objeto Corredores con el que se compara.
	// Devuelve: true si son distintos, false en caso contrario.
	bool operator!=(const Corredores& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación <
	// Descripción: Compara dos objetos Corredores.
	// Argumentos:
	//      otro: Objeto Corredores con el que se compara.
	// Devuelve: true si el objeto actual es menor que el otro.
	bool operator<(const Corredores& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación >
	// Descripción: Compara dos objetos Corredores.
	// Argumentos:
	//      otro: Objeto Corredores con el que se compara.
	// Devuelve: true si el objeto actual es mayor que el otro.
	bool operator>(const Corredores& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación <=
	// Descripción: Compara dos objetos Corredores.
	// Argumentos:
	//      otro: Objeto Corredores con el que se compara.
	// Devuelve: true si el objeto actual es menor o igual que el otro.
	bool operator<=(const Corredores& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación >=
	// Descripción: Compara dos objetos Corredores.
	// Argumentos:
	//      otro: Objeto Corredores con el que se compara.
	// Devuelve: true si el objeto actual es mayor o igual que el otro.
	bool operator>=(const Corredores& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador binario *
	// Descripción: Realiza la intersección de dos objetos Corredores.
	// Argumentos:
	//      uno: primer objeto Corredores.
	//      otro: segundo objeto Corredores.
	// Devuelve: Un objeto Corredores con los elementos comunes.
	friend Corredores operator*(const Corredores uno, const Corredores& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 1) [Corredores] && [Corredores]
	// Descripción: Devuelve true si el primer objeto Corredores 
	//				contiene al segundo. 
	// Argumentos:
	//        uno: primer objeto Corredores.
	//		  otro: segundo objeto Corredores.
	// Devuelve: true si el primer objeto contiene al segundo.
	friend bool operator&&( const Corredores& uno , const Corredores otro); 

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 2) [Corredores] && [Corredor]
	// Descripción: Devuelve true si el primer objeto Corredores
	//				contiene un Corredor 
	// Argumentos:
	//		  uno: Primer objeto Corredores.
	//        otro: Corredor a buscar.
	// Devuelve: true si el primer objeto contiene al Corredor.
	friend bool operator&&(const Corredores& uno , const Corredor& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 3) [Corredor] && [Corredores]
	// Descripción: Devuelve true si el primer objeto Corredor 
	//              esta contenido en en Corredores
	// Argumentos:
	//        Corredor: Corredor a buscar.
	//        uno: Primer objeto Corredores.
	// Devuelve: true si el Corredor esta en el primer objeto.
	friend bool operator&&(const Corredor& Corredor, const Corredores& uno);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 4) [Corredores] && [int]
	// Descripción: Devuelve true si el primer objeto Corredores
	//            Contiene un Corredor con el dorsal dado.
	// Argumentos:
	//		  uno: Primer objeto Corredores.
	//        num_dorsal: Dorsal a buscar.
	// Devuelve: true si el primer objeto contiene al Corredor.
	friend bool operator&&(const Corredores& uno, const int num_dorsal);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 5) [int] && [Corredores]
	// Descripción: Devuelve true si el primer parametro dorsal
	//            esta contenido en en Corredores
	// Argumentos:
	//        num_dorsal: Dorsal a buscar.
	//        uno: Primer objeto Corredores.
	// Devuelve: true si el Corredor esta en el primer objeto.
	friend bool operator&&(const int num_dorsal, const Corredores& uno);
	
	/***********************************************/
	/***********************************************/
	// Operador binario + (version 1) [Corredores] + [Corredores]
	// Descripción: Concatena dos datos Corredores en uno nuevo. 
	//		Los valores delsegundo (operando de la derecha) se añaden 
	//		(en el mismo orden) en una copia del primero.
	// Argumentos:
	//        uno: primer objeto Corredores.
	//		  otro: segundo objeto Corredores.
	// Devuelve: Un objeto Corredores con los elementos concatenados.
	friend Corredores operator+(const Corredores uno, const Corredores& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 2) [Corredores] + [Corredor]
	// Descripción: Añade un Corredor al final de una copia del 
	//				objeto Corredores.
	// Argumentos:
	//        uno: primer objeto Corredores.
	//		  otro: Corredor a añadir.
	// Devuelve: Un objeto Corredores con el Corredor añadido.
	friend Corredores operator+(const Corredores uno, const Corredor& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 3) [Corredor] + [Corredores]
	// Descripción: Añade un Corredor al principio de una copia del
	//				objeto Corredores.
	// Argumentos:
	//        uno: Corredor a añadir.
	//		  otro: primer objeto Corredores.
	// Devuelve: Un objeto Corredores con el Corredor añadido.
	friend Corredores operator+(const Corredor& uno, const Corredores otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 1) [Corredores] += [Corredores]
	// Descripción: Añade los elementos de un objeto Corredores al final.
	// Argumentos:
	//        uno: primer objeto Corredores.
	// Devuelve: Un objeto Corredores con los elementos añadidos.
	Corredores& operator+=(const Corredores& otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 2) [Corredores] += [Corredor]
	// Descripción: Añade un Corredor al final del objeto Corredores.
	// Argumentos:
	//        uno: primer objeto Corredores.
	// Devuelve: Un objeto Corredores con el Corredor añadido.
	Corredores& operator+=(const Corredor& otro);


private:

	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.

	void ReservarMemoria (const Corredores& otro);

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

	void CopiarDatos (const Corredores& otro);

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
	Corredor& ValorCasilla(const int num_casilla) const;


	/***********************************************/
	/***********************************************/
	// EsIgualA
	// Descripción: Compara dos objetos Corredores.
	// Argumentos:
	//      otro: Objeto Corredores con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool EsIgualA(const Corredores& otro) const;

};

#endif