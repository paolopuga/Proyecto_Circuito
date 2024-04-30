/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Fecha.h
//
// Declaraciones de la clase Fecha del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#ifndef FECHA
#define FECHA


#include <iostream>
#include <string>



using namespace std;

class Fecha {
private:
    
    // Datos principales, campos de la clase
    int dia;
    int mes;
    int anio;

    static const char DELIMITADOR = '/'; // separador de la cadena

public:
    
    /******************CONSTRUCTORES**********************/
    
    /***********************************************/
    /***********************************************/
    // Sin paramteros incializa Fecha con la fecha actual
    Fecha();

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
    Fecha(string linea, char delimitador=DELIMITADOR);



    /******************GETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Leen el valor de cada uno de los campos.
    //
    // Devuelve:
    //      lo que valen  dia, mes y anio
    int GetDia() const;
    int GetMes()const;
    int GetAnio()const ;

    

    /******************SETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Cambian el valor de cada uno de los campos.
    //
    // POST:
    //      Cambian lo que valen dia, mes y anios
    void SetDia(int d);
    void SetMes(int m);
    void SetAnio(int a);

    /******************TOSTRING**********************/

    /***********************************************/
    /***********************************************/
    // Imprime la fecha
    // no recibe nada pero usa ":".
    //
    // Devuelve:
    //      La fecha en formato string
    string ToString(bool corto=false)const;

    /******************OPERADORES**********************/

    /***********************************************/
    /***********************************************/
    // Compara dos fechas
    // Argumentos:
    //      f: fecha con la que se compara
    // Devuelve:
    //      true si la fecha es igual, false en caso contrario
    bool operator==(const Fecha &f)const;

    /***********************************************/
    /***********************************************/
    // Compara dos fechas
    // Argumentos:
    //      f: fecha con la que se compara
    // Devuelve:
    //      true si la fecha es mayor, false en caso contrario
    bool operator>(const Fecha &f)const;
};



#endif
