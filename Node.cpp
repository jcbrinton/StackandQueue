
#include "Node.h"
Node::Node() 		// Node Constructor
{
	link = NULL;

}

Node::Node(Node_entry item, Node * add_on) // Another Node Condtructor
{
	entry = item;
	link = add_on;
}
