#include "dlist.h"

int list::count_last()
{
   int count = 0;
   if(!head) return 0;
   if(head == tail) return 1;
   count_last(tail, count);
   return count;
}

void list::count_last(node * tail, int & count)
{
   if(tail == NULL) return;
   count_last(tail->previous, count);
   if(tail->data == this->tail->data)
      ++count;
}
