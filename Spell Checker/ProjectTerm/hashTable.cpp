
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include"hashTable.h"


HashTable::HashTable(int desiredNum) {
	this->valN = desiredNum;
	myHashTable = new list<string>[valN];
}

void HashTable::inputValue(string desiredInput, int slot) {
	myHashTable[slot].push_back(desiredInput);
}
//
//void HashTable::printHashFunction(int desiredSlot) {
//	cout << alpha[desiredSlot] << " "; 
//	for (string value: table[desiredSlot]) {
//		cout << "--> " << value << " ";
//
//	}cout << endl; 
//
//}

int HashTable::hashFunction(char input) {
	for (int i = 0; i <= 26; i++) {
		char letter = alpha[i];
		if (letter == input) {
			return i;

		}
	} return 0;
}

bool HashTable::searchHash(int slot, string userWord) {
	for (string value : myHashTable[slot]) {
		if (value == userWord) {
			return true;
			break;
		}
	}return false;
}

void HashTable::caseOne(int slot, string userWord) {
	string word = userWord.substr(0, 2);
	for (string value : myHashTable[slot]) {
		string wordTwo = value.substr(0, 2);
		if (word == wordTwo) {
			cout << value << endl;
		}
	}

}

string HashTable::caseTwo(int slot, string userWord, int score) {
	string highest;
	int highScore = 0;
	int correct;

	for (string value : myHashTable[slot]) {
		int suggestWordLenght = value.length();
		int userWordLength = userWord.length();
		int length;

		if (userWordLength >= suggestWordLenght) {
			length = suggestWordLenght;
		}
		if (suggestWordLenght >= userWordLength) {
			length = userWordLength;
		}
		if (suggestWordLenght == userWordLength) {
			score++;
		}

		for (int i = 1; i <= length - 1; i++) {
			char userLetter = userWord.at(i);
			char suggestLetter = userWord.at(i);

			if (userLetter == suggestLetter) {
				score++;
			}
		}
		for (int j = 1; j <= length; j++) {
			char userLetter = userWord.at(userWordLength - j);
			char suggestLetter = value.at(suggestWordLenght - j);
			if (userLetter == suggestLetter) {
				score++;
			}
		}
		for (int k = 1; k <= userWordLength - 1; k++) {
			for (int l = 1; l <= suggestWordLenght - 1; l++) {
				char userLetter = userWord.at(k);
				char suggestLetter = value.at(l);

				if (userLetter == suggestLetter) {
					score++;
				}
			}
		}
		if (score > highScore) {
			highest = value;
			highScore = score;
		}
		score = 0;
	}
	if (highScore == 0) {
		cout << "False, No Word Ressemblence" << endl;

	}
	else {
		cout << "Did you mean: " << highest << " ?\nYes=1\nNo=0" << endl;
		cin >> correct;
		if (correct == 0) {
			cout << "\nSimilar Words" << endl;
			return highest;
		}
		else if (correct == 1) {
			cout << "Your word --> " << highest << endl;;
		}
	}
	return userWord;
}
