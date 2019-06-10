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

struct Node* Reverse(struct  Node* head) {

	struct Node *current, *prev, *next;
	current = head;
	prev = NULL;

	while(current != NULL) {
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	} 
	head = prev;

	return head;

}

void Print(Node *head) {

	printf("List is: ");

	while(head != NULL) {
		printf("%d  ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

int main() {

	struct Node* head = NULL; // local variable
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);

	Print(head);
	head = Reverse(head);
	Print(head);

	return 0;

}