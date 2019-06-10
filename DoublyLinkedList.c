#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;   // gloabal variable

struct  Node* GetNewNode(int x) {

	struct Node* temp = (Node*) malloc (sizeof(struct Node));

	temp -> data = x;
	temp -> next = NULL;
	temp -> prev = NULL;

	return temp;
}

void InsertAtBeginning(int x) {

	struct  Node* newNode = GetNewNode(x);

	// Insert node at the beginning
	if(head == NULL) {
		head = newNode;
		return;
	}

	head -> prev = newNode;
	newNode -> next = head;
	head = newNode;
}


void Print() {

	struct Node* temp = head;

	printf("Forward: ");

	while(temp != NULL) {
		printf("%d  ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

void ReversePrint() {
	
	struct Node* temp = head;

	if(temp == NULL)  // list is empty
		return;

	// going to the last node
	while(temp -> next != NULL) {
		temp = temp -> next;
	}

	// traversing backwards using "prev" pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d  ", temp -> data);
		temp = temp -> prev;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	head = NULL;  // empty list.
	InsertAtBeginning(2);  Print();  ReversePrint();
	InsertAtBeginning(4);  Print();  ReversePrint();
	InsertAtBeginning(6);  Print();  ReversePrint();
	return 0;
}