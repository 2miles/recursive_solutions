#include "list.h"
//////////////////////////////////////////////////////////////////////////////
// Copy the list. Return the number of nodes copied
//////////////////////////////////////////////////////////////////////////////
int list::copy(list &copyTo)
{
   if (!head)
      return 0;
   return copy_rec(copyTo.head, copyTo.tail, head);
}

int list::copy_rec(node *&destHead, node *&destTail, node *sourceHead)
{
   if (!sourceHead)
   {
      destHead = NULL;
      return 0;
   }
   destHead = new node;
   destHead->data = sourceHead->data;
   destTail = destHead;

   return copy_rec(destHead->next, destTail, sourceHead->next) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Copy the list. Return the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int list::copy_v2(list &original)
{
   if (!original.head)
      return 0;
   return copy_v2(head, original.head, original.tail);
}

int list::copy_v2(node *&dest, node *source, node *source_tail)
{
   if (!source)
      return 0;
   dest = new node;
   dest->data = source->data;
   if (source == source_tail)
      tail = dest;
   return copy_v2(dest->next, source->next, source_tail) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Copy the elements of the list with data equal to the given argument.
// Return the number of nodes copied
//////////////////////////////////////////////////////////////////////////////
int list::copy_only_arg(list &copyTo, int toCopy)
{
   if (!head)
      return 0;
   return copy_only_arg_rec(copyTo.head, copyTo.tail, head, toCopy);
}

int list::copy_only_arg_rec(node *&destHead, node *&destTail, node *sourceHead, int toCopy)
{
   if (!sourceHead)
   {
      destHead = NULL;
      return 0;
   }
   if (sourceHead->data == toCopy)
   {
      destHead = new node;
      destHead->data = sourceHead->data;
      destTail = destHead;
   }
   else
      return copy_only_arg_rec(destHead, destTail, sourceHead->next, toCopy);
   return copy_only_arg_rec(destHead->next, destTail, sourceHead->next, toCopy) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Copy the even data. Return the number of nodes copied
//////////////////////////////////////////////////////////////////////////////
int list::copy_even(list &to_copy)
{
   if (!head)
      return 0; // list is empty
   return copy_even(to_copy.head, to_copy.tail, head);
}

int list::copy_even(node *&dest_head, node *&dest_tail, node *source_head)
{
   if (!source_head)
   {
      dest_head = NULL;
      return 0;
   }
   if (source_head->data % 2 == 0)
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
