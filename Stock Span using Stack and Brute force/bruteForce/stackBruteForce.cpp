#include<iostream>
#include<vector>

using namespace std;

//defining the max number for our arrays 
#define MAX 50

//This function will calculate the span 
//the fucntion takes 2 arguments, the user input for prices and the number of prices
void span(int stockSize, int priceArray[MAX]) {

	// the output array 
	int outputArray[stockSize];

	//printing the user prices input into an array 
	for (int i = 0; i < stockSize; i++) {
		cout << priceArray[i] << " ";
	}

	//The first character of the output array is equal to 1 
	for (int i = 0; i < stockSize; i++) {
		outputArray[i] = 1;

	//Loop for calculating the span of other character
		for (int j = i - 1; j >= 0; j--) {
			//Condition to increament the character of the array by one if the price is larger
			if (priceArray[i] >= priceArray[j]) {
				outputArray[i]++;
			}
			else {
				break;
			}
		}
	}
	cout << endl;
	//Printing the result as an array 
	for (int i = 0; i < stockSize; i++) {
		cout << outputArray[i] << " ";
	}

}

//Main Function 

int main() {
	//creating variables and arrays 
	int price[MAX], output[MAX], stock_size;
	
	//Taking the user input for the number of dyas (stock size)
	cout << "Enter the number of days " << endl;
	cin >> stock_size;

	//Taking the user input for the prices 
	for (int i = 0; i < stock_size; i++) {

		cout << "Enter the price of stock at day " << i + 1 << endl; ;
		cin >> price[i];

	}

	//Calling back the function
	span(stock_size, price);
}
