#include "PA 2.h"

Node *makeNode(Record newData)
{
	Node *pMem = NULL;
	pMem = (Node*)malloc(sizeof(Node));
	pMem->data = newData;
	pMem->pNext = NULL;
	return pMem;
}
// calls makeNode() and returns 1 for successfully allocating space for a node; 0 otherwise
int insertFront(Node **pList, Record newRecord)
{
	Node *pMem = NULL;
	int success = 0;

	pMem = makeNode(newRecord);

	if (pMem != NULL) // we allocated space for a Node and initialized it
	{
		// connect the new Node/container to the list
		if (*pList != NULL) // not empty list
		{
			pMem->pNext = *pList;
			(*pList)->pPrev = pMem; // doubly linked list
			*pList = pMem;
			success = 1;
		}
		else // empty list
		{
			//pMem->pNext = *pList;
			//*pList)->pPrev = pMem;
			*pList = pMem;
			success = 1;
		}
	}
	return success;
}
// visits each node in the list and prints out the contents of the record
void printList(Node *pCurr)
{
	if (pCurr == NULL)
	{
		return;
	}
	printList(pCurr->pNext);
	printf("%d\n", pCurr->data);
}

int deleteRecord(Node **pList, int search)
{
	Node *pCur = NULL, *pPrev = NULL;
	int success = 0;

	pCur = *pList;
	while (pCur != NULL &&
		strcmp(search, pCur->data.song) != 0)
	{
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pPrev != NULL && pCur != NULL) // removing not at the front of list
	{
		success = 1;
		pPrev->pNext = pCur->pNext;
		free(pCur);
	}
	else if (pPrev == NULL && pCur != NULL) // removing at front
	{
		success = 1;
		*pList = pCur->pNext;
		free(pCur);
	}
	else // didn't find record in list
	{
		printf("Record not in list\n");
	}

	return success;


}
// help from GeeksforGeeks.org/select-a-random-node-from-a-singly-linked-list/ 
void printRandom(struct Node *pHead)
{
	if (pHead == NULL)
		return;
	
	srand(time(NULL));
	int result = pHead->data;

	struct Node *pCur = pHead;
	int n;
	for (n = 2; pCur != NULL; n++)
	{
		// change result with probability 1/n
		if (rand() % n == 0)
			result = pCur->data;

		// Move to next node
		pCur = pCur->pNext;
	}

	printf("%d", result);

}