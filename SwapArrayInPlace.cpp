#include <iostream>
using namespace std;

void swap (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void SwapArrayInPlace(int A[], int n) {

	if(!A) {
		cout << "Invalid array";
	}

	int start = 0, end = n-1;

	while (start < end) {
		swap(&A[start], &A[end]);
		start++;
		end--;
	}
}

int main(int argc, char const *argv[]) {
	
	int A[] = { 1, 3, 2, 5, 6, 8, 4 },
		n = (sizeof(A)/sizeof(A[0]));

	SwapArrayInPlace(A, n);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
	return 0;
}