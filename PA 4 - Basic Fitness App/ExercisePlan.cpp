#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(int goalSteps, string planName, string dateIntended)
{
	if (goalSteps < 0)
		mGoal = 0;
	else
		mGoal = goalSteps;

	mName = planName;
	mDate = dateIntended;
}

ExercisePlan::ExercisePlan(ExercisePlan &copyExercisePlan)
{
	mGoal = copyExercisePlan.getGoalSteps();
	mName = copyExercisePlan.getName();
	mDate = copyExercisePlan.getDate();
}

ExercisePlan::~ExercisePlan()
{
	// what do i do here??
}

ExercisePlan & ExercisePlan::operator= (const ExercisePlan &rhs)
{
	if (this != &rhs)
	{
		mGoal = rhs.getGoalSteps();
		mName = rhs.getName();
		mDate = rhs.getDate();
	}
	return *this;
}

int ExercisePlan::getGoalSteps() const
{
	return mGoal;
}

string ExercisePlan::getName() const
{
	return mName;
}

string ExercisePlan::getDate() const
{
	return mDate;
}

void ExercisePlan::setGoal(int newGoal)
{
	mGoal = newGoal;
}

void ExercisePlan::setName(string newName)
{
	mName = newName;
}

void ExercisePlan::setDate(string newDate)
{
	mDate = newDate; 
}

void ExercisePlan::editGoal()
{
	int newGoal;
	cout << "What do you want your new goal steps to be?" << endl;
	cin >> newGoal;
	mGoal = newGoal;
}

ofstream &operator<<(ofstream &lhs, ExercisePlan &rhs)
{
	// output to file
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoalSteps() << endl;
	
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

ostream &operator << (ostream &lhs, ExercisePlan &rhs)
{
	//print to screen
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoalSteps() << endl;
	
	lhs << rhs.getDate() << endl << endl;

	return lhs;
}

ifstream &operator >> (ifstream &lhs, ExercisePlan &rhs)
{
	// for loadweeklyplan()
	string name, date;
	int goal;

	lhs >> name >> goal >> date;
	rhs.setName(name);
	rhs.setGoal(goal);
	rhs.setDate(date);

	return lhs;
}