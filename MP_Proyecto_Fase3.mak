############################################################################
#
# METODOLOGÍA DE LA PROGRAMACIÓN
#
# PAOLO PUGA DE PATTO
# PRIMERO B DE INGENIERÍA INFORMÁTICA
#
# Fichero: MP_Proyecto_Fase3.mak
#
# Makefile para la compilacion de MP_Proyecto_Fase3
#
# Proyecto FASE 3
#
############################################################################

# DECLARACION MACROS................................

PROYECTO = CIRCUITO DE CARRERAS DE FONDO

HOME = .
HOME_CLASES_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_CLASES_UTILS =  $(HOME_CLASES_UTILS)/src
OBJ_CLASES_UTILS =  $(HOME_CLASES_UTILS)/obj
LIB_CLASES_UTILS =  $(HOME_CLASES_UTILS)/lib
INCLUDE_CLASES_UTILS = $(HOME_CLASES_UTILS)/include

LIBS_DIR = -L$(HOME_CLASES_UTILS)/lib
LIBS = -lCorredor -lCategoria -lResultado -lCarrera -lTiempo -lFecha -lutils \
	   -lCorredores -lCategorias -lResultados -lCarreras -lTodosResultados

#.............................FIN DECLARACION MACROS



# DESTINOS SIMBOLICOS...............................

all:  preambulo \
	  mr.proper \
      $(BIN)/MP_Proyecto_Fase3 \
	  final

preambulo:
	@echo
	@echo ---------------------------------------------
	@echo FASE 1 DEL PROYECTO: $(PROYECTO)
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo
	@echo PAOLO PUGA DE PATTO
	@echo PRIMERO B DE INGENIERÍA INFORMÁTICA
	@echo Universidad de Granada
	@echo ---------------------------------------------
	@echo



final: 
	@echo
	@echo .............. FIN $(PROYECTO) ..............	
	@echo

#............................FIN DESTINOS SIMBOLICOS



# EJECUTABLES.......................................

$(BIN)/MP_Proyecto_Fase3: $(OBJ)/main_MP_Proyecto_Fase3.o \
    $(LIB_CLASES_UTILS)/libutils.a \
    $(LIB_CLASES_UTILS)/libCarrera.a \
    $(LIB_CLASES_UTILS)/libCategoria.a \
    $(LIB_CLASES_UTILS)/libCorredor.a \
    $(LIB_CLASES_UTILS)/libResultado.a \
    $(LIB_CLASES_UTILS)/libTiempo.a \
    $(LIB_CLASES_UTILS)/libFecha.a \
	$(LIB_CLASES_UTILS)/libCarreras.a \
	$(LIB_CLASES_UTILS)/libCategorias.a \
	$(LIB_CLASES_UTILS)/libCorredores.a $(LIB_CLASES_UTILS)/libResultados.a $(LIB_CLASES_UTILS)/libTodosResultados.a                 
	@echo 
	@echo Creando ejecutable: MP_Proyecto_Fase3
	@echo 
	g++ -o $(BIN)/MP_Proyecto_Fase3 \
		   $(OBJ)/main_MP_Proyecto_Fase3.o \
	       $(LIBS_DIR) $(LIBS)
# ...................................FIN EJECUTABLES


# OBJETOS...........................................

$(OBJ)/main_MP_Proyecto_Fase3.o: $(SRC)/main_MP_Proyecto_Fase3.cpp \
	$(INCLUDE_CLASES_UTILS)/utils.h \
    $(INCLUDE_CLASES_UTILS)/Carrera.h \
    $(INCLUDE_CLASES_UTILS)/Categoria.h \
    $(INCLUDE_CLASES_UTILS)/Corredor.h \
    $(INCLUDE_CLASES_UTILS)/Resultado.h \
    $(INCLUDE_CLASES_UTILS)/Tiempo.h \
    $(INCLUDE_CLASES_UTILS)/Fecha.h \
	$(INCLUDE_CLASES_UTILS)/Carreras.h \
	$(INCLUDE_CLASES_UTILS)/Categorias.h \
	$(INCLUDE_CLASES_UTILS)/Corredores.h \
	$(INCLUDE_CLASES_UTILS)/Resultados.h $(INCLUDE_CLASES_UTILS)/TodosResultados.h                    
	@echo 
	@echo Creando objeto: main_MP_Proyecto_Fase3.o
	@echo 
	g++ -c -o $(OBJ)/main_MP_Proyecto_Fase3.o \
		$(SRC)/main_MP_Proyecto_Fase3.cpp \
		-I$(INCLUDE_CLASES_UTILS) -std=c++14
	      
# .......................................FIN OBJETOS


# BIBLIOTECAS.......................................

#.............. CLASE CARRERA ..............	
$(LIB_CLASES_UTILS)/libCarrera.a: \
	$(OBJ_CLASES_UTILS)/Carrera.o
	@echo 
	@echo Creando biblioteca: libCarrera.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libCarrera.a \
        $(OBJ_CLASES_UTILS)/Carrera.o	

$(OBJ_CLASES_UTILS)/Carrera.o: \
	$(SRC_CLASES_UTILS)/Carrera.cpp \
    $(INCLUDE_CLASES_UTILS)/Carrera.h
	@echo 
	@echo Creando objeto: Carrera.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Carrera.o \
        $(SRC_CLASES_UTILS)/Carrera.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN CARRERA ...............	


#.............. CLASE CORREDOR ..............	
$(LIB_CLASES_UTILS)/libCorredor.a: \
	$(OBJ_CLASES_UTILS)/Corredor.o
	@echo 
	@echo Creando biblioteca: libCorredor.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libCorredor.a \
        $(OBJ_CLASES_UTILS)/Corredor.o

$(OBJ_CLASES_UTILS)/Corredor.o: \
	$(SRC_CLASES_UTILS)/Corredor.cpp \
    $(INCLUDE_CLASES_UTILS)/Corredor.h
	@echo 
	@echo Creando objeto: Corredor.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Corredor.o \
        $(SRC_CLASES_UTILS)/Corredor.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN CORREDOR ...............


#.............. CLASE CATEGORIA ..............
$(LIB_CLASES_UTILS)/libCategoria.a: \
	$(OBJ_CLASES_UTILS)/Categoria.o
	@echo 
	@echo Creando biblioteca: libCategoria.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libCategoria.a \
        $(OBJ_CLASES_UTILS)/Categoria.o

$(OBJ_CLASES_UTILS)/Categoria.o: \
	$(SRC_CLASES_UTILS)/Categoria.cpp \
    $(INCLUDE_CLASES_UTILS)/Categoria.h
	@echo 
	@echo Creando objeto: Categoria.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Categoria.o \
        $(SRC_CLASES_UTILS)/Categoria.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN CATEGORIA ...............


#.............. CLASE RESULTADO ..............
$(LIB_CLASES_UTILS)/libResultado.a: \
	$(OBJ_CLASES_UTILS)/Resultado.o
	@echo 
	@echo Creando biblioteca: libResultado.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libResultado.a \
        $(OBJ_CLASES_UTILS)/Resultado.o

$(OBJ_CLASES_UTILS)/Resultado.o: \
	$(SRC_CLASES_UTILS)/Resultado.cpp \
    $(INCLUDE_CLASES_UTILS)/Resultado.h
	@echo 
	@echo Creando objeto: Resultado.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Resultado.o \
        $(SRC_CLASES_UTILS)/Resultado.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN RESULTADO ...............


#.............. CLASE TIEMPO ..............
$(LIB_CLASES_UTILS)/libTiempo.a: \
	$(OBJ_CLASES_UTILS)/Tiempo.o
	@echo 
	@echo Creando biblioteca: libTiempo.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libTiempo.a \
        $(OBJ_CLASES_UTILS)/Tiempo.o

$(OBJ_CLASES_UTILS)/Tiempo.o: \
	$(SRC_CLASES_UTILS)/Tiempo.cpp \
    $(INCLUDE_CLASES_UTILS)/Tiempo.h
	@echo 
	@echo Creando objeto: Tiempo.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Tiempo.o \
        $(SRC_CLASES_UTILS)/Tiempo.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN TIEMPO ...............


#.............. CLASE FECHA ..............
$(LIB_CLASES_UTILS)/libFecha.a: \
	$(OBJ_CLASES_UTILS)/Fecha.o
	@echo 
	@echo Creando biblioteca: libFecha.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libFecha.a \
        $(OBJ_CLASES_UTILS)/Fecha.o

$(OBJ_CLASES_UTILS)/Fecha.o: \
	$(SRC_CLASES_UTILS)/Fecha.cpp \
    $(INCLUDE_CLASES_UTILS)/Fecha.h
	@echo 
	@echo Creando objeto: Fecha.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Fecha.o \
        $(SRC_CLASES_UTILS)/Fecha.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN FECHA ...............


#.............. CLASE UTILS ..............
$(LIB_CLASES_UTILS)/libutils.a: \
	$(OBJ_CLASES_UTILS)/utils.o
	@echo 
	@echo Creando biblioteca: libutils.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libutils.a \
        $(OBJ_CLASES_UTILS)/utils.o

$(OBJ_CLASES_UTILS)/utils.o: \
	$(SRC_CLASES_UTILS)/utils.cpp \
    $(INCLUDE_CLASES_UTILS)/utils.h
	@echo 
	@echo Creando objeto: utils.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/utils.o \
        $(SRC_CLASES_UTILS)/utils.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN UTILS ...............


#.............. CLASE CARRERAS ..............	
$(LIB_CLASES_UTILS)/libCarreras.a: \
	$(OBJ_CLASES_UTILS)/Carreras.o
	@echo 
	@echo Creando biblioteca: libCarreras.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libCarreras.a \
        $(OBJ_CLASES_UTILS)/Carreras.o	

$(OBJ_CLASES_UTILS)/Carreras.o: \
	$(SRC_CLASES_UTILS)/Carreras.cpp \
    $(INCLUDE_CLASES_UTILS)/Carreras.h
	@echo 
	@echo Creando objeto: Carreras.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Carreras.o \
        $(SRC_CLASES_UTILS)/Carreras.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN CARRERA ...............	


#.............. CLASE CORREDORES ..............	
$(LIB_CLASES_UTILS)/libCorredores.a: \
	$(OBJ_CLASES_UTILS)/Corredores.o
	@echo 
	@echo Creando biblioteca: libCorredores.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libCorredores.a \
        $(OBJ_CLASES_UTILS)/Corredores.o

$(OBJ_CLASES_UTILS)/Corredores.o: \
	$(SRC_CLASES_UTILS)/Corredores.cpp \
    $(INCLUDE_CLASES_UTILS)/Corredores.h
	@echo 
	@echo Creando objeto: Corredores.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Corredores.o \
        $(SRC_CLASES_UTILS)/Corredores.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN CORREDORES ...............


#.............. CLASE CATEGORIAS ..............
$(LIB_CLASES_UTILS)/libCategorias.a: \
	$(OBJ_CLASES_UTILS)/Categorias.o
	@echo 
	@echo Creando biblioteca: libCategorias.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libCategorias.a \
        $(OBJ_CLASES_UTILS)/Categorias.o

$(OBJ_CLASES_UTILS)/Categorias.o: \
	$(SRC_CLASES_UTILS)/Categorias.cpp \
    $(INCLUDE_CLASES_UTILS)/Categorias.h
	@echo 
	@echo Creando objeto: Categorias.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Categorias.o \
        $(SRC_CLASES_UTILS)/Categorias.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN CATEGORIAS ...............


#.............. CLASE RESULTADOS ..............
$(LIB_CLASES_UTILS)/libResultados.a: \
	$(OBJ_CLASES_UTILS)/Resultados.o
	@echo 
	@echo Creando biblioteca: libResultados.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libResultados.a \
        $(OBJ_CLASES_UTILS)/Resultados.o

$(OBJ_CLASES_UTILS)/Resultados.o: \
	$(SRC_CLASES_UTILS)/Resultados.cpp \
    $(INCLUDE_CLASES_UTILS)/Resultados.h
	@echo 
	@echo Creando objeto: Resultados.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/Resultados.o \
        $(SRC_CLASES_UTILS)/Resultados.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN RESULTADOS ...............


#.............. CLASE TODOSRESULTADOS ..............
$(LIB_CLASES_UTILS)/libTodosResultados.a: \
	$(OBJ_CLASES_UTILS)/TodosResultados.o
	@echo 
	@echo Creando biblioteca: libTodosResultados.a
	@echo
	ar rvs $(LIB_CLASES_UTILS)/libTodosResultados.a \
        $(OBJ_CLASES_UTILS)/TodosResultados.o

$(OBJ_CLASES_UTILS)/TodosResultados.o: \
	$(SRC_CLASES_UTILS)/TodosResultados.cpp \
    $(INCLUDE_CLASES_UTILS)/TodosResultados.h
	@echo 
	@echo Creando objeto: TodosResultados.o 
	@echo
	g++ -c -o $(OBJ_CLASES_UTILS)/TodosResultados.o \
        $(SRC_CLASES_UTILS)/TodosResultados.cpp \
       -I$(INCLUDE_CLASES_UTILS) -std=c++14
#............... FIN RESULTADO ...............


# ...................................FIN BIBLIOTECAS


# LIMPEZA...........................................

clean: clean-objs clean-libs

clean-objs: 
	@echo
	@echo Borrando objetos de $(PROYECTO)...
	-rm $(OBJ)/main_MP_Proyecto_Fase3.o
	-rm $(OBJ_CLASES_UTILS)/utils.o 
	-rm $(OBJ_CLASES_UTILS)/Fecha.o 
	-rm $(OBJ_CLASES_UTILS)/Tiempo.o
	-rm $(OBJ_CLASES_UTILS)/Carrera.o 
	-rm $(OBJ_CLASES_UTILS)/Corredor.o 
	-rm $(OBJ_CLASES_UTILS)/Categoria.o 
	-rm $(OBJ_CLASES_UTILS)/Resultado.o
	-rm $(OBJ_CLASES_UTILS)/Carreras.o 
	-rm $(OBJ_CLASES_UTILS)/Corredores.o 
	-rm $(OBJ_CLASES_UTILS)/Categorias.o 
	-rm $(OBJ_CLASES_UTILS)/Resultados.o
	-rm $(OBJ_CLASES_UTILS)/TodosResultados.o  
	@echo ...Borrados objetos de $(PROYECTO)
	@echo 

clean-libs: 
	@echo
	@echo Borrando bibliotecas de $(PROYECTO)...
	-rm $(LIB_CLASES_UTILS)/libCarrera.a
	-rm $(LIB_CLASES_UTILS)/libCorredor.a
	-rm $(LIB_CLASES_UTILS)/libCategoria.a
	-rm $(LIB_CLASES_UTILS)/libResultado.a
	-rm $(LIB_CLASES_UTILS)/libTiempo.a
	-rm $(LIB_CLASES_UTILS)/libFecha.a
	-rm $(LIB_CLASES_UTILS)/libutils.a
	-rm $(LIB_CLASES_UTILS)/libCarreras.a
	-rm $(LIB_CLASES_UTILS)/libCorredores.a
	-rm $(LIB_CLASES_UTILS)/libCategorias.a
	-rm $(LIB_CLASES_UTILS)/libResultados.a
	-rm $(LIB_CLASES_UTILS)/libTodosResultados.a
	@echo ...Borradas bibliotecas de $(PROYECTO)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de $(PROYECTO)...
	-rm $(BIN)/MP_Proyecto_Fase3
	@echo ...Borrados ejecutables de la sesion de $(PROYECTO)

mr.proper:  clean-objs clean-libs clean-bins

#.......................................FIN LIMPIEZA