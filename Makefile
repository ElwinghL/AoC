CXX       = g++
CXXFLAGS += -Wall -pedantic -Wextra
SRC       = src/
BIN       = bin/
TOOL      = include/tools.h

all: $(patsubst $(SRC)%.cpp,$(BIN)%,$(wildcard $(SRC)*.cpp))

$(BIN)%: $(SRC)%.cpp
	$(CXX) $< $(TOOL) $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(PROGS)
