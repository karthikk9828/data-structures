#include <iostream>
using namespace std;

int BinarySearch(int A[], int n, int ele) {

    int low = 0, high = n-1, mid;

    while(low <= high) {

        mid = low + (high-low) / 2;

        if(ele == A[mid])
            return A[mid];
        else if (ele < A[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

void PairWithGivenSum(int A[], int n, int sum) {

	int next, notFound = 0;
	for(int i=0; i<n; i++) {
		next = BinarySearch(A, n, sum - A[i]);
		//cout << next << " ";
		if(next != -1 && next != A[i]) {
			cout << A[i] << " "<< next << " " << sum << "\n";
		}
		else
			notFound = 1;
	}
	//if(notFound == 1) 
	//	cout << -1;
}

int main(int argc, char const *argv[]) {

	int A[] = {1, 2, 3, 4, 5, 6, 7},
		sum = 8,
		n = sizeof(A) / sizeof(A[0]);

	PairWithGivenSum(A, n, sum);
	return 0;
}