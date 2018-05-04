#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
typedef int Stack_entry;
enum Error_Code { success, overflow, underflow };
class Stack {
public:
	Stack();
	bool empty() const;
	Error_Code push(const Stack_entry& item);
	Error_Code pop();
	void print();
	~Stack();
private:
	Node* top_node;
};
