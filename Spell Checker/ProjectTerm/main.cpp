
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sys/time.h>
#include<unordered_map>
#include <cstddef>
#include "hashTable.h"
#include "timeInterval.h"
#include "map.cpp"

using namespace std;

int main() {
	//	bool buildHash = true; 
	bool keepGoing = true;
	unordered_map<string, string> hashtable1;
	unordered_map<string, string> hashtable2;
	ifstream inFile, file;
	inFile.open("Dictionary.txt");
	file.open("Dictionary.txt");
	string item;
	int input;
	char choice;
	string userWord;

	HashTable h(26);
	TimeInterval t;

	while (getline(inFile, item)) {
		//		if (inFile.eof()) {
		//			buildHash = false;
		//		}
		//		else {
		char firstLetter = tolower(item.at(0));
		int slot = h.hashFunction(firstLetter);
		h.inputValue(item, slot);
		//		}


	}
	inFile.close();

	while (keepGoing) {

		// Open the food.txt file

		// Read the file line by line
		string line;
		while (getline(file, line))
		{
			// Insert the food into the HashTables
			hashtable1.insert({ line.substr(0, 2), line });
			hashtable2.insert({ line.substr(0, 1), line });
		}
		// Close the file
		file.close();





		/*getline(inFile, item);
		char firstLetter = tolower(item.at(0));
		int slot = h.hashFunction(firstLetter);
		h.inputValue(item, slot);*/


		cout << "Term Project\n0. Quit\n1. Spell Checker" << endl;
		cin >> input;
		/*if (input == 1) {
			cout << "Choose a letter" << endl;
			cin >> choice;
			int slot = h.hashFunction(choice);
			h.printHashFunction(slot);
		}
		else if(input==2) {
			for (int i = 0; i < 26; i++) {
				h.printHashFunction(i);
			}
		}*/
		if (input == 0) {
			keepGoing = false;
			cout << "QUITTING____" << endl;
		}
		else if (input == 1) {
			cout << "Insert Word" << endl;
			cin >> userWord;
						char firstLetter = tolower(userWord.at(0));
			int slot = h.hashFunction(firstLetter);
			//	bool TF = h.searchHash(slot, userWord);

			t.start();
			// Ask the user for the food
			//cout << "Enter the food: ";
			//string food;
			//cin >> food;
			// Search the HashTable for the first two characters of the food
			string result1 = firstTwo(hashtable1, userWord);
			// If the food is not found, search the HashTable for the first character of the food
			if (result1 == "The Word does not exist")
			{
				string result2 = firstOne(hashtable2, userWord);
				//cout << result2 << endl;
				cout << "The word does not exists " << endl;
				cout << "Closest Word" << endl;
				cout << result2 << endl;

			}
			else
			{
				cout << "Closest Word" << endl;
				cout << result1 << endl;

			}









			//if (TF == true) {
			//	cout << "True" << endl;
			//	h.caseOne(slot, userWord);
			//	t.stop();
			//	cout << "Time: " << t.GetInterval() << " micro seconds" << endl;

		//	}
		//	else {

			string potentialSolution = h.caseTwo(slot, userWord, 0);
			//				if (potentialSolution != userWord) {
			h.caseOne(slot, potentialSolution);
			t.stop();
			cout << "Time: " << t.GetInterval() << " micro seconds" << endl;
			//	}
		//	}
		}
		else {
			cout << "INVALID ENTRY_____	\nTry Again(Chose between 0&1" << endl;
		}

	}
	//	return 0; 
		//inFile.close();
}













