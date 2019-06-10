
#include<iostream>

using namespace std;

int FindMissingNumber(int A[], int n) {

	int total = ((n+1)*(n+2) / 2);

	for(int i=0; i<n; i++) {
		total = total - A[i];
	}

	return total;
}

int main() {

	int A[] = { 1, 3, 2, 5, 6, 8, 4 };
	int n = (sizeof(A)/sizeof(A[0]));

	int missingNumber = FindMissingNumber(A, n);

	if(missingNumber != -1)
		cout << "Missing number is: " << missingNumber;
	else
		cout << "No Missing number";

	return 0;
}