#include "list.h"

int list::copy_even(list & to_copy)
{
   if(!head) return 0;        //list is empty
   return copy_even(to_copy.head, to_copy.tail, head);
}

int list::copy_even(node *& dest_head, node *& dest_tail, node * source_head)
{
   if(!source_head)
   {
      dest_head = NULL;
      return 0;
   }
   if(source_head->data % 2 == 0)
   {
      dest_head = new node;
      dest_head->data = source_head->data;
      dest_tail = dest_head;
      return copy_even(dest_head->next, dest_tail, source_head->next) + 1;
   }
   else
   {
      return copy_even(dest_head, dest_tail, source_head->next);
   }
   
}
