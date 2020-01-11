#pragma once
#include <iostream>
#include <string>
#include <cstdlib> 
#include <fstream>
#include <ctime>

using std::fstream;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Data
{

public: 
	Data(int customer = 0, int service = 0, int total = 0);
	Data(Data &copyData);
	~Data();
	Data & operator= (Data &rhs);

	// setters
	int getCustomerNum();
	int getServiceTime();
	int getTotalTime();
	// getters
	void setCustomerNum(int newCustomer = 0);
	void setServiceTime(int newService = 0);
	void setTotalTime(int newTotal = 0);


private:

	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime;    // Random time; varies between express and normal lanes; units in minutes
	int totalTime;      // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

	Data *pData;

}; // This memory needs to be allocated on the heap!