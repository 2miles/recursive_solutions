#include "table.h"

void table::removeSmallest()
{
   if(!root) return;
   removeSmallest(root);
}

void table::removeSmallest(node *& root)
{
   //either smalles has one right child or no children
   if(!root->left)
   {
      if(!root->right) //smallst has no choldern
      {
         delete root;
         root = NULL;
         return;
      }
      else
      {
         node * hold = root->right;
         delete root;
         root = hold;
         return;
      }
   }
   removeSmallest(root->left);
}
