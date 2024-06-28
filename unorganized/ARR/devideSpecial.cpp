#include "arr.h"

bool table::devideSpecial()
{
   int longest = 0; //length of the longest LLL 
   int shortest = 1000; //length of the shortest LLL 
   int sumLongest = 0; //sum of longest LLL
   int sumShortest = 0;//sum of shortest LLL
   int count = 0;  //length of the current LLL

   if(!head) return 0;
   devideSpecial(head, longest, shortest, count, sumLongest, sumShortest);
   int result = sumLongest % sumShortest;
                  //result evaluates to 0 if sum of longest devides sum of shortest

   cout << "sumLongest: " << sumLongest << endl;
   cout << "sumShortest: " << sumShortest << endl;
   cout << "longestLength: " << longest << endl;
   cout << "shortestLength: " << shortest << endl;
   cout << "result: " << result << endl;
   return !result; //return true if result is 0;
}

//traverses through each LLL in the array
//finding the longest and shortest LLL and both their data sums
void table::devideSpecial(node** head, int & longest, int & shortest, 
                          int & count, int & sumLongest, int & sumShortest)
{
   int sum = 0;
   if(head == this->head + size) return;
   count = countNodes(*head, sum);
   if(count > longest)
   {
      longest = count;
      sumLongest = sum;
   }
   if(count < shortest)
   {
      shortest = count;
      sumShortest = sum;
   }
   devideSpecial(++head, longest, shortest, count, sumLongest, sumShortest);
}


//return the number of nodes in a LLL 
//also update sum with the sum of the data in this LLL
int table::countNodes(node * head, int &sum)
{
   if(!head) return 0;
   sum += head->data;
   return countNodes(head->next, sum) + 1;
}




