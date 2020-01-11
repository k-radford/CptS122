#include "QueueNode.h"


QueueNode::QueueNode(int customerNum, int serviceTime, int totalTime)
{
	pData = new Data(customerNum, serviceTime, totalTime); // allocates memory on heap
	pNext = nullptr;
}

QueueNode::QueueNode(QueueNode &copyQueueNode)
{
	// not needed
}

QueueNode::~QueueNode()
{
	// TA says this isnt needed
}

void QueueNode::setNextPtr(QueueNode *pNew)
{
	pNext = pNew;
}

void QueueNode::setDataPtr(Data *pNew)
{
	pData = pNew;
}

QueueNode* QueueNode::getNextPtr()
{
	return pNext;
}

Data* QueueNode::getDataPtr()
{
	return pData;
}
