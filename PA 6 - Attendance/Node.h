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

#include "Record.h"

// Stores the fields acquired from each record. In addition to the fields in the file, you are required to add two extra fields in your node. 
// These fields include number of absences and a stack (may be implemented using an array) for storing the dates of absences. 
// The most recent absence date will always be at the top (Last-In First-Out, LIFO)!
class Node
{
public:
	Node(Record newRecord);
	Node(Node &copyList);
	~Node();

	// getters
	Node *getNextPtr();
	Record *getRecordPtr();

	// setters
	void setNextPtr(Node *pNew);
	void setRecordPtr(Record *pNew);


private:
	Node *pNext;
	Record *pRecord;
};