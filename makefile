CXX = g++
CXXFLAGS = -g -Wall -std=c++20

TARGET = A4
OBJECTS = A4.o

# Build all targets
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files
A4.o: A4.cpp dsexceptions.h BinarySearchTree.h RedBlackTree.h Treap.h UniformRandom.h
	$(CXX) $(CXXFLAGS) -c A4.cpp

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET)