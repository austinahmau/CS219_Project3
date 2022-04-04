homework: main.o converter.o
	g++ main.o converter.o -o homework

main.o: main.cpp
	g++ -c main.cpp

converter.o: converter.h converter.cpp
	g++ -c converter.cpp
clean:
	rm *.o homework
