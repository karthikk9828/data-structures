#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

void Insert(int x) {

	Node* temp = new Node();
	temp -> data = x;
	temp -> next = NULL;

	// Insert node at the beginning
	if(head != NULL)
		temp -> next = head;
	head = temp;
}

void Print() {

	Node* temp = head;

	cout << "List is: ";

	while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	head = NULL;

	int n, i, x;

	cout << "How many numbers?\n";
	cin >> n;

	for(i=0; i<n; i++) {
		cout << "\nEnter the number: ";
		cin >> x;
		Insert(x);
		Print();
	}
	cout << endl;
	return 0;
}