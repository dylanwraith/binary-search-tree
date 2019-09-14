#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree list;
	list.insert(15);
	list.insert(115);
	list.insert(1);
	list.insert(105);
	list.insert(106);
	list.insert(102);
	list.insert(103);
	list.insert(151);
	list.insert(175);
	list.insert(144);
	list.insert(150);
	list.insert(133);
	list.insert(140);
	cout << "***List***\n";
	list.display();
	node *lowestValue = list.findSmallestValue();
	cout << "\nThe lowest value in this list is " << lowestValue->data << endl;
	list.deleteNode(115);
	cout << "\n\n\n***List after deletion***\n";
	list.display();
	return 0;
}