#include<iostream>
using namespace std;

#define SIZE 101

class queue {

private:
	int front, rear,
		A[SIZE];

public:
	queue() {
		front = -1, rear = -1;
	}

	bool isEmpty() {
		return (front == -1 && rear == -1);
	}

	bool isFull() {
		return (rear == SIZE - 1);
	}

	void enqueue(int x) {
		if(isFull()) {
			cout << "Queue is full."; 
			return;
		}

		else if (isEmpty()) {
			front = 0;
			rear = 0;
		}

		else
			rear = rear + 1;

		A[rear] = x;
	}

	void dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty.";
			return;
		}

		else if (front == rear) {
			front = -1;
			rear = -1;
		}

		else
			front = front + 1;
	}

	int Front() {
		return A[front];
	}

	void display() {
		cout << "\n";
		for(int i=front; i<=rear; i++) {
			cout << A[i] << " ";
		}
	}
};

int main(int argc, char const *argv[]) {

	queue q;
	q.dequeue();   // prints queue is empty, returns and executes next instruction
	q.enqueue(2);
	q.enqueue(10);
	q.enqueue(12);
	q.enqueue(3);
	q.display();
	
	q.dequeue();
	q.display();

	cout << endl << q.Front();

	return 0;
}