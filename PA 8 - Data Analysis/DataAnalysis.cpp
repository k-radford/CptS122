#include "DataAnalysis.h"

/////////////////////////////////////////////////////////////  PUBLIC  /////////////////////////////////////////////////////////////////////
DataAnalysis::DataAnalysis()
{

}

DataAnalysis::~DataAnalysis()
{

}

void DataAnalysis::runAnalysis()
{
	readCsv();
	loop();
	printTrends();
}

/////////////////////////////////////////////////////////////  PRIVATE  ///////////////////////////////////////////////////////////////////

// A function that opens data.csv yes, it’s private, and must use mCsvStream to open the file
void DataAnalysis::readCsv()
{
	mCsvStream.open("data.csv");
	cout << "LOADING SYSTEM DATA..." << endl << endl;
}

// A function that reads one line from the file and splits the line into units, type, and transaction fields
void DataAnalysis::readLine()
{
	string tempUnits = "", tempData = "", tempTransaction = "";
	getline(mCsvStream, tempUnits, ',');
	getline(mCsvStream, tempData, ',');
	getline(mCsvStream, tempTransaction, '\n');
	
	soldOrPurchased(tempTransaction, std::stoi(tempUnits), tempData);
}

// A function that loops until all lines are read from the file; calls the function below, and then displays the current contents of both BSTs;
// use inOrderTraversal() to display the trees
void DataAnalysis::loop()
{
	string trash;
	getline(mCsvStream, trash);
	while (!mCsvStream.eof())
	{
		readLine();
	}
	mCsvStream.close();
	cout << "PURCHASED: " << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl << "SOLD: " << endl;
	mTreeSold.inOrderTraversal();
}

// A function that compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased)
// note with the way the data.csv file is organized the trees will be fairly balanced
void DataAnalysis::soldOrPurchased(string transaction, int units, string data)
{
	if (transaction == "Purchased")
	{
		mTreePurchased.insert(units, data);
	}
	else if (transaction == "Sold")
	{
		mTreeSold.insert(units, data);
	}
}
	
// A function that writes to the screen the trends we see in our tree; the function must display the type and number of units that are least
// purchased and sold, and the most purchased and sold
void DataAnalysis::printTrends()
{
	// Your system is only required to output the following to the screen :
	// -The contents of the two BSTs, which will be printed in order
	// - The product that type and number of units that sold the most
	// - The product that type and number of units that sold the least
	// - The product that type and number of units that were purchased the most
	// - The product that type and number of units that were purchased the least

	cout << endl << "The product that was purchased the least: " << mTreePurchased.findSmallest().getData() << endl;
	cout << "The product that was purchased the most: " << mTreePurchased.findLargest().getData() << endl;
	cout << "The product that was sold the least: " << mTreeSold.findSmallest().getData() << endl;
	cout << "The product that was sold the most: " << mTreeSold.findLargest().getData() << endl << endl;

}