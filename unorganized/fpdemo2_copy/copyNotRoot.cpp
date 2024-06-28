#include "table.h"

int table::copyNotRoot(table & to_copy)
{
   int count = 0;
   if(!to_copy.root) return 0;                  //source tree is empty
   if(!to_copy.root->right && !to_copy.root->left) return 0; //source tree has one node
   if(!to_copy.root->right)                    //source tree root has one left child
      return copy(root, to_copy.root->left);        //source tree root has one right child
   if(!to_copy.root->left)
      return copy(root, to_copy.root->right);
   else                                        //source tree root ahs two children
   {
      node * hold = to_copy.root->right;
      count = copy(root, to_copy.root->left);
      node * largestNode = largest(root);
      count += copy(largestNode->right, hold);
      return count;
   }
}


//return a pointer to the largest element in the tree
node * table::largest(node * root)
{
   if(!root) return NULL;
   if(!root->right) return root;
   return largest(root->right);
}


//copy tree helper function
/*
int copy(node *& dest_root, node * source_root) 
{
   int count = 0;
   if(!root) return 0;
   dest_root = new node;
   dest_root->data = source_root->data;
   dest_root->right = dest_root->left = NULL;
   ++count;

   count += copy(dest_root->left, source_root->left);
   count += copy(dest_root->right, source_root->right);
   return count;
}
*/
