#include "table.h"

int table::removeSmallestTwo()
{
   bool removed = false;
   if(!root) return 1;
   return removeSmallestTwo(root, removed);
}

int table::removeSmallestTwo(node *& root, bool & removed)
{
   int total = 0;
   int number;
   if(!root) return 0;
   if(!root->left)  //we are at the smallest node
   {
      if(!root->right)  //smallest node has no children
      {
         number = root->data;
         delete root;
         root = NULL;
      }
      else
      //case 2: smallest has a right child
         // delete the smallest's ios
         // then on the way back delete the smallest
      {
         number = deleteSmallest(root->right);
         number += root->data;
         node * hold = root->right;
         delete root;
         root = hold;
         removed = true;
      }
      return number;
   }
   total += removeSmallestTwo(root->left, removed);
   if(!removed)
   {
      int result = root->data;
      node * hold = root->right;
      delete root;
      root = hold;
      removed = true;
      return result + number;
   }
   return total;
}


int table::deleteSmallest(node *& root)
{
   if(!root) return 0;
   if(!root->left)
   {
      int temp = root->data;
      node * hold = root->right;
      delete root;
      root = hold;
      return temp;
   }
   return deleteSmallest(root->left);
}


