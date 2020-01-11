#include "Node.h"

//////////////////////////////////////////  NODE  //////////////////////////////////////////

// constructor which accepts a string to set the data in the node; each pointer in the node is set to NULL
Node::Node(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{

}

void Node::setData(string newData)
{
	mData = newData;
}

void Node::setLeftPtr(Node *newPtr)
{
	mpLeft = newPtr;
}

void Node::setRightPtr(Node *newPtr)
{
	mpRight = newPtr;
}

string Node::getData()
{
	return mData;
}

Node*& Node::getLeftPtr()
{
	return mpLeft;
}

Node*& Node::getRightPtr() 
{
	return mpRight;
}

void Node::printData()
{
	cout << mData << endl;
}

//////////////////////////////////////////  TRANSACTION NODE  //////////////////////////////////////////


TransactionNode::~TransactionNode()
{

}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

int TransactionNode::getUnits()
{
	return mUnits;
}

void TransactionNode::printData()
{
	cout << this->mData << " " << this->mUnits << endl;
}