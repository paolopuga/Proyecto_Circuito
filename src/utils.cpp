/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: utils.cpp
//
// Definiciones de la clase utils del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include "utils.h"
using namespace std; 

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

string FormatInt (int numero, int num_casillas, char relleno)
{
	string format_int = to_string(numero);

	int tamanio = format_int.size();
	int diferencia = num_casillas - tamanio;
	
	if (diferencia > 0)
	{
		for (int i = 0; i < diferencia; ++i)
		{
			format_int = string(1,relleno) + format_int;
		}
	}


	return format_int;
}


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
int num_dec, char relleno)
{	
	string format_double = to_string(numero); // Cadena completa para tamanio
	int tamanio = format_double.size();
	
	int entera = static_cast<int>(numero);
	string parte_ent = to_string(entera); // Cadena con la parte entera
	int tamanio_ent = parte_ent.size();

	string parte_dec = format_double.substr(tamanio_ent+1);	// Cadena parte dec
	int tamanio_dec = parte_dec.size();					// quitando el punto

	
	if (num_dec == 0) // Si es 0 muestro solo la parte entera
	{
		format_double = parte_ent;
		tamanio = tamanio_ent;
	}

	if (num_dec > tamanio_dec) // Relleno con 0 si es mayor que el numero decim
	{
		for (int i = 0; i < (num_dec - tamanio_dec); ++i)
		{
			format_double = format_double + "0";
			tamanio++;
		}
	}

	if (num_dec < tamanio_dec)
	{
		format_double = format_double.substr(0,tamanio_ent+num_dec+1);
	}


	if (num_casillas > tamanio) // Relleno con relleno si es mayor que num_cas
	{
		for (int i = 0; i < (num_casillas - tamanio); ++i)
		{
			format_double = string(1,relleno) + format_double;
		}
	}

 	return format_double; // devuelvo la cadena formateada
}


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
		TipoAlineacion alineacion ,
		char relleno)
{
	int tamanio_cadena = la_cadena.size();

    if (tamanio_cadena >= num_casillas)
    {
        // La cadena ya es igual o más larga que el espacio deseado
        return la_cadena;
    }

    int espacios_restantes = num_casillas - tamanio_cadena;
    string format_string;

    if (alineacion == TipoAlineacion::Izquierda)
    {
        format_string = la_cadena + string(espacios_restantes, relleno);
    }

    else if (alineacion == TipoAlineacion::Centro)
    {
        int espacios_izquierda = espacios_restantes / 2;
        int espacios_derecha = espacios_restantes - espacios_izquierda;

        format_string = string(espacios_izquierda, relleno) + la_cadena +
                    	string(espacios_derecha, relleno);
    }

    else if (alineacion == TipoAlineacion::Derecha)
    {
        format_string= string(espacios_restantes, relleno) + la_cadena;
    }

    return format_string;	
}


/***************************************************************************/
/***************************************************************************/
// Formatea el numero del mes
//
// Argumentos:
// 		numero: numero del mes
//
// Devuelve: el nombre del mes

string FormatMes(int numero, bool corto)
{

	string format_mes;

	if (numero == 1)
	{
		format_mes = "Enero";
	}
	if (numero == 2)
	{
		format_mes = "Febrero";
	}
	if (numero == 3)
	{
		format_mes = "Marzo";
	}
	if (numero == 4)
	{
		format_mes = "Abril";
	}
	if (numero == 5)
	{
		format_mes = "Mayo";
	}
	if (numero == 6)
	{
		format_mes = "Junio";
	}
	if (numero == 7)
	{
		format_mes = "Julio";
	}
	if (numero == 8)
	{
		format_mes = "Agosto";
	}
	if (numero == 9)
	{
		format_mes = "Septiembre";
	}
	if (numero == 10)
	{
		format_mes = "Octubre";
	}
	if (numero == 11)
	{
		format_mes = "Noviembre";
	}
	if (numero == 12)
	{
		format_mes = "Diciembre";
	}

	if (corto)
	{
		format_mes=format_mes.substr(0,3);
	}
	return format_mes;
}


/***************************************************************************/
/***************************************************************************/
// Elimina los separadores extremos
//
// Argumentos:
// 		cadena: referencia a la cadena original
//
// POST: La cadena no tiene separadores extremos

void rem_se_ext( string& cadena)
{
	int inicio = 0;
    int fin = cadena.length() - 1;

    while (inicio < cadena.length() && isspace(cadena[inicio])) {
        inicio++;
    }

    while (fin > inicio && isspace(cadena[fin])) {
        fin--;
    }

    cadena = cadena.substr(inicio, fin - inicio + 1);
}


