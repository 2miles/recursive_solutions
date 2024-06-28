#include "dlist.h"

int list::copy(list & to_copy)
{
   if(!to_copy.head) return 0;
   return copy(head, NULL, to_copy.head);
}

int list::copy(node *& dest_head, node * prev,  node * source_head)
{
   if(!source_head) return 0;

   dest_head = new node;
   dest_head->data = source_head->data;
   dest_head->next = NULL;
   dest_head->previous = prev;
   tail = dest_head;
   return copy(dest_head->next, dest_head, source_head->next) + 1;
}


//copy every 2 into a new list and return the number of 2s copied
int list::copyEvery2(list & to_copy)
{
   if(!to_copy.head) return 0;
   return copyEvery2(head, NULL, to_copy.head);
}

int list::copyEvery2(node *& dest_head, node * prev, node * source_head)
{
   if(!source_head) return 0;
   if(source_head->data == 2)
   {
      dest_head = new node;
      dest_head->data = source_head->data;
      dest_head->next = NULL;
      dest_head->previous = prev;
      tail = dest_head;
      return copyEvery2(dest_head->next, dest_head, source_head->next) + 1;
   }
   return copyEvery2(dest_head, prev, source_head->next);
}

