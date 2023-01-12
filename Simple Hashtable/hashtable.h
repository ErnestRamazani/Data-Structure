#pragma once
#ifndef HASHTABLE_H_EXISTS
#define HASHTABLE_H_EXISTS
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

//Creating the class HashTable
class HashTable {
public:
	//Making the table constant so we wont modify it in future
	static const int hashTable = 10;

	//Creating the linked list 
	list<pair<int, int>> linkedListTable[hashTable];

	//Declaring method of the class that will be used 
	int hashFunction(int key);
	void addIndex(int key, int value);
	void deleteIndex(int key);
	int searchIndex(int key);
	void printTable();
};

#endif