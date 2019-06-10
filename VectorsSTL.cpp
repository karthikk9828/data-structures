//#include "stdafx.h"
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

bool order(int x, int y) {
	return x > y;  // for descending order
	//return x < y // for ascending order
}

int main(int argc, char const *argv[]) {

	int x[] = {2, 13, 19, 8, 11, 5},
		n = sizeof(x) / sizeof(x[0]);
	
	// converting array to vector
	vector<int> A(x, x + n);//= {2, 13, 19, 8, 11, 5};

	//cout << A[1] << "\n";   // 13

	//sort(A.begin(), A.end());  // sorts array in O(log N) time

	//for(std::vector<int> iterator it = A.begin(); it != A.end(); ++it) {
	//	cout << *it << " ";
	//}

	A.push_back(30);  
	A.push_back(31);  
	A.push_back(4);   
	A.push_back(31);  
	A.push_back(14);  
	A.push_back(31);  // 2, 13, 19, 8, 11, 5, 30, 31, 4, 31, 14, 31

	A.push_back(50);  // 2, 13, 19, 8, 11, 5, 30, 1, 31, 31, 31, 31, 50

	//A.pop_back();    // 2, 13, 19, 8, 11, 5, 30, 1, 31, 31, 31, 31

	sort(A.begin(), A.end());  // sorts array in O(log N) time

	for(vector<int> :: iterator it = A.begin(); it != A.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	

	/*
	// using enhanced for loop, does not modify the original data as it is pass by value
	for(int x: A) {
		x++;
		cout << x;
	}

	// using enhanced for loop,  modifies the original data as it is pass by reference
	for(int &x: A) {
		x++;
		cout << x;
	}
	*/

	cout << endl << endl;

	// search for element using binary_search  -->  O(log N)
	cout << binary_search(A.begin(), A.end(), 8) << endl;
	cout << binary_search(A.begin(), A.end(), 100) << endl;

	cout << endl;

	vector<int> :: iterator it1 = lower_bound(A.begin(), A.end(), 31); // 31 (first occurance)
	vector<int> :: iterator it2 = upper_bound(A.begin(), A.end(), 31); // 50

	cout << *it1 << " " << *it2 << endl;  // *it1 = 100   *it2 = 50
	cout << it2 - it1 << endl;          // it2 - it1 = 4  (count of 31)

	cout << endl;
	//cout << "Size : " << A.size(); 
    //cout << "\nCapacity : " << A.capacity(); 
    //cout << "\nMax_Size : " << A.max_size(); 

    // sort vector in descending order
	sort(A.begin(), A.end(), order);

	for(vector<int> :: iterator it= A.begin(); it != A.end(); it++)
		cout << *it << " ";

	cout << endl;

	// deletes the vector from the memory
	A.clear();
	cout << A.size();

	return 0;
}