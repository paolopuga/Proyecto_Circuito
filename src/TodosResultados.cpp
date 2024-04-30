/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: TodosResultados.cpp
//
// Definiciones de la clase TodosResultados del proyecto
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/
#include <iostream>
#include <string>

#include "TodosResultados.h"
#include "Resultados.h"

using namespace std;


/***********************************************/
/***********************************************/
// Constructor de copia
// Descripción: Crea un nuevo objeto TodosResultados a partir de otro.
// Argumentos:
//      otro: Objeto TodosResultados del cual se copian los datos.
TodosResultados::TodosResultados(const TodosResultados& otro) :
capacidad(otro.capacidad)
{
    ReservarMemoria(otro); // Reservamos memoria
    CopiarDatos(otro); // Copiamos los datos
}

/***********************************************/
/***********************************************/
// Constructor con capacidad inicial
// Descripción: Crea un objeto TodosResultados con una capacidad inicial.
// Argumentos:
//      capacidad_inicial: Capacidad inicial deseada.
TodosResultados::TodosResultados(const int capacidad_inicial) :
capacidad(capacidad_inicial) // Inicializamos la capacidad
{   
    datos = new Resultados[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usados
}

/***********************************************/
/***********************************************/
// Destructor
// Descripción: Libera memoria y recursos utilizados por el objeto.
TodosResultados::~TodosResultados(void)
{
    LiberarMemoria(); // Liberamos la memoria
}

/***********************************************/
/***********************************************/
// getCapacidad
// Descripción: Devuelve la capacidad actual del objeto.
int TodosResultados::Capacidad(void)
{
    return capacidad; // Devolvemos la capacidad
}

/***********************************************/
/***********************************************/
// getUsados
// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
int TodosResultados:: Usados(void)
{
    return usados; // Devolvemos los usados
}

/***********************************************/
/***********************************************/
// EstaVacio
// Descripción: Comprueba si el objeto está vacío.
bool TodosResultados::EstaVacio(void)
{
    return usados == 0; // Devolvemos si está vacío

}



/***********************************************/
/***********************************************/
// EliminaTodos
// Descripción: Elimina todos los elementos, dejándolo vacío.
void TodosResultados::EliminaTodos(void)
{    
    usados = 0; // Ponemos los usados a 0
}

/***********************************************/
/***********************************************/
// Aniade
// Descripción: Añade un objeto Resultados al final del objeto.
// Argumentos:
//      objeto: Objeto Resultados que se añade al final.
void TodosResultados::Aniade(const Resultados objeto)
{
    if (usados <=capacidad) // Si no hay espacio
    {
        datos[usados] = objeto; // Añadimos el objeto
        usados++; // Aumentamos los usados
    }
    
}

/***********************************************/
/***********************************************/
// Inserta
// Descripción: Inserta un objeto Resultados en una posición específica.
// Argumentos:
//      objeto: Objeto Resultados que se inserta.
//      num_casilla: Índice de la casilla en la que se inserta.
void TodosResultados::Inserta(const Resultados objeto, const int num_casilla)
{
    if (usados <= capacidad) // Si no hay espacio
    {
        for (int i = usados; i > num_casilla; i--) // Recorremos los datos
        {
            datos[i] = datos[i - 1]; // Desplazamos los datos
        }
        datos[num_casilla] = objeto; // Insertamos el objeto
        usados++; // Aumentamos los usados  
    }
    
}

/***********************************************/
/***********************************************/
// ToString()
// Descripción: Convierte el objeto en una cadena de caracteres.
// Devuelve: Una cadena de caracteres que representa los datos del objeto.
string TodosResultados::ToString()
{
    string cadena; // Cadena de caracteres

    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        cadena += datos[i].ToString(); // Añadimos los datos
        cadena += "\n"; // Añadimos un salto de línea
    }

    return cadena; // Devolvemos la cadena
}

/***********************************************/
/***********************************************/
// Operador de asignación
// Descripción: Asigna los datos de otro objeto a este objeto.
// Argumentos:
//      otro: Objeto TodosResultados del cual se copian los datos.
// Devuelve: Una referencia al objeto actual después de la asignación.
TodosResultados & TodosResultados::operator=(const TodosResultados& otro)
{
    
        LiberarMemoria(); // Liberamos la memoria
        ReservarMemoria(otro); // Reservamos memoria
        CopiarDatos(otro); // Copiamos los datos
    
    return *this; // Devolvemos el objeto actual
    
}

/***********************************************/
/***********************************************/
// Operador de acceso
// Descripción: Permite modificar y leer una posición especifica.
// Argumentos:
//      num_casilla: Índice de la casilla del objeto deseado.
// Devuelve: Una referencia al objeto en la posición especificada.
// PRE: 1 <= num_casilla <= usados
Resultados & TodosResultados::operator[](const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto  
}

/***********************************************/
/***********************************************/
// Operador de acceso
// Descripción: Permite modificar y leer una posición especifica.
// Argumentos:
//      num_casilla: Índice de la casilla del objeto deseado.
// Devuelve: Una referencia al objeto en la posición especificada.
// PRE: 1 <= num_casilla <= usados
Resultados & TodosResultados::operator()(const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto  
}

/***********************************************/
/***********************************************/
// Operador de acceso sobrecargado
// Descripción: Permite modificar y leer una posición especifica.
// Argumentos:
//      num_casilla1: Índice de la casilla de Resultados deseado.
//      num_casilla2: Índice de la casilla del Resultado deseado.
// Devuelve: Una referencia al Resultado en la posición especificada.
// PRE: 1 <= num_casilla1 <= usados y 1 <= num_casilla2 <= usados
Resultado & TodosResultados:: operator()(const int num_casilla1, 
    const int num_casilla2)
{
    return ValorCasilla(num_casilla1-1)(num_casilla2); // Devolvemos el objeto
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
// Metodos Privados

/************************************************************/
/************************************************************/
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), objeto que sirve de modelo.
void TodosResultados::ReservarMemoria (const TodosResultados& otro) 
{
   
    datos = new Resultados[capacidad]; // Reservamos memoria
    usados = otro.usados; // Copiamos los usados
   
}

/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos
void TodosResultados::CopiarDatos (const TodosResultados& otro)
{
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        datos[i] = otro.datos[i]; // Copiamos los datos
    }
}

/************************************************************/
/************************************************************/
// Libera memoria

void TodosResultados:: LiberarMemoria (void)
{
    
    if (datos) // Si hay datos
    {
        delete [] datos; // Liberamos la memoria
        datos = nullptr; // Ponemos el puntero a nulo
    }
       
}

/************************************************************/
/************************************************************/
// ValorCasilla
// Descripción: Devuelve el valor de una casilla específica.
// Argumentos:
//      num_casilla: Índice de la casilla deseada.
// Devuelve: El objeto Resultados en la posición especificada.
// PRE: 0 <= num_casilla < usados
Resultados& TodosResultados::ValorCasilla(const int num_casilla) const
{
    return datos[num_casilla]; // Devolvemos el objeto
}
