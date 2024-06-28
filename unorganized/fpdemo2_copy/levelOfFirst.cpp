#include "table.h"

int table::levelOfFirst()
{
   bool found = false;
   if(!root) return 0;
   return levelOfFirst(root, found);
      
}

int table::levelOfFirst(node * root, bool & found)
{
   int level = 0;
   if(!root) return 0;
   if(root->data == 15) 
   {
      found = true;
      return 1;
   }
   if(found)
      ++level;
   level += levelOfFirst(root->left, found);
   level += levelOfFirst(root->right, found);
   return level;

}
