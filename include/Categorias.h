/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Categorias.h
//
// Declaraciones de la clase Categorias del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef Categorias_H
#define Categorias_H

#include <iostream>
#include <string>

#include "Categoria.h"

using namespace std;

class Categorias{

private:

	// Tamanio del bloque para redimensionar
	static const int TAM_BLOQUE = 5;

	Categoria * datos;
	int capacidad;
	int usados;


public:
	
	
	/***********************************************/
	/***********************************************/
	// Constructor predeterminado
	// Descripción: Crea un objeto Categorias vacío.
	Categorias(void);

	/***********************************************/
	/***********************************************/
	// Constructor de copia
	// Descripción: Crea un nuevo objeto Categorias a partir de otro.
	// Argumentos:
	//      otro: Objeto Categorias del cual se copian los datos.
	Categorias(const Categorias& otro);

	/***********************************************/
	/***********************************************/
	// Constructor con capacidad inicial
	// Descripción: Crea un objeto Categorias con una capacidad inicial.
	// Argumentos:
	//      capacidad_inicial: Capacidad inicial deseada.
	Categorias(int capacidad_inicial);

	/***********************************************/
	/***********************************************/
	// Destructor
	// Descripción: Libera memoria y recursos utilizados por el objeto.
	~Categorias(void);

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
	// Descripción: Añade un objeto Categoria al final del objeto.
	// Argumentos:
	//      objeto: Objeto Categoria que se añade al final.
	void Aniade(const Categoria& objeto);

	/***********************************************/
	/***********************************************/
	// Inserta 
	// Descripción: Inserta un objeto Categoria en una posición específica.
	// Argumentos:
	//      objeto: Objeto Categoria que se inserta.
	//      num_casilla: Índice de la casilla en la que se inserta.
	void Inserta(const Categoria& objeto, const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Elimina 
	// Descripción: Elimina un objeto Categoria en una posición específica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto que se elimina.
	void Elimina(const int num_casilla);

	/***********************************************/
	/***********************************************/
	// Operador de asignación
	// Descripción: Asigna los datos de otro objeto a este objeto.
	// Argumentos:
	//      otro: Objeto Categorias del cual se copian los datos.
	// Devuelve: Una referencia al objeto actual después de la asignación.
	Categorias& operator=(const Categorias& otro);


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un Categoria,
	// dado su IdCategoria. Si no está registrado devuelve -1.
	int NumOrdenCategoria (const int IdCategoria) const;


	/***********************************************/
	/***********************************************/
	// Devuelve la posición en una colección de un Categoria,
	// dado su Denominación. Si no está registrado devuelve -1.
	int NumOrdenCategoria (const string Denominacion) const;


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
	Categoria& operator[](const int num_casilla);
	Categoria operator[](const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de acceso
	// Descripción: Permite modificar y leer una posición especifica.
	// Argumentos:
	//      num_casilla: Índice de la casilla del objeto deseado.
	// Devuelve: Una referencia al objeto en la posición especificada.
	// PRE: 1 <= num_casilla <= usados
	Categoria& operator()(const int num_casilla);
	Categoria operator()(const int num_casilla) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación ==
	// Descripción: Compara dos objetos Categorias.
	// Argumentos:
	//      otro: Objeto Categorias con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	bool operator==(const Categorias& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador de comparación !=
	// Descripción: Compara dos objetos Categorias.
	// Argumentos:
	//      otro: Objeto Categorias con el que se compara.
	// Devuelve: true si son distintos, false en caso contrario.
	bool operator!=(const Categorias& otro) const;

	/***********************************************/
	/***********************************************/
	// Operador binario *
	// Descripción: Realiza la intersección de dos objetos Categorias.
	// Argumentos:
	//      uno: primer objeto Categorias.
	//      otro: segundo objeto Categorias.
	// Devuelve: Un objeto Categorias con los elementos comunes.
	friend Categorias operator*(const Categorias uno, const Categorias& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 1) [Categorias] && [Categorias]
	// Descripción: Devuelve true si el primer objeto Categorias 
	//				contiene al segundo. 
	// Argumentos:
	//        uno: primer objeto Categorias.
	//		  otro: segundo objeto Categorias.
	// Devuelve: true si el primer objeto contiene al segundo.
	friend bool operator&&( const Categorias& uno , const Categorias otro); 

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 2) [Categorias] && [Categoria]
	// Descripción: Devuelve true si el primer objeto Categorias
	//				contiene un Categoria 
	// Argumentos:
	//		  uno: Primer objeto Categorias.
	//        otro: Categoria a buscar.
	// Devuelve: true si el primer objeto contiene al Categoria.
	friend bool operator&&(const Categorias& uno , const Categoria& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 3) [Categoria] && [Categorias]
	// Descripción: Devuelve true si el primer objeto Categoria 
	//              esta contenido en en Categorias
	// Argumentos:
	//        Categoria: Categoria a buscar.
	//        uno: Primer objeto Categorias.
	// Devuelve: true si el Categoria esta en el primer objeto.
	friend bool operator&&(const Categoria& Categoria, const Categorias& uno);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 4) [Categorias] && [int]
	// Descripción: Devuelve true si el primer objeto Categorias
	//            Contiene un Categoria con el dorsal dado.
	// Argumentos:
	//		  uno: Primer objeto Categorias.
	//        IdCategoria: ID a buscar.
	// Devuelve: true si el primer objeto contiene al Categoria.
	friend bool operator&&(const Categorias& uno, const int IdCategoria);

	/***********************************************/
	/***********************************************/
	// Operador binario && (version 5) [int] && [Categorias]
	// Descripción: Devuelve true si el primer parametro dorsal
	//            esta contenido en en Categorias
	// Argumentos:
	//        IdCategoria: Dorsal a buscar.
	//        uno: Primer objeto Categorias.
	// Devuelve: true si el Categoria esta en el primer objeto.
	friend bool operator&&(const int nIdCategoria, const Categorias& uno);
	
	/***********************************************/
	/***********************************************/
	// Operador binario + (version 1) [Categorias] + [Categorias]
	// Descripción: Concatena dos datos Categorias en uno nuevo. 
	//		Los valores delsegundo (operando de la derecha) se añaden 
	//		(en el mismo orden) en una copia del primero.
	// Argumentos:
	//        uno: primer objeto Categorias.
	//		  otro: segundo objeto Categorias.
	// Devuelve: Un objeto Categorias con los elementos concatenados.
	friend Categorias operator+(const Categorias uno, const Categorias& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 2) [Categorias] + [Categoria]
	// Descripción: Añade un Categoria al final de una copia del 
	//				objeto Categorias.
	// Argumentos:
	//        uno: primer objeto Categorias.
	//		  otro: Categoria a añadir.
	// Devuelve: Un objeto Categorias con el Categoria añadido.
	friend Categorias operator+(const Categorias uno, const Categoria& otro);

	/***********************************************/
	/***********************************************/
	// Operador binario + (version 3) [Categoria] + [Categorias]
	// Descripción: Añade un Categoria al principio de una copia del
	//				objeto Categorias.
	// Argumentos:
	//        uno: Categoria a añadir.
	//		  otro: primer objeto Categorias.
	// Devuelve: Un objeto Categorias con el Categoria añadido.
	friend Categorias operator+(const Categoria& uno, const Categorias otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 1) [Categorias] += [Categorias]
	// Descripción: Añade los elementos de un objeto Categorias al final.
	// Argumentos:
	//        uno: primer objeto Categorias.
	// Devuelve: Un objeto Categorias con los elementos añadidos.
	Categorias& operator+=(const Categorias& otro);

	/***********************************************/
	/***********************************************/
	// Operador combinado += (version 2) [Categorias] += [Categoria]
	// Descripción: Añade un Categoria al final del objeto Categorias.
	// Argumentos:
	//        uno: primer objeto Categorias.
	// Devuelve: Un objeto Categorias con el Categoria añadido.
	Categorias& operator+=(const Categoria& otro);


private:

	/************************************************************/
	/************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo.

	void ReservarMemoria (const Categorias& otro);

	/************************************************************/
	/************************************************************/
	// Pide memoria dado la capacidad
	// Parámetros: capacidad, capacidad deseada, por defecto TAM_BLOQUE
	void ReservarMemoria (int capacidad_incial = TAM_BLOQUE);

	/************************************************************/
	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Categorias& otro);

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
	
	Categoria& ValorCasilla(const int num_casilla) const;


	/***********************************************/
	/***********************************************/
	// EsIgualA
	// Descripción: Compara dos objetos Categorias.
	// Argumentos:
	//      otro: Objeto Categorias con el que se compara.
	// Devuelve: true si son iguales, false en caso contrario.
	
	bool EsIgualA(const Categorias& otro) const;

};

#endif