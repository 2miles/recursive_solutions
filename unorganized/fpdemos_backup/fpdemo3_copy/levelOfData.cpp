#include "table.h"

int table::levelOfFirstData(int number)
{
   bool found = false;
   if(!root) return 0;
   return levelOfFirstData(root, number, found);
}

int table::levelOfFirstData(node * root, int number, bool & found)
{
   int count = 0;
   if(!root) return 0;
   if(root->data == number)
   {
      found = true;
      return 1;
   }
   if(root->data < number)
      count = levelOfFirstData(root->right, number, found);
   else
      count += levelOfFirstData(root->left, number, found);
   if(found)
      ++count;
   return count;

}



int table::levelOfLastData(int number)
{
   bool found = false;
   if(!root) return 0;
   return levelOfLastData(root, number, found);
}

int table::levelOfLastData(node * root, int number, bool & found)
{
   int count = 0;
   if(!root) return 0;
   if(root->data <= number)
      count = levelOfLastData(root->right, number, found);
   else
      count += levelOfLastData(root->left, number, found);
   if(root->data == number && !found)
   {
      found = true;
      return 1;
   }
   if(found)
      ++count;
   return count;
}


//display all the data of a given level and return the average
int table::displayLevel(int number)
{
   int level = 0;
   int sum = 0;
   int total = 0;
   if(!root) return 0;
   total = displayLevel(root, level, number, sum);
   return sum / total;
}

int table::displayLevel(node * root, int & level, int number, int & sum)
{
   int total = 0;
   if(!root) return 0;
   ++level;
   if(level == number)
   {
      cout << root->data << ' ';
      sum += root->data;
      --level;
      return 1;
   }
   total = displayLevel(root->left, level, number, sum);
   total += displayLevel(root->right, level, number, sum);
   --level;
   return total;

}




