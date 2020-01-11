#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper();
	FitnessAppWrapper(int numberPlans);
	~FitnessAppWrapper();

	FitnessAppWrapper & operator= (const FitnessAppWrapper &rhs);

	void runApp(void);
	void loadDailyDietPlan(DietPlan &plan);
	void loadDailyExercisePlan(ExercisePlan &plan);
	void loadWeeklyDietPlan(DietPlan weeklyDietPlan[]);
	void loadWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[]);
	void displayDailyDietPlan(DietPlan &plan) const;
	void displayDailyExercisePlan(ExercisePlan &plan) const;
	void displayWeeklyDietPlan(DietPlan weeklyDietPlan[]) const;
	void displayWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[]) const;
	void storeDailyDietPlan(DietPlan &plan);
	void storeDailyExercisePlan(ExercisePlan &plan);
	void storeWeeklyDietPlan(DietPlan weeklyDietPlan[]);
	void storeWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[]);

	void displayMenu();
	int getMenuOption() const;


private:
	// FitnessAppWrapper *mPlansptr;
	bool *mPlansAvailableptr;
	int mNumberPlans;
	ifstream inputStream;
	ofstream outputStream;

	DietPlan weeklyDietPlan[7];
	ExercisePlan weeklyExercisePlan[7];
};

class ListNode
{


};

class List
{


};