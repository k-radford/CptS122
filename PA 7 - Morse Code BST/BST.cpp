#include "BST.h"


// the constructor must open and read the file, create nodes for each character in the tree, insert the nodes into the tree 
// (using an insert () function), and close the file. Note: the tree object could be declared as const, since all changes to it are 
// being performed in the constructor.
BST::BST(BSTNode *pRoot)
{
	mpRoot = pRoot;
	string tempMorse = "";
	char tempLetter, garbage;
	inputStream.open("MorseTable.txt");
	cout << "LOADING MORSE CODE TABLE..." << endl << endl;
	while (!inputStream.eof())
	{
		inputStream.get(tempLetter);
		inputStream.get(garbage);
		getline(inputStream, tempMorse);
		insert(tempLetter, tempMorse);
	}

	inputStream.close();
}

BST::BST(BST &copyBST)
{

}

BST::~BST()
{
	destroyTree(mpRoot);
}

void BST::destroyTree(BSTNode *pRoot)
{
	if (pRoot != nullptr)
	{
		destroyTree(pRoot->getLeftPtr());
		destroyTree(pRoot->getRightPtr());
		delete(pRoot);
	}
}

BSTNode* BST::getRootPtr()
{
	return mpRoot;
}

void BST::insert(char &newLetter, string &newCode)
{
	insert(mpRoot, newLetter, newCode);
}

// private function
void BST::insert(BSTNode *&node, char &newLetter, string &newCode)
{
	if (node == nullptr) // base case
	{
		BSTNode *pRoot = new BSTNode(newLetter, newCode);
		node = pRoot;
	}
	else // recursive case
	{
		if (newLetter < node->getLetter()) // go left for inserting newText
		{
			insert(node->getLeftPtr(), newLetter, newCode); 
		}
		else if (newLetter > node->getLetter()) // go right for inserting newText
		{
			insert(node->getRightPtr(), newLetter, newCode);
		}
	}
}

// build a search ( ) function that will return the Morse code string for each English character searched for. 
// Do you need to return a found indicator from the search function? Should you use recursion?
string BST::search(BSTNode *pRoot, char key)
{
	// Base Cases: root is null or key is present at root
	if (pRoot->getLetter() == key)
		return pRoot->getMorse();

	// Key is greater than root's key
	if (pRoot->getLetter() < key)
		return search(pRoot->getRightPtr(), key);

	// Key is smaller than root's key
	else
		return search(pRoot->getLeftPtr(), key);
}

// Create a print ( ) function that uses recursion to traverse the tree in order (left most printed first).
void BST::print(BSTNode *pRoot)
{
	if (pRoot != nullptr)
	{
		print(pRoot->getLeftPtr());
		cout << pRoot->getMorse() << endl;
		print(pRoot->getRightPtr());
	}
}

// opens convert.txt reads from file, and converts string to Morse Code
void BST::printMorse(BSTNode *pRoot)
{
	char tempLetter, space;
	string morseCode = "";
	inputStream.open("Convert.txt");
	while (!inputStream.eof())
	{
		inputStream.get(tempLetter);
		if (tempLetter == ' ')
		{
			cout << ' ';
		}
		else if (tempLetter == '\n')
		{
			cout << endl;
		}
		else
		{
			morseCode = search(pRoot, toupper(tempLetter));
			cout << morseCode << ' ';
		}
	}
	cout << endl;
	
	inputStream.close();
}

void BST::runBST()
{
	printMorse(mpRoot);
}