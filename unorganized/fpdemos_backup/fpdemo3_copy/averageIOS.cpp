#include "table.h"

//return the average of the data in the roots ios right
int table::averageIOS()
{
   int sum = 0;
   if(!root) return 0;
   if(!root->right) return 0;
   node * ios = getIOS(root->right);
   int result = numberOfNodes(ios->right, sum);
   int theAverage;
   cout << "result = " << result << endl;
   if(result == 0)
      theAverage = 0;
   else theAverage = sum / result;
   return theAverage;
}

int table::numberOfNodes(node * root, int & sum)  
{
   int total = 0;
   if(!root) return 0;
   total = numberOfNodes(root->left, sum);
   sum += root->data;
   ++total;
   total += numberOfNodes(root->right, sum);
   return total;
}

//returns the ios when called with root->right
node * table::getIOS(node * root)
{
   if(!root->left) return root;
   return getIOS(root->left);
}


