CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Board.o Cell.o
	cat main.cpp

Board.o: Board.cpp Board.h Cell.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o
	cat main.cpp

Cell.o: Cell.cpp Cell.h
	$(CXX) $(CXXFLAGS) --compile Cell.cpp -o Cell.o
	cat main.cpp

clean: 
	rm *.o a.out
	cat main.cpp
