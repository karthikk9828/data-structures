
#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node* next;
};

Node* Insert(Node* head, int x) {

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

	return head;
}

void Print(struct Node* p) {

	if(p == NULL)  // exit or base case
 		return;

 	printf("%d  ", p -> data);  // first print the value in the node
 	Print(p -> next);   // Recursive call
}

void PrintReversed(struct Node* p) {

	if(p == NULL)
		return;

	PrintReversed(p -> next);
	printf("%d  ", p -> data);
}

int main() {

	struct Node* head = NULL; // local variable
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);

	Print(head);
	printf("\n");
	PrintReversed(head);

	return 0;
}