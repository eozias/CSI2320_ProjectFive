all: main

main: main.o CityClock.o
	g++ main.o CityClock.o -o main

main.o: main.cpp
	g++ -c main.cpp

Clock.o: CityClock.cpp
	g++ -c CityClock.cpp

clean:
	rm -f *.o main

run: main
	./main