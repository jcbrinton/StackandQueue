#include "Stack.h"

Stack::Stack() //  Constructor
{ 

	top_node = NULL;
} 


Stack::~Stack() //  Destructor

{
	while (!empty())
		pop(); 
}

Error_Code Stack::push(const Stack_entry& item)
{
	Node *new_top = new Node(item, top_node);
	top_node = new_top;
	return success;
}


Error_Code Stack::pop()
{
	Node *old_top = top_node;
	if (top_node == NULL)
		return underflow;
	top_node = old_top->link;
	delete old_top;
	return success;
}

bool Stack::empty() const
{
	if (top_node == NULL) {
		return true;
	}
	else
	{
		return false;
	}
}


void Stack::print()

{
	Node *current = top_node;
	cout << "Stack" << endl;
	while (current != nullptr) {
		cout << current->entry << endl;
		current = current->link;
	}

	
}

