#include "table.h"

int table::removeEveryLeaf()
{
   if(!root) return 0;
   return removeEveryLeaf(root);
}

int table::removeEveryLeaf(node *& root)
{
   int count = 0;
   if(!root) return 0;
   if(!root->left && !root->right)
   {
      delete root;
      root = NULL;
      return 1;
   }
   count += removeEveryLeaf(root->left);
   count += removeEveryLeaf(root->right);
   return count;
}
