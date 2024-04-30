/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Tiempo.cpp
//
// Definiciones de la clase Tiempo del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <chrono>
#include <iostream>
#include <cstring>
#include <iomanip>

#include "Tiempo.h"
#include "utils.h"


using namespace std;


/***********************************************/
/***********************************************/
// Sin paramteros incializa el tiempo con la hora actual

Tiempo::Tiempo()
{
    // Obtener el reloj de sistema actual
    auto now = chrono::system_clock::now();

    // Convertir el tiempo actual en un formato de fecha
    time_t time_now = chrono::system_clock::to_time_t(now);
    struct tm* timeinfo = localtime(&time_now);

    // Extraer el día, el mes y el año de la fecha actual
    
    horas = timeinfo->tm_hour;
    minutos = timeinfo->tm_min; 
    segundos = timeinfo->tm_sec ; 
}

/***********************************************/
/***********************************************/
// Inicializa el tiempo
// Argumentos: 
//      linea: cadena de donde saca la informacion de cada
//              campo.
//      delimitador: separadore entre los campos (por defecto
//              el definido en la clase ":").
// POST :
//      Se han inicializado horas, minutos y segundos

Tiempo::Tiempo(string linea, char delimitador)
{
   
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
    rem_se_ext(campo1);
    linea = linea.substr(pos2+1);

    size_t pos3 = linea.find(delimitador);
    campo3 = linea.substr(0,pos3);
    rem_se_ext(campo1);

    
    /*********************************************/
    // Inicializo los campos
    horas = stoi(campo1);    
    minutos = stoi(campo2);
    segundos = stoi(campo3);
}

/******************GETTERS**********************/

/***********************************************/
/***********************************************/
// Leen el valor de cada uno de los campos.
//
// Devuelve:
//      lo que valen las horas, minutos y segundos
int Tiempo::GetHoras() const{
    return horas;
}

int Tiempo::GetMinutos() const {
    return minutos;
}

int Tiempo::GetSegundos() const {
    return segundos;
}


/******************SETTERS**********************/

/***********************************************/
/***********************************************/
// Cambian el valor de cada uno de los campos.
//
// POST:
//      Cambian lo que valen las horas, minutos y segundos
void Tiempo::SetHoras(int h) {
    horas = h;
}

void Tiempo::SetMinutos(int m) {
    minutos = m;
}

void Tiempo::SetSegundos(int s) {
    segundos = s;
}

/******************TOSTRING**********************/

/***********************************************/
/***********************************************/
// Imprime la hora 00:00:00
// no recibe nada 
// Devuelve:
//      la hora formateada   
string Tiempo::ToString() const
{
    
    string hora_actual;


    string campo1, campo2, campo3;
    campo1 = FormatInt(horas,2,'0') + ":";
    campo2 = FormatInt(minutos,2,'0')+ ":";
    campo3 = FormatInt(segundos,2, '0');
    hora_actual = campo1 + campo2 + campo3;
    

    return hora_actual;
}

/******************OPERADORES**********************/

/***********************************************/
/***********************************************/
// Operador de comparacion
// Argumentos:
//      t: tiempo con el que se compara
// Devuelve:
//      true si el tiempo es igual, false en caso contrario
bool Tiempo::operator==(const Tiempo &t)const
{
    return (horas == t.horas && minutos == t.minutos && 
            segundos == t.segundos);
}

/***********************************************/
/***********************************************/
// Operador de comparacion >
// Argumentos:
//      t: tiempo con el que se compara
// Devuelve:
//      true si el tiempo es mayor, false en caso contrario
bool Tiempo::operator>(const Tiempo &t)const
{
    bool menor = false;
    
    if(horas > t.horas)
    {
        menor = true;
    }
    else if(horas == t.horas)
    {
        if(minutos > t.minutos)
        {
            menor = true;
        }
        else if(minutos == t.minutos)
        {
            if(segundos > t.segundos)
            {
                menor = true;
            }
        }
    }

    return menor;
}