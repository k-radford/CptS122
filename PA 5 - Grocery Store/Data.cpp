#include "Data.h"

Data::Data(int customer, int service, int total)
{
	this->customerNumber = customer;
	this->serviceTime = service;
	this->totalTime = total;
}

Data::Data(Data &copyData)
{
	customerNumber = copyData.getCustomerNum();
	serviceTime = copyData.getServiceTime();
	totalTime = copyData.getTotalTime();
}

Data::~Data()
{
	// TA says this isnt needed
}

Data & Data::operator= (Data &rhs)
{
	if (this != &rhs)
	{
		customerNumber = rhs.getCustomerNum();
		serviceTime = rhs.getServiceTime();
		totalTime = rhs.getTotalTime();
	}
	return *this;
}

int Data::getCustomerNum()
{
	return customerNumber;
}

int Data::getServiceTime()
{
	return serviceTime;
}

int Data::getTotalTime()
{
	return totalTime;
}
void Data::setCustomerNum(int newCustomer)
{
	customerNumber = newCustomer;
}

void Data::setServiceTime(int newService)
{
	serviceTime = newService;
}

void Data::setTotalTime(int newTotal)
{
	totalTime = newTotal;
}
