/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Corredores.cpp
//
// Definiciones de la clase Corredores del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Corredores.h"
#include "Corredor.h"

using namespace std;


/***********************************************/
/***********************************************/
// Constructor predeterminado
// Descripción: Crea un objeto Corredores vacío.
Corredores::Corredores(void)
{
    capacidad = TAM_BLOQUE; // Inicializamos la capacidad
    datos = new Corredor[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usados
}

/***********************************************/
/***********************************************/
// Constructor de copia
// Descripción: Crea un nuevo objeto Corredores a partir de otro.
// Argumentos:
//      otro: Objeto Corredores del cual se copian los datos.
Corredores::Corredores(const Corredores& otro)
{
    ReservarMemoria(otro); // Reservamos memoria
    CopiarDatos(otro); // Copiamos los datos
}

/***********************************************/
/***********************************************/
// Constructor con capacidad inicial
// Descripción: Crea un objeto Corredores con una capacidad inicial.
// Argumentos:
//      capacidad_inicial: Capacidad inicial deseada.
Corredores::Corredores(int capacidad_inicial)
{
    if (capacidad_inicial <= 0) // Si la capacidad es menor o igual a 0
    {
        capacidad = TAM_BLOQUE; // Inicializamos la capacidad
    }
    else // Si la capacidad es mayor que 0
    {
        capacidad = capacidad_inicial; // Inicializamos la capacidad
    }
    datos = new Corredor[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usados
}

/***********************************************/
/***********************************************/
// Destructor
// Descripción: Libera memoria y recursos utilizados por el objeto.
Corredores::~Corredores(void)
{
    LiberarMemoria(); // Liberamos la memoria
}

/***********************************************/
/***********************************************/
// getCapacidad
// Descripción: Devuelve la capacidad actual del objeto.
int Corredores::Capacidad(void)
{
    return capacidad; // Devolvemos la capacidad
}

/***********************************************/
/***********************************************/
// getUsados
// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
int Corredores:: Usados(void)
{
    return usados; // Devolvemos los usados
}

/***********************************************/
/***********************************************/
// EstaVacio
// Descripción: Comprueba si el objeto está vacío.
bool Corredores::EstaVacio(void)
{
    return usados == 0; // Devolvemos si está vacío

}


/***********************************************/
/***********************************************/
// EliminaTodos
// Descripción: Elimina todos los elementos, dejándolo vacío.
void Corredores::EliminaTodos(void)
{    
    usados = 0; // Ponemos los usados a 0
}

/***********************************************/
/***********************************************/
// Elimina 
// Descripción: Elimina un objeto Corredor en una posición específica.
// Argumentos:
//      num_casilla: Índice de la casilla del objeto que se elimina.
void Corredores::Elimina(const int num_casilla)
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
// Descripción: Añade un objeto Corredor al final del objeto.
// Argumentos:
//      objeto: Objeto Corredor que se añade al final.
void Corredores::Aniade(const Corredor& objeto)
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
// Descripción: Inserta un objeto Corredor en una posición específica.
// Argumentos:
//      objeto: Objeto Corredor que se inserta.
//      num_casilla: Índice de la casilla en la que se inserta.
void Corredores::Inserta(const Corredor& objeto, const int num_casilla)
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
// Devuelve la posición en una colección de un corredor,
// dado su dorsal. Si no está registrado devuelve -1.
int Corredores::NumOrdenCorredor (const int num_dorsal) const
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
// Devuelve la posición en una colección de un corredor,
// dado su DNI. Si no está registrado devuelve -1.
int Corredores::NumOrdenCorredor (const string el_DNI_buscado) const
{
    int posicion = -1; // Suponemos que no está
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i].GetDNI() == el_DNI_buscado) // Si encontramos el DNI
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
string Corredores::ToString(const string titulo) const
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
//      otro: Objeto Corredores del cual se copian los datos.
// Devuelve: Una referencia al objeto actual después de la asignación.
Corredores & Corredores::operator=(const Corredores& otro)
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
Corredor & Corredores::operator[](const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}
Corredor Corredores::operator[](const int num_casilla) const
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
Corredor & Corredores::operator()(const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto   
}

Corredor Corredores::operator()(const int num_casilla) const
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// Operador de comparación ==
// Descripción: Compara dos objetos Corredores.
// Argumentos:
//      otro: Objeto Corredores con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Corredores:: operator==(const Corredores& otro) const
{
    return EsIgualA(otro); // Devolvemos si son iguales
}

/***********************************************/
/***********************************************/
// Operador de comparación !=
// Descripción: Compara dos objetos Corredores.
// Argumentos:
//      otro: Objeto Corredores con el que se compara.
// Devuelve: true si son distintos, false en caso contrario.
bool Corredores::operator!=(const Corredores& otro) const
{
    return !EsIgualA(otro); // Devolvemos si son distintos
}


/***********************************************/
/***********************************************/
// Operador binario *
// Descripción: Realiza la intersección de dos objetos Corredores.
// Argumentos:
//      uno: primer objeto Corredores.
//      otro: segundo objeto Corredores.
// Devuelve: Un objeto Corredores con los elementos comunes.
Corredores operator*(const Corredores uno, const Corredores& otro)
{
    Corredores resultado; // Objeto resultado

    for (int i = 0; i < uno.usados; i++) // Recorremos los datos
    {
        if (otro.NumOrdenCorredor(uno.datos[i].GetDorsal()) != -1) 
        {
            resultado.Aniade(uno.datos[i]); // Añadimos el objeto
        }
    }

    return resultado; // Devolvemos el resultado
}

/***********************************************/
/***********************************************/
// Operador binario && (version 1)
// Descripción: Devuelve true si el primer objeto Corredores 
//				contiene al segundo. 
// Argumentos:
//        uno: primer objeto Corredores.
//		  otro: segundo objeto Corredores.
// Devuelve: true si el primer objeto contiene al segundo.
bool operator&&( const Corredores& uno , const Corredores otro)
{
    bool contiene = true; // incializamos la variable
    int i= 0;

    while(contiene && i<otro.usados){

        if (uno.NumOrdenCorredor(otro.datos[i].GetDorsal())==-1)
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
// Descripción: Devuelve true si el primer objeto Corredores
//				contiene un Corredor 
// Argumentos:
//		  uno: Primer objeto Corredores.
//        otro: Corredor a buscar.
// Devuelve: true si el primer objeto contiene al Corredor.
bool operator&&(const Corredores& uno , const Corredor& otro)
{
    Corredores corredor_nuevo; // creo un objeto corredores

    corredor_nuevo.Aniade(otro); // Aniado el unico corredor

    return (uno && corredor_nuevo); // devuelvo la comparacion de colecciones
}

/***********************************************/
/***********************************************/
// Operador binario && (version 3)
// Descripción: Devuelve true si el primer objeto Corredor 
//              esta contenido en en Corredores
// Argumentos:
//        Corredor: Corredor a buscar.
//        uno: Primer objeto Corredores.
// Devuelve: true si el Corredor esta en el primer objeto.
bool operator&&(const Corredor& Corredor, const Corredores& uno)
{
    return (uno&&Corredor); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario && (version 4)
// Descripción: Devuelve true si el primer objeto Corredores
//            Contiene un Corredor con el dorsal dado.
// Argumentos:
//		  uno: Primer objeto Corredores.
//        num_dorsal: Dorsal a buscar.
// Devuelve: true si el primer objeto contiene al Corredor.
bool operator&&(const Corredores& uno, const int num_dorsal)
{
    Corredor dorsal_nuevo; // Creo un nuevo objeto corredor vació

    dorsal_nuevo.SetDorsal(num_dorsal); // le cambio el dorsal

    return (uno&&dorsal_nuevo); // devuelvo la comparación con corredor
}

/***********************************************/
/***********************************************/
// Operador binario && (version 5)
// Descripción: Devuelve true si el primer parametro dorsal
//            esta contenido en en Corredores
// Argumentos:
//        num_dorsal: Dorsal a buscar.
//        uno: Primer objeto Corredores.
// Devuelve: true si el Corredor esta en el primer objeto.
bool operator&&(const int num_dorsal, const Corredores& uno)
{
    return (uno&&num_dorsal); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario + (version 1) [Corredores] + [Corredores]
// Descripción: Concatena dos datos Corredores en uno nuevo. 
//		Los valores delsegundo (operando de la derecha) se añaden 
//		(en el mismo orden) en una copia del primero.
// Argumentos:
//        uno: primer objeto Corredores.
//		  otro: segundo objeto Corredores.
// Devuelve: Un objeto Corredores con los elementos concatenados.
Corredores operator+(const Corredores uno, const Corredores& otro)
{
    Corredores resultado = uno; // Copiamos el primer objeto

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
// Operador binario + (version 2) [Corredores] + [Corredor]
// Descripción: Añade un Corredor al final de una copia del 
//				objeto Corredores.
// Argumentos:
//        uno: primer objeto Corredores.
//		  otro: Corredor a añadir.
// Devuelve: Un objeto Corredores con el Corredor añadido.
Corredores operator+(const Corredores uno, const Corredor& otro)
{
    Corredores resultado = uno; // Copiamos el primer objeto

    if (!(otro&&uno)) // si no está contenido
    {
        resultado.Aniade(otro); // Añadimos el objeto
    }

    return resultado; // Devolvemos el resultado

}

/***********************************************/
/***********************************************/
// Operador binario + (version 3) [Corredor] + [Corredores]
// Descripción: Añade un Corredor al principio de una copia del
//				objeto Corredores.
// Argumentos:
//        uno: Corredor a añadir.
//		  otro: primer objeto Corredores.
// Devuelve: Un objeto Corredores con el Corredor añadido.
Corredores operator+(const Corredor& uno, const Corredores otro)
{
    return otro + uno; // Invertimos el orden
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 1) [Corredores] += [Corredores]
// Descripción: Añade los elementos de un objeto Corredores al final.
// Argumentos:
//        uno: primer objeto Corredores.
// Devuelve: Un objeto Corredores con los elementos añadidos.
Corredores& Corredores::operator+=(const Corredores& otro)
{
    *this = *this + otro; // Concatenamos los objetos

    return *this; // Devolvemos el objeto actual
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 2) [Corredores] += [Corredor]
// Descripción: Añade un Corredor al final del objeto Corredores.
// Argumentos:
//        uno: primer objeto Corredores.
// Devuelve: Un objeto Corredores con el Corredor añadido.
Corredores& Corredores::operator+=(const Corredor& otro)
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
void Corredores::ReservarMemoria (const Corredores& otro)
{
    capacidad = otro.capacidad; // Copiamos la capacidad
    datos = new Corredor[capacidad]; // Reservamos memoria
    usados = otro.usados; // Copiamos los usados
   
}

/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos
void Corredores::CopiarDatos (const Corredores& otro)
{
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        datos[i] = otro.datos[i]; // Copiamos los datos
    }
}

/************************************************************/
/************************************************************/
// Libera memoria

void Corredores:: LiberarMemoria (void)
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
void Corredores:: Reajusta(void)
{
    int nueva_capacidad = usados;
    Corredor *tmp = new Corredor[nueva_capacidad]; // Reservamos memoria tmp
    
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
void Corredores::Redimensiona(void)
{
    Corredor *tmp = new Corredor[capacidad + TAM_BLOQUE]; // Reservamos mem
    
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
Corredor& Corredores::ValorCasilla(const int num_casilla) const
{
    return datos[num_casilla]; // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// EsIgualA
// Descripción: Compara dos objetos Corredores.
// Argumentos:
//      otro: Objeto Corredores con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Corredores:: EsIgualA(const Corredores& otro) const
{
    bool es_igual = true; // Inicializamos la variable

    if (usados != otro.usados) // Si los usados son distintos
    {
        es_igual = false; // No son iguales
    }
    else // Si los usados son iguales
    {
        for (int i = 0; i < usados; i++) // Recorremos los datos
        {
            if (datos[i].GetDorsal() != otro.datos[i].GetDorsal())
            {
                es_igual = false; // No son iguales
            }
        }
    }

    return es_igual; // Devolvemos si son iguales
}
