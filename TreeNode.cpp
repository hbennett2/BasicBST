#include "TreeNode.h"
/*-- TreeNode.cpp------------------------------------------------------------
   This file implements the TreeNode member functions.
-------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

/* constructor to create the tree node */
TreeNode::TreeNode(ElementType value, TreeNode* l, TreeNode * r)
{
	data = value;
	left = l;
	right = r;
}

/* helper function to delete the entire tree of section of a tree 
   This is a recursive function */
void TreeNode::deleteTree(TreeNode *node) 
{
	if (node != NULL)
	{
		deleteTree(node->right);
		deleteTree(node->left);
		delete node;
	}
}