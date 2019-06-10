#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node* next;
};

struct Node* head;   // gloabal variable

void InsertAtBeginning(int x) {

	Node* temp = (Node*) malloc (sizeof(struct Node));

	temp -> data = x;
	temp -> next = NULL;

	// Insert node at the beginning
	if(head != NULL)
		temp -> next = head;
	head = temp;
}

void InsertAtEnd(int x) {

	Node* temp = (Node*) malloc (sizeof(struct Node));   // create a new node for the element 'x'

	temp -> data = x;
	temp -> next = NULL;

	if(head == NULL)
		head = temp;
	else {
		Node * temp1 = head;  // to traverse through the linked list to find the last element
		while(temp1 != NULL) {
			temp1 = temp1 -> next;
		}
		temp1  = temp;
	}
}

void InsertAtPosition(int x, int n) {

	Node* temp1 = (Node*) malloc (sizeof(struct Node));   // create a new node for the element 'x'

	temp1 -> data = x;
	temp1 -> next = NULL;

	if(n == 1)  // insert at 1st position
	{
		temp1 -> next = head;
		head = temp1;
		return;
	}

	Node* temp2 = head;   // to go to n-1 th position, we are already at head, so go to (n-2)th position
	for(int i=0; i< n-2; i++) {
		temp2 = temp2 -> next;
	}
	temp1 -> next = temp2 -> next;
	temp2 -> next = temp1;

}

void DeleteAtPosition(int n) {

	struct Node* temp1 = head;
	// delete first node
	if(n == 1) {
		head = temp1 -> next;
		free(temp1);
		return;
	}

	for(int i=0; i< n-2; i++) {
		temp1 = temp1 -> next;
	}

	// the node to be deleted is temp2
	struct Node* temp2 = temp1 -> next;

	// fix the link
	temp1 -> next = temp2 -> next;

	// delete temp2
	free(temp2);
}

void Print() {

	struct Node* temp = head;

	printf("List is: ");

	while(temp != NULL) {
		printf("%d  ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	head = NULL;

	int n, i, x;

	//printf("How many numbers?\n");
	//scanf("%d", &n);

	/*for(i=0; i<n; i++) {
		printf("\nEnter the number: ");
		scanf("%d", &x);
		InsertAtEnd(x);
		Print();
	}*/

	InsertAtPosition(3, 1);    // List: 3
	InsertAtPosition(5, 2);    // List: 3, 5
	InsertAtPosition(6, 1);    // List: 6, 3, 5
	InsertAtPosition(10, 2);   // List: 6, 10, 3, 5
	InsertAtPosition(7, 4);    // List: 6, 10, 3, 7, 5

	Print();
	printf("\n");

	DeleteAtPosition(1);
	Print();
	DeleteAtPosition(2);
	Print();

	InsertAtEnd(21);
	Print();
	return 0;
}