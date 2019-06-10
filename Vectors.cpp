//#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	
	vector<int> A;//= {2, 13, 19, 8, 11, 5};

	cout << A[1] << "\n";   // 13

	sort(A.begin(), A.end());  // sorts array in O(log N) time

	//for(std::vector<int> iterator it = A.begin(); it != A.end(); ++it) {
	//	cout << *it << " ";
	//}

	A.push_back(30);  // 2, 5, 8, 11, 13, 19, 30
	A.push_back(31);  // 2, 5, 8, 11, 13, 19, 30, 31
	A.push_back(31);  // 2, 5, 8, 11, 13, 19, 30, 31, 31
	A.push_back(31);  // 2, 5, 8, 11, 13, 19, 30, 31, 31, 31
	A.push_back(31);  // 2, 5, 8, 11, 13, 19, 30, 31, 31, 31, 31
	A.push_back(31);  // 2, 5, 8, 11, 13, 19, 30, 31, 31, 31, 31, 31

	A.push_back(50);  // 2, 13, 19, 8, 11, 5, 30, 1, 31, 31, 31, 31, 50

	vector<int> :: iterator it1 = lower_bound(A.begin(), A.end(), 31); // 31 (first occurance)
	vector<int> :: iterator it2 = upper_bound(A.begin(), A.end(), 31); // 50

	cout << *it1 << " " << *it2 << endl;  // *it1 = 100   *it2 = 50
	cout << it2 - it2 << endl;          // it2 - it1 = 4  (count of 31)

	return 0;
}