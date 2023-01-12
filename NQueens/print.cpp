#include<iostream>
#include<stack>
#include<vector>
#include"position.h"
using namespace std;

//This function makes the queen shifting column 
//This function takes 2 arguments 
//It returns true if the number of column is less than equal to the user input 
bool switchQueen(int q_col, int N) {
	if (q_col <= N){
		return  true;
	}
	else{
		return false;
	}
}

//This function print the board 
//this function takes two arguments 
void print(vector<vector<int>> board, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}cout << endl;
	}
}

//This function check for conflicts between queens 
//This functions takes as arguments the row, the column. the number of queens and the vector used 
bool nQueenMain(int row, int col, int num, vector<vector<int>>bVector) {

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (bVector[i][j] == 1) {
				if (row == i && col == j) {
					return true;
				}
				else if (col == j || (abs(col - j) == 1 && abs(row - i) == 1) || (abs(col - j) == abs(row - i))) {
					return false;
				}
			}
		}
	}
}
