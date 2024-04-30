/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Corredor.cpp
//
// Definiciones de la clase Corredor del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Corredor.h"
#include "utils.h"
#include "Fecha.h"

/******************CONSTRUCTORES**********************/

/***********************************************/
/***********************************************/
// Inicializa Corredor
// Argumentos: 
//      linea: cadena de donde saca la informacion de cada
//              campo.
//      delimitador: separadore entre los campos (por defecto
//              el definido en la clase ":").
// POST :
//      Se han inicializado Dorsal, DNI, Nombre
//      Appelidos, FechaNacimiento y Sexo
Corredor::Corredor(string linea, char delimitador) {

    // Declaro un string para campo
    string campo1, campo2, campo3, campo4, campo5, campo6;
    
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
    linea = linea.substr(pos5+1);

    size_t pos6 = linea.find(delimitador);
    campo6 = linea.substr(0,pos6);
    rem_se_ext(campo6);

    /*********************************************/
    // Inicializo los campos
    Dorsal = stoi(campo1);
    DNI = campo2;
    Nombre = campo3;
    Apellidos = campo4;
    FechaNacimiento = Fecha(campo5);
    Sexo = campo6[0];
    
    
}


/***********************************************/
/***********************************************/
// Inicializa Corredor
// Argumentos:
//	  no tiene argumentos
// POST : 
//	  Se han inicializado Corredor vacío.
Corredor::Corredor() : FechaNacimiento (Fecha())
{
    Dorsal = 0;
    DNI = "";
    Nombre = "";
    Apellidos = "";
    Sexo = ' ';

}




/******************GETTERS**********************/

/***********************************************/
/***********************************************/
// Leen el valor de cada uno de los campos.
//
// Devuelve:
//      lo que valen  Dorsal, DNI, Nombre
//      Appelidos, FechaNacimiento y Sexo
int Corredor::GetDorsal() const{
    return Dorsal;
}

string Corredor::GetDNI()const {
    return DNI;
}

Fecha Corredor::GetFechaNacimiento()const {
    return FechaNacimiento.ToString();
}

string Corredor::GetNombre()const {
    return Nombre;
}

string Corredor::GetApellidos()const {
    return Apellidos;
}

char Corredor::GetSexo()const{
    return Sexo;
}


/******************SETTERS**********************/

/***********************************************/
/***********************************************/
// Cambian el valor de cada uno de los campos.
//
// POST:
//      Cambian lo que valen DNI, Nombre
//      Appelidos, FechaNacimiento y Sexo
void Corredor::SetDorsal(int dorsal) {
    Dorsal = dorsal;
}

void Corredor::SetDNI(string dni) {
    DNI = dni;
}

void Corredor::SetFechaNacimiento(Fecha fecha_nacimiento) {
    FechaNacimiento = fecha_nacimiento;
}

void Corredor::SetNombre(string nombre) {
    Nombre = nombre;
}

void Corredor::SetApellidos(string apellidos) {
    Apellidos = apellidos;
}

void Corredor::SetSexo(char sexo) {
    Sexo = sexo;
}



/******************TOSTRING**********************/

/***********************************************/
/***********************************************/
// Imprime los campos de Corredor
// no recibe nada pero usa los métodos de formateo de utils
//
// Devuelve:
//      Corredor en formato string
string Corredor::ToString() const{
    
    // Creo el campo nom_comp y diferencio el sexo
    string nom_comp = Apellidos + ", " + Nombre;
    string sex_comp;
    if (Sexo == 'H')
    {
        sex_comp = "HOMBRE";
    }else
        {
            sex_comp = "MUJER";
        }

    // Formateo los campos
    string campo_1 = FormatInt(Dorsal, 4) + " ";
    string campo_2_3 = FormatString(nom_comp,35) + " ";
    string campo_4 = DNI + " ";
    string campo_5 = FechaNacimiento.ToString(true) + " ";
    string campo_6 = FormatString(sex_comp,7);

    // Devuelvo la concatenacion
    return campo_1 + campo_2_3 + campo_4 + campo_5 + campo_6;
}