#ifndef POSITION_H_EXISTS
#define POSITION_H_EXISTS

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Creating the struct position 

struct position {

	//declaring variables, vectors and functions 
	int row, col;
	position(int row, int col) : row(row), col(col) {}
	vector<vector<int>>myVector;
};

//declaring functions to be used in other files 
bool nQueenMain(int row, int col, int num, vector<vector<int>>);
bool switchQueen(int col, int num);
void print(vector<vector<int>>, int num);
void printAllQueen();

#endif 
