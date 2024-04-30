/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Categoria.cpp
//
// Definiciones de la clase Categoria del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Categoria.h"
#include "utils.h"

/******************CONSTRUCTORES**********************/

/***********************************************/
/***********************************************/
// Inicializa Categoria
// Argumentos: 
//      linea: cadena de donde saca la informacion de cada
//              campo.
//      delimitador: separadore entre los campos (por defecto
//              el definido en la clase ":").
// POST :
//      Se han inicializado IdCategoria, Denomicacion, Sexo
//      FechaInicial, FechaFinal
Categoria::Categoria(string linea, char delimitador) {

    // Declaro un string para campo
    string campo1, campo2, campo3, campo4, campo5;
    
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
    linea = linea.substr(pos3+1);

    size_t pos4 = linea.find(delimitador);
    campo4 = linea.substr(0,pos4);
    rem_se_ext(campo4);
    linea = linea.substr(pos4+1);

    size_t pos5 = linea.find(delimitador);
    campo5 = linea.substr(0,pos5);
    rem_se_ext(campo5);

   
    /*********************************************/
    // Inicializo los campos
    IdCategoria = stoi(campo1);
    Denominacion = campo2;
    Sexo = campo3[0];
    FechaInicial = Fecha(campo4);
    FechaFinal = Fecha(campo5);
    
}

/***********************************************/
/***********************************************/
// Inicializa Categoria
// Argumentos:
//	  no tiene argumentos
// POST : 
//	  Se han inicializado Categoria vacía.
Categoria::Categoria(): FechaInicial(Fecha()),
    FechaFinal(Fecha())
{
    IdCategoria = 0;
    Denominacion = "";
    Sexo = ' ';
}



/******************GETTERS**********************/

/***********************************************/
/***********************************************/
// Leen el valor de cada uno de los campos.
//
// Devuelve:
//      lo que valen  IdCategoria, Denomicacion, Sexo
//      FechaInicial, FechaFinal
int Categoria::GetIdCategoria()const {
    return IdCategoria;
}

string Categoria::GetDenominacion()const {
    return Denominacion;
}

char Categoria::GetSexo()const {
    return Sexo;
}

Fecha Categoria::GetFechaInicial()const {
    return FechaInicial;
}

Fecha Categoria::GetFechaFinal()const {
    return FechaFinal;
}



/******************SETTERS**********************/

/***********************************************/
/***********************************************/
// Cambian el valor de cada uno de los campos.
//
// POST:
//      Cambian lo que valen Denomicacion, Sexo
//      FechaInicial, FechaFinal
void Categoria::SetIdCategoria(int id_categoria) {
    IdCategoria = id_categoria;
}
void Categoria::SetDenominacion(string denominacion) {
    Denominacion = denominacion;
}

void Categoria::SetSexo(char sexo) {
    Sexo = sexo;
}

void Categoria::SetFechaInicial(Fecha fecha_inicial) {
    FechaInicial = fecha_inicial;
}

void Categoria::SetFechaFinal(Fecha fecha_final) {
    FechaFinal = fecha_final;
}



/******************TOSTRING**********************/

/***********************************************/
/***********************************************/
// Imprime los campos de Categoria
// no recibe nada pero usa los métodos de formateo de utils
//
// Devuelve:
//      Categoria en formato string
string Categoria::ToString()const{
  
    // Diferencio el sexo

    string sex_comp;

    if (Sexo == 'H')
    {
        sex_comp = "HOMBRE";
    }else
        {
            sex_comp = "MUJER";
        }

    // Formateo los campos
    string campo_1 = FormatInt(IdCategoria,2) + " ";
    string campo_2 = FormatString(Denominacion, 10) + " ";
    string campo_3 = FormatString(sex_comp, 7) + " ";
    string campo_4 = "De "+ FechaInicial.ToString(true) + " ";
    string campo_5 = "a "+ FechaFinal.ToString(true);

    // Devuelvo la concatenacion
    return campo_1 + campo_2 + campo_3 + campo_4 + campo_5;
}
