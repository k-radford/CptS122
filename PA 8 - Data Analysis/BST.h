#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <string>

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

#include "Node.h"

class BST
{
public:
	BST();
	~BST();

	// setters
	
	// getters
	Node* getRootPtr();

	void insert(int &units, string &date);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();

private:
	void destroyTree(Node *pRoot);
	void insert(Node *&pRoot, int &units, string &data);
	void inOrderTraversal(Node *pRoot);

	Node *mpRoot;
};

/*
Define a class BST, which encapsulates the following:

Data members:

- mpRoot : Node * // yes, we want a pointer to a Node, not TransactionNode here!

Member functions:

+ destructor // calls destroyTree ()
- destroyTree () // yes, it’s private, and it should visit each node in postOrder to delete them
+ default constructor
+ setter
+ getter
+ insert () // public used to hide pointer information, i.e. won’t pass in the root of the tree into this function,
only the private insert () function
- insert () // yes, it’s private, and it dynamically allocates a TransactionNode and inserts recursively in the correct subtree
based on mUnits; should pass in a reference to a pointer (i.e. Node *& pT)
+ inOrderTraversal () // yes, once again it’s private to hide pointer information
- inOrderTraversal (), which recursively visits and prints the contents (mData and mUnits) of each node in the tree in order; each node’s
printData () should be called contents should be printed on a separate line; must call the printData () function associated with
the TransactionNode
+ findSmallest (), which returns a reference to a TransactionNode (i.e TransactionNode &)  with the smallest mUnits
+ findLargest (), which returns a reference to a TransactionNode with the largest mUnits

*/