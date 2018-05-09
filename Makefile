CXX=clang++-5.0
CXXFLAGS=-std=c++14

all: Board.o Cell.o

Board.o: Board.cpp Board.h Cell.h
	cat main.cpp

Cell.o: Cell.cpp Cell.h
	$(CXX) $(CXXFLAGS) --compile Cell.cpp -o Cell.o

clean: 
	rm *.o a.out
	cat main.cpp
