#include "table.h"

void table::insert(int to_add)
{
   if(!root)
   {
      root = new node;
      root->left = NULL;
      root->right = NULL;
      root->data = to_add;
      return;
   }
   insert(root, to_add);
}

void table::insert(node *& root, int to_add)
{
      if(!root)
      {
         root = new node;
         root->left = NULL;
         root->right = NULL;
         root->data = to_add;
         return;
      }
      if(to_add < root->data)
         insert(root->left, to_add);
      else
         insert(root->right, to_add);

}
