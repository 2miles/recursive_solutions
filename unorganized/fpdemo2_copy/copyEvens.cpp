#include "table.h"

int table::copyEvens(table & to_copy)
{
   if(!to_copy.root) return 0;
   return copyEvens(root, to_copy.root);
}

int table::copyEvens(node *& dest, node * source)
{
   int count = 0;
   if(!source) return 0;
   if(dest)
      count += copyEvens(dest->right, source);
   else
   {
      if(source->data % 2 == 0)
      {
         dest = new node;
         dest->data = source->data;
         dest->left = dest->right = NULL;
         ++count;
         count += copyEvens(dest->left, source->left);
         count += copyEvens(dest->right, source->right);
      }
      else
      {
         count += copyEvens(dest, source->left);
         count += copyEvens(dest, source->right);
      }
   }
   return count;
}
