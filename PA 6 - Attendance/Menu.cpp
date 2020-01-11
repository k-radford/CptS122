#include "Menu.h"

Menu::Menu()
{
}

Menu::Menu(Menu &copyMenu)
{
}

Menu::~Menu()
{
}

// Reads the .csv course file and overwrites the master list.
void Menu::importCourseList(List &list)
{
	Record classList;
	inputStream.open("classList.csv");
	string trash = "";

	cout << "LOADING COURSE LIST..." << endl;
	getline(inputStream, trash); // gets rid of header for doc

	while (!inputStream.eof())
	{
		inputStream >> classList;
		list.insertAtEnd(classList);
	}

	inputStream.close();
	cout << "*COURSE LIST LOADED*" << endl << endl;
}

// Populates the master list with previous nodes from masterList.csv.
// aka load from masterList.csv
void Menu::loadMasterList(List &list)
{
	Record masterList;
	inputStream.open("masterList.csv");

	cout << "LOADING MASTER LIST..." << endl;
	while (!inputStream.eof())
	{
		inputStream >> masterList;
		list.insertAtEnd(masterList);
	}

	inputStream.close();
	cout << "*MASTER LIST LOADED*" << endl << endl;
}

// Stores the contents of the master list’s nodes to master.csv.
void Menu::storeMasterList(List &list)
{
	cout << "STORING MASTER LIST..." << endl;
	outputStream.open("masterList.csv");
	outputStream << masterList;

	outputStream.close();
	cout << "*MASTER LIST STORED*" << endl << endl;
}

// Runs through the master list, displays each student’s name, and prompts if he/she was absent for the current day. 
// The data must be pushed to the stack that is contained within the node representative of the student.
void Menu::markAbsences()
{
	string date = "", year = "", month = "", day = "";

	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	cout << "Today's Date: " << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << endl;
	year = std::to_string(now->tm_year + 1900);
	month = std::to_string(now->tm_mon + 1);
	day = std::to_string(now->tm_mday);

	cout << "*TAKING ATTENDENCE* Enter 1 = absent, 0 = present" << endl << endl;

	Node *pTemp = masterList.getpHead();
	
	int attendence = 0;

	if (pTemp == NULL)
		cout << "No Students in Master List" << endl << endl;
	else
	{
		while (pTemp->getNextPtr() != nullptr)
		{
			cout << "Student: " << pTemp->getRecordPtr()->getName() << endl; // Prints name
			cout << "Was this student absent today?" << endl;
			cin >> attendence;
			pTemp->getRecordPtr()->setAbsences(attendence); // Marks attendence
			date = year + '-' + month + '-' + day;
			if (attendence == 1)
			{
				pTemp->getRecordPtr()->setDates(date); // adds date to vector array
			}
			pTemp = pTemp->getNextPtr();
		}
		cout << "ATTENDENCE RECORDED" << endl << endl;
	}
}

// Prompts for an ID number or name of student to edit. Prompts for the date of absence to edit.
// Extra Credit: 20 pts
void Menu::editAbsences()
{
	int id = 0; 
	string date = "";
	cout << "Please enter the id of student you want to edit" << endl;
	cin >> id;
	cout << "Please enter the date of which to edit the absence in the format YYYY-M-D" << endl;
	cin >> date;

	Node *pTemp = masterList.getpHead();

	while (pTemp != nullptr)
	{
		if ((pTemp->getRecordPtr()->getIdNum()) == id)
		{
			cout << endl << "Editing Absence of Student: " <<pTemp->getRecordPtr()->getName() << endl;
			for (int i = 0; i < (pTemp->getRecordPtr()->getDates().size()); i++)
			{
				if (pTemp->getRecordPtr()->getDates()[i] == date)
				{
					cout << "Editing Absence Date: " << pTemp->getRecordPtr()->getDates()[i] << endl;
					// modify to remove this date from vector array
					// pTemp->getRecordPtr()->getDates().erase(pTemp->getRecordPtr()->getDates().begin() + (i - 1)); 
					pTemp->getRecordPtr()->getDates()[i].erase(0);
					pTemp->getRecordPtr()->setAbsences(-1); //remove absence from record
					cout << "Successfully Removed Absence from Record" << endl;
				}
				else
				{
					cout << "Was Not Able to Remove an Absence. Possible Problems: " << endl;
					cout << "1. Student Id Entered Incorrectly" << endl << "2. Have you loaded your class list first?" << endl;
					cout << "3. Absence date incorrect" << endl << endl;
				}
			}
		}
		pTemp = pTemp->getNextPtr();
	}
	cout << "ABSENCE EDITED" << endl;
}

// Submenu -> 1. Generate report for all students; showing only the most recent absence for each student.This is a peek() operation!
// 2. Generate report for students with absences that match or exceed(the number entered by the user).
void Menu::generateReport()
{
	bool status = true;
	do
	{
		int option2 = 0, n = 0;
		cout << "GENERATE REPORT" << endl << "1. Generate report for all students" << endl;
		cout << "2. Generate report for students with absences that match or exceed -user entered variable-" << endl;
		cout << "3. Exit Report Menu" << endl;

		Node *pTemp = masterList.getpHead();

		cin >> option2;
		cout << endl;

		if (option2 == 1)
		{
			while (pTemp->getNextPtr() != nullptr)
			{
				cout << (pTemp->getRecordPtr()->getName()) << "  ";
				if (pTemp->getRecordPtr()->getDates().size() == 0)
				{
					cout << "No Absences" << endl;
				}
				else
				{
					cout << pTemp->getRecordPtr()->getDates().back() << endl;
				}
				pTemp = pTemp->getNextPtr();
			}
			cout << endl;
		}

		if (option2 == 2)
		{
			cout << "You want to see the students with how many absences?" << endl;
			cin >> n;
			while (pTemp->getNextPtr() != nullptr)
			{
				if (pTemp->getRecordPtr()->getAbsences() == n)
				{
					cout << pTemp->getRecordPtr()->getName() << endl;
				}
				pTemp = pTemp->getNextPtr();
			}
			cout << endl;
		}

		if (option2 == 3)
		{
			cout << "Exiting Sub-Menu" << endl << endl;
			status = false; // Exit
		}

		if (option2 == 4)
		{
			cout << "ERROR: Invalid choice!" << endl;
		}

	} while (status != false);
}

void Menu::displayMenu()
{
	cout << "MAIN MENU" << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences" << endl;  // Bonus 20 pts
	cout << "6. Generate report" << endl;
	cout << "7. Exit" << endl;
}

int Menu::getMenuOption() const
{
	int option = 0;

	cin >> option;

	system("cls");

	return option;
}

void Menu::runTracker()
{
	int option = 0;
	bool status = true, success = true;

	cout << "*** Welcome to KR's Attendance Tracker Application ***" << endl << endl;

	do
	{
		displayMenu();
		option = getMenuOption();

		switch (option)
		{
		case 1:
			importCourseList(masterList);
			break;
		case 2:
			loadMasterList(masterList);
			break;
		case 3:
			storeMasterList(masterList);
			break;
		case 4:
			markAbsences();
			break;
		case 5:
			editAbsences();
			break;
		case 6:
			generateReport();
			break;
		case 7:
			cout << "*** Now Exiting KR's Attendance Tracker ***" << endl;
			status = false; // Exit
			break;
		default: 
			cout << "ERROR: Invalid choice!" << endl;
			break;
		}

	} while (status != false);
}