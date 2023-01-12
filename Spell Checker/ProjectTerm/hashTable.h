#ifndef HASHTABLE_H_EXISTS
#define HASHTABLE_H_EXISTS

#include<iostream>
#include<string>
#include<list>

using namespace std;

class HashTable {
	list<string>* myHashTable;
public:
	int valN;
	HashTable(int desirerdNum);
	void inputValue(string desiredInput, int slot);
	int hashFunction(char input);
	bool searchHash(int slot, string userWord);
	void caseOne(int slot, string userWord);
	string caseTwo(int slot, string userWord, int score);


};
char alpha[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
#endif; 