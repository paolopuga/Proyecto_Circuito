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
#include <iomanip>

#include "Resultado.h"
#include "utils.h"

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
    
    /**********************************************************/
    // Busco la posicion del delimitador para separar la cadena
    size_t pos1 = linea.find(delimitador);
    campo1 = linea.substr(0,pos1); // separo el campo
    rem_se_ext(campo1); // quito los espacios en blanco
    linea = linea.substr(pos1+1); // renuevo la linea quitando el separador

    //Repito el primer proceso para todos los campos

    size_t pos2 = linea.find(delimitador);
    campo2 = linea.substr(0,pos2);
    rem_se_ext(campo2);
    linea = linea.substr(pos2+1);

    size_t pos3 = linea.find(delimitador);
    campo3 = linea.substr(0,pos3);
    rem_se_ext(campo3);

    
    /*********************************************/
    // Inicializo los campos
    Dorsal = stoi(campo1);
    TiempoCarrera = Tiempo(campo2);
    Posicion = stoi(campo3);
    
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
// Devuelve:
//      Resultado en formato string
string Resultado::ToString() const{
    
    // Formateo los campos
    string campo_1 = FormatInt(Posicion,4) + ". ";
    string campo_2 = FormatInt(Dorsal,4) + " ";
    string campo_3 = TiempoCarrera.ToString(); 

    // Devuelvo la concatenacion
    return campo_1 + campo_2 + campo_3 ;
}
