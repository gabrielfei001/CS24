testbst: intbst.o testbst.o
	g++ intbst.o testbst.o -o testbst

intbst.o: intbst.cpp intbst.h
	g++ intbst.cpp -c

testbst.o: testbst.cpp intbst.h
	g++ testbst.cpp -c

test_intbst: intbst.o test_intbst.o
	g++ intbst.o test_intbst.o -o test_intbst

test_intbst.o: test_intbst.cpp intbst.h
	g++ test_intbst.cpp -c
clean:
	rm intbst intbst.o testbst.o