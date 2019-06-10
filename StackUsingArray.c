#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) {
	if(top == MAX - 1) {
		printf("Error: Stack is full\n");
		return;
	}
	stack[++top] = x;
}

// pop function doesnot return the element popped
void pop() {
	if(top == -1) {
		printf("Error: Stack is Empty\n");
		return;
	}
	top--;
}

int Top() {
	return stack[top];
}

bool isEmpty() {
	if(top == -1)
		return true;
	return false;
}

void print() {
	printf("Stack: ");
	for(int i=0; i<=top; i++)
		printf("%d  ", stack[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	push(2);  print();
	push(5);  print();
	push(10);  print();
	pop();  print();
	push(12);  print();

	return 0;
}