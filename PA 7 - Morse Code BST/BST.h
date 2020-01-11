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

#include "BST Node.h"


// To do templates , create two template classes for string and char

// 50 pts - Creating the BST code and create a Morse lookup BST
// 1.    2 pts correct data member in BST(root)
// 2.    10 pts correct insert()
// 3.    2 pts for opening “MorseTable.txt”
// 4.    2 pts for closing “MorseTable.txt”
// 5.    6 pts for reading contents of “MorseTable.txt”
// 6.    5 pts for correct print()
// 7.    9 pts for correct search()
// 8.    6 pts for correct constructor
// 9.    8 pts for correct destructor

class BST
{
public:
	// The tree should be built by the constructor for the BST.
	// This means the constructor must open and read the file, create nodes for each character in the tree, insert the nodes into the tree 
	// (using an insert () function), and close the file. Note: the tree object could be declared as const, since all changes to it are 
	// being performed in the constructor.
	BST(BSTNode *pRoot = nullptr);
	BST(BST &copyBST);
	~BST();

	BSTNode *getRootPtr();
	void insert(char &letter, string &code);
	void print(BSTNode *pRoot);
	string search(BSTNode *pRoot, char letter);
	void printMorse(BSTNode *pRoot);
	void destroyTree(BSTNode *pRoot);
	void runBST();

private:
	BSTNode *mpRoot;
	ifstream inputStream;
	ofstream outputStream;

	void insert(BSTNode *&pRoot, char &letter, string &code);

};
