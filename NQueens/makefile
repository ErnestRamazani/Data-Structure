NQueens: print.o queenSwitch.o main.o position.h
	g++ print.o queenSwitch.o main.o -o NQueens
print.o: print.cpp position.h
	g++ -c print.cpp
queenSwitch.o: queenSwitch.cpp position.h
	g++ -c queenSwitch.cpp
main.o: main.cpp position.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm NQueens
run: NQueens
	./NQueens