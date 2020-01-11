#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::getline;

class Node
{
public:
	Node(string newData = "");
	virtual ~Node();

	// setters
	void setData(string newData);
	void setLeftPtr(Node *newPtr);
	void setRightPtr(Node *newPtr);

	// getters
	string getData();
	Node*& getLeftPtr();
	Node*& getRightPtr();

	virtual void printData();

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;

private:

};

/*
You will first need to start by defining an abstract base class Node, which encapsulates the following:
Data members:

# mData : std::string // # denotes protected
# mpLeft : Node *
# mpRight : Node *

Member functions:

+ virtual destructor // + denotes public
+ constructor which accepts a string to set the data in the node; each pointer in the node is set to NULL
+ setters – one for each data member (3 total should be defined)
+ getters – one for each data member (3 total should be defined, the 2 defined to get the pointers should return a reference to the pointer, i.e. Node *&)
+ pure virtual printData () function, which must be overridden in class TransactionNode
*/

class TransactionNode : public Node
{
public:
	TransactionNode(string newData = "", int units = 0) :
		Node(newData)
	{
		mUnits = units;
	}
	~TransactionNode();
	void setUnits(int newUnits);
	int getUnits();
	void printData();

private:
	int mUnits;
};

/*
Next define a class TransactionNode, which publically inherits from abstract base class Node.
Class TransactionNode must encapsulate the following:

New Data members:

- mUnits : int // - denotes private

New Member functions:

+ destructor // + denotes public
+ constructor which accepts a string to set the data and an integer to set the number of units in the node;
should invoke class Node’s constructor
+ setter
+ getter
+ printData (), which overrides the pure virtual function in class Node
*/
