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
    
    // Usamos flujos para separar los campos
    istringstream iss(linea);

    getline(iss, campo1, delimitador);
    getline(iss, campo2, delimitador);
    getline(iss, campo3, delimitador);
    getline(iss, campo4, delimitador);
    getline(iss, campo5, delimitador);
    getline(iss, campo6, delimitador);
    

    /*********************************************/
    // Inicializo los campos numericos con stoi
    Dorsal = stoi(campo1);

    // Inicializo los campos de tipo Fecha
    FechaNacimiento = Fecha(campo5);

    // Inicializo los campos de tipo string
    string sexoespacios;
    istringstream iss2(campo6);
    while (iss2 >> campo6) {
        sexoespacios+= campo6 + " ";
    }
    sexoespacios.pop_back(); // quito el último espacio
    Sexo = sexoespacios[0];
    
    istringstream iss3(campo2);
    while (iss3 >> campo2) {
        DNI += campo2 + " ";
    }
    DNI.pop_back(); // quito el último espacio
 

    istringstream iss4(campo3);
    while (iss4 >> campo3) {
        Nombre += campo3 + " ";
    }
    Nombre.pop_back(); // quito el último espacio
    
    istringstream iss5(campo4);
    while (iss5 >> campo4) {
        Apellidos += campo4 + " ";
    }
    Apellidos.pop_back(); // quito el último espacio

       
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
// Argumentos:
//      nombre: nombre del corredor
// Devuelve:
//      Carrera en formato string
string Corredor::ToString (const string nombre) const
{
    ostringstream oss;

    oss<<setw(4) << Dorsal << " ";
    oss<<setw(30)<< left<<(Apellidos + ", " + Nombre) << " ";
    oss<<setw(12)<< left<<DNI << " ";
    oss<<setw(12)<<FechaNacimiento.ToString(true) << " ";

    if (Sexo == 'H')
        oss<<setw(6)<< left<<"HOMBRE";
    else
        oss<<setw(6)<< left<<"MUJER";

    return oss.str();
}

/***********************************************/
// Operador >>
// Argumentos:
//      objeto: objeto a inicilizar
// Inicializa los campos
istream & operator >> (istream & in, Corredor & objeto)
{
    string linea;
    getline(in, linea);
    objeto = Corredor(linea);
    return in;

}

/**********************************************/
// Operator <<
// Argumentos:
//      objeto: objeto a mostrar
// devuelve un flujo con el objeto
ostream & operator << (ostream &out, Corredor & objeto)
{
    out << objeto.Dorsal << objeto.DELIMITADOR;
    out << objeto.DNI << objeto.DELIMITADOR;
    out << objeto.Nombre << objeto.DELIMITADOR;
    out << objeto.Apellidos << objeto.DELIMITADOR;
    out << objeto.FechaNacimiento << objeto.DELIMITADOR;
    out << objeto.Sexo << objeto.DELIMITADOR;

    return out;
}	