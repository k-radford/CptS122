#include "List.h"

List::List()
{
	pHead = nullptr;
	pTail = nullptr;
}

List::List(List &copyList)
{
	// nada
}

List::~List()
{
	// zip
}

void List::setpHead(Node *pNew)
{
	pHead = pNew;
}

void List::setpTail(Node *pNew)
{
	pTail = pNew;
}

Node* List::getpHead()
{
	return pHead;
}

Node* List::getpTail()
{
	return pTail;
}

void List::insertAtEnd(Record newRecord)
{
	Node *pMem = new Node(newRecord);

	if (pHead == nullptr)
	{
		pHead = pMem;
		pTail = pMem;
	}
	else
	{
		pTail->setNextPtr(pMem);
		pTail = pMem;
	}
}

ifstream &operator >> (ifstream &lhs, List &rhs)
{
	// input from file
	Record master;
	string name, email, major, level, date;
	int record, id, credits, absences;

	lhs >> record >> id;
	getline(lhs, name, '\"');
	getline(lhs, name, '\"');
	getline(lhs, email, ',');
	lhs >> credits;
	getline(lhs, major, ',');
	getline(lhs, level, ',');
	lhs >> absences;
	getline(lhs, date);
	
	master.setRecordNum(record);
	master.setIdNum(id);
	master.setName(name);
	master.setEmail(email);
	master.setNumCredits(credits);
	master.setMajor(major);
	master.setGradeLevel(level);
	master.setAbsences(absences);
	master.setDates(date);

	rhs.insertAtEnd(master);

	return lhs;
}

ofstream &operator << (ofstream &lhs, List &rhs)
{
	// output to file
	Node *pTemp = rhs.getpHead();

	while (pTemp != nullptr)
	{
		lhs << *(pTemp->getRecordPtr());
		pTemp = pTemp->getNextPtr();
	}

	return lhs;
}
