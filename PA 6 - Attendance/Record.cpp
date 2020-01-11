#include "Record.h"

Record::Record(int recordNum, int idNum, string name, string email, int numCredits, string major, string gradeLevel, int absences, 
	vector <string> dates)
{
	mRecord = recordNum;
	mId = idNum;
	mName = name;
	mEmail = email;
	mCredits = numCredits;
	mMajor = major;
	mGrade = gradeLevel;
	mAbsences = absences;
	mDates = dates;
}

Record::Record(Record &copyRecord)
{
	mRecord = copyRecord.getRecordNum();
	mId = copyRecord.getIdNum();
	mName = copyRecord.getName();
	mEmail = copyRecord.getEmail();
	mCredits = copyRecord.getNumCredits();
	mMajor = copyRecord.getMajor();
	mGrade = copyRecord.getGradeLevel();
	mAbsences = copyRecord.getAbsences();
}

Record::~Record()
{
	// idk
}

int Record::getRecordNum() const
{
	return mRecord;
}

int Record::getIdNum() const
{
	return mId;
}

string Record::getName() const
{
	return mName;
}

string Record::getEmail() const
{
	return mEmail;
}

int Record::getNumCredits() const
{
	return mCredits;
}

string Record::getMajor() const
{
	return mMajor;
}

string Record::getGradeLevel() const
{
	return mGrade;
}

int Record::getAbsences() const
{
	return mAbsences;
}

vector <string> Record::getDates()
{
	return mDates;
}

void Record::setRecordNum(int newRecordNum) 
{
	mRecord = newRecordNum;
}

void Record::setIdNum(int newIdNum)
{
	mId = newIdNum;
}

void Record::setName(string newName)
{
	mName = newName;
}

void Record::setEmail(string newEmail)
{
	mEmail = newEmail;
}

void Record::setNumCredits(int newNumCredits)
{
	mCredits = newNumCredits;
}

void Record::setMajor(string newMajor)
{
	mMajor = newMajor;
}

void Record::setGradeLevel(string newGradeLevel)
{
	mGrade = newGradeLevel;
}

void Record::setAbsences(int newAbsence)
{

	mAbsences += newAbsence;
}

void Record::setDates(string newDate)
{
	mDates.push_back(newDate);
}

ofstream &operator << (ofstream &lhs, Record &rhs)
{
	// output to file
	lhs << rhs.getRecordNum() << endl;
	lhs << rhs.getIdNum() << endl;
	lhs << rhs.getName() << endl;
	lhs << rhs.getEmail() << endl;
	lhs << rhs.getNumCredits() << endl;
	lhs << rhs.getMajor() << endl;
	lhs << rhs.getGradeLevel() << endl;
	lhs << rhs.getAbsences() << endl;
	for (int i = 0; i < (rhs.getDates().size()); i++)
	{
		lhs << rhs.getDates()[i]; // << ",";
									 // if i != getdates.size-1, then print comma
		if (i != rhs.getDates().size() - 1)
		{
			lhs << ",";
		}
	}
	lhs << endl;

	return lhs;
}

ifstream &operator >> (ifstream &lhs, Record &rhs)
{
	// input from file
	string name = "", email = "", major = "", level = "", credits = "";
	int record = 0, id = 0;

	lhs >> record;
	getline(lhs, name, ',');
	lhs >> id;
	getline(lhs, name, '\"');
	getline(lhs, name, '\"');
	getline(lhs, email, ',');
	getline(lhs, email, ',');
	getline(lhs, credits, ',');
	getline(lhs, major, ',');
	getline(lhs, level, '\n');

	rhs.setRecordNum(record);
	rhs.setIdNum(id);
	rhs.setName(name);
	rhs.setEmail(email);

	if (credits == "AU")
	{
		rhs.setNumCredits(0);
	}
	else
	{
		rhs.setNumCredits(std::stoi(credits));
	}

	rhs.setMajor(major);
	rhs.setGradeLevel(level);



	return lhs;
}

ostream &operator << (ostream &lhs, Record &rhs)
{
	// print to screen
	lhs << rhs.getRecordNum() << endl;
	lhs << rhs.getIdNum() << endl;
	lhs << rhs.getName() << endl;
	lhs << rhs.getEmail() << endl;
	lhs << rhs.getNumCredits() << endl;
	lhs << rhs.getMajor() << endl;
	lhs << rhs.getGradeLevel() << endl;
	lhs << rhs.getAbsences() << endl << endl;

	return lhs;
}