#include "Queue.h"

Queue::Queue()  /*Post: The Queue is initialized to be empty.*/
{
	front = NULL;
	rear = NULL;
}

Queue::~Queue() //  Destructor

{

}

Error_Code_Q Queue::append(const Queue_entry &item)
{
	Node *new_rear = new Node(item, NULL);
	if (rear == NULL) {
		front = new_rear;
		rear = front;
		return s;
	}
	else {
		rear->link = new_rear;
		rear = new_rear;
		return s;
	}

}

Error_Code_Q Queue::serve()
{

	Node *old_front = front;
	if (front == NULL) {
		return u;
	}
	else {
		if (rear == front) {
			rear = NULL;
		}
		front = front->link;

		delete old_front;
		return s;
	}
}

void Queue::print()
{
	Node *current = front;
	cout << "Queue" << endl;
	while (current != nullptr) {
		cout << current->entry << endl;
		current = current->link;
	}


}