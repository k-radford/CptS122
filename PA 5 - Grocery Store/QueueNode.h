#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

#include "Data.h"

using std::fstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class QueueNode
{

public:
	QueueNode(int customerNum, int serviceTime, int totalTime);
	QueueNode(QueueNode &copyQueueNode);
	~QueueNode();

	//setters
	void setNextPtr(QueueNode *pNew);
	void setDataPtr(Data *pNew);

	//getters
	QueueNode *getNextPtr();
	Data *getDataPtr();

private:
	Data *pData;    // The memory for Data will need to be allocated on the heap as well!
	QueueNode *pNext;
	
	

};