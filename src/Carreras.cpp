/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Carreras.cpp
//
// Definiciones de la clase Carreras del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Carreras.h"
#include "Carrera.h"

using namespace std;


/***********************************************/
/***********************************************/
// Constructor predeterminado
// Descripción: Crea un objeto Carreras vacío.
Carreras::Carreras(void)
{
    capacidad = TAM_BLOQUE; // Inicializamos la capacidad
    datos = new Carrera[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usados
}

/***********************************************/
/***********************************************/
// Constructor de copia
// Descripción: Crea un nuevo objeto Carreras a partir de otro.
// Argumentos:
//      otro: Objeto Carreras del cual se copian los datos.
Carreras::Carreras(const Carreras& otro)
{
    ReservarMemoria(otro); // Reservamos memoria
    CopiarDatos(otro); // Copiamos los datos
}

/***********************************************/
/***********************************************/
// Constructor con capacidad inicial
// Descripción: Crea un objeto Carreras con una capacidad inicial.
// Argumentos:
//      capacidad_inicial: Capacidad inicial deseada.
Carreras::Carreras(int capacidad_inicial)
{
    if (capacidad_inicial <= 0) // Si la capacidad es menor o igual a 0
    {
        capacidad = TAM_BLOQUE; // Inicializamos la capacidad
    }
    else // Si la capacidad es mayor que 0
    {
        capacidad = capacidad_inicial; // Inicializamos la capacidad
    }
    datos = new Carrera[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usados
}

/***********************************************/
/***********************************************/
// Destructor
// Descripción: Libera memoria y recursos utilizados por el objeto.
Carreras::~Carreras(void)
{
    LiberarMemoria(); // Liberamos la memoria
}

/***********************************************/
/***********************************************/
// getCapacidad
// Descripción: Devuelve la capacidad actual del objeto.
int Carreras::Capacidad(void)
{
    return capacidad; // Devolvemos la capacidad
}

/***********************************************/
/***********************************************/
// getUsados
// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
int Carreras:: Usados(void)
{
    return usados; // Devolvemos los usados
}

/***********************************************/
/***********************************************/
// EstaVacio
// Descripción: Comprueba si el objeto está vacío.
bool Carreras::EstaVacio(void)
{
    return usados == 0; // Devolvemos si está vacío

}


/***********************************************/
/***********************************************/
// EliminaTodos
// Descripción: Elimina todos los elementos, dejándolo vacío.
void Carreras::EliminaTodos(void)
{    
    usados = 0; // Ponemos los usados a 0
}

/***********************************************/
/***********************************************/
// Elimina 
// Descripción: Elimina un objeto Carrera en una posición específica.
// Argumentos:
//      num_casilla: Índice de la casilla del objeto que se elimina.
void Carreras::Elimina(const int num_casilla)
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
// Descripción: Añade un objeto Carrera al final del objeto.
// Argumentos:
//      objeto: Objeto Carrera que se añade al final.
void Carreras::Aniade(const Carrera& objeto)
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
// Descripción: Inserta un objeto Carrera en una posición específica.
// Argumentos:
//      objeto: Objeto Carrera que se inserta.
//      num_casilla: Índice de la casilla en la que se inserta.
void Carreras::Inserta(const Carrera& objeto, const int num_casilla)
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
// Devuelve la posición en una colección de un Carrera,
// dado su dorsal. Si no está registrado devuelve -1.
int Carreras::NumOrdenCarrera (const int IdCarrera) const
{
    int posicion = -1; // Suponemos que no está
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i].GetIdCarrera() == IdCarrera) // Si encontramos el dorsal
        {
            posicion = i; // Si lo encontramos
        }
    }
    return posicion; // devolvemos la posición
}

/***********************************************/
/***********************************************/
// Devuelve la posición en una colección de un Carrera,
// dado su DNI. Si no está registrado devuelve -1.
int Carreras::NumOrdenCarrera (const string nombre) const
{
    int posicion = -1; // Suponemos que no está
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i].GetNombre() == nombre) // Si encontramos el DNI
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
string Carreras::ToString(const string titulo) const
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
//      otro: Objeto Carreras del cual se copian los datos.
// Devuelve: Una referencia al objeto actual después de la asignación.
Carreras & Carreras::operator=(const Carreras& otro)
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
Carrera & Carreras::operator[](const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}
Carrera Carreras::operator[](const int num_casilla) const
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
Carrera & Carreras::operator()(const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto   
}

Carrera Carreras::operator()(const int num_casilla) const
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// Operador de comparación ==
// Descripción: Compara dos objetos Carreras.
// Argumentos:
//      otro: Objeto Carreras con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Carreras:: operator==(const Carreras& otro) const
{
    return EsIgualA(otro); // Devolvemos si son iguales
}

/***********************************************/
/***********************************************/
// Operador de comparación !=
// Descripción: Compara dos objetos Carreras.
// Argumentos:
//      otro: Objeto Carreras con el que se compara.
// Devuelve: true si son distintos, false en caso contrario.
bool Carreras::operator!=(const Carreras& otro) const
{
    return !EsIgualA(otro); // Devolvemos si son distintos
}


/***********************************************/
/***********************************************/
// Operador binario *
// Descripción: Realiza la intersección de dos objetos Carreras.
// Argumentos:
//      uno: primer objeto Carreras.
//      otro: segundo objeto Carreras.
// Devuelve: Un objeto Carreras con los elementos comunes.
Carreras operator*(const Carreras uno, const Carreras& otro)
{
    Carreras resultado; // Objeto resultado

    for (int i = 0; i < uno.usados; i++) // Recorremos los datos
    {
        if (otro.NumOrdenCarrera(uno.datos[i].GetIdCarrera()) != -1) 
        {
            resultado.Aniade(uno.datos[i]); // Añadimos el objeto
        }
    }

    return resultado; // Devolvemos el resultado
}

/***********************************************/
/***********************************************/
// Operador binario && (version 1)
// Descripción: Devuelve true si el primer objeto Carreras 
//				contiene al segundo. 
// Argumentos:
//        uno: primer objeto Carreras.
//		  otro: segundo objeto Carreras.
// Devuelve: true si el primer objeto contiene al segundo.
bool operator&&( const Carreras& uno , const Carreras otro)
{
    bool contiene = true; // incializamos la variable
    int i= 0;

    while(contiene && i<otro.usados){

        if (uno.NumOrdenCarrera(otro.datos[i].GetIdCarrera())==-1)
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
// Descripción: Devuelve true si el primer objeto Carreras
//				contiene un Carrera 
// Argumentos:
//		  uno: Primer objeto Carreras.
//        otro: Carrera a buscar.
// Devuelve: true si el primer objeto contiene al Carrera.
bool operator&&(const Carreras& uno , const Carrera& otro)
{
    Carreras Carrera_nuevo; // creo un objeto Carreras

    Carrera_nuevo.Aniade(otro); // Aniado el unico Carrera

    return (uno && Carrera_nuevo); // devuelvo la comparacion de colecciones
}

/***********************************************/
/***********************************************/
// Operador binario && (version 3)
// Descripción: Devuelve true si el primer objeto Carrera 
//              esta contenido en en Carreras
// Argumentos:
//        Carrera: Carrera a buscar.
//        uno: Primer objeto Carreras.
// Devuelve: true si el Carrera esta en el primer objeto.
bool operator&&(const Carrera& Carrera, const Carreras& uno)
{
    return (uno&&Carrera); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario && (version 4)
// Descripción: Devuelve true si el primer objeto Carreras
//            Contiene un Carrera con el dorsal dado.
// Argumentos:
//		  uno: Primer objeto Carreras.
//        IdCarrera: Id a buscar.
// Devuelve: true si el primer objeto contiene al Carrera.
bool operator&&(const Carreras& uno, const int IdCarrera)
{
    Carrera Id_nuevo; // Creo un nuevo objeto Carrera vació

    Id_nuevo.SetIdCarrera(IdCarrera); // le cambio el IdCarrera

    return (uno&&Id_nuevo); // devuelvo la comparación con Carrera
}

/***********************************************/
/***********************************************/
// Operador binario && (version 5)
// Descripción: Devuelve true si el primer parametro dorsal
//            esta contenido en en Carreras
// Argumentos:
//        IdCarrera: Id a buscar.
//        uno: Primer objeto Carreras.
// Devuelve: true si el Carrera esta en el primer objeto.
bool operator&&(const int IdCarrera, const Carreras& uno)
{
    return (uno&&IdCarrera); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario + (version 1) [Carreras] + [Carreras]
// Descripción: Concatena dos datos Carreras en uno nuevo. 
//		Los valores delsegundo (operando de la derecha) se añaden 
//		(en el mismo orden) en una copia del primero.
// Argumentos:
//        uno: primer objeto Carreras.
//		  otro: segundo objeto Carreras.
// Devuelve: Un objeto Carreras con los elementos concatenados.
Carreras operator+(const Carreras uno, const Carreras& otro)
{
    Carreras resultado = uno; // Copiamos el primer objeto

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
// Operador binario + (version 2) [Carreras] + [Carrera]
// Descripción: Añade un Carrera al final de una copia del 
//				objeto Carreras.
// Argumentos:
//        uno: primer objeto Carreras.
//		  otro: Carrera a añadir.
// Devuelve: Un objeto Carreras con el Carrera añadido.
Carreras operator+(const Carreras uno, const Carrera& otro)
{
    Carreras resultado = uno; // Copiamos el primer objeto

    if (!(otro&&uno)) // si no está contenido
    {
        resultado.Aniade(otro); // Añadimos el objeto
    }

    return resultado; // Devolvemos el resultado

}

/***********************************************/
/***********************************************/
// Operador binario + (version 3) [Carrera] + [Carreras]
// Descripción: Añade un Carrera al principio de una copia del
//				objeto Carreras.
// Argumentos:
//        uno: Carrera a añadir.
//		  otro: primer objeto Carreras.
// Devuelve: Un objeto Carreras con el Carrera añadido.
Carreras operator+(const Carrera& uno, const Carreras otro)
{
    return otro + uno; // Invertimos el orden
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 1) [Carreras] += [Carreras]
// Descripción: Añade los elementos de un objeto Carreras al final.
// Argumentos:
//        uno: primer objeto Carreras.
// Devuelve: Un objeto Carreras con los elementos añadidos.
Carreras& Carreras::operator+=(const Carreras& otro)
{
    *this = *this + otro; // Concatenamos los objetos

    return *this; // Devolvemos el objeto actual
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 2) [Carreras] += [Carrera]
// Descripción: Añade un Carrera al final del objeto Carreras.
// Argumentos:
//        uno: primer objeto Carreras.
// Devuelve: Un objeto Carreras con el Carrera añadido.
Carreras& Carreras::operator+=(const Carrera& otro)
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
void Carreras::ReservarMemoria (const Carreras& otro)
{
    capacidad = otro.capacidad; // Copiamos la capacidad
    datos = new Carrera[capacidad]; // Reservamos memoria
    usados = otro.usados; // Copiamos los usados
   
}

/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos
void Carreras::CopiarDatos (const Carreras& otro)
{
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        datos[i] = otro.datos[i]; // Copiamos los datos
    }
}

/************************************************************/
/************************************************************/
// Libera memoria

void Carreras:: LiberarMemoria (void)
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
void Carreras:: Reajusta(void)
{
    int nueva_capacidad = usados;
    Carrera *tmp = new Carrera[nueva_capacidad]; // Reservamos memoria tmp
    
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
void Carreras::Redimensiona(void)
{
    Carrera *tmp = new Carrera[capacidad + TAM_BLOQUE]; // Reservamos mem
    
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
Carrera& Carreras::ValorCasilla(const int num_casilla) const
{
    return datos[num_casilla]; // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// EsIgualA
// Descripción: Compara dos objetos Carreras.
// Argumentos:
//      otro: Objeto Carreras con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Carreras:: EsIgualA(const Carreras& otro) const
{
    int tamanio_union = (*this + otro).Usados(); // Unimos 
    int tamanio_interseccion = (*this * otro).Usados(); // Intersectamos 

    return (tamanio_union==tamanio_interseccion); // Devolvemos si son iguales
}