HashTable: hashtable.o main.o
	g++ hashtable.o main.o -o HashTable
hashtable.o: hashtable.cpp hashtable.h
	g++ -c hashtable.cpp 
main.o: main.cpp hashtable.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm HashTable
run: HashTable
	./HashTable
