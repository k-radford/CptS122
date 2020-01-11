#include "BST.h"

//////////////////////////////////////////////////////////  PUBLIC  //////////////////////////////////////////////////////////////////

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

Node* BST::getRootPtr()
{
	return mpRoot;
}

// public used to hide pointer information, i.e. won’t pass in the root of the tree into this function, only the private insert() function
void BST::insert(int &units, string &date)
{
	insert(mpRoot, units, date);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

// Returns a reference to a TransactionNode (i.e TransactionNode &)  with the smallest mUnits
TransactionNode& BST::findSmallest()
{
	TransactionNode *temp = dynamic_cast<TransactionNode*>(mpRoot);
	while (temp->getLeftPtr() != nullptr)
	{
		temp = dynamic_cast<TransactionNode*>(temp->getLeftPtr());
	}
	return *temp;
}

//Returns a reference to a TransactionNode with the largest mUnits
TransactionNode& BST::findLargest()
{
	TransactionNode *temp = dynamic_cast<TransactionNode*>(mpRoot);
	while (temp->getRightPtr() != nullptr)
	{
		temp = dynamic_cast<TransactionNode*>(temp->getRightPtr());
	}
	return *temp;
}



///////////////////////////////////////////////////////////  PRIVATE  ////////////////////////////////////////////////////////////////

// Should visit each node in postOrder to delete them
void BST::destroyTree(Node *pRoot)
{
	if (pRoot != nullptr)
	{
		destroyTree(pRoot->getLeftPtr());
		destroyTree(pRoot->getRightPtr());
		delete(pRoot);
	}
}

// Dynamically allocates a TransactionNode and inserts recursively in the correct subtree based on mUnits; 
// should pass in a reference to a pointer(i.e.Node *& pT)
void BST::insert(Node *&node, int &units, string &data)
{
	if (node == nullptr) // base case
	{
		Node *pRoot = new TransactionNode(data, units);
		node = pRoot;
	}
	else // recursive case
	{
		if (units < (dynamic_cast<TransactionNode*>(node))->getUnits()) // go left for inserting
		{
			insert(node->getLeftPtr(), units, data);
		}
		else if (units > (dynamic_cast<TransactionNode*>(node))->getUnits()) // go right for inserting
		{
			insert(node->getRightPtr(), units, data);
		}
	}
}

// recursively visits and prints the contents (mData and mUnits) of each node in the tree in order; each node’s printData() should be 
// called contents should be printed on a separate line; must call the printData() function associated with the TransactionNode
void BST::inOrderTraversal(Node *pRoot)
{
	if (pRoot != nullptr)
	{
		inOrderTraversal(pRoot->getLeftPtr());
		pRoot->printData();
		inOrderTraversal(pRoot->getRightPtr());
	}
}