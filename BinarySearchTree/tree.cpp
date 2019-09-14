#include <iostream>
#include "Tree.h"

node* createNewNode(int input)
{
	node *newNode = new node;
	newNode->data = input;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

Tree::Tree()
{
	root = nullptr;
}

void Tree::insertPrivate(node *currentNode, int number)
{
	if (root == nullptr)
	{
		root = createNewNode(number);
	}
	else if (number < currentNode->data)
	{
		if (currentNode->left == nullptr)
			currentNode->left = createNewNode(number);
		else
			insertPrivate(currentNode->left, number);
	}
	else
	{
		if (currentNode->right == nullptr)
			currentNode->right = createNewNode(number);
		else
			insertPrivate(currentNode->right, number);
	}
}

void Tree::insert(int number)
{
	insertPrivate(root, number);
}

void Tree::display()
{
	displayPrivate(root);
}

void Tree::displayPrivate(node *currentNode)
{
	if (currentNode->left != nullptr)
		displayPrivate(currentNode->left);
	if (currentNode != nullptr)
		std::cout << currentNode->data << std::endl;
	if (currentNode->right != nullptr)
		displayPrivate(currentNode->right);
}

node* Tree::findSmallestValue()
{
	node* lowestValue = findSmallestValuePrivate(root);
	return lowestValue;
}

node* Tree::findSmallestValuePrivate(node *currentNode)
{
	while (currentNode->left != nullptr)
		currentNode = currentNode->left;
	return currentNode;
}

void Tree::deleteNode(int input)
{
	deleteNodePrivate(root, input);
} 

void Tree::deleteNodePrivate(node *currentNode, int input)
{
	if (currentNode == nullptr)									//Number is not in the tree, invalid user input
	{
		std::cout << "ERROR: NUMBER NOT FOUND\n";
	}
	else if (input < currentNode->data)							//Number is in the left branch of the node,
	{															//search the left branch if possible
		deleteNodePrivate(currentNode->left, input);
	}
	else if (input > currentNode->data)							//Number is in the right branchof the node,
	{															//search the right branch if possible
		deleteNodePrivate(currentNode->right, input);
	}
	else														//Number is in the current node!
	{
		if (currentNode->left == nullptr && currentNode->right == nullptr)			//Deleted node has no children nodes
			deleteNode0(currentNode, input);
		else if (currentNode->left == nullptr || currentNode->right == nullptr)		//Deleted node has only one child node
			deleteNode1(currentNode, input);
		else																		//Deleted node has two children nodes
			deleteNode2(currentNode, input);
	}
}

void Tree::deleteNode0(node *currentNode, int input)
{
	node *endNode = findPreviousNode(currentNode, input);
	if (endNode->left == currentNode)
		endNode->left = nullptr;
	else
		endNode->right = nullptr;
	delete currentNode;
}

void Tree::deleteNode1(node *currentNode, int input)
{
	node *endNode = findPreviousNode(currentNode, input);
	if (endNode->left == currentNode)
		if (currentNode->left != nullptr)
			endNode->left = currentNode->left;
		else
			endNode->left = currentNode->right;
	else
		if (currentNode->left != nullptr)
			endNode->right = currentNode->left;
		else
			endNode->right = currentNode->right;
	delete currentNode;
}

void Tree::deleteNode2(node *currentNode, int input)
{
	node *duplicateNode = currentNode->right;
	duplicateNode = findSmallestValuePrivate(duplicateNode);
	int newNodeValue = duplicateNode->data;
	if (duplicateNode->left == nullptr && duplicateNode->right == nullptr)
		deleteNode0(duplicateNode, duplicateNode->data);
	else
		deleteNode1(duplicateNode, duplicateNode->data);
	currentNode->data = newNodeValue;
}

node* Tree::findPreviousNode(node *targetNode, int number)
{
	node *currentNode = root;
	while (currentNode->left != targetNode && currentNode->right != targetNode)
	{
		if (number < currentNode->data)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	return currentNode;
}