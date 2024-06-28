#include "table.h"

//wrapper function
int table::copyNotLargest(table & to_copy)
{
   if(!to_copy.root) return 0;
   return copyNotLargest(root,to_copy.root);
}

//recursive function:
//keep calling copyRootAndLeftSub on roots right child
//until roots right child is the largest element 
//Then either return or copy largest's left subtree
int table::copyNotLargest(node *& dest_root, node * source_root)
{
   int count = 0;
   if(!source_root->right && !source_root->left) return count;
   if(!source_root->right && source_root->left)
   {
      count += copy(dest_root, source_root->left);
      return count;
   }
   count += copyRootAndLeftSub(dest_root, source_root);
   count += copyNotLargest(dest_root->right, source_root->right);
   return count;
}



//copy root and left subtree HELPER
int table::copyRootAndLeftSub(node *& dest_root, node * source_root)
{
   int count = 0;
   if(!source_root) return 0;
   dest_root = new node;
   dest_root->data = source_root->data;
   dest_root->left = dest_root->right = NULL;
   ++count;
   count += copy(dest_root->left, source_root->left);
   return count;
}

//general copy function HELPER
int table::copy(node *& dest_root, node * source_root)
{
   int count = 0;
   if(!source_root) return 0;
   dest_root = new node;
   dest_root->data = source_root->data;
   dest_root->left = dest_root->right = NULL;
   ++count;
   count += copy(dest_root->left, source_root->left);
   count += copy(dest_root->right, source_root->right);
   return count;
}






