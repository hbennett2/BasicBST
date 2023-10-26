
/*-- BSTstd.h ---------------------------------------------------------------
  This header file defines the  class for a Binary Search Tree using nodes 
  and pointers
  Basic operations are:
	 Constructor
	 insert
	 remove
	 findMin
	 findMax
	 inorder
	 traversal
-------------------------------------------------------------------------*/
#ifndef BST_STD
#define BST_STD

#include "TreeNode.h"

class BSTstd
{
public:
	/* constructor */
	BSTstd();
	/* destructor */
	~BSTstd();

	/* insert an element in the binary tree */
	void insert(ElementType element);
	/* remove an element from the binary tree */
	void remove(ElementType element);
	/* find the minimum value in the tree */
	int findmin();
	/* find the max value in the tree */
	int findmax();
	/* traverse the tree inorder */
	void inorder();
	/* traverse the tree  */
	/* traverse the tree preorder */
	void preorder();
	/* traverse the tree postorder */
	void postorder();
	void traversal();
	/* Search for an element in the binary search tree */
    bool search(ElementType element);

private:
	TreeNode* root;

	/* private methods used as helper functions */
	int findmax(TreeNode* p);
	int findmin(TreeNode* p);
	void inorder(TreeNode* p);
	void preorder(TreeNode* p);
	void postorder(TreeNode* p);

};
#endif