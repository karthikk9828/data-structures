#include <iostream>
using namespace std;

// returns an array
void FindIntersectionofArrays(int arr1[], int arr2[], int arr3[]) {

	int top = -1,
		result[10] = {0};

	// assume arrays are of equal size => n=5
	int n = sizeof(arr1) / sizeof(arr1[0]);
	
	int i=0, j=0, k=0;
	for(i=0; i < n; i++) {
		if(arr1[i] == arr2[j]) {
			result[++top] = arr1[i];
		} 

		else if (arr1[i] < arr2[j]) {
			i++;
		}

		else if(arr2[j] < arr3[k]) {
			j++;
		}

		else
			k++;
	}

	cout << "\nIntersection is: ";

	for(int i=0; i<5; i++) {
		cout << result[i] << " ";
	}

	//return result;
}

int main() {
	int arr1[] = {2, 6, 9, 11, 13, 17};
	int arr2[] = {3, 6, 7, 10, 13, 18};
	int arr3[] = {4, 5, 6, 9, 11, 13};

	//int result[10] = {0};

	FindIntersectionofArrays(arr1, arr2, arr3);

	//cout << "\nIntersection is: ";

	//for(int i=0; i<5; i++) {
	//	cout << result[i] << " ";
	//}

}