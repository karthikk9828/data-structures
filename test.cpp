#include <iostream>
#include<vector>
#include <iterator>
using namespace std;

int main() {

	int n, num;

	vector<int> v;

	cout << "Enter size of the vector: ";
	cin >> n;

	cout << "Enter " << n << " elements\n";
	for(int i=0; i< n; i++) {
		cin >> num;
		v.push_back(num);
	}

	cout << "Vector elements are\n";
	for(int i=0; i<n; i++) 
		cout << v[i] << " ";

	return 0;
}