all: dfa

dfa: main.o dfa.o
	g++ -o dfa main.o dfa.o

main.o: main.cpp DFA.hpp
	g++ -g -c main.cpp -ansi -std=c++0x

dfa.o: DFA.cpp DFA.hpp
	g++ -g -c DFA.cpp -ansi -std=c++0x

clean:
	rm *.o dfa
