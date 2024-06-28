#include "table.h"

int table::removeSmallestOneChild() 
{
   bool isRemoved = false;
   if(!root) return 0;
   return removeSmallestOneChild(root, isRemoved);
}

int table::removeSmallestOneChild(node *& root, bool & isRemoved)
{
   int count = 0;

   if(!root) return 0;

   count = removeSmallestOneChild(root->left, isRemoved);

   if(!root->left && root->right && !isRemoved)
   {
      node * hold = root->right;
      delete root;
      root = hold;
      isRemoved = true;
      return 1;
   }
   if(root->left && !root->right && !isRemoved)
   {
      node * hold = root->left;
      delete root;
      root = hold;
      isRemoved = true;
      return 1 ;
   }

   count += removeSmallestOneChild(root->right, isRemoved);
   return count;

}
