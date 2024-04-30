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


// Modelo de alineacion para formatear Cadenas
enum class TipoAlineacion {Izquierda, Centro, Derecha};


/***************************************************************************/
/***************************************************************************/
// Formatea un número entero como una cadena de caracteres con un número 
// específico de casillas.Si el número tiene menos dígitos que el número de 
// casillas, se rellena con el carácter especificado.
//
// Argumentos:
// 		numero: El enetero a formatear.
// 		num_casillas: El número total de casillas deseado.
// 		relleno: El carácter de relleno (por defecto es espacio).
//
// Devuelve: La cadena formateada.

string FormatInt (int numero, int num_casillas, char relleno=' ');


/***************************************************************************/
/***************************************************************************/
// Formatea un double como una cadena de caracteres con un número específico 
// de casillas y un número específico de decimales. Se rellena con el carácter 
// especificado si es necesario.
//
// Argumentos:
// 		numero: El double a formatear.
// 		num_casillas: El número total de casillas deseado.
//		num_dec: El número de decimales deseado.		
// 		relleno: El carácter de relleno (por defecto es espacio).
//
// Devuelve: La cadena formateada.

string FormatDouble (double numero, int num_casillas,
int num_dec, char relleno=' ');


/***************************************************************************/
/***************************************************************************/
// Formatea una cadena de caracteres con un número específico de casillas y 
// alineación. Se rellena con el carácter especificado si es necesario.
//
// Argumentos:
// 		la_cadena: La cadena de caracteres original.
// 		num_casillas: El número total de casillas deseado.
// 		alineacion: La alineación deseada (Izquierda, Centro o Derecha).
// 		relleno: El carácter de relleno (por defecto es espacio).
//
// Devuelve: La cadena formateada.

string FormatString (string la_cadena, int num_casillas,
TipoAlineacion alineacion = TipoAlineacion::Izquierda,
char relleno=' ');

/***************************************************************************/
/***************************************************************************/
// Formatea el numero del mes
//
// Argumentos:
// 		numero: numero del mes
//
// Devuelve: el nombre del mes

string FormatMes(int numero, bool corto = false);


/***************************************************************************/
/***************************************************************************/
// Elimina los separadores extremos
//
// Argumentos:
// 		cadena: referencia a la cadena original
//
// POST: La cadena no tiene separadores extremos

void rem_se_ext(string& cadena);

#endif 