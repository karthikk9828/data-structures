


//##################################################################################################################


#include<iostream>
using namespace std;

class Stack {
	int mainTop = -1, supportTop = -1;
	int mainStack[30], supportStack[30]; 

public:

	void push(int item) {
		mainStack[++mainTop] = item;

		if( (mainTop == -1 && supportTop == -1) || (item < supportStack[supportTop]))
			supportStack[++supportTop] = item;



		/*if(mainTop == -1 && supportTop == -1)
			supportStack[++supportTop] = item;
		else if(item < supportStack[supportTop])
			supportStack[++supportTop] = item; */
	}

	void pop() {

		int ele = mainStack[mainTop--];

		if(ele == supportStack[supportTop])
			supportStack[supportTop--];
	}

	int GetMinFromStack() {
		return supportStack[supportTop];
	}
};

int main() {

	Stack s;

	s.push(50);
	s.push(40);
	s.push(35);
	cout << "Minimum value as of now: " << s.GetMinFromStack();
	s.push(55);
	s.push(37);
	s.push(20);
	cout << "\nMinimum value as of now: " << s.GetMinFromStack();
	s.pop();
	s.pop();
	cout << "\nMinimum value as of now: " << s.GetMinFromStack();
	s.push(60);
	s.pop();
	s.push(10);
	cout << "\nMinimum value as of now: " << s.GetMinFromStack();

	return 0;
}
