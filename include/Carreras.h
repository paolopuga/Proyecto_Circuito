/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Carreras.h
//
// Declaraciones de la clase Carreras del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef Carreras_H
#define Carreras_H

#include <iostream>
#include <string>

#include "Carrera.h"

using namespace std;

class Carreras{

private:

	// Tamanio del bloque para redimensionar
	static const int TAM_BLOQUE = 5;

	Carrera * datos;
	int capacidad;
	int usados;


public:
	
	
	/***********************************************/
	/***********************************************/
	// Constructor predeterminado
	// Descripción: Crea un objeto Carreras vacío.
	Carreras(void);

	/***********************************************/
	/***********************************************/
	// Constructor de copia
	// Descripción: Crea un nuevo objeto Carreras a partir de otro.
	// Argumentos:
	//      otro: Objeto Carreras del cual se copian los datos.
	Carreras(const Carreras& otro);

	/***********************************************/
	/***********************************************/
	// Constructor con capacidad inicial
	// Descripción: Crea un objeto Carreras con una capacidad inicial.
	// Argumentos:
	//      capacidad_inicial: Capacidad inicial deseada.
	Carreras(int capacidad_inicial);

	/***********************************************/
	/***********************************************/
	// Destructor
	// Descripción: Libera memoria y recursos utilizados por el objeto.
	~Carreras(void);

	/***********************************************/
	/***********************************************/
	// getCapacidad
	// Descripción: Devuelve la capacidad actual del objeto.
	int Capacidad(void)const;

	/***********************************************/
	/***********************************************/
	// getUsados
	// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
	int Usados(void)const;

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
	// Descripción: Añade un objeto Carrera al final del objeto.
	// Argumentos:
	//      objeto: Objeto Carrera que se añade al final.
	void Aniade(const Carrera& objeto);

	/***********************************************/
	/***********************************************/
	// Inserta 
	// Descripción: Inserta un objeto Carrera en una posición específica.
	// Argumentos:
	//      objeto: Objeto Carrera que se inserta.
	//      num_casilla: Índice de la casilla en la que se inserta.
	void Inserta(const Carrera& objeto, const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Elimina 
	// Descripción: Elimina un objeto Carrera en una posición específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto que se elimina.
	void Elimina(const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Operador de asignación
	// Descripción: Asigna los datos de otro objeto a este objeto.
	// Argumentos:
	//      otro: Objeto Carreras del cual se copian los datos.
	// Devuelve: Una referencia al objeto actual después de la asignación.
	Carreras& operator=(const Carreras& otro);


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un Carrera,
	// dado su IdCarrera. Si no está registrado devuelve -1.
	int NumOrdenCarrera (const int IdCarrera) const;


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un Carrera,
	// dado su nombre. Si no está registrado devuelve -1.
	int NumOrdenCarrera (const string nombre) const;


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
	Carrera& operator[](const int num_casilla);
	Carrera operator[](const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 1 <= num_casilla <= usados
	Carrera& operator()(const int num_casilla);
	Carrera operator()(const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación ==
	// Descripción: Compara dos objetos Carreras.
	// Argumentos:
	//      otro: Objeto Carreras con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool operator==(const Carreras& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación !=
	// Descripción: Compara dos objetos Carreras.
	// Argumentos:
	//      otro: Objeto Carreras con el que se compara.
	// Devuelve: true si son distintos, false en caso contrario.
	bool operator!=(const Carreras& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador binario *
	// Descripción: Realiza la intersección de dos objetos Carreras.
	// Argumentos:
	//      uno: primer objeto Carreras.
	//      otro: segundo objeto Carreras.
	// Devuelve: Un objeto Carreras con los elementos comunes.
	friend Carreras operator*(const Carreras uno, const Carreras& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 1) [Carreras] && [Carreras]
	// Descripción: Devuelve true si el primer objeto Carreras 
	//				contiene al segundo. 
	// Argumentos:
	//        uno: primer objeto Carreras.
	//		  otro: segundo objeto Carreras.
	// Devuelve: true si el primer objeto contiene al segundo.
	friend bool operator&&( const Carreras& uno , const Carreras otro); 

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 2) [Carreras] && [Carrera]
	// Descripción: Devuelve true si el primer objeto Carreras
	//				contiene un Carrera 
	// Argumentos:
	//		  uno: Primer objeto Carreras.
	//        otro: Carrera a buscar.
	// Devuelve: true si el primer objeto contiene al Carrera.
	friend bool operator&&(const Carreras& uno , const Carrera& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 3) [Carrera] && [Carreras]
	// Descripción: Devuelve true si el primer objeto Carrera 
	//              esta contenido en en Carreras
	// Argumentos:
	//        Carrera: Carrera a buscar.
	//        uno: Primer objeto Carreras.
	// Devuelve: true si el Carrera esta en el primer objeto.
	friend bool operator&&(const Carrera& Carrera, const Carreras& uno);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 4) [Carreras] && [int]
	// Descripción: Devuelve true si el primer objeto Carreras
	//            Contiene un Carrera con el dorsal dado.
	// Argumentos:
	//		  uno: Primer objeto Carreras.
	//        IdCarrera: Id a buscar.
	// Devuelve: true si el primer objeto contiene al Carrera.
	friend bool operator&&(const Carreras& uno, const int IdCarrera);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 5) [int] && [Carreras]
	// Descripción: Devuelve true si el primer parametro dorsal
	//            esta contenido en en Carreras
	// Argumentos:
	//        IdCarrera: Id a buscar.
	//        uno: Primer objeto Carreras.
	// Devuelve: true si el Carrera esta en el primer objeto.
	friend bool operator&&(const int IdCarrera, const Carreras& uno);
	
	/***********************************************/
	/***********************************************/
	// Operador binario + (version 1) [Carreras] + [Carreras]
	// Descripción: Concatena dos datos Carreras en uno nuevo. 
	//		Los valores delsegundo (operando de la derecha) se añaden 
	//		(en el mismo orden) en una copia del primero.
	// Argumentos:
	//        uno: primer objeto Carreras.
	//		  otro: segundo objeto Carreras.
	// Devuelve: Un objeto Carreras con los elementos concatenados.
	friend Carreras operator+(const Carreras uno, const Carreras& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 2) [Carreras] + [Carrera]
	// Descripción: Añade un Carrera al final de una copia del 
	//				objeto Carreras.
	// Argumentos:
	//        uno: primer objeto Carreras.
	//		  otro: Carrera a añadir.
	// Devuelve: Un objeto Carreras con el Carrera añadido.
	friend Carreras operator+(const Carreras uno, const Carrera& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 3) [Carrera] + [Carreras]
	// Descripción: Añade un Carrera al principio de una copia del
	//				objeto Carreras.
	// Argumentos:
	//        uno: Carrera a añadir.
	//		  otro: primer objeto Carreras.
	// Devuelve: Un objeto Carreras con el Carrera añadido.
	friend Carreras operator+(const Carrera& uno, const Carreras otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 1) [Carreras] += [Carreras]
	// Descripción: Añade los elementos de un objeto Carreras al final.
	// Argumentos:
	//        uno: primer objeto Carreras.
	// Devuelve: Un objeto Carreras con los elementos añadidos.
	Carreras& operator+=(const Carreras& otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 2) [Carreras] += [Carrera]
	// Descripción: Añade un Carrera al final del objeto Carreras.
	// Argumentos:
	//        uno: primer objeto Carreras.
	// Devuelve: Un objeto Carreras con el Carrera añadido.
	Carreras& operator+=(const Carrera& otro);


private:

	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.

	void ReservarMemoria (const Carreras& otro);

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

	void CopiarDatos (const Carreras& otro);

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
	Carrera& ValorCasilla(const int num_casilla) const;


	/***********************************************/
	/***********************************************/
	// EsIgualA
	// Descripción: Compara dos objetos Carreras.
	// Argumentos:
	//      otro: Objeto Carreras con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool EsIgualA(const Carreras& otro) const;

};

#endif