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
#include <sstream>
#include <string>

#include "Tiempo.h"


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
    
    // Usamos flujos para separar los campos
    istringstream iss(linea);

    getline(iss, campo1, delimitador);
    getline(iss, campo2, delimitador);
    getline(iss, campo3, delimitador);
    
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
    ostringstream oss;

    oss << setfill('0') << setw(2) << horas << ":"
        << setfill('0') << setw(2) << minutos << ":"
        << setfill('0') << setw(2) << segundos;

    return oss.str();   
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

/***********************************************/
// Operador >>
// Argumentos:
//      objeto: objeto a inicilizar
// Inicializa los campos
istream &operator >> (istream & in, Tiempo & objeto)
{
    string linea;
    getline(in, linea);
    objeto = Tiempo(linea);

    return in;
}

/**********************************************/
// Operatos <<
// Argumentos:
//      objeto: objeto a mostrar
// devuelve un flujo con el objeto
ostream &operator << (ostream &out, Tiempo & objeto)
{
    out << setfill('0') << setw(2) << objeto.horas << ":"
        << setfill('0') << setw(2) << objeto.minutos << ":"
        << setfill('0') << setw(2) << objeto.segundos;

    return out;
}