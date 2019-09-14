#pragma once
#include <iostream>

struct node
{
	int data;
	node *left;
	node *right;
};

class Tree
{
private:
	node *root;
	void insertPrivate(node*, int);			//Inserts node in tree in ascending order
	void displayPrivate(node*);				//Displays each value in the array in ascending order
	void deleteNodePrivate(node*, int);		//Deletes the first instance of the input value from the tree
	node* findSmallestValuePrivate(node*);	//Finds node with smallest vaule starting at input
	node* findPreviousNode(node*, int);		//Finds node previous to node input
	void deleteNode0(node*, int);			//Used by deleteNodePrivate function for 0 child node case
	void deleteNode1(node*, int);			//Used by deleteNodePrivate function for 0 child node case
	void deleteNode2(node*, int);			//Used by deleteNodePrivate function for 0 child node case
public:
	Tree();
	void insert(int);						//Calls insertPrivate using root as input
	void display();							//Calls displayPrivate using root as input
	void deleteNode(int);					//Calls deleteNodePrivate using root as input
	node* findSmallestValue();				//Finds node with lowest number starting at root
};