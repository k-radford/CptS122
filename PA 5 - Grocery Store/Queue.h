#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

#include "QueueNode.h"

using std::fstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Queue
{

public:
	Queue();
	Queue(Queue &copyQueue);
	~Queue();
	void destroyQueue();

	//setters
	void setpHead(QueueNode *pNew);
	void setpTail(QueueNode *pNew);

	//getters
	QueueNode *getpHead();
 	QueueNode *getpTail();

	int calcTotalTime();
	void printQueue();
	bool isEmpty();
	bool enqueue(int customerNum, int serviceTime, int totalTime);    // insert
	void dequeue();                                                   // delete


private:

	QueueNode *pHead; 
	QueueNode *pTail;
};