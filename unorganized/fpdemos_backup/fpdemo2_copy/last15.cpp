#include "table.h"

int table::last15()
{
   bool found = false;
   if(!root) return 0;
   last15(root, found);
   return last15(root, found);
}

int table::last15(node * root, bool & found)
{
   int level = 0;
   if(!root) {
      return 0;
   }
   level = last15(root->right, found);
   level = last15(root->left, found);
   if(root->data == 15 && !found)
   {
      found = true;
      return 1;
   }
   if(!found)
      return 0;
   else
      return level + 1;

}
