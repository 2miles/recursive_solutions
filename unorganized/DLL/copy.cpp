#include "dlist.h"

bool list::copy(list & the_copy)
{
   if(!head) return false;
   return copy( the_copy.head, the_copy.tail, head);
}

bool list::copy( node *& dest_head, node *& dest_tail, node * source_head)
{

   if(source_head == head)
   {
      dest_head = new node;
      dest_head->previous = NULL;
   }
   dest_head->data = source_head->data;
   if(source_head->next)
   {
      dest_head->next = new node;
      dest_head->next->previous = dest_head;
   }
   else 
   {
      dest_head->next = NULL;
      dest_tail = dest_head;
      return true;
   }
   return copy(dest_head->next, dest_tail, source_head->next);
}



bool list::copy_from(list & the_original)
{
   if(!the_original.head) return false;
   return copy_from( head, tail, the_original.head);
}

bool list::copy_from(node *& dest_head, node *& dest_tail, node * source_head)
{
   if(dest_head == head)
   {
      dest_head = new node;
      dest_head->previous = NULL;
   }
   dest_head->data = source_head->data;
   if(source_head->next)
   {
      dest_head->next = new node;
      dest_head->next->previous = dest_head;
   }
   else
   {
      dest_head->next = NULL;
      dest_tail = dest_head;
      return true;
   }
   return copy(dest_head->next, dest_tail, source_head->next);

}

int list::copyV2(list & source_list)
{
   if(!source_list.head)
      return 0;
   return copyV2(head, source_list.head, head);
}

int list::copyV2(node *& dest_head, node * source_head, node * prev)
{
   if(!source_head) return 0;
   dest_head = new node;
   dest_head->data = source_head->data;
   if(dest_head == head)
      dest_head->previous = NULL;
   else
      dest_head->previous = prev;
   if(!source_head->next)
      dest_head->next = NULL;
   return copyV2( dest_head->next, source_head->next, dest_head) + 1;
}







