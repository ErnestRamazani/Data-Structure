
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include <sys/time.h>
#include<unordered_map>
#include <cstddef>


using namespace std;

/*struct timeval{
long    tv_sec;         // seconds
long    tv_usec;        // microseconds
};
*/
class TimeInterval {
public:
	timeval start_time;
	timeval end_time;
public:
	TimeInterval();
	void start();
	void stop();
	float GetInterval();
};
TimeInterval::TimeInterval() {}
void TimeInterval::start()
{
	gettimeofday(&this->start_time, NULL);
}
void TimeInterval::stop()
{
	gettimeofday(&this->end_time, NULL);
}
float TimeInterval::GetInterval()
{
	float t = (float)(end_time.tv_sec - start_time.tv_sec) * 1000000.0 + (float)
		(end_time.tv_usec - start_time.tv_usec); // in micro-sec
		// t = t / 1000000.0 // in sec
	return t;
}

char alpha[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' }; 

string firstTwo(unordered_map<string, string>& hashtable, string myWord)
{
	string key = myWord.substr(0, 2);
	if (hashtable.find(key) == hashtable.end())
	{
		return "The Word does not exist";
	}
	else
	{
		return hashtable[key];
	}
}

string firstOne(unordered_map<string, string>& hashtable, string myWord)
{
	string key = myWord.substr(0, 1);
	if (hashtable.find(key) == hashtable.end())
	{
		return "The Word does not exist";
	}
	else
	{
		return hashtable[key];
	}
}

class HashTable {
	list<string>* myHashTable;
public:
	bool searchKey(int valN, string word);
	void oneChar(int valN, string word);
	string twoChar(int valN, string word, int maxi);
	int valN;
	HashTable(int myNu);
	void input(string input, int valN);
	int hashFunction(char input);
	
	

};

HashTable::HashTable(int desiredNum) {
	this->valN = desiredNum;
	myHashTable = new list<string>[valN];
}

void HashTable::input(string desiredInput, int slot) {
	myHashTable[slot].push_back(desiredInput);
}


int HashTable::hashFunction(char input) {
	for (int i = 0; i <= 26; i++) {
		char letter = alpha[i];
		if (letter == input) {
			return i;

		}
	} return 0;
}

bool HashTable::searchKey(int slot, string userWord) {
	for (string value : myHashTable[slot]) {
		if (value == userWord) {
			return true;
			break;
		}
	}return false;
}

void HashTable::oneChar(int slot, string userWord) {
	string word = userWord.substr(0, 2);
	for (string value : myHashTable[slot]) {
		string wordTwo = value.substr(0, 2);
		if (word == wordTwo) {
			cout << value << endl;
		}
	}

}

string HashTable::twoChar(int valN, string myword, int maxi) {
	string highest;
	int correct;

	for (string value : myHashTable[valN]) {
		int suggestWordLenght = value.length();
		int userWordLength = myword.length();
		int length;

		if (userWordLength >= suggestWordLenght) {
			length = suggestWordLenght;
		}
		if (suggestWordLenght >= userWordLength) {
			length = userWordLength;
		}
		

		for (int i = 1; i <= suggestWordLenght-1||i<=userWordLength - 1; i++) {
			char userLetter = myword.at(i);
			char suggestLetter = myword.at(i);

			
		}
		for (int j = 1; j <= suggestWordLenght  || j <= userWordLength ; j++) {
			char userLetter = myword.at(userWordLength - j);
			char suggestLetter = value.at(suggestWordLenght - j);
			
		}
		for (int k = 1; k <= userWordLength - 1; k++) {
			for (int l = 1; l <= suggestWordLenght - 1; l++) {
				char userLetter = myword.at(k);
				char suggestLetter = value.at(l);

				
			}
		}
		
			highest = value;
		
		
		maxi = 0;
	}
	
		cout << "Is your word: " << highest << " ?\nYes=1\nNo=0" << endl;
		cin >> correct;
		if (correct == 0) {
			cout << "\nSimilar Words" << endl;
			return highest;
		}
		else if (correct == 1) {
			cout << "Your word --> " << highest << endl;;
		}
	
	return myword;
}

int main() {
	
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
		
		char firstLetter = tolower(item.at(0));
		int slot = h.hashFunction(firstLetter);
		h.inputValue(item, slot);
	}
	inFile.close();

	while (keepGoing) {

		string line;
		while (getline(file, line))
		{
			
			hashtable1.insert({ line.substr(0, 2), line });
			hashtable2.insert({ line.substr(0, 1), line });
		}

		file.close();

		cout << "Term Project\n0. Quit\n1. Spell Checker" << endl;
		cin >> input;
		
		if (input == 0) {
			keepGoing = false;
			cout << "QUITTING____" << endl;
		}
		else if (input == 1) {
			cout << "Insert Word" << endl;
			cin >> userWord;
			char firstLetter = tolower(userWord.at(0));
			int slot = h.hashFunction(firstLetter);
			

			t.start();
			
			string result1 = firstTwo(hashtable1, userWord);
			
			if (result1 == "The Word does not exist")
			{
				string result2 = firstOne(hashtable2, userWord);
				
				cout << "The word does not exists " << endl;
				cout << "Closest Word" << endl;
				cout << result2 << endl;

			}
			else
			{
				cout << "Closest Word" << endl;
				cout << result1 << endl;

			}

			string potentialSolution = h.caseTwo(slot, userWord, 0);
						
			h.caseOne(slot, potentialSolution);
			t.stop();
			cout << "Time: " << t.GetInterval() << " micro seconds" << endl;
		
		}
		else {
			cout << "INVALID ENTRY_____	\nTry Again(Chose between 0&1" << endl;
		}

	}

}













