CXX       = g++
CXXFLAGS += -Wall -pedantic -Wextra
SRC       = src/
BIN       = bin/

all: $(patsubst $(SRC)%.cpp,$(BIN)%,$(wildcard $(SRC)*.cpp))

$(BIN)%: $(SRC)%.cpp
	$(CXX) $< $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(PROGS)
