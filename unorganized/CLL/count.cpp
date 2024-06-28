#include "clist.h"
//////////////////////////////////////////////////////////////////////////////
// Return the number of nodes with even data
//////////////////////////////////////////////////////////////////////////////
int list::count_evens()
{
   if (!rear)
      return 0;
   return count_evens(rear->next);
}
int list::count_evens(node *rear)
{
   if (rear == this->rear)
   {
      if (rear->data % 2 == 0)
         return 1;
      else
         return 0;
   }
   if (rear->data % 2 == 0)
      return count_evens(rear->next) + 1;
   else
      return count_evens(rear->next);
}
