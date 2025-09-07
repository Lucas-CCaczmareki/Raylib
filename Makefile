# Compilador a ser usado
CC = gcc

# Nome do executável
EXECUTABLE = jogo

# Pasta dos arquivos fonte (.c)
SRC_DIR = src

# Pasta dos arquivos de cabeçalho (.h)
INCLUDE_DIR = include

# Pasta das bibliotecas (.a)
LIB_DIR = lib

# Flags do compilador: -Wall (mostra todos os warnings) e -I (onde achar os includes)
CFLAGS = -Wall -I$(INCLUDE_DIR) -g

# Flags do Linker: -L (onde achar as libs) e -l (quais libs usar)
LDFLAGS = -L$(LIB_DIR) -lraylib -lopengl32 -lgdi32 -lwinmm

# Pega todos os arquivos .c da pasta src
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Regra principal: compila o executável
all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE).exe $(CFLAGS) $(LDFLAGS)

# Regra para limpar os arquivos compilados
clean:
	rm -f $(EXECUTABLE).exe