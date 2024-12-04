CXX       = g++
CXXFLAGS += -Wall -pedantic -Wextra
SRC       = src/
INCLUDE   = include/
BIN       = bin/
TOOL      = include/tools.h

all: $(patsubst $(SRC)%.cpp,$(BIN)%,$(wildcard $(SRC)*.cpp))

$(BIN)%: $(SRC)%.cpp $(INCLUDE)*.h
	$(CXX) $< $(TOOL) $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(PROGS)
