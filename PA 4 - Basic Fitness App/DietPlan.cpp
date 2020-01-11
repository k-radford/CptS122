#include "DietPlan.h"

DietPlan::DietPlan(int goalCalories, string planName, string dateIntended)
{
	if (goalCalories < 0)
		mGoal = 0;
	else
		mGoal = goalCalories;

	mName = planName;
	mDate = dateIntended;
}

DietPlan::DietPlan(DietPlan &copyDietPlan)
{
	mGoal = copyDietPlan.getGoalCal();
	mName = copyDietPlan.getName();
	mDate = copyDietPlan.getDate();
}

DietPlan::~DietPlan()
{
	// what do i do here??
}

DietPlan & DietPlan::operator= (const DietPlan &rhs)
{
	if (this != &rhs)
	{
		mGoal = rhs.getGoalCal();
		mName = rhs.getName();
		mDate = rhs.getDate();
	}
	return *this;
}

int DietPlan::getGoalCal() const
{
	return mGoal;
}

string DietPlan::getName() const
{
	return mName;
}

string DietPlan::getDate() const
{
	return mDate;
}

void DietPlan::setGoal(int newGoal)
{
	mGoal = newGoal;
}

void DietPlan::setName(string newName)
{
	mName = newName;
}
void DietPlan::setDate(string newDate)
{
	mDate = newDate;
}

void DietPlan::editGoal()
{
	int newGoal;
	cout << "What do you want your new goal calories to be?" << endl;
	cin >> newGoal;
	mGoal = newGoal;
}

ofstream &operator<<(ofstream &lhs, DietPlan &rhs)
{
	// output to file
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoalCal() << endl;
	
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

ifstream &operator >> (ifstream &lhs, DietPlan &rhs)
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

ostream &operator << (ostream &lhs, DietPlan &rhs)
{
	//print to screen
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoalCal() << endl;
	
	lhs << rhs.getDate() << endl << endl;

	return lhs;
}
