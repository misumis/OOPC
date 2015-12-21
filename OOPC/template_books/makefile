all: testbook

testbook: book.o map_template.o testbook.o
	g++ -Wall -pedantic $^ -o $@
book.o: book.cpp book.h
	g++ -g3 -c -Wall -pedantic $< -o $@
clean:
	rm testbook.o testbook book.o
