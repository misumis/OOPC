all: testmap

testmap: employee.o map_template.h testmap.o 
	g++ -Wall -pedantic $^ -o $@
testmap.o: testmap.cpp map_template.h
	g++ -g3 -c -Wall -pedantic $< -o $@
employee.o: employee.cpp employee.h 
	g++ -g3 -c -Wall -pedantic $< -o $@
clean:
	rm employee.o testmap.o testmap
