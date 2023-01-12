#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<unordered_map>

using namespace std; 


string firstTwo(unordered_map<string, string>& hashtable, string food)
{
	string key = food.substr(0, 2);
	if (hashtable.find(key) == hashtable.end())
	{
		return "The Word does not exist";
	}
	else
	{
		return hashtable[key];
	}
}
// This function takes the first character of the food as a key and returns the food
string firstOne(unordered_map<string, string>& hashtable, string food)
{
	string key = food.substr(0, 1);
	if (hashtable.find(key) == hashtable.end())
	{
		return "The Word does not exist";
	}
	else
	{
		return hashtable[key];
	}
}