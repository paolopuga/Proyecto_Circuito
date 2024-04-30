/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Tiempo.h
//
// Declaraciones de la clase Tiempo del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/
#ifndef TIEMPO
#define TIEMPO



#include <string>
#include <iostream>

using namespace std;

class Tiempo {
private:
    
    // Datos principales, campos de la clase
    int horas;
    int minutos;
    int segundos;
  
    static const char DELIMITADOR = ':'; // separador de la cadena

public:

    /******************CONSTRUCTORES**********************/
    
    /***********************************************/
    /***********************************************/
    // Sin paramteros incializa el tiempo con la hora actual
    Tiempo();

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
    Tiempo(string linea, char delimitador=DELIMITADOR);

    
    /******************GETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Leen el valor de cada uno de los campos.
    //
    // Devuelve:
    //      lo que valen las horas, minutos y segundos
    int GetHoras()const;
    int GetMinutos()const;
    int GetSegundos()const;



    /******************SETTERS**********************/

    /***********************************************/
    /***********************************************/
    // Cambian el valor de cada uno de los campos.
    //
    // POST:
    //      Cambian lo que valen las horas, minutos y segundos
    void SetHoras(int h);
    void SetMinutos(int m);
    void SetSegundos(int s);


    /******************TOSTRING**********************/

    /***********************************************/
    /***********************************************/
    // Imprime la hora 00:00:00
    // no recibe nada pero usa entrada.
    // Devuelve:
    //      Concatenacion de los tres campos
    string ToString()const;


    /******************OPERADORES**********************/
    
    /***********************************************/
    /***********************************************/
    // Operador de comparacion
    // Argumentos:
    //      t: tiempo con el que se compara
    // Devuelve:
    //      true si el tiempo es igual, false en caso contrario
    bool operator==(const Tiempo &t)const;

    /***********************************************/
    /***********************************************/
    // Operador de comparacion >
    // Argumentos:
    //      t: tiempo con el que se compara
    // Devuelve:
    //      true si el tiempo es mayor, false en caso contrario
    bool operator>(const Tiempo &t)const;
};

#endif