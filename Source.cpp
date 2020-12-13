////////Implementation of Priority Queue usin Linked List//////////////////
#include<iostream>
using namespace std;
struct Node {
	int priority, data;
	struct Node* next;
};

class priorityQueue {
public:
	priorityQueue();
	bool isEmpty();
	bool isFull();
	void insertValue(int, int);
	void deleteValue();
	void Display();

private:
	Node* front;
};

priorityQueue::priorityQueue() {
	front = NULL;
}

bool priorityQueue::isEmpty() {
	if ( front == NULL) {
		cout << "Your Queue is Empty ";
		return true;
	}
	else {
		return false;
	}
}

bool priorityQueue::isFull() {
	Node* newNode;
	try {
		newNode = new Node;
		delete newNode;
		cout << "Your Queue is not Full";
		return false;
	}
	catch (bad_alloc exception) {
		return true;
	}
}
void priorityQueue::insertValue(int key, int priorityKey) {
	Node* newNode, * rear;
	newNode = new Node;
	newNode->data = key;
	newNode->priority = priorityKey;
	// if queue is empty or priority is greter then th 1st priority
	if (front == NULL || priorityKey < front->priority) { 
		newNode->next = front;
		front = newNode;
	}
	else {
		rear = front;
		while (rear->next != NULL && rear->next->priority <= priorityKey) {
			rear = rear->next;
		}
		newNode->next = rear->next;
		rear->next = newNode;
	}
}

void priorityQueue::deleteValue() {
	Node* newNode;
	if (front == NULL) {
		cout << "Queue is Empty. No Deletion occurs." << endl;
	}
	else {
		newNode = front;
		front = front->next;
		free(newNode);
	}
}
void priorityQueue::Display() {
	Node* newNode;
	newNode = front;
	if (front == NULL) {
		cout << "Queue is Empty " << endl;
	}
	else {
		cout << "Your Priority Queue is " << endl;
		cout << "Priority\tValue" << endl;
		while (newNode != NULL) {
			cout << newNode->priority << "\t\t" << newNode->data << endl;
			newNode = newNode->next;
		}
	}
}

int main() {
	priorityQueue q;
	int choice, number, priority;
	char ch;
	do {
		system("cls");
		cout << "Enter 1 if you want to check whether the Queue is Empty or not " << endl;
		cout << "Enter 2 if you want to check whether the Queue is Full or not " << endl;
		cout << "Enter 3 if you want to enqueue value in the Queue " << endl;
		cout << "Enter 4 if you want to dequeue value from the Queue " << endl;
		cout << "Enter 5 if you want to Display the Queue " << endl;
		cout << "Enter your choice "; cin >> choice;
		switch (choice) {
		case 1: {
			q.isEmpty();
			cout << endl;
			break;
		}
		case 2: {
			q.isFull();
			cout << endl;
			break;
		}
		case 3: {
			cout << "Enter any positive Number you want to enqueue "; cin >> number;
			cout << "Enter Priority of the value "; cin >> priority;
			q.insertValue(number, priority);
			cout << endl;
			break;
		}
		case 4: {
			q.deleteValue();
			break;
		}
		case 5: {
			q.Display();
			cout << endl;
			break;
		}
		}
		cout << "Enter \'Y\' or \'y\' if you want to Enqueue/Dequeue/Display the Queue "; cin >> ch;
		system("pause");
	} while (ch == 'y' || ch == 'Y');
	return 0;
}