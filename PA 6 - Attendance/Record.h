#pragma once
#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::getline;
using std::vector;

class Record
{
public:
	Record(int record = 0, int id = 0, string name = "", string email = "", int credits = 0, string major = "", string grade = "", 
		int absences = 0, vector <string> dates = {});
	Record(Record &copyRecord);
	~Record();

	// getters
	int getRecordNum() const;
	int getIdNum() const;
	string getName() const;
	string getEmail() const;
	int getNumCredits() const;
	string getMajor() const;
	string getGradeLevel() const;
	int getAbsences() const;
	vector <string> getDates();

	// setters
	void setRecordNum(int newRecordNum);
	void setIdNum(int newIdNum);
	void setName(string newName);
	void setEmail(string newEmail);
	void setNumCredits(int newNumCredits);
	void setMajor(string newMajor);
	void setGradeLevel(string newGradLevel);
	void setAbsences(int newAbsences);
	void setDates(string newDate);

private:
	int mRecord;
	int mId;
	string mName;
	string mEmail;
	int mCredits;
	string mMajor;
	string mGrade;
	int mAbsences;
	vector <string> mDates; // a stack (may be implemented using an array) for storing the dates of absences

	Record *pRecord;
};

ofstream &operator << (ofstream &lhs, Record &rhs);
ifstream &operator >> (ifstream &lhs, Record &rhs);
ostream &operator << (ostream &lhs, Record &rhs);