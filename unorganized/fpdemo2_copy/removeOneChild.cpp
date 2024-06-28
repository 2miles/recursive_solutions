#include "table.h"

int table::removeOneChild()
{
   if(!root) return 0;
   return removeOneChild(root);
}
int table::removeOneChild(node *& root)
{
   int count = 0;
   if(!root) return 0;
   if(!root->left && !root->right) return 0;


   if(!root->left) 
   {
      root = root->right;
      ++count;
      count += removeOneChild(root);
      return count;
   }
   if(!root->right)
   {
      root = root->left;
      ++count;
      count += removeOneChild(root);
      return count;
   }
   count += removeOneChild(root->left);
   count += removeOneChild(root->right);
   return count;
   
}
