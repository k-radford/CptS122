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

// This is a -container- for the nodes.
// The List class will be considered your master list.
class List
{
public:
	List();
	List(List &copyList);
	~List();

	// getters
	Node *getpHead();
	Node *getpTail();

	// setters
	void setpHead(Node *pNew);
	void setpTail(Node *pNew);

	void insertAtEnd(Record newRecord);


private:
	Node *pHead;
	Node *pTail;

};

ifstream &operator >> (ifstream &lhs, List &rhs);
ofstream &operator << (ofstream &lhs, List &rhs);