#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <string.h>



typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

int totalCals(struct FitbitData[], char *FitbitData);