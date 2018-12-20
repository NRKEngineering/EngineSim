
TARGET = EngineSim.exe

CXX := g++
LINKER := g++
CXXFLAGS := -std=c++11 -Wall -Wextra 

INC := -I include/ $(shell pkg-config --cflags glib-2.0 gtk+-3.0)
LIBS := $(shell pkg-config --libs glib-2.0 gtk+-3.0)
SRC := $(wildcard src/*.cpp) 
OBJ := $(patsubst %.cpp,%.o,$(SRC))

$(TARGET): $(OBJ)
	$(LINKER) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f src/*.o src/*.d $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

