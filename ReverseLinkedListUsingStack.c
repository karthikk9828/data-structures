#include <stdio.h>
#include <stdlib.h>
#include<stack>

struct Node {

	int data;
	struct Node* next;
};

struct  Node* head;  // global variable

void Insert(int x) {

	Node* temp1 = (Node*) malloc (sizeof(struct Node));   // create a new node for the element 'x'

	temp1 -> data = x;
	temp1 -> next = NULL;

	if(head == NULL)
		head = temp1;

	else{
	Node* temp2 = head;   
	
	while(temp2 -> next != NULL)
		temp2 = temp2 -> next;
	temp2 -> next = temp1;
	}
}

void Reverse() {

	if(head == NULL)
		return;

	stack<struct Node*> S;
	Node* temp = head;

	while(temp != NULL) {
		S.push(temp);
		temp = temp -> next;
	}

	temp = S.pop();
	head = temp;
	S.pop();

	while(!S.empty()) {
		temp -> next = S.top();
		S.pop();
		temp = temp -> next;
	}
	temp -> next = NULL;
}

void Print() {

	printf("List is: ");

	while(head != NULL) {
		printf("%d  ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

int main() {

	Insert(2);
	Insert(4);
	Insert(6);
	Insert(8);

	Print();
	Reverse();
	Print();

	return 0;

}