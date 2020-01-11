#include "Node.h"

Node::Node(Record newRecord)
{
	pRecord = new Record(newRecord);
	pNext = nullptr;
}

Node::Node(Node &copyList)
{
	// idk
}

Node::~Node()
{
	// lmao
}

void Node::setNextPtr(Node *pNew)
{
	pNext = pNew;
}

void Node::setRecordPtr(Record *pNew)
{
	pRecord = pNew;
}

Node* Node::getNextPtr()
{
	return pNext;
}

Record* Node::getRecordPtr()
{
	return pRecord;
}

