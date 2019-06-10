#include<iostream>
using namespace std;

int getMin(int A[], int start, int end) {

	int min = -1;
	for(int i=start; i<end; i++) {
		if(end == 0)
			return min;
		else if(A[i] < A[end])
			min = A[i];
	}
	return min;
}

int MinimumValue(int A[], int n) {
	int min = A[0];
	for(int i=0; i<n; i++) {
		if(A[i] < min)
			min = A[i];
	}
	return min;
}

void SmallerOnLeft(int A[], int n, int res[]) {

	for(int i=0; i<n;i++) {
		res[i] = getMin(A, 0, i);
	}
}

void SmallerOnLeft2(int A[], int n, int res[]) {

	int min = A[0];

	res[0] = -1; // always there will be no smaller element to the left of first element

	for(int i=1; i<n; i++) {
		if(min < A[i])
			res[i] = min;
		else if(A[i] < min) {
			min = A[i];
			res[i] = min;
		}
		else {
			//min = -1;
			res[i] = -1;
		}
	}
}

int main(int argc, char const *argv[]) {
	
	int A[] = {2, 3, 4, 5, 1},
		n = sizeof(A) / sizeof(A[0]),
		res[n];

	SmallerOnLeft(A, n, res);   // O(n^2) time

	for(int i=0; i<n; i++)
		cout << res[i] << " ";

	//SmallerOnLeft2(A, n, res);  // O(n) time

	//for(int i=0; i<n; i++)
	//	cout << res[i] << " ";

	return 0;
}