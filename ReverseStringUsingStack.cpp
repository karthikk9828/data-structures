#include<iostream>
#include<string.h>
#include<stack>   // stack from Standard Tenplate Library

using namespace std;

void ReverseStringUsingStack(char* C, int n) {

	stack<char> S;  // create a character stack using STL

	// loop for push
	for(int i=0; i<n; i++)
		S.push(C[i]);

	// loop for reverse and pop
	for(int i=0; i<n; i++) {
		C[i] = S.top();   // overwrite the character at index i
		S.pop();    // pop from stack
	}
} 

int main(int argc, char const *argv[])
{
	char C[50];
	cout << "Enter a string: ";
	cin >> C;
	//gets(C);

	ReverseStringUsingStack(C, strlen(C));
	cout << "\nOutput: " << C;
	return 0;
}