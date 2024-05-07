/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// PAOLO PUGA DE PATTO
// PRIMERO B DE INGENIERÍA INFORMÁTICA
// 
// Fichero: Categorias.cpp
//
// Definiciones de la clase Categorias del proyecto 
//
// Proyecto. FASE 02. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Categorias.h"
#include "Categoria.h"

using namespace std;


/***********************************************/
/***********************************************/
// Constructor predeterminado
// Descripción: Crea un objeto Categorias vacío.
Categorias::Categorias(void)
{
    ReservarMemoria(); // Reservamos memoria
}

/***********************************************/
/***********************************************/
// Constructor de copia
// Descripción: Crea un nuevo objeto Categorias a partir de otro.
// Argumentos:
//      otro: Objeto Categorias del cual se copian los datos.
Categorias::Categorias(const Categorias& otro)
{
    ReservarMemoria(otro); // Reservamos memoria
    CopiarDatos(otro); // Copiamos los datos
}

/***********************************************/
/***********************************************/
// Constructor con capacidad inicial
// Descripción: Crea un objeto Categorias con una capacidad inicial.
// Argumentos:
//      capacidad_inicial: Capacidad inicial deseada.
Categorias::Categorias(int capacidad_inicial)
{
    ReservarMemoria(capacidad_inicial); // Reservamos memoria
}

/***********************************************/
/***********************************************/
// Destructor
// Descripción: Libera memoria y recursos utilizados por el objeto.
Categorias::~Categorias(void)
{
    LiberarMemoria(); // Liberamos la memoria
}

/***********************************************/
/***********************************************/
// getCapacidad
// Descripción: Devuelve la capacidad actual del objeto.
int Categorias::Capacidad(void) const
{
    return capacidad; // Devolvemos la capacidad
}

/***********************************************/
/***********************************************/
// getUsados
// Descripción: Devuelve la cantidad de elementos utilizados en el objeto.
int Categorias:: Usados(void) const
{
    return usados; // Devolvemos los usados
}

/***********************************************/
/***********************************************/
// EstaVacio
// Descripción: Comprueba si el objeto está vacío.
bool Categorias::EstaVacio(void)
{
    return usados == 0; // Devolvemos si está vacío

}


/***********************************************/
/***********************************************/
// EliminaTodos
// Descripción: Elimina todos los elementos, dejándolo vacío.
void Categorias::EliminaTodos(void)
{    
    usados = 0; // Ponemos los usados a 0
}

/***********************************************/
/***********************************************/
// Elimina 
// Descripción: Elimina un objeto Categoria en una posición específica.
// Argumentos:
//      num_casilla: Índice de la casilla del objeto que se elimina.
void Categorias::Elimina(const int num_casilla)
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
// Descripción: Inserta un objeto Categoria en una posición específica.
// Argumentos:
//      objeto: Objeto Categoria que se inserta.
//      num_casilla: Índice de la casilla en la que se inserta.
void Categorias::Inserta(const Categoria& objeto, const int num_casilla)
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
// Devuelve la posición en una colección de un Categoria,
// dado su IdCategoria. Si no está registrado devuelve -1.
int Categorias::NumOrdenCategoria (const int IdCategoria) const
{
    int posicion = -1; // Suponemos que no está
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i].GetIdCategoria() == IdCategoria) // Si encontramos el Id
        {
            posicion = i; // Si lo encontramos
        }
    }
    return posicion; // devolvemos la posición
}

/***********************************************/
/***********************************************/
// Devuelve la posición en una colección de un Categoria,
// dado su DNI. Si no está registrado devuelve -1.
int Categorias::NumOrdenCategoria(const string Denominacion) const
{
    int posicion = -1; // Suponemos que no está
    
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        if (datos[i].GetDenominacion() == Denominacion)
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
string Categorias::ToString(const string titulo) const
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
//      otro: Objeto Categorias del cual se copian los datos.
// Devuelve: Una referencia al objeto actual después de la asignación.
Categorias & Categorias::operator=(const Categorias& otro)
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
Categoria & Categorias::operator[](const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}
Categoria Categorias::operator[](const int num_casilla) const
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
Categoria & Categorias::operator()(const int num_casilla)
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto   
}

Categoria Categorias::operator()(const int num_casilla) const
{     
    return ValorCasilla(num_casilla-1); // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// Operador de comparación ==
// Descripción: Compara dos objetos Categorias.
// Argumentos:
//      otro: Objeto Categorias con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Categorias:: operator==(const Categorias& otro) const
{
    return EsIgualA(otro); // Devolvemos si son iguales
}

/***********************************************/
/***********************************************/
// Operador de comparación !=
// Descripción: Compara dos objetos Categorias.
// Argumentos:
//      otro: Objeto Categorias con el que se compara.
// Devuelve: true si son distintos, false en caso contrario.
bool Categorias::operator!=(const Categorias& otro) const
{
    return !EsIgualA(otro); // Devolvemos si son distintos
}

/***********************************************/
/***********************************************/
// Operador de comparación <
// Descripción: Compara dos objetos Categorias.
// Argumentos:
//      otro: Objeto Categorias con el que se compara.
// Devuelve: true si el objeto actual es menor que el otro.
bool Categorias::operator<(const Categorias& otro) const
{
    return (Usados() < otro.Usados()); // Devolvemos si es menor
}

/***********************************************/
/***********************************************/
// Operador de comparación >
// Descripción: Compara dos objetos Categorias.
// Argumentos:
//      otro: Objeto Categorias con el que se compara.
// Devuelve: true si el objeto actual es mayor que el otro.
bool Categorias::operator>(const Categorias& otro) const
{
    return (Usados() > otro.Usados()); // Devolvemos si es mayor
}

/***********************************************/
/***********************************************/
// Operador de comparación <=
// Descripción: Compara dos objetos Categorias.
// Argumentos:
//      otro: Objeto Categorias con el que se compara.
// Devuelve: true si el objeto actual es menor o igual que el otro.
bool Categorias::operator<=(const Categorias& otro) const
{
    return (Usados() <= otro.Usados()); // Devolvemos si es menor o igual
}

/***********************************************/
/***********************************************/
// Operador binario *
// Descripción: Realiza la intersección de dos objetos Categorias.
// Argumentos:
//      uno: primer objeto Categorias.
//      otro: segundo objeto Categorias.
// Devuelve: Un objeto Categorias con los elementos comunes.
Categorias operator*(const Categorias uno, const Categorias& otro)
{
    Categorias resultado; // Objeto resultado

    for (int i = 0; i < uno.usados; i++) // Recorremos los datos
    {
        if (otro.NumOrdenCategoria(uno.datos[i].GetIdCategoria()) != -1) 
        {
            resultado.Aniade(uno.datos[i]); // Añadimos el objeto
        }
    }

    return resultado; // Devolvemos el resultado
}

/***********************************************/
/***********************************************/
// Operador binario && (version 1)
// Descripción: Devuelve true si el primer objeto Categorias 
//				contiene al segundo. 
// Argumentos:
//        uno: primer objeto Categorias.
//		  otro: segundo objeto Categorias.
// Devuelve: true si el primer objeto contiene al segundo.
bool operator&&( const Categorias& uno , const Categorias otro)
{
    bool contiene = true; // incializamos la variable
    int i= 0;

    while(contiene && i<otro.usados){

        if (uno.NumOrdenCategoria(otro.datos[i].GetIdCategoria())==-1)
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
// Descripción: Devuelve true si el primer objeto Categorias
//				contiene un Categoria 
// Argumentos:
//		  uno: Primer objeto Categorias.
//        otro: Categoria a buscar.
// Devuelve: true si el primer objeto contiene al Categoria.
bool operator&&(const Categorias& uno , const Categoria& otro)
{
    Categorias Categoria_nuevo; // creo un objeto Categorias

    Categoria_nuevo.Aniade(otro); // Aniado el unico Categoria

    return (uno && Categoria_nuevo); // devuelvo la comparacion de colecciones
}

/***********************************************/
/***********************************************/
// Operador binario && (version 3)
// Descripción: Devuelve true si el primer objeto Categoria 
//              esta contenido en en Categorias
// Argumentos:
//        Categoria: Categoria a buscar.
//        uno: Primer objeto Categorias.
// Devuelve: true si el Categoria esta en el primer objeto.
bool operator&&(const Categoria& Categoria, const Categorias& uno)
{
    return (uno&&Categoria); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario && (version 4)
// Descripción: Devuelve true si el primer objeto Categorias
//            Contiene un Categoria con el dorsal dado.
// Argumentos:
//		  uno: Primer objeto Categorias.
//        IdCategoria: Dorsal a buscar.
// Devuelve: true si el primer objeto contiene al Categoria.
bool operator&&(const Categorias& uno, const int IdCategoria)
{
    Categoria Id_nuevo; // Creo un nuevo objeto Categoria vació

    Id_nuevo.SetIdCategoria(IdCategoria); // le cambio el dorsal

    return (uno&&Id_nuevo); // devuelvo la comparación con Categoria
}

/***********************************************/
/***********************************************/
// Operador binario && (version 5)
// Descripción: Devuelve true si el primer parametro dorsal
//            esta contenido en en Categorias
// Argumentos:
//        IdCategoria: Dorsal a buscar.
//        uno: Primer objeto Categorias.
// Devuelve: true si el Categoria esta en el primer objeto.
bool operator&&(const int IdCategoria, const Categorias& uno)
{
    return (uno&&IdCategoria); // invierto el orden
}

/***********************************************/
/***********************************************/
// Operador binario + (version 1) [Categorias] + [Categorias]
// Descripción: Concatena dos datos Categorias en uno nuevo. 
//		Los valores delsegundo (operando de la derecha) se añaden 
//		(en el mismo orden) en una copia del primero.
// Argumentos:
//        uno: primer objeto Categorias.
//		  otro: segundo objeto Categorias.
// Devuelve: Un objeto Categorias con los elementos concatenados.
Categorias operator+(const Categorias uno, const Categorias& otro)
{
    Categorias resultado = uno; // Copiamos el primer objeto

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
// Operador binario + (version 2) [Categorias] + [Categoria]
// Descripción: Añade un Categoria al final de una copia del 
//				objeto Categorias.
// Argumentos:
//        uno: primer objeto Categorias.
//		  otro: Categoria a añadir.
// Devuelve: Un objeto Categorias con el Categoria añadido.
Categorias operator+(const Categorias uno, const Categoria& otro)
{
    Categorias categoria; // Creamos un objeto Categorias

    categoria.Aniade(otro); // Añadimos el objeto

    return uno + categoria; // Concatenamos los objetos

}

/***********************************************/
/***********************************************/
// Operador binario + (version 3) [Categoria] + [Categorias]
// Descripción: Añade un Categoria al principio de una copia del
//				objeto Categorias.
// Argumentos:
//        uno: Categoria a añadir.
//		  otro: primer objeto Categorias.
// Devuelve: Un objeto Categorias con el Categoria añadido.
Categorias operator+(const Categoria& uno, const Categorias otro)
{
    Categorias categoria; // Creamos un objeto Categorias

    categoria.Aniade(uno); // Añadimos el objeto

    return categoria + otro; // Concatenamos los objetos
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 1) [Categorias] += [Categorias]
// Descripción: Añade los elementos de un objeto Categorias al final.
// Argumentos:
//        uno: primer objeto Categorias.
// Devuelve: Un objeto Categorias con los elementos añadidos.
Categorias& Categorias::operator+=(const Categorias& otro)
{
    *this = *this + otro; // Concatenamos los objetos

    return *this; // Devolvemos el objeto actual
}

/***********************************************/
/***********************************************/
// Operador combinado += (version 2) [Categorias] += [Categoria]
// Descripción: Añade un Categoria al final del objeto Categorias.
// Argumentos:
//        uno: primer objeto Categorias.
// Devuelve: Un objeto Categorias con el Categoria añadido.
Categorias& Categorias::operator+=(const Categoria& otro)
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
void Categorias::ReservarMemoria (const Categorias& otro)
{
    capacidad = otro.capacidad; // Copiamos la capacidad
    datos = new Categoria[capacidad]; // Reservamos memoria
    usados = otro.usados; // Copiamos los usados
   
}

/************************************************************/
/************************************************************/
// Pide memoria dado la capacidad
// Parámetros: capacidad, capacidad deseada.
void Categorias::ReservarMemoria (int capacidad_inicial)
{
    if (capacidad_inicial <= 0) // Si la capacidad es menor o igual a 0
    {
        capacidad = TAM_BLOQUE; // Inicializamos la capacidad
    }
    else // Si la capacidad es mayor que 0
    {
        capacidad = capacidad_inicial; // Inicializamos la capacidad
    }
    datos = new Categoria[capacidad]; // Reservamos memoria
    usados = 0; // Inicializamos los usados
}


/************************************************************/
/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
//
// PRE: Se ha reservado memoria para los datos
void Categorias::CopiarDatos (const Categorias& otro)
{
    for (int i = 0; i < usados; i++) // Recorremos los datos
    {
        datos[i] = otro.datos[i]; // Copiamos los datos
    }
}

/************************************************************/
/************************************************************/
// Libera memoria

void Categorias:: LiberarMemoria (void)
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
void Categorias:: Reajusta(void)
{
    int nueva_capacidad = usados;
    Categoria *tmp = new Categoria[nueva_capacidad]; // Reservamos memoria tmp
    
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
void Categorias::Redimensiona(void)
{
    Categoria *tmp = new Categoria[capacidad + TAM_BLOQUE]; // Reservamos mem
    
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
Categoria& Categorias::ValorCasilla(const int num_casilla) const
{
    return datos[num_casilla]; // Devolvemos el objeto
}

/***********************************************/
/***********************************************/
// EsIgualA
// Descripción: Compara dos objetos Categorias.
// Argumentos:
//      otro: Objeto Categorias con el que se compara.
// Devuelve: true si son iguales, false en caso contrario.
bool Categorias:: EsIgualA(const Categorias& otro) const
{
    int tamanio_union = (*this + otro).Usados(); // Unimos 
    int tamanio_interseccion = (*this * otro).Usados(); // Intersectamos 

    return (tamanio_union==tamanio_interseccion); // Devolvemos si son iguales
}

/***********************************************/
/***********************************************/
// Aniade
// Descripción: Añade un objeto Categoria al final del objeto.
// Argumentos:
//      objeto: Objeto Categoria que se añade al final.
void Categorias::Aniade(const Categoria& objeto)
{
    if (usados == capacidad) // Si no hay espacio
    {
        Redimensiona(); // Redimensionamos
    }
    datos[usados] = objeto; // Añadimos el objeto
    usados++; // Aumentamos los usados
}