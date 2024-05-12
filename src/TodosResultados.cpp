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
// Constructor predeterminado
// Descripción: Crea un objeto TodosResultados vacío.
TodosResultados::TodosResultados(void)
{
    ReservarMemoria(); // Reservamos memoria
}

/***********************************************/
/***********************************************/
// Constructor de copia
// Descripción: Crea un nuevo objeto TodosResultados a partir de otro.
// Argumentos:
//      otro: Objeto TodosResultados del cual se copian los datos.
TodosResultados::TodosResultados(const TodosResultados& otro)
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
TodosResultados::TodosResultados(int capacidad_inicial)
{
    ReservarMemoria(capacidad_inicial); // Reservamos memoria
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
int TodosResultados::Capacidad(void) const
{
    return capacidad; // Devolvemos la capacidad
}

/***********************************************/
/***********************************************/
// getUsados
// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
int TodosResultados:: Usados(void) const
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
// Elimina 
// Descripción: Elimina un objeto Resultados en una posición específica.
// Argumentos:
//      num_casilla: Índice de la casilla del objeto que se elimina.
void TodosResultados::Elimina(const int num_casilla)
{
    if (num_casilla >= 0 && num_casilla < usados) // Si la casilla es válida
    {
        for (int i = num_casilla; i < usados - 1; i++) // Recorremos los datos
        {
            datos[i] = datos[i + 1]; // Desplazamos los datos
        }
        usados--; // Disminuimos los usados
    }

}

/***********************************************/
/***********************************************/
// Inserta
// Descripción: Inserta un objeto Resultados en una posición específica.
// Argumentos:
//      objeto: Objeto Resultados que se inserta.
//      num_casilla: Índice de la casilla en la que se inserta.
void TodosResultados::Inserta(const Resultados& objeto, const int num_casilla)
{
    if (usados < capacidad) // Si hay espacio
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
// NumOrdenResultados
// Descripción: Devuelve la posición de un objeto Resultados en el objeto.
// Argumentos:
//          resultados: Objeto Resultados que se busca.
// Devuelve: La posición del objeto en el objeto, -1 si no se encuentra.     
int TodosResultados::NumOrdenTodosResultados (const Resultados resultados)const
{
    int posicion = -1; // Inicializamos la posición

    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i] == resultados) // Si son iguales
        {
            posicion = i; // Guardamos la posición
        }
    }

    return posicion; // Devolvemos la posición
}

/***********************************************/
/***********************************************/
// ToString()
// Descripción: Convierte el objeto en una cadena de caracteres.
// Argumentos:
//      titulo, cadena de caracteres que se añade al principio.
// Devuelve: Una cadena de caracteres que representa los datos del objeto.
string TodosResultados::ToString(const string titulo) const
{
    string cadena; // Cadena de caracteres

    cadena += titulo + "\n"; // Añadimos el título

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
    if(*this != otro) // Si no son el mismo objeto
    {
        LiberarMemoria(); // Liberamos la memoria
        ReservarMemoria(otro); // Reservamos memoria
        CopiarDatos(otro); // Copiamos los datosl
    }
    
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
Resultados TodosResultados::operator[](const int num_casilla) const
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

Resultados TodosResultados::operator()(const int num_casilla) const
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// Operador de acceso sobrecargado
// Descripción: Permite modificar y leer una posición especifica.
// Argumentos:
//      num_casilla1: Índice de la casilla del objeto deseado.
//      num_casilla2: Índice de la casilla del objeto deseado.
// Devuelve: Una referencia al objeto en la posición especificada.
// PRE: 1 <= num_casilla1 <= usados. 1<= num_casilla2 <= usados
Resultado & TodosResultados::operator()(const int num_casilla1, 
            const int num_casilla2)
{     
    return (*this)[num_casilla1][num_casilla2]; // Devolvemos el objeto
}

Resultado & TodosResultados::operator()(const int num_casilla1, 
            const int num_casilla2) const
{     
    return (*this)[num_casilla1][num_casilla2]; // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// Operador de comparación ==
// Descripción: Compara dos objetos TodosResultados.
// Argumentos:
//      otro: Objeto TodosResultados con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool TodosResultados:: operator==(const TodosResultados& otro) const
{
    return EsIgualA(otro); // Devolvemos si son iguales
}

/***********************************************/
/***********************************************/
// Operador de comparación !=
// Descripción: Compara dos objetos TodosResultados.
// Argumentos:
//      otro: Objeto TodosResultados con el que se compara.
// Devuelve: true si son distintos, false en caso contrario.
bool TodosResultados::operator!=(const TodosResultados& otro) const
{
    return !EsIgualA(otro); // Devolvemos si son distintos
}

/***********************************************/
/***********************************************/
// Operador de comparación <
// Descripción: Compara dos objetos TodosResultados.
// Argumentos:
//      otro: Objeto TodosResultados con el que se compara.
// Devuelve: true si el objeto actual es menor que el otro.
bool TodosResultados::operator<(const TodosResultados& otro) const
{
    return (Usados() < otro.Usados()); // Devolvemos si es menor
}

/***********************************************/
/***********************************************/
// Operador de comparación >
// Descripción: Compara dos objetos TodosResultados.
// Argumentos:
//      otro: Objeto TodosResultados con el que se compara.
// Devuelve: true si el objeto actual es mayor que el otro.
bool TodosResultados::operator>(const TodosResultados& otro) const
{
    return (Usados() > otro.Usados()); // Devolvemos si es mayor
}

/***********************************************/
/***********************************************/
// Operador de comparación <=
// Descripción: Compara dos objetos TodosResultados.
// Argumentos:
//      otro: Objeto TodosResultados con el que se compara.
// Devuelve: true si el objeto actual es menor o igual que el otro.
bool TodosResultados::operator<=(const TodosResultados& otro) const
{
    return (Usados() <= otro.Usados()); // Devolvemos si es menor o igual
}

/***********************************************/
/***********************************************/
// Operador binario *
// Descripción: Realiza la intersección de dos objetos TodosResultados.
// Argumentos:
//      uno: primer objeto TodosResultados.
//      otro: segundo objeto TodosResultados.
// Devuelve: Un objeto TodosResultados con los elementos comunes.
TodosResultados operator*(const TodosResultados uno, 
                const TodosResultados& otro)
{
    TodosResultados resultado(uno.Capacidad()+otro.Capacidad()); 

    for (int i = 1; i <= uno.usados; i++) // Recorremos los datos
    {
        if (otro.NumOrdenTodosResultados(uno[i]) != -1) 
        {
            resultado.Aniade(uno[i]); // Añadimos el objeto
        }
    }

    return resultado; // Devolvemos el resultado
}

/***********************************************/
/***********************************************/
// Operador binario && (version 1)
// Descripción: Devuelve true si el primer objeto TodosResultados 
//				contiene al segundo. 
// Argumentos:
//        uno: primer objeto TodosResultados.
//		  otro: segundo objeto TodosResultados.
// Devuelve: true si el primer objeto contiene al segundo.
bool operator&&( const TodosResultados& uno , const TodosResultados otro)
{
    bool contiene = true; // incializamos la variable
    
    int i= 1;

    while(contiene && i<=otro.usados){

        if (uno.NumOrdenTodosResultados(otro[i])==-1)
        {
            contiene = false;
        }
        
        i++;
    }
    
    return contiene; // devolvemos
}

/***********************************************/
/***********************************************/
// Operador binario && (version 2)
// Descripción: Devuelve true si el primer objeto TodosResultados
//				contiene un Resultados 
// Argumentos:
//		  uno: Primer objeto TodosResultados.
//        otro: Resultados a buscar.
// Devuelve: true si el primer objeto contiene al Resultados.
bool operator&&(const TodosResultados& uno , const Resultados& otro)
{
    TodosResultados Resultados_nuevo; // creo un objeto TodosResultados

    Resultados_nuevo.Aniade(otro); // Aniado el unico Resultados

    return (uno && Resultados_nuevo); // devuelvo la comparacion de colecciones
}

/***********************************************/
/***********************************************/
// Operador binario && (version 3)
// Descripción: Devuelve true si el primer objeto Resultados 
//              esta contenido en en TodosResultados
// Argumentos:
//        Resultados: Resultados a buscar.
//        uno: Primer objeto TodosResultados.
// Devuelve: true si el Resultados esta en el primer objeto.
bool operator&&(const Resultados& Resultados, const TodosResultados& uno)
{
    return (uno&&Resultados); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario && (version 4)
// Descripción: Devuelve true si el primer objeto TodosResultados
//            Contiene un Resultados con el Resultado dado.
// Argumentos:
//		  uno: Primer objeto TodosResultados.
//        otro: Resultado dado.
// Devuelve: true si el primer objeto contiene al Resultados.
bool operator&&(const TodosResultados& uno, const Resultado otro)
{
    Resultados Resultados_nuevo; // creo un objeto Resultados

    Resultados_nuevo+=otro; // Aniado el unico Resultados

    return (uno&&otro); // devuelvo la comparación con Resultados
}

/***********************************************/
/***********************************************/
// Operador binario && (version 5)
// Descripción: Devuelve true si el primer parametro dorsal
//            esta contenido en en TodosResultados
// Argumentos:
//        otro: Resultado dado.
//        uno: Primer objeto TodosResultados.
// Devuelve: true si el Resultados esta en el primer objeto.
bool operator&&(const  Resultado otro, const TodosResultados& uno)
{
    return (uno&&otro); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario + (version 1) [TodosResultados] + [TodosResultados]
// Descripción: Concatena dos datos TodosResultados en uno nuevo. 
//		Los valores delsegundo (operando de la derecha) se añaden 
//		(en el mismo orden) en una copia del primero.
// Argumentos:
//        uno: primer objeto TodosResultados.
//		  otro: segundo objeto TodosResultados.
// Devuelve: Un objeto TodosResultados con los elementos concatenados.
TodosResultados operator+(const TodosResultados uno, 
                const TodosResultados& otro)
{
    TodosResultados resultado = uno; // Copiamos el primer objeto

    for (int i = 0; i < otro.usados; i++) // Recorremos los datos
    {
        if (!(otro.datos[i]&&uno)) // si no está contenido
        {
             resultado.Aniade(otro.datos[i]); // Añadimos el objeto
        }   
    }

    return resultado; // Devolvemos el resultado

}

/***********************************************/
/***********************************************/
// Operador binario + (version 2) [TodosResultados] + [Resultados]
// Descripción: Añade un Resultados al final de una copia del 
//				objeto TodosResultados.
// Argumentos:
//        uno: primer objeto TodosResultados.
//		  otro: Resultados a añadir.
// Devuelve: Un objeto TodosResultados con el Resultados añadido.
TodosResultados operator+(const TodosResultados uno, const Resultados& otro)
{
    TodosResultados resultados; // Creamos un objeto vacío

    resultados.Aniade(otro); // Añadimos el Resultados

    return uno + resultados; // Concatenamos los objetos

}

/***********************************************/
/***********************************************/
// Operador binario + (version 3) [Resultados] + [TodosResultados]
// Descripción: Añade un Resultados al principio de una copia del
//				objeto TodosResultados.
// Argumentos:
//        uno: Resultados a añadir.
//		  otro: primer objeto TodosResultados.
// Devuelve: Un objeto TodosResultados con el Resultados añadido.
TodosResultados operator+(const Resultados& uno, const TodosResultados otro)
{
    TodosResultados resultados; // Creamos un objeto vacío

    resultados.Aniade(uno); // Añadimos el Resultados

    return resultados + otro; // Concatenamos los objetos
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 1) [TodosResultados] += [TodosResultados]
// Descripción: Añade los elementos de un objeto TodosResultados al final.
// Argumentos:
//        uno: primer objeto TodosResultados.
// Devuelve: Un objeto TodosResultados con los elementos añadidos.
TodosResultados& TodosResultados::operator+=(const TodosResultados& otro)
{
    *this = *this + otro; // Concatenamos los objetos

    return *this; // Devolvemos el objeto actual
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 2) [TodosResultados] += [Resultados]
// Descripción: Añade un Resultados al final del objeto TodosResultados.
// Argumentos:
//        uno: primer objeto TodosResultados.
// Devuelve: Un objeto TodosResultados con el Resultados añadido.
TodosResultados& TodosResultados::operator+=(const Resultados& otro)
{
    *this = *this + otro; // Concatenamos los objetos

    return *this; // Devolvemos el objeto actual

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
    capacidad = otro.capacidad; // Copiamos la capacidad
    datos = new Resultados[capacidad]; // Reservamos memoria
    usados = otro.usados; // Copiamos los usados
   
}

/************************************************************/
/************************************************************/
// Pide memoria dado la capacidad
// Parámetros: capacidad, capacidad deseada.
void TodosResultados::ReservarMemoria (int capacidad_inicial)
{
    if (capacidad_inicial <= 0) // Si la capacidad es menor o igual a 0
    {
        capacidad = TAM_BLOQUE; // Inicializamos la capacidad
    }
    else // Si la capacidad es mayor que 0
    {
        capacidad = capacidad_inicial; // Inicializamos la capacidad
    }
    datos = new Resultados[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usados
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


/***********************************************/
/***********************************************/
// Valor Casilla
// Descripción: Devuelve el valor de una casilla específica.
// Argumentos:
//      num_casilla: Índice de la casilla deseada.
// Devuelve: Una referencia al objeto en la posición especificada.
// PRE: 0 <= num_casilla < usados
Resultados& TodosResultados::ValorCasilla(const int num_casilla) const
{
    return datos[num_casilla]; // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// EsIgualA
// Descripción: Compara dos objetos TodosResultados.
// Argumentos:
//      otro: Objeto TodosResultados con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool TodosResultados:: EsIgualA(const TodosResultados& otro) const
{
    int tamanio_union = (*this + otro).Usados(); // Unimos 
    int tamanio_interseccion = (*this * otro).Usados(); // Intersectamos 

    return (tamanio_union==tamanio_interseccion); // Devolvemos si son iguales
}

/***********************************************/
/***********************************************/
// Aniade
// Descripción: Añade un objeto Resultados al final del objeto.
// Argumentos:
//      objeto: Objeto Resultados que se añade al final.
void TodosResultados::Aniade(const Resultados& objeto)
{
    if (usados < capacidad) // Si hay espacio
    {
        datos[usados] = objeto; // Añadimos el objeto
        usados++; // Aumentamos los usados
    }   
}
