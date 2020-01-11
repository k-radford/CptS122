#include "FAWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	// help
}

FitnessAppWrapper::FitnessAppWrapper(int numberPlans)
{
	mNumberPlans = numberPlans;
	// idk what to do here??
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	// here also??
}

// Must define two of these functions; one for a DietPlan and one for an ExercisePlan. This function reads one record from the given stream. 
// These will be considered overloaded functions! Precondition: file is already open!
void FitnessAppWrapper::loadDailyDietPlan(DietPlan &plan)
{
	inputStream >> plan;
}

void FitnessAppWrapper::loadDailyExercisePlan(ExercisePlan &plan)
{
	inputStream >> plan;
}

// Must define two of these functions; one for a DietPlan and one for an ExercisePlan. This function reads one record from the given stream.
// These will be considered overloaded functions! Precondition: file is already open!
void FitnessAppWrapper::loadWeeklyDietPlan(DietPlan weeklyDietPlan[])
{
	inputStream.open("dietPlans.txt");

	for (int i = 0; i < 7; i++)
	{
		loadDailyDietPlan(weeklyDietPlan[i]);

	}
}

void FitnessAppWrapper::loadWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[])
{
	inputStream.open("exercisePlans.txt");

	for (int i = 0; i < 7; i++)
	{
		loadDailyExercisePlan(weeklyExercisePlan[i]);

	}

	inputStream.close();
}

// Writes a daily plan to the screen. You must apply the overloaded stream insertion operator here! Note: you must determine the appropriate 
// parameters and return type. Once again you must define two of these!
void FitnessAppWrapper::displayDailyDietPlan(DietPlan &plan) const
{
	cout << plan;
}

void FitnessAppWrapper::displayDailyExercisePlan(ExercisePlan &plan) const
{
	cout << plan;
}

// Writes a weekly plan to the screen. This function must call displayDailyPlan (). Note: you must determine the appropriate parameters 
// and return type. Once again you must define two of these!
void FitnessAppWrapper::displayWeeklyDietPlan(DietPlan weeklyDietPlan[]) const
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyDietPlan(weeklyDietPlan[i]);

	}
}

void FitnessAppWrapper::displayWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[]) const
{

	for (int i = 0; i < 7; i++)
	{
		displayDailyExercisePlan(weeklyExercisePlan[i]);

	}
}

// Writes a daily plan to a file. You must apply the overloaded stream insertion operator here! Note: you must determine the appropriate 
// parameters and return type. Once again you must define two of these!
void FitnessAppWrapper::storeDailyDietPlan(DietPlan &plan)
{
	outputStream << plan;
}

void FitnessAppWrapper::storeDailyExercisePlan(ExercisePlan &plan)
{
	outputStream << plan;
}

// Writes a weekly plan to a file. This function must call storeDailyPlan (). You must apply the overloaded stream insertion operator here! 
// Note: you must determine the appropriate parameters and return type. Once again you must define two of these!
void FitnessAppWrapper::storeWeeklyDietPlan(DietPlan weeklyDietPlan[])
{
	outputStream.open("dietPlans.txt");
	for (int i = 0; i < 7; i++)
	{
		storeDailyDietPlan(weeklyDietPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[])
{
	outputStream.open("exercisePlans.txt");
	for (int i = 0; i < 7; i++)
	{
		storeDailyExercisePlan(weeklyExercisePlan[i]);
	}
}


void FitnessAppWrapper::displayMenu()
{
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl; //Note: this must write the most recent weekly plans to the corresponding files.
}

int FitnessAppWrapper::getMenuOption() const
{
	int option = 0;

	cin >> option;

	system("cls");

	return option;
}

// starts the main application
void FitnessAppWrapper::runApp(void)
{
	int option = 0;
	bool status = true, success = true;
	FitnessAppWrapper diet, exercise;
	DietPlan diet1;
	ExercisePlan exercise1;

	cout << "*** Welcome to KR's Basic Fitness Application ***" << endl << endl;

	do
	{
		displayMenu();
		option = getMenuOption();

		switch (option)
		{
		case 1: 
			loadWeeklyDietPlan(weeklyDietPlan);
			break;
		case 2:
			loadWeeklyExercisePlan(weeklyExercisePlan);
			break;
		case 3:
			storeWeeklyDietPlan(weeklyDietPlan);
			break;
		case 4:
			storeWeeklyExercisePlan(weeklyExercisePlan);
			break;
		case 5:
			displayWeeklyDietPlan(weeklyDietPlan);
			break;
		case 6:
			displayWeeklyExercisePlan(weeklyExercisePlan);
			break;
		case 7:
			diet1.editGoal();
			break;
		case 8:
			exercise1.editGoal();
			break;
		case 9:
			storeWeeklyDietPlan(weeklyDietPlan);
			storeWeeklyExercisePlan(weeklyExercisePlan);
			status = false;
			break;
		default: cout << "ERROR: Invalid choice!" << endl;
			break;

		}

	} while(status != false);

}

