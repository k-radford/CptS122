#define _CRT_NO_SECURE_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct record {

	char artist[20];
	char album[20];
	char song[20];
	char genre[20];
	Duration songLength;
	int timesPlayed;
	int rating;

} Record;

Record mainPlaylist[100];

typedef struct node {

	Record data;
	struct node *pNext;
	struct node *pPrev;

} Node;

int insertFront(Node **pList, Record newRecord);
void printList(Node *pCurr);
int deleteRecord(Node **pList, int search);
Node *makeNode(Record newData);
void printRandom(struct Node *pHead);