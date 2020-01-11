#include "Stack.h"

Stack::Stack()
{
	this->pHead = this->pTail = nullptr;
}

Stack::Stack(Stack &copyStack)
{
	// idk
}

Stack::~Stack()
{
	// idk
}

bool Stack::isEmpty()
{
	return (this->pHead == nullptr);
}

void Stack::peek(Node *info) // change to taking in no parameters, just peeking at the top of the stack
{
	int record = 0, id = 0, credits = 0, absences = 0;
	string name = "", email = "", major = "", grade = "";
	name = info->getRecordPtr()->getName();
	absences = info->getRecordPtr()->getAbsences();

	cout << name << absences << endl; // edit this depending on the information we need to show when peeking
}

// obtained from T Cripe
void Stack::pop()
{
	Node *pMem = nullptr;
	pMem = new Node(*this->pHead);
	this->pHead = this->pHead->getNextPtr();
	delete(pMem);
}

void Stack::push(Node *info)
{
	Node *pTemp = nullptr;
	pTemp = new Node(*this->pHead); // inserting at front or end? make this insert at front
	info = pTemp->getNextPtr();
	// info = pTemp;
}

void Stack::setpHead(Node *pNew)
{
	pHead = pNew;
}

void Stack::setpTail(Node *pNew)
{
	pTail = pNew;
}

Node* Stack::getpHead()
{
	return pHead;
}

Node* Stack::getpTail()
{
	return pTail;
}

