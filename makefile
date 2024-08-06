# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = main.cpp Boatman.cpp BoatmanFactory.cpp Infantry.cpp InfantryFactory.cpp ShieldBearer.cpp ShieldBearerFactory.cpp CareTaker.cpp ConcreteMemento.cpp Soldiers.cpp SoldiersFactory.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Run the executable
run: $(EXEC)
	./$(EXEC)
