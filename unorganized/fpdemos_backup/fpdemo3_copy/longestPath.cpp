#include "table.h"

int table::longestPath()
{
   int sum = 0;
   bool found = false;
   int level = 0;
   if(!root) return 0;
   int height = findHeight(root);
   int count = longestPath(root,level, found, height, sum);
   return sum / count;
}

int table::longestPath(node * root, int & level, bool & found, int height, int & sum)
{
   int total = 0;
   if(!root) return 0;
   ++level;
   if(level == height)
   {
      found = true;
      sum += root->data;
      cout << root->data << ' ';
      --level;
      return 1;
   }
   total = longestPath(root->left, level, found, height, sum);
   if(!found)
      total += longestPath(root->right, level, found, height, sum);
   --level;
   if(found)
   {
      sum += root->data;
      cout << root->data << ' ';
      ++total;
   }
   return total;
}


int table::findHeight(node * root)
{
   if(!root) return 0;
   return max(findHeight(root->left), findHeight(root->right)) + 1;
}
