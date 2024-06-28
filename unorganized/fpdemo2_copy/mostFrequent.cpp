#include "table.h"

int table::mostFrequent() 
{
   int count = 0;
   int mostFreq = 0;
   int largest = 0;
   int prev = 0;

   if(!root) return 0;
   mostFrequent(root, root->data, mostFreq, count, largest);
   cout << endl;
   return mostFreq;
}

void table::mostFrequent(node * root, int & prev, int & mostFreq, int & count, int & largest) 
{
   if(!root) return;

   mostFrequent(root->left, prev, mostFreq, count, largest);

   if(root->data == prev)
      ++count;
   else 
      count = 1;
   if( count > largest)
   {
      largest = count;
      mostFreq = root->data;
   }
   prev = root->data;
   mostFrequent(root->right, prev, mostFreq, count, largest);
}


