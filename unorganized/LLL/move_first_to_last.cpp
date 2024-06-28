#include "list.h"

int list::move_first_to_last()
{
   if(!head) return 0;
   if(!head->next) return head->data;

   node * hold = head->next;
   head->next = NULL;

   return move_first_to_last(hold, hold);
}
int list::move_first_to_last(node *& head, node * hold)
{
   int currentData = head->data;
   if(!head->next)
   {
      head->next = this->head;
      tail = this->head;
      this->head = hold;
      return currentData;
   }
   return currentData + move_first_to_last(head->next, hold);
}


