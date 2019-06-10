#include <iostream>
using namespace std;

void swap (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int ReverseArrayInPlace(int A[], int n) {

	if(!A) {
		return -1;
	}

	int start = 0, end = n-1;

	while (start < end) {
		swap(&A[start], &A[end]);
		start++;
		end--;
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	
	int A[] = { 1, 3, 2, 5, 6, 8, 4 },
		n = (sizeof(A)/sizeof(A[0]));

	int x = ReverseArrayInPlace(A, n);

	if(x != -1) {
	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
		}
	}

	else
		cout << "Invalid array!";
	return 0;
}