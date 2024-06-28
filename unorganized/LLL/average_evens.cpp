#include "list.h"

int list::average_evens()
{
   int sum = 0;
   if (!head) return 0;
   int total = average_evens( head, sum);
   return sum / total;
}

int list::average_evens( node * head, int & sum)
{
   if(!head)
      return 0;
   if(head->data % 2 == 0)
   {
      sum += head->data;
      return average_evens(head->next, sum) + 1;
   }
   return average_evens(head->next, sum);

}
