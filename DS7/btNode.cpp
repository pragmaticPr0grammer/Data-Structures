#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert (btNode*& root, const int number)
{
   btNode* newOne = new btNode;
   newOne->left = 0;
   newOne->right = 0;
   newOne->data = number;

	if (root == 0)
   {
      root = newOne;
		return;
   }

   btNode* cursor = root;

	bool done = false;
	while (!done)
   {
      if (number <= cursor->data)
      {
         if (cursor->left == 0)
         {
            cursor->left = newOne;
            done = true;
         }
         else
            cursor = cursor->left;
      }
      else
      {
         if (cursor->right == 0)
         {
            cursor->right = newOne;
            done = true;
         }
         else
            cursor = cursor->right;
      }
   }
   return;
   }

bool bst_remove (btNode*& root, const int target)
{
   btNode* oldroot;

   if (root == 0) return false;

   if (target < root->data)
		return (bst_remove(root->left, target));

   if (target > root->data)
      return (bst_remove(root->right, target));

   if (root->left == 0)
   {
		oldroot = root;
		root = root->right;
		delete oldroot;
		return true;
	}
	else
   {
    bst_remove_max(root->left, root->data);
    return true;
   }
}

void bst_remove_max (btNode*& root, int& number)
{
   btNode* oldRoot;
   if (root->right == 0)
   {
      number = root->data;
      oldRoot = root;
		root = root->left;
		delete oldRoot;
		return;
   }
      bst_remove_max(root->right, number);
}
