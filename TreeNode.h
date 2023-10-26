#ifndef TREENODE
#define TREENODE
/*-- TreeNode.h ---------------------------------------------------------------

  This header file defines the class for a TreeNode
  Basic operations are:
	 Constructor
-------------------------------------------------------------------------*/
#include "ElementType.h"
#include <cstddef>

class TreeNode {
public:
	ElementType data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(ElementType value, TreeNode* l = NULL, TreeNode * r = NULL);

	/* Required for proper memory management - call this to delete all 
	   nodes remaining in the tree */
	static void deleteTree(TreeNode* root);
};


#endif

