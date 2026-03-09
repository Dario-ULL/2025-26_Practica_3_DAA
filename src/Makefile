# Variables
CC = g++
# Añadimos -I. para encontrar nlohmann/json.hpp si está en Clases/nlohmann
CXXFLAGS = -Wall -std=c++17 -IClases -I. -I./external 
OBJ_DIR = ImplementacionClases
INC_DIR = Clases
SRC_DIR = $(OBJ_DIR)
MAIN_SRC = main.cc
EXEC = Ejecutable

# Archivos objeto - AÑADIMOS InstanciaPlanificacion.o
OBJ_FILES = $(OBJ_DIR)/Algoritmo.o \
            $(OBJ_DIR)/DivideYVenceras.o \
            $(OBJ_DIR)/Escribir.o \
            $(OBJ_DIR)/LeerFichero.o \
            $(OBJ_DIR)/Algoritmos/AlgoritmoMergeSort.o \
            $(OBJ_DIR)/Algoritmos/AlgoritmoQuickSort.o \
            $(OBJ_DIR)/Instancias/InstanciaVector.o \
            $(OBJ_DIR)/Instancias/InstanciaPlanificacion.o \
            $(OBJ_DIR)/Soluciones/SolucionVector.o \
            $(OBJ_DIR)/Soluciones/SolucionPlanificacion.o

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable (Cambiado CFLAGS por CXXFLAGS)
$(EXEC): $(OBJ_FILES) $(MAIN_SRC)
	$(CC) $(CXXFLAGS) $(OBJ_FILES) $(MAIN_SRC) -o $(EXEC)

# Reglas genéricas (Cambiado CFLAGS por CXXFLAGS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Algoritmos/%.o: $(SRC_DIR)/Algoritmos/%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Soluciones/%.o: $(SRC_DIR)/Soluciones/%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Instancias/%.o: $(SRC_DIR)/Instancias/%.cc
	$(CC) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(EXEC)

re: fclean all