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

class DietPlan
{
public:
	DietPlan(int goalCalories = 0, string planName = "", string dateIntended = "");     //constructor
	DietPlan(DietPlan &copyDietPlan);                                                   //shallow copy constructor
	~DietPlan();                                                                        //destructor

	DietPlan & operator= (const DietPlan &rhs);                                         // overloaded assignment operator

	// getters / accessors	
	int getGoalCal() const;
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

ofstream &operator << (ofstream &lhs, DietPlan &rhs);
ifstream &operator >> (ifstream &lhs, DietPlan &rhs);
ostream &operator << (ostream &lhs, DietPlan &rhs);