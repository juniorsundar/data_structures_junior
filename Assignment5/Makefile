CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address -Wall -Werror -Wextra -pedantic

SRC = ProducerConsumer.cpp ProducerConsumerDriver.cpp
OBJ = $(SRC:.cc=.o)
EXEC = ProducerConsumer.exe

# SRC = RPNCalculator.cpp RPNCalculatorDriver.cpp
# OBJ = $(SRC:.cc=.o)
# EXEC = Calculator.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)