CC = g++
CCFLAGS = -Ofast -Wall -std=c++11 -o caveroute.exe main.cpp A_Star.cpp Graph.cpp Edge.cpp Node.cpp
CDFLAGS = -DDEBUG

clean:
	del *.exe

build:
	$(CC) $(CCFLAGS)

debug:
	$(CC) $(CDFLAGS) $(CCFLAGS)