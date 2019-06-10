#include<iostream>
using namespace std;

#define SIZE 5

class CircularQueue {

private:
	int front, rear,
		A[SIZE];

public:
	CircularQueue() {
		front = -1, rear = -1;
	}

	bool isEmpty() {
		return (front == -1 && rear == -1);
	}

	bool isFull() {
		if ((front == 0 && rear = SIZE - 1) || front = rear + 1)
			return true;
		return false;
		//return ((rear + 1) % SIZE == front);
	}

	void enqueue(int x) {
		if(isFull()) {
			cout << "\nQueue is full."; 
			return;
		}

		else if (isEmpty()) {
			front = 0;
			rear = 0;
		}

		else
			rear = ((rear + 1) % SIZE);

		A[rear] = x;
	}

	void dequeue() {
		if(isEmpty()) {
			cout << "\nQueue is empty.";
			return;
		}

		else if (front == rear) {   // there is only one element in the queue.
			front = -1;
			rear = -1;
		}

		else
			front = ((front + 1) % SIZE);
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

	CircularQueue q;
	q.dequeue();   // prints queue is empty, returns and executes next instruction
	q.enqueue(2);
	q.enqueue(10);
	q.enqueue(12);
	q.enqueue(3);
	q.enqueue(23);   // queue is full
	//q.enqueue(55);  

	q.display();
	
	q.dequeue();
	q.display();

	q.enqueue(1);
	q.display();

	//cout << endl << q.Front();

	return 0;
}