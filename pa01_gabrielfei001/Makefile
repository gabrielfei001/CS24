#Makefile
CXX_FLAG = --std=c++11 -g

all: testcards game

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

game: cards.o main.o
	g++ $(CXX_FLAG) -o game cards.o main.o

testcards.o: testcards.cpp testcards.h cards.h
	g++ -c $(CXX_FLAG) testcards.cpp

cards.o: cards.cpp cards.h
	g++ -c $(CXX_FLAG) cards.cpp

main.o: main.cpp cards.h
	g++ -c $(CXX_FLAG) main.cpp

clean: rm -f testcards game *.o


