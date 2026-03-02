# Variables
CC = g++
CFLAGS = -Wall -std=c++11
OBJ_DIR = ImplementacionClases
INC_DIR = Clases
SRC_DIR = $(OBJ_DIR)
MAIN_SRC = main.cc
EXEC = Ejecutable

# Archivos objeto
OBJ_FILES = 

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJ_FILES) $(MAIN_SRC)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJ_FILES) $(MAIN_SRC) -o $(EXEC)

# 1. Regla para archivos en el directorio raíz de fuentes
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Limpiar los archivos objeto
clean:
	rm -f $(OBJ_FILES)

# Limpiar todo
fclean: clean
	rm -f $(EXEC)

# Recompilar todo
re: fclean all

