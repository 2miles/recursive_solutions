#include "table.h"

bool table::appearTwice()
{
   if(!root) return false;
   if(!root->right) return false;
   return appearTwice(root->right, this->root->data);
}

bool table::appearTwice(node * root, int rootData)
{
   //do an in-order traversal
   //if roots data is the same as this->roots data then return true

   bool result;
   if(!root) return false;
   result = appearTwice(root->left, rootData);
   if(root->data == rootData) return true;
   return result;
}

