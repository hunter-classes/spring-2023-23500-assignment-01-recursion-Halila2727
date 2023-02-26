main: queens.o
	g++ -o main queens.o

knights.o: queens.cpp
	g++ -c queens.cpp