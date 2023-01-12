
#include <iostream>
#include <list>
#include <cstring>
#include "hashtable.h"
using namespace std;

int main() {

	//Creating the Hash Table object 
	HashTable myHashTable;

	int quest;

	//Generating 1000 random numbers between 10 and 99
	int  n = 0;

	for (float i = 0; i < 1000; i++) {

		int rando = (rand() % 90) + 10;

		//Calling the method addIndex 
		//Adding random number to the method addIndex 
		myHashTable.addIndex(rando, rando);

		n += 1;

	}
	//printing the sum of number that were generated 
	cout << n << " numbers were generated" << endl;

	//Calling the method prinTtable 
	myHashTable.printTable();

	//Asking the user to input a key 
	cout << "Choose a key to display the entries" << endl;
	cin >> quest;

	//Calling the method searchIndex to print all the value of the key inputed 
	myHashTable.searchIndex(quest);

}
