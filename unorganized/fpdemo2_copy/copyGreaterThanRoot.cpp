#include "table.h"

int table::copyGreaterThanRoot(table & to_copy)
{
   if(!to_copy.root) return 0;
   if(!to_copy.root->right) return 0;
   return copyGreaterThanRoot(root, to_copy.root->right, to_copy.root->data);
}

int table::copyGreaterThanRoot(node *& dest, node * source, int original)
{
   int count = 0;
   if(!source) return 0;
   if(dest)
      count += copyGreaterThanRoot(dest->right, source, original);
   if(source->data > original)
   {
      dest = new node;
      dest->data = source->data;
      dest->left = dest->right = NULL;
      ++count;
      count += copyGreaterThanRoot(dest->left, source->left, original);
      count += copyGreaterThanRoot(dest->right, source->right, original);
   }
   else
   {
      count += copyGreaterThanRoot(dest, source->left, original);
      count += copyGreaterThanRoot(dest, source->right, original);
   }
   return count;

}
