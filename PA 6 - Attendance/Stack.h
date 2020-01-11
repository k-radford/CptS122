#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;

#include "Node.h"

// You are required to implement only one class for the Stack. The Stack class will be implemented using an array. 
// The Stack class must support push (), pop (), peek (), and isEmpty () operations. All of these should execute in constant time.
class Stack
{
public:
	Stack();
	Stack(Stack &copyStack);
	~Stack();

	// setters
	void setpHead(Node *pNew);
	void setpTail(Node *pNew);

	// getters
	Node *getpHead();
	Node *getpTail();

	bool isEmpty();
	void peek(Node *info);
	void pop();
	void push(Node *info); // parameters?

private:
	Node *pHead;
	Node *pTail;

};