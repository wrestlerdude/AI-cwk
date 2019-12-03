CC = g++
CLFLAGS = -c -O3 -Wall
CLFILE1 = Node.cpp -o node.o
CLFILE2 = Edge.cpp -o edge.o
CCFLAGS = -shared -o ../libgraph.so node.o edge.o

build: library clean

clean:
	del *.o

library:
	$(CC) $(CLFLAGS) $(CLFILE1)
	$(CC) $(CLFLAGS) $(CLFILE2)
	$(CC) $(CCFLAGS)