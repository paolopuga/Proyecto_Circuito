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
#include <sstream>
#include <string>

#include "Fecha.h"

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

    // inicializo vector de meses
    MESES[0] = "Enero";
    MESES[1] = "Febrero";
    MESES[2] = "Marzo";
    MESES[3] = "Abril";
    MESES[4] = "Mayo";
    MESES[5] = "Junio";
    MESES[6] = "Julio";
    MESES[7] = "Agosto";
    MESES[8] = "Septiembre";
    MESES[9] = "Octubre";
    MESES[10] = "Noviembre";
    MESES[11] = "Diciembre";
   
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

    // Usamos flujos de string para separar los campos
    istringstream iss(linea);

    // Separo los campos
    getline(iss, campo1, delimitador);
    getline(iss, campo2, delimitador);
    getline(iss, campo3, delimitador);

    /*********************************************/
    // Inicializo los campos
    dia = stoi(campo1);
    mes = stoi(campo2);
    anio = stoi(campo3);

    // inicializo vector de meses
    MESES[0] = "Enero";
    MESES[1] = "Febrero";
    MESES[2] = "Marzo";
    MESES[3] = "Abril";
    MESES[4] = "Mayo";
    MESES[5] = "Junio";
    MESES[6] = "Julio";
    MESES[7] = "Agosto";
    MESES[8] = "Septiembre";
    MESES[9] = "Octubre";
    MESES[10] = "Noviembre";
    MESES[11] = "Diciembre";
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
    
    ostringstream oss;

    string mes_string = MESES[mes-1]; // Obtengo el mes en formato string

    string mes_corto = mes_string.substr(0,3); // mes en formato corto

    oss<< setfill('0') << setw(2) << dia; // Relleno con 0 a la izquierda

    if(corto)
    {
        oss << " " << mes_corto << " " << setw(4)<<anio;
    }
    else
    {
        oss << " " << mes_string << " " << setw(4)<<anio;
    }

    return oss.str();

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

/***********************************************/
// Operador >>
// Argumentos:
//      objeto: objeto a inicilizar
// Inicializa los campos
istream &operator >> (istream & in, Fecha & objeto) 
{
    string linea;
    getline(in, linea);
    objeto = Fecha(linea);

    return in;
}

/**********************************************/
// Operatos <<
// Argumentos:
//      objeto: objeto a mostrar
// devuelve un flujo con el objeto
ostream &operator << (ostream &out, Fecha & objeto)
{
    out << setfill('0') << setw(2) << objeto.dia << "/"
        << setfill('0') << setw(2) << objeto.mes << "/"
        << setfill('0') << setw(4) << objeto.anio;

    return out;
}