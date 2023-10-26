/*-- BSTstd.cpp------------------------------------------------------------
   This file implements the BSTstd member functions.
-------------------------------------------------------------------------*/
#include "BSTstd.h"
#include <iostream>
using namespace std;

/* Constructor */
BSTstd::BSTstd()
{
	root = NULL;
}

/* Destructor */
BSTstd::~BSTstd()
{
	if (root != NULL) TreeNode::deleteTree(root);
}

/* Insert an element into the BST */
void BSTstd::insert(ElementType element)
{
	TreeNode* newptr = new TreeNode(element);

	if (root == NULL)
	{
		root = newptr;
	}
	else
	{
		TreeNode* p = root;
		TreeNode* parent = NULL;
		while ((p != NULL) && (p->data != element)) //find the right location for the new node
		{
			if (element < p->data)
			{
				parent = p;
				p = p->left;
			}
			else
			{
				parent = p;
				p = p->right;
			}
		}

		if (p == NULL) //if the element is not in the BST
		{
			if (element < parent->data)
				parent->left = newptr;
			else
				parent->right = newptr;
		}
		else
			cout << "node duplicate!" << endl;
	}
}

/* Remove an element from the BST */
void BSTstd::remove(ElementType element)
{
	TreeNode* p = root;
	TreeNode* parent = NULL;
	
	if (root == NULL) // No nodes in the tree
	{
		cout << "tree is empty, unable to remove element" << endl;
		return;
	}

	while ((p != NULL) && (p->data != element)) //find the correct location for the new node
	{
		if (element < p->data)
		{
			parent = p;
			p = p->left;
		}
		else
		{
			parent = p;
			p = p->right;
		}
	}

	if (p == NULL)  // Element not found
	{
		cout << "Unable to find element.  It will not be removed" << endl;
	} 
	else             // Element was found, so let's remove it
	{
		if (p->left == NULL && p->right == NULL) //case 1
		{
			if (p == root) {  // node is root node
				root = NULL;
			}
			else
			{
				if (element < parent->data)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			delete p;
		}
		else if (p->left != NULL && p->right == NULL) //case 2
		{
			if (p == root)   // node is root nodes
			{
				root = p->left;
			}
			else
			{
				if (element < parent->data)
					parent->left = p->left;
				else
					parent->right = p->left;
			}
			delete p;
		}
		else if (p->left == NULL && p->right != NULL) //case 2
		{
			if (p == root)  // node is root node
			{
				root = p->right;
			}
			else
			{
				if (element < parent->data)
					parent->left = p->right;
				else
					parent->right = p->right;
			}
			delete p;
		}
		else //case 3 - neither child is NULL
		{
			int min_of_right_child = findmin(p->right);
			remove(min_of_right_child);
			p->data = min_of_right_child;
		}
	}
}

/* Find the minimum value recursively starting from a specific node */
int BSTstd::findmin(TreeNode* p)
{
	while (p->left != NULL)
		p = p->left;
	return p->data;
}

/* Find the minimum value for the entire tree */
int BSTstd::findmin()
{
	return findmin(root);
}

/* Find the maximum value recursivly starting from a specific node */
int BSTstd::findmax(TreeNode* p)
{
	while (p->right != NULL)
		p = p->right;
	return p->data;
}

/* Find the minimum value for the entire tree */
int BSTstd::findmax()
{
	return findmax(root);
}

/* Traverse the tree recursively from a node using inorder */
void BSTstd::inorder(TreeNode* p)
{
	if (p != NULL)
	{
		inorder(p->left);
		cout << p->data << " ";
		inorder(p->right);
	}

}

/* Traverse the tree inorder */
void BSTstd::inorder()
{
	inorder(root);
}

/* Traverse the tree recursively from a node using preorder */
void BSTstd::preorder(TreeNode* p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

/* Traverse the tree preorder */
void BSTstd::preorder()
{
	preorder(root);
}

/* Traverse the tree recursively from a node using preorder */
void BSTstd::postorder(TreeNode* p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout << p->data << " ";
	}
}

/* Traverse the tree postorder */
void BSTstd::postorder()
{
	postorder(root);
}

/* Display output of various traversal methods */
void BSTstd::traversal()
{
	cout << "\n Min value: " << findmin() << endl;
	cout << " Max value: " << findmax() << endl;
	cout << "\n Inorder: " << endl;
	inorder();
	cout << "\n------------------------------------------------------";
	cout << endl;
	cout << "\n Min value: " << findmin() << endl;
	cout << " Max value: " << findmax() << endl;
	cout << "\n Preorder: " << endl;
	preorder();
	cout << "\n------------------------------------------------------";
	cout << endl;
	cout << "\n Min value: " << findmin() << endl;
	cout << " Max value: " << findmax() << endl;
	cout << "\n Postorder: " << endl;
	postorder();
	cout << "\n------------------------------------------------------";
}

bool BSTstd::search(ElementType element)
{
	if (element != NULL)
	{
		TreeNode* locptr = root; //create location pointer
		bool found = false; //initialize bool
		
		cout << "\nSearch Path: ";
		while (!found && locptr != 0)
		{
			cout << locptr->data << "-";
			if (element < locptr->data) //decend left
				locptr = locptr->left;
			else if (locptr->data < element) //decend right
				locptr = locptr->right;
			else
				found = true; //item found
		}
		return found;
	}
}
