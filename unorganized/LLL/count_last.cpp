#include "list.h"

int list::count_last()
{
   int last;
   int count = 0;
   if(!head) return 0;
   if(head == tail) return 1;
   count_last(head, last, count);
   return count;
}


void list::count_last( node * head, int & last, int & count)
{
   if(head == tail)
   {
      last = head->data;
      ++count;
      return;
   }
   count_last(head->next, last, count);
   if(head->data == last)
      ++count;
}
