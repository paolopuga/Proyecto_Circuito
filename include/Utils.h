/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: utils.h
//
// Declaraciones de la clase utils del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/
#ifndef UTILS
#define UTILS

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Declaración de la función SaltarCabecera
//
// Parámetros:
// 	- ifstream &fichero: referencia a un fichero de entrada
//
// Función:
// 	Salta las líneas de comentario de un fichero de entrada
//
// Valor devuelto:
// 	ninguno
//
/***************************************************************************/
void SaltarCabecera(ifstream &fichero);


/***************************************************************************/
/***************************************************************************/
// Aniade el directorio de datos al nombre del fichero
//
// Parámetros:
// 	- string directorio: directorio de datos
// 	- string fichero: nombre del fichero
//
// Función:
// 	Concatena el directorio de datos con el nombre del fichero
//
// Valor devuelto:
// 	string: el nombre del fichero con el directorio de datos
//
/***************************************************************************/
string AniadirDirectorio(const string &directorio, const string &fichero);

/***************************************************************************/
/***************************************************************************/
// Delcaracion de la funcion RemoveBlanks
//
// Parámetros:
// 	- string &linea: referencia a una cadena de caracteres
//
// Función:
// 	Quita los espacios en blanco al principio y al final de la cadena
//
// Valor devuelto:
// 	string: la cadena sin espacios en blanco al principio y al final
//
/***************************************************************************/
string RemoveBlanks(string &linea);

#endif