#include<iostream>
using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int NextNonZero(int A[], int i, int n) {
	int j;
	//while(A[i] == 0) {
	//	i++;
	//}

	for(int j=i; j<n; j++) {
		if(A[j] != 0)
			break;
	}
	return j;
}

void SegregateNonZerosInPlace(int A[], int n) {

	int i, j;

	for(i=0; i<n; i++) {
		j = NextNonZero(A, i, n);
		//if(A[i] == 0)
		//	j = ++i;
	if(j < n)
		swap(&A[i], &A[j]);
	}

	for(int i=0; i<n; i++) 
		cout << A[i] << " ";
}

int main(int argc, char const *argv[]) {

	int A[] = {0, 16, 17, 0, 4, 0, 0, 3, 5, 2, 0};

	int n = (sizeof(A) / sizeof(A[0]));
	SegregateNonZerosInPlace(A, n);

	//for(int i=0; i<n; i++) 
	//	cout << A[i] << " ";
	return 0;
}