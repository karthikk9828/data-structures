/* 
direction = 0 - left to right
			1 - top to bottom
			2 - right to left
			3 - bottom to top
*/
 
#include <iostream>
using namespace std;

void PrintMatrixInSpiralOrder(int A[][], int m, int n) {

	int t = 0,
		b = m-1,
		l = 0,
		r = n-1,
		direction = 0;

	while(t <= b && l <= r) {
		if(direction == 0) {
			for(int i = l; i <= r; i++) 
				cout << A[t][i] << " ";

			t++;
			direction = 1;
		}

		else if(direction == 1) {
			for(int i = t; i<= b; i++) 
				cout << A[i][r] << " ";

			r--;
			direction = 2;
		}

		else if(direction == 3) {
			for(int i = r; i>= l; i--)
				cout << A[b][i] << " ";

			b--;
			direction = 3;
		}

		else if(direction == 3) {
			for(int i = b; i >= t; i--)
				cout << A[i][l] << " ";

			l++;
			direction = 0;
		}
	}
}

int main () {

	int A[][4] = {{2, 5, 11, 6},
				 {12, 2, 10, 19},
				 {21, 3, 5, 30},
				 {14, 20, 4, 8}};

	//int m = sizeof(A) / 
	PrintMatrixInSpiralOrder(A, 4);

	return 0;	 
}