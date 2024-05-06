/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase3.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 03. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "utils.h"

#include "Fecha.h"
#include "Tiempo.h"

#include "Carrera.h"
#include "Corredor.h"
#include "Categoria.h"
#include "Resultado.h"

#include "Carreras.h"
#include "Corredores.h"
#include "Categorias.h"
#include "Resultados.h"

#include "TodosResultados.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

string Cabecera  (const char * titulo);

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales


	// Cada linea se lee en un dato string. 
	string linea;

	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";

	
	//......................................................................
	//......................................................................
	// DATOS GENERALES 
	//......................................................................
	//......................................................................

	cout << Cabecera ("DATOS GENERALES:");
	cout << endl; 	
	
	getline(cin, linea); 
	cout << "CIRCUITO: " << linea << endl; 
	cout << endl; 	

	getline(cin, linea); 
	int num_carreras_circuito = stoi (linea);
	cout << "Carreras:   " << num_carreras_circuito << endl; 
 
	getline(cin, linea); 
	int num_carreras_minimo = stoi (linea);
	cout << "Minimo:     " << num_carreras_minimo << endl; 

	getline(cin, linea); 
	int num_carreras_disputadas = stoi (linea);
	cout << "Disputadas: " << num_carreras_disputadas << endl; 

	getline(cin, linea); // Saltar TERMINADOR


	//......................................................................
	//......................................................................
	// CARRERAS
	//......................................................................
	//......................................................................

	Carreras coleccion_carreras; // Crear colección (vacía)


	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
					
		Carrera una_carrera (linea);

		// Añadir el dato "Carrera" leido a la colección 
		coleccion_carreras += una_carrera; // Operator += 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)



	cout << Cabecera ("CARRERAS:");

	cout << endl;
	cout << coleccion_carreras.ToString(); 
	cout << endl;

	cout << "Total carreras del circuito = "<<setw(3) 
	     << coleccion_carreras.Usados() << endl; 
	cout << endl; 



	//......................................................................
	//......................................................................
	// CORREDORES
	//......................................................................
	//......................................................................
	 
	Corredores coleccion_corredores; // Crear colección (vacía)


	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
					
		Corredor un_corredor (linea);

		// Añadir el dato "Corredor" leido a la colección 
		coleccion_corredores += un_corredor; // Operator += 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)


	cout << Cabecera ("CORREDORES:");

	cout << endl;
	cout << coleccion_corredores.ToString(); 
	cout << endl;

	cout << "Total corredores del circuito = "<<setw(3) 
	     << coleccion_corredores.Usados() << endl; 
	cout << endl; 



	//......................................................................
	//......................................................................
	// CATEGORIAS
	//......................................................................
	//......................................................................
	 
	Categorias coleccion_categorias; // Crear colección (vacía)

	cout << Cabecera ("CATEGORIAS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
					
		Categoria una_categoria (linea);

		// Añadir el dato "Categoria" leido a la colección  
		coleccion_categorias += una_categoria; // Operator += 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)

	cout << endl;
	cout << coleccion_categorias.ToString(); 
	cout << endl;

	cout << "Total categorias = "<<setw(3) 
	     << coleccion_categorias.Usados() << endl; 
	cout << endl; 
	


	//......................................................................
	//......................................................................
	// RESULTADOS Y COLECCION DE RESULTADOS
	//......................................................................
	//......................................................................
	 
	// Almacen de los resultados de todas las carreras 
	// Se reserva espacio para todas las carreras aunque alguna 
	// no se haya disputado. 

	TodosResultados todos_resultados (num_carreras_circuito); 


	cout << Cabecera ("RESULTADOS:");


	// Para cada carrera disputada

	for (int i=1; i<=num_carreras_disputadas; i++) {

		// Para almacenar la clasificación de la carrera "i" 

		Resultados resultados_carrera_i; // Crear colección (vacía)


		getline(cin, linea); // Lectura adelantada

		while (linea != TERMINADOR) {
							
			Resultado un_resultado (linea);

			// Añadir el dato "Resultado" leido a la colección  
			resultados_carrera_i += un_resultado;

			// Leer la siguiente linea 
			getline(cin, linea); 
			
		} // while (linea != TERMINADOR)


		Carrera carrera_actual = coleccion_carreras[i]; 
		// Operator [] de "Carreras"

		cout << "Guardados los resultados de la carrera " << FormatInt(i, 2) 
		     << " [ " << carrera_actual.GetNombre() << " ] " << endl;
		     
		cout << "Total finalizados = "
		     << setw(3) << resultados_carrera_i.Usados() << endl; 
		cout << endl; 


		// Añadir "coleccion_resultados" a "todos_resultados"
		todos_resultados += resultados_carrera_i; 
		
	} // for i 


	cout << Cabecera ("TODOS RESULTADOS:");

	cout << endl;
	cout << todos_resultados.ToString(); 
	cout << endl;

	cout << "Total carerras con resultados = "<<setw(3) 
	     << todos_resultados.Usados() << endl; 
	cout << endl; 



	return 0;
}

/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo)
{
	const int TAM_GUIONES = 70; 
	char guiones[TAM_GUIONES]; 

	memset (guiones, '-', TAM_GUIONES-1); 
	guiones[TAM_GUIONES-1] = '\0'; 

	string cad_guiones (guiones); 

	string cad;

	cad = cad + cad_guiones + "\n";
	cad = cad + titulo + "\n";
	cad = cad + cad_guiones + "\n";

	return cad; 
}

/***************************************************************************/
/***************************************************************************/

void Intercambia (Corredor & uno, Corredor & otro)
{
	Corredor tmp = uno;
	uno = otro; 
	otro = tmp; 
}

/***************************************************************************/
/***************************************************************************/
