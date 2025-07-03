CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic
SRC = main.cpp
HEADERS = MyContainer.hpp
TARGET = main
TEST = test
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

# Build the main demo program
main: $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run doctest tests 
test: test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST) test.cpp
	./$(TEST)

# Check for memory leaks
valgrind: $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -g -o $(TARGET) $(SRC)
	valgrind $(VALGRIND_FLAGS) ./$(TARGET)

valgrind_test: test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -g -o $(TEST) test.cpp
	valgrind $(VALGRIND_FLAGS) ./$(TEST)

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(TEST) *.o
