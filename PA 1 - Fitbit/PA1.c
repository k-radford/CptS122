#include "PA1.h"

// Compute the total calories burned
int totalCals(struct FitbitData[], char *FitbitData)
{
	int i = 0, total = 0;
	while (FitbitData[i].calories != NULL)
	{
		total += FitbitData[i].calories;
		i += 1;
	}
	return total;
}
// Compute distance walked in miles
int totalDist()
{
	int i = 0, total = 0;
	while (FitbitData[i].distance != NULL)
	{
		total += FitbitData[i].distance;
		i += 1;
	}
	return total;
}
// Compute floors walked
int totalFloors()
{
	int i = 0, total = 0;
	while (FitbitData[i].floors != NULL)
	{
		total += FitbitData[i].floors;
		i += 1;
	}
	return total;
}
// Compute steps taken
int totalSteps()
{
	int i = 0, total = 0;
	while (FitbitData[i].steps != NULL)
	{
		total += FitbitData[i].steps;
		i += 1;
	}
	return total;
}
// Compute average heartrate over the 24 hour period
int avgHeart()
{



}
// Report the max steps taken in one minute over the 24 hour period; if there are multiple minutes throughout the day where the
// max is discovered, then report the one that is the latest in the 24 hour period
int maxSteps()
{


}
// Report the longest consecutive range of poor sleep; a range is defined as one or more consecutive minutes where the
// sleepLevel > 1; the poorest sleep is not based on the length of the range, but the sum of the sleep levels in the range; the max sum
// of the ranges is considered the poorest sleep(report the starting and ending minutes of range)
int poorSleep()
{



}

