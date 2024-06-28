#include "list.h"

int list::copyP2(list & original)
{
   if(!original.head)
      return 0;
   return copyP2(head, original.head, original.tail);
}

int list::copyP2(node *& dest, node * source, node * source_tail)
{
   if(!source) return 0;
   dest = new node;
   dest->data = source->data;
   if(source == source_tail)
      tail = dest;
   return copyP2(dest->next, source->next, source_tail) + 1;
}


