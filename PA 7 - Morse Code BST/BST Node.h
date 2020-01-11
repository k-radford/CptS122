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

// 15 pts - Defining the BSTNode structure
// 1.    4 pts correct data members in node(char, string, left and right pointers)
// 2.    3 pts correct constructor
// 3.    8 pts other member functions

class BSTNode
{
public:
	// have a constructor that accepts arguments to set the English text character and Morse code string.
	BSTNode(char letter = '\0', string morse = "");
	BSTNode(BSTNode &copyBSTNode);
	~BSTNode();

	// getters
	BSTNode *&getRightPtr();
	BSTNode *&getLeftPtr();
	char getLetter();
	string getMorse();

	//setters
	void setRightPtr(BSTNode *newNode);
	void setLeftPtr(BSTNode *newNode);
	void setLetter(char newLetter);
	void setMorse(string newCode);

private:
	BSTNode *pLeft;
	BSTNode *pRight;
	char mLetter;
	string mMorse;

};

ofstream &operator << (ofstream &lhs, BSTNode &rhs);
ostream &operator << (ostream &lhs, BSTNode &rhs);
