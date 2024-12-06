# Nombre del ejecutable
EXECUTABLE = bin/snake_game

# Directorios
SRC_DIR = src
INCLUDE_DIR = include
ASSETS_DIR = assets
FTXUI_DIR = FTXUI

# Archivos fuente y objeto
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Bandera del compilador
CXX = g++
CXXFLAGS = -I$(INCLUDE_DIR) -I$(FTXUI_DIR)/include -std=c++17 -Wall -Wextra -pedantic

# Enlace con la biblioteca FTXUI
LDFLAGS = -L$(FTXUI_DIR)/build -lftxui-screen -lftxui-dom -lftxui-component -ltinfo -lpthread

# Generar el ejecutable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p bin
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)
	@echo "Ejecutable creado en: $(EXECUTABLE)"

# Compilar los archivos fuente en objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de archivos binarios y objetos
clean:
	rm -f $(SRC_DIR)/*.o $(EXECUTABLE)
	@echo "Archivos compilados eliminados."

# Regla por defecto
all: $(EXECUTABLE)