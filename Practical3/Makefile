# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g -fprofile-arcs -ftest-coverage
LDFLAGS = --coverage
LDLIBS = -lgcov

# Source files
SRCS = Infantry.cpp Cavalry.cpp Artillery.cpp Legion.cpp Ambush.cpp Flanking.cpp Fortification.cpp TacticalCommand.cpp main.cpp Direction.cpp
OBJS = $(SRCS:.cpp=.o)

# Headers
HEADERS = UnitComponent.h Infantry.h Cavalry.h Artillery.h CompositeUnit.h Legion.h Direction.h Cohort.h Century.h Ambush.h BattleStrategy.h Flanking.h Fortification.h TacticalCommand.h LegionUnit.h LegionFactory.h OpenField.h OpenFieldFactory.h Riverbank.h RiverbankFactory.h Woodland.h WoodlandFactory.h

# Executable name
TARGET = roman_battle_simulator

# Valgrind settings
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Default rule: compile the program
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

# Compile each .cpp file into .o file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Check for memory leaks with Valgrind
memcheck: $(TARGET)
	$(VALGRIND) ./$(TARGET)

# Run code coverage
coverage: $(TARGET)
	./$(TARGET)
	# Generate gcov reports
	gcov $(SRCS)
	# Install lcov if not already installed
	@sudo apt-get install -y lcov
	# Capture coverage data
	lcov --capture --directory . --output-file coverage.info
	# Generate HTML report
	genhtml coverage.info --output-directory coverage_report
	# Open the HTML report in the default browser
	xdg-open coverage_report/index.html || echo "Open coverage_report/index.html to view the coverage report"

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS) *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report

.PHONY: all run memcheck coverage clean
