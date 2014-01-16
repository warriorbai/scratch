run: case.o testbench.o
	g++ case.o testbench.o -o run
case.o: case.cxx
	g++ -c case.cxx
testbench.o: testbench.cxx common_header.h
	g++ -c testbench.cxx

clean:
	rm *.o -rf
	rm run -f
