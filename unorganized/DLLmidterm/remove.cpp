#include "dlist.h"

int list::removeEvery2()
{
   if(!head) return 0;
   tail = NULL;
   return removeEvery2( head, NULL);
}


int list::removeEvery2( node* &head, node * prev)
{
   if(!head) return 0;
   if(head->data == 2)
   {
      node * hold = head->next;
      if(hold)
         hold->previous = prev;
      delete head;
      head = hold;
      if(head)
         return removeEvery2(head->next, head) + 1;
      else return 1;
   }
   tail = head;
   return removeEvery2(head->next, head);
}
