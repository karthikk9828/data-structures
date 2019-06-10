
//  program to find minimum elelment from the stack in O(1) time

/*

#include<iostream>

using namespace std;

int stack1[30], stack2[30], top1 = -1, top2 = -1;

bool isEmpty(int stack[]) {
	return (top1 == -1 || top2 == -1);
}

void push(int x) {

	stack1[++top1] = x;

	if(stack1[top1] == NULL && stack2[top2] == NULL) {
		stack2[++top2] = x;
	}
	else if(x < stack2[top2]) {
		stack2[++top2] = x;
	}
}

void pop() {
	int ele = stack1[top1--], ele2;

	if(ele == stack2[top2])
		ele2 = stack2[top2--];
}

void display(int stack[]) {

}

int GetMinFromStack() {
	return stack2[top2];
}

int main() {
	push(50);
	push(40);
	push(35);
	cout << "Minimum value as of now: " << GetMinFromStack();
	push(55);
	push(37);
	push(20);
	cout << "\nMinimum value as of now: " << GetMinFromStack();
	pop();
	pop();
	cout << "\nMinimum value as of now: " << GetMinFromStack();
	push(60);
	pop();
	push(10);
	cout << "\nMinimum value as of now: " << GetMinFromStack();

	return 0;
}


*/