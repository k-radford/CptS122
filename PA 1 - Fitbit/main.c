// Kate Radford
// SI# 11537868
// PA 1
// Due: Jan 26
// Objective: analyzing data from real life Fitbit
// Notes: My apoligies for the tardiness, I caught a fever and my academics really suffered from it

#include "PA1.h"

/*In particular, you will analyze 24 hours of data. Each record in the “FitbitData.csv” represents one minute of data and consists of 
seven fields. These include the following:
1.    Minute
2.    Calories
3.    Distance (in miles)
4.    Floors
5.    Heartrate
6.    Steps
7.    Sleep level*/

int main(void)
{
	FILE *infile = NULL;
	FILE *outfile = NULL;
	// Open “FitbitData.csv” for mode read
	infile = fopen("FitbitData.csv", "r");
	// Define an array of FitbitData that can store 24 hours of minute data
	struct fitbit FitbitData[1440];
	char *token;
	int index = 0, counter = 0;

	if (infile != NULL) //Checks if successfully reads infile
	{
		printf("Successfully read FitbitData.csv\n");

		// You must parse each record using strtok() from <string.h> into the corresponding fields, and store into the FitbitData array;
		// Note: not all fields have values, some are “empty” or null
		while (fgets(FitbitData, 1440, infile) != NULL)
		{
			fgets(FitbitData, 1440, infile);


			token = strtok(FitbitData, ",");
			while (token != NULL)
			{
				index += 1;
				printf(" %s\n", token); //TESTING
				token = strtok(NULL, ",\n");
				counter += 1;
				if (index > 7)
					index = 1;
				if (index == 1)
				{
					//FitbitData[counter].minute = token;
					//strcpy(FitbitData[counter].minute, FitbitData[counter]);
				}
				if (index == 2)
				{
					FitbitData[counter].calories = token;
				}
				if (index == 3)
				{
					FitbitData[counter].distance = token;
				}
				if (index == 4)
				{
					FitbitData[counter].floors = token;
				}
				if (index == 5)
				{
					FitbitData[counter].heartRate = token;
				}
				if (index == 6)
				{
					FitbitData[counter].steps = token;
				}
				if (index == 7)
				{
					FitbitData[counter].sleepLevel = token;
				}
				index += 1;
			}
		}
	}
	else //fail
	{
		printf("Failure in reading FitbitData.csv\n");
	}

	// Open “Results.csv” for mode write
	outfile = fopen("Results.csv", "w");
	
	
	// You must output two lines to “Results.csv” and to the screen in the following format:
	// o   Line 1: Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep
	// o   Line 2: valueCalories,valueDistance,valueFloors,valueSteps,valueHeartrate,valueMax,valueSleepStart:valueSleepEnd
	int cals = totalCals(&FitbitData);
	int dist = totalDist();
	int floors = totalFloors();
	int steps = totalSteps();
	int heart = avgHeart();
	int maxsteps = maxSteps();
	int sleep = poorSleep();

	fprintf(outfile, "%s%s%s%s%s%s%s", cals, dist, floors, steps, heart, maxsteps, sleep);

	// You must close “FitbitData.csv” and “Results.csv”
	fclose(infile);
	fclose(outfile);
	return 0;
}