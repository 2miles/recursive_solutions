#include "table.h"

int table::retrieveIOS()
{
   if(!root)  return 0;
   if(!root->right) return 0;
   return retrieveIOS(root->right);
}

int table::retrieveIOS(node *  root)
{
   if(!root->left) return root->data;
   return retrieveIOS(root->left);
}
