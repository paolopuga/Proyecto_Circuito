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
#include <sstream>
#include <string>

#include "Categoria.h"

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
    
    // Usamos flujos para separar los campos
    istringstream iss(linea);

    getline(iss, campo1, delimitador);
    getline(iss, campo2, delimitador);
    getline(iss, campo3, delimitador);
    getline(iss, campo4, delimitador);
    getline(iss, campo5, delimitador);
   
    /*********************************************/
    // Inicializo los campos numericos con stoi
    IdCategoria = stoi(campo1);

    // Inicializo los campos de tipo Fecha
    FechaInicial = Fecha(campo4);
    FechaFinal = Fecha(campo5);
    
    // Inicializo los campos de tipo string    
    istringstream iss2(campo2);
    while (iss2 >> campo2) {
        Denominacion += campo2 + " ";
    }
    Denominacion.pop_back(); // quito el último espacio

    string sexoespacios;

    istringstream iss3(campo3);
    while (iss3 >> campo3) {
        sexoespacios+= campo3 + " ";
    }
    sexoespacios.pop_back(); // quito el último espacio

    Sexo = sexoespacios[0];

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
// Argumentos:
//      nombre: nombre de la Categoria
// Devuelve:
//      Carrera en formato string
string Categoria::ToString (const string nombre) const
{
    // inicialio el flujo de salida
	ostringstream oss;

	// Establezco las flags
	oss.setf(ios::fixed);
	oss.setf(ios::showpoint);
	oss.precision(3);
	
	// Imprimo los campos
	oss << setw(2) << IdCategoria << " ";
    oss << setw(10) << right << Denominacion << " ";
    
    if (Sexo == 'H') {
        oss << setw(7) << left << "HOMBRE" << " ";
    } else {
        oss << setw(7) << left << "MUJER" << " ";
    }

    oss << "[" << FechaInicial.GetAnio() << " - " << FechaFinal.GetAnio() << "]" ;

	return oss.str(); // Devuelvo el flujo formato string
}

/***********************************************/
// Operador >>
// Argumentos:
//      objeto: objeto a inicilizar
// Inicializa los campos
istream & operator >> (istream & in, Categoria& objeto)
{
    string linea;
    getline(in, linea);
    objeto = Categoria(linea);
    return in;
}

/**********************************************/
// Operator <<
// Argumentos:
//      objeto: objeto a mostrar
// devuelve un flujo con el objeto
ostream & operator << (ostream &out, Categoria & objeto)
{
    out << objeto.IdCategoria << objeto.DELIMITADOR;
    out << objeto.Denominacion << objeto.DELIMITADOR;
    out << objeto.Sexo << objeto.DELIMITADOR;
    out << objeto.FechaInicial << objeto.DELIMITADOR;
    out << objeto.FechaFinal << objeto.DELIMITADOR;

    return out;
}