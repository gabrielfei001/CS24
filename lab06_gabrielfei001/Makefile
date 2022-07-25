#Makefile
CXX_FLAG = --std=c++11 -g

examheap: examheap.o heap.o
	g++ $(CXX_FLAG) -o examheap examheap.o heap.o

examheap.o: heap.h examheap.cpp
	g++ -c $(CXX_FLAG) examheap.cpp

heap.o: heap.h heap.cpp
	g++ -c $(CXX_FLAG) heap.cpp

clean: rm -f examheap *.o