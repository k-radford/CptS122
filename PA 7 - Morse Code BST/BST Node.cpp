#include "BST Node.h"

BSTNode::BSTNode(char letter, string morse)
{
	mLetter = letter;
	mMorse = morse;
	pLeft = nullptr;
	pRight = nullptr;
}

BSTNode::BSTNode(BSTNode &copyBSTNode)
{
	mLetter = copyBSTNode.getLetter();
	mMorse = copyBSTNode.getMorse();
	pLeft = nullptr;
	pRight = nullptr;
}

BSTNode::~BSTNode()
{

}

void BSTNode::setLetter(char newLetter)
{
	mLetter = newLetter;
}

void BSTNode::setMorse(string newCode)
{
	mMorse = newCode;
}

void BSTNode::setLeftPtr(BSTNode *newNode)
{
	pLeft = newNode;
}

void BSTNode::setRightPtr(BSTNode *newNode)
{
	pRight = newNode;
}

char BSTNode::getLetter()
{
	return mLetter;
}

string BSTNode::getMorse()
{
	return mMorse;
}

BSTNode*& BSTNode::getLeftPtr()
{
	return pLeft;
}

BSTNode*& BSTNode::getRightPtr()
{
	return pRight;
}

// output to file
ofstream &operator << (ofstream &lhs, BSTNode &rhs)
{

	return lhs;
}

// print to screen
ostream &operator << (ostream &lhs, BSTNode &rhs)
{

	lhs << rhs.getMorse() << endl;

	return lhs;
}
