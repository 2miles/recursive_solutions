#include "list.h"

int list::remove_center()
{
   if(!head) return 0;
   if(head == tail) return 0;
   if(head->next == tail) return 0;
   return remove_center(head->next);
}

int list::remove_center(node *& head)
{
   int head_data = head->data;
   if(head == tail) return 0;
   node * hold = head->next;
   delete head;
   head = hold;
   return remove_center(head) + head_data;
}
