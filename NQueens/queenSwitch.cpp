#include<iostream>
#include<stack>
#include<vector>
#include"position.h"
using namespace std;

//This is the main function 
void printAllQueen() {

	//creating the stack and defining some variables and booleans 
	stack<struct position>queenStack;
	int row, col, ch, num;
	bool keepGoing = true, ff = true;


	//Taking user imput
	cout << "Enter the number of Queens:\nBoard must have at least 4 Queens " << endl;
	cin >> num;

	//Creating the vector 
	vector<vector<int>> board(num, vector<int>(num));

	//creating the board graphics and making the fisrt location for the queen 
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			board[i][j] = 0;
		}
	}

	board[0][0] = 1;
	row = 0, col = 0, ch = 0;

	queenStack.push(position(row, col));

	//This loop checks for confilics and deal with row tracking 
	//Add queens into the board, if the board is filled, it stops the prigram 
	//Otherwise, it add new column and rows

	while (keepGoing) {
		if (nQueenMain(row, col, num, board) && ff) {
			ch++;
			if (ch == num) {
				keepGoing = false;
			}
			else {
				row++;
				col = 0;
				board[row][col] = 1;
				queenStack.push(position(row, col));
			}
		}
		else if (switchQueen(col + 1, num - 1)) {
			board[row][col] = 0;

			queenStack.pop();
			col++;

			board[row][col] = 1;

			queenStack.push(position(row, col));
			ff = true;
		}
		else {
			ch--;

			board[row][col] = 0;
			queenStack.pop();

			col = queenStack.top().col;
			row = queenStack.top().row;
			ff = false;
		}
	}


	print(board, num);

}
