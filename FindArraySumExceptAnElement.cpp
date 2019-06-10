#include<iostream>
using namespace std;

int getSum(int A[], int start, int end) {
		int total = 0;
		for(int i=start; i<= end; i++)
			total = total + A[i];

		return total;
	}

// executes in O(n2) time
void FindArraySumExceptAnElement(int A[], int n) {

	int leftSum=0, rightSum=0, size = n;
	int sum[size];

	for(int i=0; i<n; i++) {
		leftSum = getSum(A, 0, i-1);
		rightSum = getSum(A, i+1, n-1);

		sum[i] = leftSum + rightSum;
	}

	for(int i=0; i<n; i++) {
		cout << sum[i] << " ";
	}
}

// executes in O(n) time
void FindArraySumExceptAnElement2(int A[], int n) {

	int leftSum[n], rightSum[n], sum[n];

	leftSum[0] = 0;
	rightSum[n-1] = 0;

	for(int i=1; i<n; i++) {
		leftSum[i] = leftSum[i-1] + A[i-1];
	}

	for(int i=n-2; i>=0; i--) {
		rightSum[i] = rightSum[i+1] + A[i+1];
	}

	for(int i=0; i<n; i++) {
		sum[i] = leftSum[i] + rightSum[i];
	}

	cout << "\n";

	for(int i=0; i<n; i++) {
		cout << sum[i] << " "; 
	}
}


int main(int argc, char const *argv[]) {

	int A[] = {4, 5, 7, 3, 10, 1};

	int n = (sizeof(A) / sizeof(A[0]));

    FindArraySumExceptAnElement(A, n);
    FindArraySumExceptAnElement2(A, n);

    //for(int i=0; i<n; i++)
    //	cout << A[i] << " ";

	return 0;
}