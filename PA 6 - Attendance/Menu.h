#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

#include "Record.h"
#include "Node.h"
#include "Stack.h"
#include "List.h"

class Menu
{
public:
	Menu();
	Menu(Menu &copyMenu);
	~Menu();

	void importCourseList(List &list);
	void loadMasterList(List &list);
	void storeMasterList(List &list);
	void markAbsences();
	void editAbsences();
	void generateReport();

	void runTracker();
	void displayMenu();
	int getMenuOption() const;

private:
	List masterList;
	ifstream inputStream;
	ofstream outputStream;
};


