#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
typedef int Queue_entry;
enum Error_Code_Q { s, o, u };
class Queue {
public:
	Queue();
	Error_Code_Q append(const Queue_entry &item);
	Error_Code_Q serve();
	void print();
	~Queue();
private:
	Node *front, *rear;
};

