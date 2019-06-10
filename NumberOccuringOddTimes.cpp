/*
program to find the number which is occuring odd number of times in an array
this program works only when there is one element which occurs odd number of times

we use XOR gate
*/

#include<iostream>

using namespace std;

int NumberOccuringOddTimes(int A[], int n) {

	int number = 0, i=0, j = n-1;

	for(int i=0; i<n; i++) {
		number = number ^ A[i];
	}

	return number; 
}

int main() {

	int arr[] = { 1, 2, 1, 2, 1, 1, 3, 1, 3 };
	int n = (sizeof(arr) / sizeof(arr[0]));
	cout << "Number occuring odd number of times is: " << NumberOccuringOddTimes(arr, n);
	
	return 0;
}