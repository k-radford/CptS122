#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;

class ExercisePlan
{
public:
	ExercisePlan(int goalSteps = 0, string planName = "", string dateIntended = "");
	ExercisePlan(ExercisePlan &copyExercisePlan);
	~ExercisePlan();

	ExercisePlan & operator= (const ExercisePlan &rhs);

	// getters / accessors	
	int getGoalSteps() const;
	string getName() const;
	string getDate() const;

	// setters / mutators
	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(string newDate);
	void editGoal();

private:
	int mGoal;
	string mName;
	string mDate;
};

ofstream &operator<< (ofstream &lhs, ExercisePlan &rhs);
ifstream &operator>> (ifstream &lhs, ExercisePlan &rhs);
ostream &operator<< (ostream &lhs, ExercisePlan &rhs);