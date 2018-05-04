// Project3.cpp : Defines the entry point for the console application.
/* Joseph Brinton
CS 2420 Section 3
Program 3 Stack and Queue
10/2/2017
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main()		// Main function starts here
{
	cout << "Joseph Brinton" << endl << "CS 2420, Section 003" << endl << "Program 3 - Stack and Queue" << endl;

	Stack s;
	Queue q;
	ifstream inputFile;
	string fileName;
	cout << "Please enter the name of data file: ";
	cin >> fileName;
	inputFile.open(fileName.c_str());
	if (inputFile.fail())
	{
		cout << "Error opening " << fileName << "\n";
		char c;
		cin >> c;
		cin.get();
		return 1;
	}

	string data;
	Error_Code code;
	Error_Code_Q qcode;
	string status;
	cout << endl;
	cout << "OPCODE " << "STACK " << "VALUE " << "RESULT" << endl;

	while (!inputFile.eof())
	{
		getline(inputFile, data);
		string opcode = "";
		string num = "";
		int value = 0;
		if (data != "pop" && data != "serve") {
			num = data.substr(data.find(" "));
			opcode = data.substr(0, data.find(" "));
			value = atoi(num.c_str());
		}
		else {
			opcode = data;
		}

		if (opcode == "push") {
			code = s.push(value);

			if (code == 0) {
				status = "    success";
			}
			if (code == 1) {
				status = "    overflow";
			}
			if (code == 2) {
				status = "    underflow";
			}
			cout << opcode << "   stack " << value << status << endl;
		}
		else if (opcode == "pop") {
			code = s.pop();
			if (code == 0) {
				status = "    success";
			}
			if (code == 1) {
				status = "    overflow";
			}
			if (code == 2) {
				status = "    underflow";
			}
			cout << opcode << "    stack " << "--" << status << endl;
		}
		else if (opcode == "append")
		{
			qcode = q.append(value);

			if (qcode == 0) {
				status = "    success";
			}
			if (qcode == 1) {
				status = "    overflow";
			}
			if (qcode == 2) {
				status = "    underflow";
			}
			cout << opcode << " queue " << value << status << endl;
		}
		else if (opcode == "serve")
		{
			qcode = q.serve();

			if (qcode == 0) {
				status = "    success";
			}
			if (qcode == 1) {
				status = "    overflow";
			}
			if (qcode == 2) {
				status = "    underflow";
			}
			cout << opcode << "  queue " << "--" << status << endl;
		}
		else
		{
			cout << "command not recognized" << endl;
		}

	}

	inputFile.close();
	cout << endl;
	s.print();
	cout << endl;
	q.print();
	

	char c;
	cin >> c;
	cin.get();
	return 0;
}
