#include "clist.h"
//////////////////////////////////////////////////////////////////////////////
// Return the average of all the even data.
//////////////////////////////////////////////////////////////////////////////
int list::average_evens()
{
   int sum = 0;
   if (!rear)
      return 0;
   int total = average_evens(rear->next, sum);
   return sum / total;
}

int list::average_evens(node *rear, int &sum)
{
   if (rear == this->rear)
   {
      if (rear->data % 2 == 0)
      {
         sum += rear->data;
         return 1;
      }
      return 0;
   }
   if (rear->data % 2 == 0)
   {
      sum += rear->data;
      return average_evens(rear->next, sum) + 1;
   }
   return average_evens(rear->next, sum);
}
