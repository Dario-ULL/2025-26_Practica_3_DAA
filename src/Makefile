# Variables
CC = g++
CFLAGS = -Wall -std=c++11
OBJ_DIR = ImplementacionClases
INC_DIR = Clases
SRC_DIR = $(OBJ_DIR)
MAIN_SRC = main.cc
EXEC = Ejecutable

# Archivos objeto
OBJ_FILES = $(OBJ_DIR)/Algoritmo.o \
						$(OBJ_DIR)/DivideYVenceras.o \
						$(OBJ_DIR)/EscribirFichero.o \
						$(OBJ_DIR)/Instancia.o \
						$(OBJ_DIR)/LeerFichero.o \
						$(OBJ_DIR)/Solucion.o \
						$(OBJ_DIR)/VectorInstancia.o \
						$(OBJ_DIR)/Algoritmos/AlgoritmoMergeSort.o \
						$(OBJ_DIR)/Algoritmos/AlgoritmoQuickSort.o \
						$(OBJ_DIR)/Instancias/InstanciaMergeSort.o \
						$(OBJ_DIR)/Instancias/InstanciaQuickSort.o \
						$(OBJ_DIR)/Soluciones/SolucionMergeSort.o \
						$(OBJ_DIR)/Soluciones/SolucionQuickSort.o 

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJ_FILES) $(MAIN_SRC)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJ_FILES) $(MAIN_SRC) -o $(EXEC)

# 1. Regla para archivos en el directorio raíz de fuentes
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# 2. Regla para archivos en Algoritmos
$(OBJ_DIR)/Algoritmos/%.o: $(SRC_DIR)/Algoritmos/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# 3. Regla para archivos en Soluciones
$(OBJ_DIR)/Soluciones/%.o: $(SRC_DIR)/Soluciones/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# 4. Regla para archivos en Instancias
$(OBJ_DIR)/Instancias/%.o: $(SRC_DIR)/Instancias/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Limpiar los archivos objeto
clean:
	rm -f $(OBJ_FILES)

# Limpiar todo
fclean: clean
	rm -f $(EXEC)

# Recompilar todo
re: fclean all

