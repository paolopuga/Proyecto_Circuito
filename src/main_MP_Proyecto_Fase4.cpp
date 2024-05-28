/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: main_MP_Proyecto_Fase4.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 04. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "Utils.h"
#include "Directorios.h"

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

int main (int argc, char **argv )
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	// comprobar argumentos
	if (argc != 2) {
		cerr << "Error: número de argumentos incorrecto" << endl;
		cerr << "Uso: " << argv[0] <<  " Fichero.cfg" <<endl;
		exit(1);
	}

	// Inicilizar el fichero de configuración

	ifstream fcfg(argv[1]);
	if (!fcfg) {
		cerr << "Error: no se pudo abrir el fichero de entrada" << endl;
		cerr << "Compruebe que el fichero: |" << argv[1] << "| existe y\nsea"
		     << " accesible"<< endl;
		exit(2);
	}	

	// Cada linea se lee en un dato string. 
	string linea;
	getline(fcfg, linea); // cadena magica

	if (linea != "CIRCUITO") {
		cerr << "Error: formato de fichero incorrecto" << endl;
		exit(3);
	}

	SaltarCabecera(fcfg); // Saltar comentarios
	
	//......................................................................
	//......................................................................
	// DATOS GENERALES 
	//......................................................................
	//......................................................................

	cout << Cabecera ("DATOS GENERALES:");
	cout << endl; 	

	getline(fcfg, linea); // nombre del circuito
	cout << "CIRCUITO: " << linea << endl; 
	cout << endl; 	

	fcfg >> linea; // numero de carreras del circuito
	int num_carreras_circuito = stoi(linea);
	cout << "Carreras:   " << num_carreras_circuito << endl; 
 
	fcfg >> linea; // numero minimo de carreras para puntuar
	int num_carreras_minimo = stoi(linea);
	cout << "Minimo:     " << num_carreras_minimo << endl; 

	fcfg >> linea; // numero de carreras disputadas
	int num_carreras_disputadas = stoi(linea);
	cout << "Disputadas: " << num_carreras_disputadas << endl; 


	//......................................................................
	//......................................................................
	// CARRERAS
	//......................................................................
	//......................................................................
	
	Carreras coleccion_carreras; // Crear colección vacia
	string fcarreras;

	fcfg >> fcarreras; // nombre del fichero de carreras

	coleccion_carreras.LeerCarreras(fcarreras); // Leer colección

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
	
	Corredores coleccion_corredores; // Crear colección vacia
	string fcorredores;

	fcfg >> fcorredores; // nombre del fichero de corredores

	coleccion_corredores.LeerCorredores(fcorredores); // Leer colección

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
	
	Categorias coleccion_categorias; // Crear colección vacia
	string fcategorias;

	fcfg >> fcategorias; // nombre del fichero de categorias

	coleccion_categorias.LeerCategorias(fcategorias); // Leer colección

	cout << Cabecera ("CATEGORIAS:");

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
	string fresultados;

	cout << Cabecera ("RESULTADOS:");


	// Para cada carrera disputada

	for (int i=1; i<=num_carreras_disputadas; i++) {

		fcfg >> fresultados; // nombre del fichero de resultados

		Resultados resultados_carrera_i; // Crear colección
		resultados_carrera_i.LeerResultados(fresultados); // Leer colección

		Carrera carrera_actual = coleccion_carreras[i]; 
		// Operator [] de "Carreras"

		cout << "Guardados los resultados de la carrera " << setw(2) << i
		     << " [ " << carrera_actual.GetNombre() << " ] " << endl;
		     
		cout << "Total finalizados = "
		     << setw(3) << resultados_carrera_i.Usados() << endl; 
		cout << endl; 


		// Añadir "coleccion_resultados" a "todos_resultados"
		todos_resultados += resultados_carrera_i; 
		
	} // for i 

	fcfg.close();
	
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