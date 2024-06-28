#include "table.h"

int table::copyEvensIf(table & to_copy)
{
   if(!to_copy.root) return 0;
   return copyEvensIf(root, to_copy.root);
}
int table::copyEvensIf(node *& dest, node * source)
{
   int count = 0;
   if(!source) return 0;
   if(dest)
      count += copyEvensIf(dest->right, source);
   else
   {
      if(source->data % 2 == 0)
      {
         dest = new node;
         dest->data = source->data;
         dest->left = dest->right = NULL;
         if(dest->data % 7 == 0)
            ++count;
         count += copyEvensIf(dest->left, source->left);
         count += copyEvensIf(dest->right, source->right);
      }
      else
      {
         count += copyEvensIf(dest, source->left);
         count += copyEvensIf(dest, source->right);
      }
   }
   return count;
}
