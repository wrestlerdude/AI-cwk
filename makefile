CC = g++
CCFLAGS = -Ofast -Wall -std=c++11 -o caveroute.exe main.cpp Graph.cpp Edge.cpp Node.cpp

clean:
	del *.exe

build:
	$(CC) $(CCFLAGS)