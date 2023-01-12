Dijkstra: dijk.o main.o
	g++ dijk.o main.o -o Dijkstra
dijk.o: dijk.cpp dijk.h
	g++ -c dijk.cpp
main.o: main.cpp dijk.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm Dijkstra
run: Dijkstra
	./Dijkstra