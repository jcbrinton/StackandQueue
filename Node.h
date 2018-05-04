#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef int Node_entry;
struct Node {			// Node definition
	Node_entry entry;
	Node *link;
	Node();
	Node(Node_entry item, Node* link = NULL);
};
