/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Fecha.cpp
//
// Definiciones de la clase Fecha del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <chrono>

#include "Fecha.h"
#include "utils.h"

using namespace std;


/***********************************************/
/***********************************************/
// Sin paramteros incializa Fecha con la fecha actual
Fecha::Fecha()
{
    // Obtener el reloj de sistema actual
    auto now = chrono::system_clock::now();

    // Convertir el tiempo actual en un formato de fecha
    time_t time_now = chrono::system_clock::to_time_t(now);
    struct tm* timeinfo = localtime(&time_now);

    // Extraer el día, el mes y el año de la fecha actual
    dia = timeinfo->tm_mday;
    mes = timeinfo->tm_mon + 1; // meses desde 0 
    anio = timeinfo->tm_year + 1900; // Años desde 1900
   
}


/***********************************************/
/***********************************************/
// Inicializa la fecha
// Argumentos: 
//      linea: cadena de donde saca la informacion de cada
//              campo.
//      delimitador: separadore entre los campos (por defecto
//              el definido en la clase ":").
// POST :
//      Se han inicializado dia, mes y anio
Fecha::Fecha(string linea, char delimitador)
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
    rem_se_ext(campo2);
    linea = linea.substr(pos2+1);

    size_t pos3 = linea.find(delimitador);
    campo3 = linea.substr(0,pos3);
    rem_se_ext(campo3);
    

    /*********************************************/
    // Inicializo los campos
    dia = stoi(campo1);
    mes = stoi(campo2);
    anio = stoi(campo3);
}

/******************GETTERS**********************/

/***********************************************/
/***********************************************/
// Leen el valor de cada uno de los campos.
//
// Devuelve:
//      lo que valen  dia, mes y anio
int Fecha::GetDia() const {
    return dia;
}

int Fecha::GetMes() const {
    return mes;
}

int Fecha::GetAnio() const {
    return anio;
}



/******************SETTERS**********************/

/***********************************************/
/***********************************************/
// Cambian el valor de cada uno de los campos.
//
// POST:
//      Cambian lo que valen dia, mes y anios
void Fecha::SetDia(int d) {
    dia = d;
}

void Fecha::SetMes(int m) {
    mes = m;
}

void Fecha::SetAnio(int a) {
    anio = a;
}



/******************TOSTRING**********************/

/***********************************************/
/***********************************************/
// Imprime la fecha
// no recibe nada pero usa ":".
//
// Devuelve:
//      La fecha en formato string
string Fecha::ToString(bool corto)  const{
    
    

    // Convierto los enteros a string
    string campo_1 = FormatString(to_string(dia),2,TipoAlineacion::Derecha);
    string campo_2 = FormatMes(mes,corto)+" ";
    string campo_3 = to_string(anio);

    // Devuelvo la concatenacion
    return campo_1 +" " + campo_2 +campo_3;
}

/******************OPERADORES**********************/

/***********************************************/
/***********************************************/
// Compara dos fechas
// Argumentos:
//      f: fecha con la que se compara
// Devuelve:
//      true si la fecha es igual, false en caso contrario
bool Fecha::operator==(const Fecha &f)const
{
    return (dia == f.dia && mes == f.mes && anio == f.anio);

}

/***********************************************/
/***********************************************/
// Compara dos fechas
// Argumentos:
//      f: fecha con la que se compara
// Devuelve:
//      true si la fecha es mayor, false en caso contrario
bool Fecha::operator>(const Fecha &f)const
{
    bool menor = false;
    
    if(anio > f.anio)
    {
        menor = true;
    }
    else if(anio == f.anio)
    {
        if(mes > f.mes)
        {
            menor = true;
        }
        else if(mes == f.mes)
        {
            if(dia > f.dia)
            {
                menor = true;
            }
        }
    }
    return menor;
}