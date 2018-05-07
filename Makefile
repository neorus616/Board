CXX=clang++-5.0
CXXFLAGS=-std=c++11

all: a.out
	./a.out

a.out: Cell.o Board.o main.o
	$(CXX) $(CXXFLAGS) Cell.o Board.o main.o

main.o: main.cpp Board.o
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o

Board.o: Board.cpp Board.h Cell.h
	$(CXX) $(CXXFLAGS) --compile Board.cpp -o Board.o

Cell.o: Cell.cpp Cell.h
	$(CXX) $(CXXFLAGS) --compile Cell.cpp -o Cell.o

clean: 
	rm *.o a.out