#include "table.h"

int table::average()
{
   int sum = 0;
   if(!root) return 0;
   int number = average(root, sum);
   cout << "Sum: " << sum << endl;
   cout << "Num: " << number << endl;
   return sum / number;
}

int table::average(node * root, int & sum)
{
   int count = 0;
   if(!root) return 0;

   count = average(root->left, sum);
   sum += root->data;
   count += average(root->right, sum) + 1;
   return count;
}
