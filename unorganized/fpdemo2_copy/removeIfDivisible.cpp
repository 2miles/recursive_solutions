#include "table.h"

int table::removeIfDivisible()
{
   if(!root) return 0;
   return removeIfDivisible(root);
}

int table::removeIfDivisible(node *& root)
{
   int count = 0;
   if(!root) return 0;
   if(root->data % 3 == 0 && root->data % 5 == 0)
   {
      count += remove(root);
      count += removeIfDivisible(root);
      return count;
   }
   count += removeIfDivisible(root->left);
   count += removeIfDivisible(root->right);
   return count;
}



//removes the root node and returns 1
int table::remove(node *& root)
{
   if(!root) return 0;

   //root has no children
   if(!root->left && !root->right)
   {
      delete root;
      root = NULL;
      return 1;
   }

   //root had 1 child, a right
   else if(!root->left && root->right)
   {
      node * hold = root->right;
      delete root;
      root = hold;
   }

   //root had 1 child, a left
   else if(root->left && !root->right)
   {
      node * hold = root->left;
      delete root;
      root = hold;
   }

   //root has 2 children
   else
   {
      //right child has NO left child
      if(!root->right->left)
      {
         root->data = root->right->data;
         node * hold = root->right->right;
         delete root->right;
         root->right = hold;
      }
      //right child has a left child
      else
         root->data = deleteAndRetrieveSmallest(root->right->left);
   }
   return 1;
}

int table::deleteAndRetrieveSmallest(node *& root)
{
   int num = 0;
   if(!root) return 0;
   if(!root->left)
   {
      num = root->data;
      node * hold = root->right;
      delete root;
      root = hold;
      return num;
   }
   return deleteAndRetrieveSmallest(root->left);
}




