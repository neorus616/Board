CXX=clang++-5.0
CXXFLAGS=-std=c++11

all: Board.o

Board.o: Board.cpp Board.h Cell.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

Cell.o: Cell.cpp Cell.h
	$(CXX) $(CXXFLAGS) --compile Cell.cpp -o Cell.o

clean: 
	rm *.o a.out