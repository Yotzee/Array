all:
	g++ main.cpp -o main

run:
	g++ main.cpp -g -o main
	./main

debug:
	g++ main.cpp -g -o main