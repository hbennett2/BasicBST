/*-- main.cpp------------------------------------------------------------
   This file implements the driver for the BSTstd
-------------------------------------------------------------------------*/

#include <iostream>
#include "BSTstd.h"

int main()
{
	// Create the binary search tree object
	BSTstd* t1 = new BSTstd();
	t1->insert(5);
	t1->insert(8);
	t1->insert(3);
	t1->insert(1);
	t1->insert(4);
	t1->insert(9);
	t1->insert(18);
	t1->insert(20);
	t1->insert(19);
	t1->insert(2);
	t1->traversal();
	if (t1->search(3)) std::cout << "\n   3 was found!" << std::endl;	
	if (t1->search(18)) std::cout << "   18 was found!" << std::endl;	
	if (t1->search(19)) std::cout << "   19 was found!" << std::endl;	
	t1->remove(9);
	t1->traversal();
	t1->remove(2);
	t1->traversal();
	t1->remove(8);
	t1->traversal();
	t1->remove(3);
	t1->traversal();
	t1->remove(5);
	t1->traversal();
	// Delete the binary search tree
	delete t1;
	return 0;
}

