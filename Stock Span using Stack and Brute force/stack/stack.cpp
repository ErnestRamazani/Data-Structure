
#include <iostream>
#include <stack>
using namespace std;


//defining the max number for our arrays 
#define MAX 50


//This function will calculate the span 
//the fucntion takes 3 arguments, the user input for prices, the number of prices and the output array
void span(int priceArray[], int stockSize, int outputArray[]){

    //cretaing our stack 
    stack<int> myStack;
    myStack.push(0);

    //Making our first array character = 0 
    outputArray[0] = 1;

    //Loop for calculating the span
    for (int i = 1; i < stockSize; i++) {

        // Searching if the price of the next elelment is higher 
        //If the stack is not empty and the top is less or equal to the price, take out the top character of the satck 
        while (!myStack.empty() && priceArray[myStack.top()] <= priceArray[i])
            myStack.pop();

        //if the stack is empty, the add +1 to the result array 
        if (myStack.empty()) {
            outputArray[i] = i + 1;

        }
        
        //else, substract the top of the stack from the index
        else {
            outputArray[i] = i - myStack.top();
        }



        //pushing the index to the array
        myStack.push(i);
    }
}

//this function will print the result as an array
void resultArray(int arr[], int stockSize){
    for (int i = 0; i < stockSize; i++)
        cout << arr[i] << " ";
}

//Main funtion 
int main()
{
    //declaring variable and array, 
    int price[MAX], stock_size;

    //taking user input for stock size
    cout << "Enter the number of days " << endl;
    cin >> stock_size;
    int outputArray[stock_size];

    //taking user input for stock prices
    for (int i = 0; i < stock_size; i++) {
        cout << "Enter the price of stock at day " << i + 1 << endl; ;
        cin >> price[i];

    }

    //calling back function span
    span(price, stock_size, outputArray);

    //calling back duntion resultArray
    resultArray(outputArray, stock_size);

    return 0;
}