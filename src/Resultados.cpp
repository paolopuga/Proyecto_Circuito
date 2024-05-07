/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Resultados.cpp
//
// Definiciones de la clase Resultados del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Resultados.h"
#include "Resultado.h"

using namespace std;


/***********************************************/
/***********************************************/
// Constructor predeterminado
// Descripción: Crea un objeto Resultados vacío.
Resultados::Resultados(void)
{
    ReservarMemoria(); // Reservamos memoria
}

/***********************************************/
/***********************************************/
// Constructor de copia
// Descripción: Crea un nuevo objeto Resultados a partir de otro.
// Argumentos:
//      otro: Objeto Resultados del cual se copian los datos.
Resultados::Resultados(const Resultados& otro)
{
    ReservarMemoria(otro); // Reservamos memoria
    CopiarDatos(otro); // Copiamos los datos
}

/***********************************************/
/***********************************************/
// Constructor con capacidad inicial
// Descripción: Crea un objeto Resultados con una capacidad inicial.
// Argumentos:
//      capacidad_inicial: Capacidad inicial deseada.
Resultados::Resultados(int capacidad_inicial)
{
    ReservarMemoria(capacidad_inicial); // Reservamos memoria
}

/***********************************************/
/***********************************************/
// Destructor
// Descripción: Libera memoria y recursos utilizados por el objeto.
Resultados::~Resultados(void)
{
    LiberarMemoria(); // Liberamos la memoria
}

/***********************************************/
/***********************************************/
// getCapacidad
// Descripción: Devuelve la capacidad actual del objeto.
int Resultados::Capacidad(void) const 
{
    return capacidad; // Devolvemos la capacidad
}

/***********************************************/
/***********************************************/
// getUsados
// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
int Resultados:: Usados(void) const 
{
    return usados; // Devolvemos los usados
}

/***********************************************/
/***********************************************/
// EstaVacio
// Descripción: Comprueba si el objeto está vacío.
bool Resultados::EstaVacio(void)
{
    return usados == 0; // Devolvemos si está vacío

}


/***********************************************/
/***********************************************/
// EliminaTodos
// Descripción: Elimina todos los elementos, dejándolo vacío.
void Resultados::EliminaTodos(void)
{    
    usados = 0; // Ponemos los usados a 0
}

/***********************************************/
/***********************************************/
// Elimina 
// Descripción: Elimina un objeto Resultado en una posición específica.
// Argumentos:
//      num_casilla: Índice de la casilla del objeto que se elimina.
void Resultados::Elimina(const int num_casilla)
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
// Aniade
// Descripción: Añade un objeto Resultado al final del objeto.
// Argumentos:
//      objeto: Objeto Resultado que se añade al final.
void Resultados::Aniade(const Resultado& objeto)
{
    if (usados == capacidad) // Si no hay espacio
    {
        Redimensiona(); // Redimensionamos
    }
    datos[usados] = objeto; // Añadimos el objeto
    usados++; // Aumentamos los usados
}

/***********************************************/
/***********************************************/
// Inserta
// Descripción: Inserta un objeto Resultado en una posición específica.
// Argumentos:
//      objeto: Objeto Resultado que se inserta.
//      num_casilla: Índice de la casilla en la que se inserta.
void Resultados::Inserta(const Resultado& objeto, const int num_casilla)
{
    if (usados == capacidad) // Si no hay espacio
    {
        Redimensiona(); // Redimensionamos
    }
    for (int i = usados; i > num_casilla; i--) // Recorremos los datos
    {
        datos[i] = datos[i - 1]; // Desplazamos los datos
    }
    datos[num_casilla] = objeto; // Insertamos el objeto
    usados++; // Aumentamos los usados
}

/***********************************************/
/***********************************************/
// Devuelve la posición en una colección de un Resultado,
// dado su dorsal. Si no está registrado devuelve -1.
int Resultados::NumOrdenResultado (const int num_dorsal) const
{
    int posicion = -1; // Suponemos que no está
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i].GetDorsal() == num_dorsal) // Si encontramos el dorsal
        {
            posicion = i; // Si lo encontramos
        }
    }
    return posicion; // devolvemos la posición
}

/***********************************************/
/***********************************************/
// Devuelve la posición en una colección de un Resultado,
// dado su tiempo. Si no está registrado devuelve -1.
int Resultados::NumOrdenResultado (const Tiempo tiempo) const
{
    int posicion = -1; // Suponemos que no está
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i].GetTiempoCarrera() == tiempo) // Si encontramos el tiempo
        {
            posicion = i; // Si lo encontramos
        }
    }
    return posicion; // devolvemos la posición
}


/***********************************************/
/***********************************************/
// ToString()
// Descripción: Convierte el objeto en una cadena de caracteres.
// Argumentos:
//      titulo, cadena de caracteres que se añade al principio.
// Devuelve: Una cadena de caracteres que representa los datos del objeto.
string Resultados::ToString(const string titulo) const
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
//      otro: Objeto Resultados del cual se copian los datos.
// Devuelve: Una referencia al objeto actual después de la asignación.
Resultados & Resultados::operator=(const Resultados& otro)
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
Resultado & Resultados::operator[](const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}
Resultado Resultados::operator[](const int num_casilla) const
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
Resultado & Resultados::operator()(const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto   
}

Resultado Resultados::operator()(const int num_casilla) const
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// Operador de comparación ==
// Descripción: Compara dos objetos Resultados.
// Argumentos:
//      otro: Objeto Resultados con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Resultados:: operator==(const Resultados& otro) const
{
    return EsIgualA(otro); // Devolvemos si son iguales
}

/***********************************************/
/***********************************************/
// Operador de comparación !=
// Descripción: Compara dos objetos Resultados.
// Argumentos:
//      otro: Objeto Resultados con el que se compara.
// Devuelve: true si son distintos, false en caso contrario.
bool Resultados::operator!=(const Resultados& otro) const
{
    return !EsIgualA(otro); // Devolvemos si son distintos
}

/***********************************************/
/***********************************************/
// Operador de comparación <
// Descripción: Compara dos objetos Resultados.
// Argumentos:
//      otro: Objeto Resultados con el que se compara.
// Devuelve: true si el objeto actual es menor que el otro.
bool Resultados::operator<(const Resultados& otro) const
{
    return (Usados() < otro.Usados()); // Devolvemos si es menor
}

/***********************************************/
/***********************************************/
// Operador de comparación >
// Descripción: Compara dos objetos Resultados.
// Argumentos:
//      otro: Objeto Resultados con el que se compara.
// Devuelve: true si el objeto actual es mayor que el otro.
bool Resultados::operator>(const Resultados& otro) const
{
    return (Usados() > otro.Usados()); // Devolvemos si es mayor
}

/***********************************************/
/***********************************************/
// Operador de comparación <=
// Descripción: Compara dos objetos Resultados.
// Argumentos:
//      otro: Objeto Resultados con el que se compara.
// Devuelve: true si el objeto actual es menor o igual que el otro.
bool Resultados::operator<=(const Resultados& otro) const
{
    return (Usados() <= otro.Usados()); // Devolvemos si es menor o igual
}

/***********************************************/
/***********************************************/
// Operador binario *
// Descripción: Realiza la intersección de dos objetos Resultados.
// Argumentos:
//      uno: primer objeto Resultados.
//      otro: segundo objeto Resultados.
// Devuelve: Un objeto Resultados con los elementos comunes.
Resultados operator*(const Resultados uno, const Resultados& otro)
{
    Resultados resultado; // Objeto resultado

    for (int i = 0; i < uno.usados; i++) // Recorremos los datos
    {
        if (otro.NumOrdenResultado(uno.datos[i].GetDorsal()) != -1) 
        {
            resultado.Aniade(uno.datos[i]); // Añadimos el objeto
        }
    }

    return resultado; // Devolvemos el resultado
}

/***********************************************/
/***********************************************/
// Operador binario && (version 1)
// Descripción: Devuelve true si el primer objeto Resultados 
//				contiene al segundo. 
// Argumentos:
//        uno: primer objeto Resultados.
//		  otro: segundo objeto Resultados.
// Devuelve: true si el primer objeto contiene al segundo.
bool operator&&( const Resultados& uno , const Resultados otro)
{
    bool contiene = true; // incializamos la variable
    int i= 0;

    while(contiene && i<otro.usados){

        if (uno.NumOrdenResultado(otro.datos[i].GetDorsal())==-1)
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
// Descripción: Devuelve true si el primer objeto Resultados
//				contiene un Resultado 
// Argumentos:
//		  uno: Primer objeto Resultados.
//        otro: Resultado a buscar.
// Devuelve: true si el primer objeto contiene al Resultado.
bool operator&&(const Resultados& uno , const Resultado& otro)
{
    Resultados Resultado_nuevo; // creo un objeto Resultados

    Resultado_nuevo.Aniade(otro); // Aniado el unico Resultado

    return (uno && Resultado_nuevo); // devuelvo la comparacion de colecciones
}

/***********************************************/
/***********************************************/
// Operador binario && (version 3)
// Descripción: Devuelve true si el primer objeto Resultado 
//              esta contenido en en Resultados
// Argumentos:
//        Resultado: Resultado a buscar.
//        uno: Primer objeto Resultados.
// Devuelve: true si el Resultado esta en el primer objeto.
bool operator&&(const Resultado& Resultado, const Resultados& uno)
{
    return (uno&&Resultado); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario && (version 4)
// Descripción: Devuelve true si el primer objeto Resultados
//            Contiene un Resultado con el dorsal dado.
// Argumentos:
//		  uno: Primer objeto Resultados.
//        num_dorsal: Dorsal a buscar.
// Devuelve: true si el primer objeto contiene al Resultado.
bool operator&&(const Resultados& uno, const int num_dorsal)
{
    Resultado dorsal_nuevo; // Creo un nuevo objeto Resultado vació

    dorsal_nuevo.SetDorsal(num_dorsal); // le cambio el dorsal

    return (uno&&dorsal_nuevo); // devuelvo la comparación con Resultado
}

/***********************************************/
/***********************************************/
// Operador binario && (version 5)
// Descripción: Devuelve true si el primer parametro dorsal
//            esta contenido en en Resultados
// Argumentos:
//        num_dorsal: Dorsal a buscar.
//        uno: Primer objeto Resultados.
// Devuelve: true si el Resultado esta en el primer objeto.
bool operator&&(const int num_dorsal, const Resultados& uno)
{
    return (uno&&num_dorsal); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario + (version 1) [Resultados] + [Resultados]
// Descripción: Concatena dos datos Resultados en uno nuevo. 
//		Los valores delsegundo (operando de la derecha) se añaden 
//		(en el mismo orden) en una copia del primero.
// Argumentos:
//        uno: primer objeto Resultados.
//		  otro: segundo objeto Resultados.
// Devuelve: Un objeto Resultados con los elementos concatenados.
Resultados operator+(const Resultados uno, const Resultados& otro)
{
    Resultados resultado = uno; // Copiamos el primer objeto

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
// Operador binario + (version 2) [Resultados] + [Resultado]
// Descripción: Añade un Resultado al final de una copia del 
//				objeto Resultados.
// Argumentos:
//        uno: primer objeto Resultados.
//		  otro: Resultado a añadir.
// Devuelve: Un objeto Resultados con el Resultado añadido.
Resultados operator+(const Resultados uno, const Resultado& otro)
{
    Resultados resultado; // Objeto resultado

    resultado.Aniade(otro); // Añadimos el objeto

    return uno + resultado; // Concatenamos los objetos

}

/***********************************************/
/***********************************************/
// Operador binario + (version 3) [Resultado] + [Resultados]
// Descripción: Añade un Resultado al principio de una copia del
//				objeto Resultados.
// Argumentos:
//        uno: Resultado a añadir.
//		  otro: primer objeto Resultados.
// Devuelve: Un objeto Resultados con el Resultado añadido.
Resultados operator+(const Resultado& uno, const Resultados otro)
{
    return otro + uno; // Invertimos el orden
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 1) [Resultados] += [Resultados]
// Descripción: Añade los elementos de un objeto Resultados al final.
// Argumentos:
//        uno: primer objeto Resultados.
// Devuelve: Un objeto Resultados con los elementos añadidos.
Resultados& Resultados::operator+=(const Resultados& otro)
{
    *this = *this + otro; // Concatenamos los objetos

    return *this; // Devolvemos el objeto actual
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 2) [Resultados] += [Resultado]
// Descripción: Añade un Resultado al final del objeto Resultados.
// Argumentos:
//        uno: primer objeto Resultados.
// Devuelve: Un objeto Resultados con el Resultado añadido.
Resultados& Resultados::operator+=(const Resultado& otro)
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
void Resultados::ReservarMemoria (const Resultados& otro)
{
    capacidad = otro.capacidad; // Copiamos la capacidad
    datos = new Resultado[capacidad]; // Reservamos memoria
    usados = otro.usados; // Copiamos los usados   
}

/************************************************************/
/************************************************************/
// Pide memoria dado la capacidad
// Parámetros: capacidad, capacidad deseada. Por defecto, TAM_BLOQUE

void Resultados::ReservarMemoria (int capacidad_inicial)
{
    if (capacidad_inicial <= 0) // Si la capacidad es menor o igual a 0
    {
        capacidad = TAM_BLOQUE; // Inicializamos la capacidad
    }
    else // Si la capacidad es mayor que 0
    {
        capacidad = capacidad_inicial; // Inicializamos la capacidad
    }
    datos = new Resultado[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usadoss
}

/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos
void Resultados::CopiarDatos (const Resultados& otro)
{
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        datos[i] = otro.datos[i]; // Copiamos los datos
    }
}

/************************************************************/
/************************************************************/
// Libera memoria

void Resultados:: LiberarMemoria (void)
{
    
    if (datos) // Si hay datos
    {
        delete [] datos; // Liberamos la memoria
        datos = nullptr; // Ponemos el puntero a nulo
    }
       
}	

/***********************************************/
/***********************************************/
// Reajusta la capacidad del objeto para adaptarla al número de elementos.
void Resultados:: Reajusta(void)
{
    int nueva_capacidad = usados;
    Resultado *tmp = new Resultado[nueva_capacidad]; // Reservamos memoria tmp
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        tmp[i] = datos[i]; // Copiamos los datos
    }
    
    delete [] datos; // Liberamos la memoria antigua
   
    // Actualizamos los datos
    datos = tmp; // Cambiamos el puntero
    capacidad = usados; // Ajustamos la capacidad
}

/***********************************************/
/***********************************************/
// Redimensiona el objeto para aumentar su capacidad.
void Resultados::Redimensiona(void)
{
    Resultado *tmp = new Resultado[capacidad + TAM_BLOQUE]; // Reservamos mem
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        tmp[i] = datos[i]; // Copiamos los datos
    }
    
    delete [] datos; // Liberamos la memoria antigua
    
    // Actualizamos los datos
    datos = tmp; // Cambiamos el puntero
    capacidad += TAM_BLOQUE; // Aumentamos la capacidad

}

/***********************************************/
/***********************************************/
// Valor Casilla
// Descripción: Devuelve el valor de una casilla específica.
// Argumentos:
//      num_casilla: Índice de la casilla deseada.
// Devuelve: Una referencia al objeto en la posición especificada.
// PRE: 0 <= num_casilla < usados
Resultado& Resultados::ValorCasilla(const int num_casilla) const
{
    return datos[num_casilla]; // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// EsIgualA
// Descripción: Compara dos objetos Resultados.
// Argumentos:
//      otro: Objeto Resultados con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Resultados:: EsIgualA(const Resultados& otro) const
{
    int tamanio_union = (*this + otro).Usados(); // Unimos 
    int tamanio_interseccion = (*this * otro).Usados(); // Intersectamos 

    return (tamanio_union==tamanio_interseccion); // Devolvemos si son iguales
}