BST: insertSmallest.o main.o node.h
	g++ insertSmallest.o main.o -o BST
insertSmallest.o: insertSmallest.cpp node.h
	g++ -c insertSmallest.cpp
main.o: main.cpp node.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm BST
run: BST
	./BST
