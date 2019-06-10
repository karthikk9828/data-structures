
// program to find all the pairs in an array whose sum is equal to given sum
// sort the array first using quicksort

#include<iostream>
using namespace std;

void swap(int *x, int *y) {

    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int start, int end) {

    int pivot = A[end], 
    	pIndex = start,
    	i;

    for (i=start; i<end; i++)
    {
        if(A[i] <= pivot)
        {
            swap(&A[i], &A[pIndex]);
            pIndex = pIndex + 1;
        }
    }
    swap(&A[pIndex], &A[end]);

    return pIndex;
}

void QuickSort(int A[], int start, int end) {

    int pIndex;
    if (start < end)
    {
        pIndex = partition(A, start, end);
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, end);
    }
}
 
void FindPairsWithSum(int A[], int n, int sum) {

	int low = 0, high = n-1;
	bool notFound = true;
	
	while(low < high) {
		
		if(A[low] + A[high] > sum) 
			high--;  

		else if(A[low] + A[high] < sum) 
			low++;
	
		else {
			cout << A[low] << " " << A[high] << " " << sum << "\n"; 
			low++;  // or high--
			notFound = false;
		}
	}

	if(notFound)
		cout << -1 << "\n";
}

int main() {
	
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8},
		n = (sizeof(A) / sizeof(A[0])),
		sum = 8;

	QuickSort(A, 0, n);
	FindPairsWithSum(A, n, sum);

	return 0;
}