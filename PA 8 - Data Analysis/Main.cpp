// Kate Radford
// PA 8 - Data Analysis using Binary Search Trees
// Due Friday, April 13th

#include "BST.h"
#include "DataAnalysis.h"
#include "Node.h"

int main(void)
{
	DataAnalysis obj;

	obj.runAnalysis();

	return 0;
}

// Questions for you to consider(you do not need to submit answers to these questions):

// -We understand that a BST is most efficient when it is balanced.If the data.csv file was not already organized to 
//  provide a fairly balanced tree, how would you balance the tree as you insert?

// -Do you think there are other data structures that would be better suited for this type of problem? Why?

// -What would happen to our program if we found duplicate products or # of units sold / purchased in the file? 
//  Would we need a data structure to efficiently combine the products and # of units? Hash table?