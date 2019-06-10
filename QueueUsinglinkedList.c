#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node* next;
};

struct Node* front = NULL;   // gloabal variables
struct Node* rear = NULL;

void enqueue(int x) {

	struct Node* temp = (Node*) malloc (sizeof(struct Node));

	temp -> data = x;
	temp -> next = NULL;

	// when queue is empty
	if(front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}

	rear -> next = temp;
	rear = temp;
}

void dequeue() {
	struct Node* temp = front;

	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}

	if(front == rear) {
		front = rear = NULL;
	}

	else {
		front = front -> next;
	}

	free(temp);
}

void Print() {

	Node* temp = front;

	printf("List is: ");

	while(temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}


int main(int argc, char const *argv[]) {

	enqueue(4);
	enqueue(12);
	enqueue(3);
	enqueue(1);
	Print();      // List: 4 12 3 1

	dequeue();
	Print();     // List: 12 3 1
	
	return 0;
}