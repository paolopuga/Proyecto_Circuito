/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Resultados.h
//
// Declaraciones de la clase Resultados del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef Resultados_H
#define Resultados_H

#include <iostream>
#include <string>

#include "Resultado.h"

using namespace std;

class Resultados{

private:

	// Tamanio del bloque para redimensionar
	static const int TAM_BLOQUE = 5;

	Resultado * datos;
	int capacidad;
	int usados;


public:
	
	
	/***********************************************/
	/***********************************************/
	// Constructor predeterminado
	// Descripción: Crea un objeto Resultados vacío.
	Resultados(void);

	/***********************************************/
	/***********************************************/
	// Constructor de copia
	// Descripción: Crea un nuevo objeto Resultados a partir de otro.
	// Argumentos:
	//      otro: Objeto Resultados del cual se copian los datos.
	Resultados(const Resultados& otro);

	/***********************************************/
	/***********************************************/
	// Constructor con capacidad inicial
	// Descripción: Crea un objeto Resultados con una capacidad inicial.
	// Argumentos:
	//      capacidad_inicial: Capacidad inicial deseada.
	Resultados(int capacidad_inicial);

	/***********************************************/
	/***********************************************/
	// Destructor
	// Descripción: Libera memoria y recursos utilizados por el objeto.
	~Resultados(void);

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
	// Descripción: Añade un objeto Resultado al final del objeto.
	// Argumentos:
	//      objeto: Objeto Resultado que se añade al final.
	void Aniade(const Resultado& objeto);

	/***********************************************/
	/***********************************************/
	// Inserta 
	// Descripción: Inserta un objeto Resultado en una posición específica.
	// Argumentos:
	//      objeto: Objeto Resultado que se inserta.
	//      num_casilla: Índice de la casilla en la que se inserta.
	void Inserta(const Resultado& objeto, const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Elimina 
	// Descripción: Elimina un objeto Resultado en una posición específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto que se elimina.
	void Elimina(const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Operador de asignación
	// Descripción: Asigna los datos de otro objeto a este objeto.
	// Argumentos:
	//      otro: Objeto Resultados del cual se copian los datos.
	// Devuelve: Una referencia al objeto actual después de la asignación.
	Resultados& operator=(const Resultados& otro);


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un Resultado,
	// dado su dorsal. Si no está registrado devuelve -1.
	int NumOrdenResultado (const int num_dorsal) const;


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un Resultado,
	// dado su DNI. Si no está registrado devuelve -1.
	int NumOrdenResultado (const Tiempo tiempo) const;


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
	Resultado& operator[](const int num_casilla);
	Resultado operator[](const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 1 <= num_casilla <= usados
	Resultado& operator()(const int num_casilla);
	Resultado operator()(const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación ==
	// Descripción: Compara dos objetos Resultados.
	// Argumentos:
	//      otro: Objeto Resultados con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool operator==(const Resultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación !=
	// Descripción: Compara dos objetos Resultados.
	// Argumentos:
	//      otro: Objeto Resultados con el que se compara.
	// Devuelve: true si son distintos, false en caso contrario.
	bool operator!=(const Resultados& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador binario *
	// Descripción: Realiza la intersección de dos objetos Resultados.
	// Argumentos:
	//      uno: primer objeto Resultados.
	//      otro: segundo objeto Resultados.
	// Devuelve: Un objeto Resultados con los elementos comunes.
	friend Resultados operator*(const Resultados uno, const Resultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 1) [Resultados] && [Resultados]
	// Descripción: Devuelve true si el primer objeto Resultados 
	//				contiene al segundo. 
	// Argumentos:
	//        uno: primer objeto Resultados.
	//		  otro: segundo objeto Resultados.
	// Devuelve: true si el primer objeto contiene al segundo.
	friend bool operator&&( const Resultados& uno , const Resultados otro); 

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 2) [Resultados] && [Resultado]
	// Descripción: Devuelve true si el primer objeto Resultados
	//				contiene un Resultado 
	// Argumentos:
	//		  uno: Primer objeto Resultados.
	//        otro: Resultado a buscar.
	// Devuelve: true si el primer objeto contiene al Resultado.
	friend bool operator&&(const Resultados& uno , const Resultado& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 3) [Resultado] && [Resultados]
	// Descripción: Devuelve true si el primer objeto Resultado 
	//              esta contenido en en Resultados
	// Argumentos:
	//        Resultado: Resultado a buscar.
	//        uno: Primer objeto Resultados.
	// Devuelve: true si el Resultado esta en el primer objeto.
	friend bool operator&&(const Resultado& Resultado, const Resultados& uno);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 4) [Resultados] && [int]
	// Descripción: Devuelve true si el primer objeto Resultados
	//            Contiene un Resultado con el dorsal dado.
	// Argumentos:
	//		  uno: Primer objeto Resultados.
	//        num_dorsal: Dorsal a buscar.
	// Devuelve: true si el primer objeto contiene al Resultado.
	friend bool operator&&(const Resultados& uno, const int num_dorsal);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 5) [int] && [Resultados]
	// Descripción: Devuelve true si el primer parametro dorsal
	//            esta contenido en en Resultados
	// Argumentos:
	//        num_dorsal: Dorsal a buscar.
	//        uno: Primer objeto Resultados.
	// Devuelve: true si el Resultado esta en el primer objeto.
	friend bool operator&&(const int num_dorsal, const Resultados& uno);
	
	/***********************************************/
	/***********************************************/
	// Operador binario + (version 1) [Resultados] + [Resultados]
	// Descripción: Concatena dos datos Resultados en uno nuevo. 
	//		Los valores delsegundo (operando de la derecha) se añaden 
	//		(en el mismo orden) en una copia del primero.
	// Argumentos:
	//        uno: primer objeto Resultados.
	//		  otro: segundo objeto Resultados.
	// Devuelve: Un objeto Resultados con los elementos concatenados.
	friend Resultados operator+(const Resultados uno, const Resultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 2) [Resultados] + [Resultado]
	// Descripción: Añade un Resultado al final de una copia del 
	//				objeto Resultados.
	// Argumentos:
	//        uno: primer objeto Resultados.
	//		  otro: Resultado a añadir.
	// Devuelve: Un objeto Resultados con el Resultado añadido.
	friend Resultados operator+(const Resultados uno, const Resultado& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 3) [Resultado] + [Resultados]
	// Descripción: Añade un Resultado al principio de una copia del
	//				objeto Resultados.
	// Argumentos:
	//        uno: Resultado a añadir.
	//		  otro: primer objeto Resultados.
	// Devuelve: Un objeto Resultados con el Resultado añadido.
	friend Resultados operator+(const Resultado& uno, const Resultados otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 1) [Resultados] += [Resultados]
	// Descripción: Añade los elementos de un objeto Resultados al final.
	// Argumentos:
	//        uno: primer objeto Resultados.
	// Devuelve: Un objeto Resultados con los elementos añadidos.
	Resultados& operator+=(const Resultados& otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 2) [Resultados] += [Resultado]
	// Descripción: Añade un Resultado al final del objeto Resultados.
	// Argumentos:
	//        uno: primer objeto Resultados.
	// Devuelve: Un objeto Resultados con el Resultado añadido.
	Resultados& operator+=(const Resultado& otro);


private:

	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.

	void ReservarMemoria (const Resultados& otro);

	/************************************************************/
	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Resultados& otro);

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
	Resultado& ValorCasilla(const int num_casilla) const;


	/***********************************************/
	/***********************************************/
	// EsIgualA
	// Descripción: Compara dos objetos Resultados.
	// Argumentos:
	//      otro: Objeto Resultados con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool EsIgualA(const Resultados& otro) const;

};

#endif