#include<iostream>
#include<cstdlib>

using namespace std;

// O(n2) time
void LeadersInAnArray1(int A[], int n) {

	for(int i=0; i<n; i++) {
		int j;
		for(j=i+1; j<n; j++) {
			if(A[i] <= A[j])
				break;
		}
		if(j==n)
			cout << A[i] << " ";
	}

	cout << "\n\n";
}

//O(n) time
void LeadersInAnArray2(int A[], int n) {

	int max = A[n-1];
	cout << max << " ";

	for(int i = n-2; i >= 0; i--) {
		if(A[i] > max) {
			max = A[i];
			cout << max << " ";
		}
	}
}

int main() {

	int A[] = {16, 17, 4, 3, 5, 2};

	int n = (sizeof(A) / sizeof(A[0]));
	LeadersInAnArray1(A, n);  // O(n2) time
	LeadersInAnArray2(A, n);  // O(n) time

	return 0;
}