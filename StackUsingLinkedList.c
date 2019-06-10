#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node* next;
};

struct Node* top;   // gloabal variable

void push(int x) {

	struct Node* temp = (Node*) malloc (sizeof(struct Node));

	temp -> data = x;
	temp -> next = top;
	top = temp;
}

void pop() {
	struct Node* temp;

	if(top == NULL) {
		return;
	}
	temp = top;
	top = top -> next;
	free(temp);
}

void print() {

	struct Node* temp = top;

	printf("List is: ");

	while(temp != NULL) {
		printf("%d  ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
int main(int argc, char const *argv[]) {
	
	push(2);  	print();
	push(5);  	print();
	push(10);   print();
	pop();      print();
	push(12);   print();

	return 0;
}