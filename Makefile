CXX=g++
LD=g++

CXXFLAGS=-std=c++14 -Wall -Weffc++ -O3

all: main.cpp.o
	$(LD) -o app.exe main.cpp.o 
main.cpp.o:
	$(CXX) $(CXXFLAGS) -o main.cpp.o -c main.cpp
clean:
	rm -f *.o app.exe