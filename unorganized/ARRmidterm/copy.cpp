#include "arr.h"

int table::copy(table & to_copy)
{
   if (!to_copy.head)
   {
      this->head = NULL;
      return 0;
   }
   size = to_copy.size;
   head = new node*[size];
   return copy(head, to_copy.head);
}

int table::copy(node ** destArray, node ** sourceArray)
{
   int count = 0;
   if( this->head + size == destArray)
      return 0;
   count = copy(*destArray, *sourceArray);
   return copy(++destArray, ++sourceArray) + count;
}

int table::copy(node *& dest_head, node * source_head)
{
   if(!source_head) 
      return 0;
   dest_head = new node;
   dest_head->next = NULL;
   dest_head->data = source_head->data;
   return copy(dest_head->next, source_head->next);
}


