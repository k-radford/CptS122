#include "Queue.h"

Queue::Queue()
{
	this->pHead = this->pTail = nullptr;

}

Queue::Queue(Queue &copyQueue)
{
	// not needed
}

Queue::~Queue()
{
	destroyQueue();
}

void Queue::destroyQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}
	// head and tail?
	if (this->pTail == nullptr && this->pHead == nullptr)
	{
		cout << "Deleted all nodes" << endl;
	}
}

int Queue::calcTotalTime()
{
	// totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
	QueueNode *pTemp = pHead;
	int totalTime = 0;

	while (pTemp != NULL)
	{
		totalTime += pTemp->getDataPtr()->getServiceTime();
		pTemp = pTemp->getNextPtr();
	}

	return totalTime;
}

void Queue::printQueue()
{
	QueueNode *pTemp = pHead;

	if (pTemp == NULL)
	{
		cout << "No customers in queue" << endl << endl;
	}
	else
	{
		while (pTemp != NULL)
		{
			cout << "Customer Number:" << endl;
			cout << pTemp->getDataPtr()->getCustomerNum() << endl;
			cout << "Service Time:" << endl;
			cout << pTemp->getDataPtr()->getServiceTime() << endl;
			cout << "Total Time:" << endl;
			cout << pTemp->getDataPtr()->getTotalTime() << endl;
			pTemp = pTemp->getNextPtr();
		}
	}
}

bool Queue::isEmpty()
{
	return (this->pHead == nullptr);
}

// Insert
bool Queue::enqueue(int customerNum, int serviceTime, int totalTime)
{
	// inserting at the end of the linked list
	QueueNode *pMem = nullptr;

	pMem = new QueueNode(customerNum, serviceTime, totalTime);

	bool success = false;

	if (this->pHead == nullptr)
	{
		// empty queue
		this->pHead = this->pTail = pMem;
	}
	else
	{
		// queue is not empty
		this->pTail->setNextPtr(pMem);
		this->pTail = pMem;
	}

	success = true;

	return success;
}

// Delete
// Precondition: queue is not empty
void Queue::dequeue()
{
	// one node in queue
	if (this->pHead == this->pTail)
	{
		delete this->pHead; // this->mpTail is a dangling pointer right now!
		this->pHead = this->pTail = nullptr;
	}
	else // more than 1 node in queue
	{
		QueueNode *pTemp = nullptr;
		pTemp = this->pHead;
		//delete pTemp;
		this->pHead = this->pHead->getNextPtr();
		delete pTemp;
	}

	// return pNext;
}

void Queue::setpHead(QueueNode *pNew)
{
	pHead = pNew;
}

void Queue::setpTail(QueueNode *pNew)
{
	pTail = pNew;
}

QueueNode* Queue::getpHead()
{
	return pHead;
}

QueueNode* Queue::getpTail()
{
	return pTail;
}