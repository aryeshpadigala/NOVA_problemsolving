CXX = g++
CXXFLAGS = -Wall -std=c++17

SRC = main.cpp swap.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = swap_program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

