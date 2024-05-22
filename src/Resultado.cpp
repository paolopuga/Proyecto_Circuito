/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Resultado.cpp
//
// Definiciones de la clase Resultado del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>

#include "Resultado.h"
#include "Tiempo.h"

#include "Utils.h"

using namespace std;

/******************CONSTRUCTORES**********************/

/***********************************************/
/***********************************************/
// Inicializa Resultado
// Argumentos: 
//      linea: cadena de donde saca la informacion de cada
//              campo.
//      delimitador: separadore entre los campos (por defecto
//              el definido en la clase ":").
// POST :
//      Se han inicializado Posicion, Dorsal y TiempoCarrera
Resultado::Resultado(string linea, char delimitador) {
    
    // Declaro un string para campo
    string campo1, campo2, campo3;
    
    // Usamos flujos para separar los campos
    istringstream iss(linea);

    getline(iss, campo1, delimitador);
    getline(iss, campo2, delimitador);
    getline(iss, campo3, delimitador);
   
    /*********************************************/
    // Inicializo los campos numericos con stoi
    Dorsal = stoi(RemoveBlanks(campo1));   
    Posicion = stoi(RemoveBlanks(campo3));

    // Inicializo los campos de tipo Tiempo
    TiempoCarrera = Tiempo(RemoveBlanks(campo2));
    
}


/***********************************************/
/***********************************************/
// Inicializa Resultado
// Argumentos:
//	  no tiene argumentos
// POST : 
//	  Se han inicializado Resultado vacío.
Resultado::Resultado():TiempoCarrera(Tiempo())
{
    Posicion = 0;
    Dorsal = 0;    
}

/******************GETTERS**********************/

/***********************************************/
/***********************************************/
// Leen el valor de cada uno de los campos.
//
// Devuelve:
//      lo que valen  Dorsal, Posicion y TiempoCarrera
int Resultado::GetDorsal() const{
    return Dorsal;
}

int Resultado::GetPosicion() const{
    return Posicion;
}

Tiempo Resultado::GetTiempoCarrera() const{
    return TiempoCarrera;
}




/******************SETTERS**********************/

/***********************************************/
/***********************************************/
// Cambian el valor de cada uno de los campos.
//
// POST:
//      Cambian lo que valen Posicion y TiempoCarrera
void Resultado::SetDorsal(int dorsal) {
    Dorsal = dorsal;
}
void Resultado::SetPosicion(int posicion) {
    Posicion = posicion;
}

void Resultado::SetTiempoCarrera(Tiempo tiempo_carrera) {
    TiempoCarrera = tiempo_carrera;
}



/******************TOSTRING**********************/

/***********************************************/
/***********************************************/
// Imprime los campos de Resultado
// no recibe nada pero usa los métodos de formateo de utils
//
// Argumentos:
//      nombre: nombre del resultado
// Devuelve:
//      Carrera en formato string
string Resultado::ToString (const string nombre) const
{
    ostringstream oss;
    oss << setw(3) << Posicion << " ";
    oss << setw(4) << Dorsal << " ";
    oss << TiempoCarrera.ToString() << " ";

    return oss.str();
}

/***********************************************/
// Operador >>
// Argumentos:
//      objeto: objeto a inicilizar
// Inicializa los campos
istream & operator >> (istream & in, Resultado & objeto)
{
    string linea;
    getline(in, linea);
    if(!in.eof())objeto = Resultado(linea);
    return in;
}

/**********************************************/
// Operatos <<
// Argumentos:
//      objeto: objeto a mostrar
// devuelve un flujo con el objeto
ostream & operator << (ostream &out, Resultado & objeto)
{
    out << objeto.Dorsal<< objeto.DELIMITADOR;
    out << objeto.TiempoCarrera << objeto.DELIMITADOR;
    out << objeto.Posicion << objeto.DELIMITADOR;

    return out;
}
