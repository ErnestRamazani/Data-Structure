#include <iostream>
#include <list>
#include <cstring>
#include "hashtable.h"
using namespace std;


/*
Method for the hashFusnction
This method will print all the first character of the Key from the generated numbers 
This method takes one parameters  */

int HashTable::hashFunction(int key) {

	while (key >= hashTable)
	{
		key /= hashTable;
	}
	
	return key;

}
/*
Method for addIndex
This method will be adding element in the Hash table 
This method takes 2 parameters, one is the Key and the other is the value added to the key*/

void HashTable::addIndex(int key, int value) {

	//assigning the value to the key 
	int keyValue = hashFunction(key);

	//c is the iterator to look for if the key exists or not 
	auto& c = linkedListTable[keyValue];
	auto searchC = begin(c);
	bool keyExists = false;

    //loop for adding the value to the linked list 
	for (; searchC != end(c); searchC++) {
		if (searchC->first == key) {
			keyExists = true;

			//Replacing the value 
			searchC->second = value;

			break;
		}
	}
	
	//Pushing the key value back in the linkedList if it does not exists
	if (!keyExists) {
		c.emplace_back(key, value);
	}
	return;
}

/*
Method for deleteIndex
This method will be deleting element in the Hash table
This method takes one parameter which is the key*/
void HashTable::deleteIndex(int key) {

	//assigning the value to the key 
	int keyValue = hashFunction(key);

	//c is the iterator to look for if the key exists or not 
	auto& c = linkedListTable[keyValue];
	auto searchC = begin(c);
	bool keyExists = false;

	//loop for deleting the value to the linked list 
	for (; searchC != end(c); searchC++) {
		if (searchC->first == key) {
			keyExists = true;
			searchC = c.erase(searchC);
			break;
		}
	}
	//If the key does not exist, print item not found
	if (!keyExists) {
		cout << "Item not found" << endl;
	}
	return;
}

/*
Method for searchIndex 
This method will be searching the key and return all its values 
This method takes one parameter which is the key*/
int  HashTable::searchIndex(int key) {
	for (int i{}; i < hashTable; i++) {
		if (linkedListTable[i].size() == 0) continue;
		auto searchC = linkedListTable[i].begin();
		for (; searchC != linkedListTable[i].end(); searchC++) {

			cout << "Value ---> " << searchC->second << endl;

		}
		return key;

	}return 0; 
}
	

/*
Method for printTable
This method will be printing the table with the key and their values 
This method does not take parameters*/

void HashTable::printTable() {
	for (int i{}; i < hashTable; i++) {
		if (linkedListTable[i].size() == 0) continue;
		auto searchC = linkedListTable[i].begin();
		for (; searchC != linkedListTable[i].end(); searchC++) {
			
			cout << "Key: " << i << "	Value ---> " << searchC->second << endl;

		}cout << endl;
	}
	return;
}

