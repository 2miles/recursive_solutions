#include "list.h"

int list::copy(list & copyTo)
{
   if(!head) return 0;
   return copy_rec(copyTo.head, copyTo.tail, head);
}

int list::copy_rec(node * & destHead, node * & destTail, node * sourceHead)
{
  if(!sourceHead) 
  {
     destHead = NULL;
     return  0;
  }
  destHead = new node;
  destHead->data = sourceHead->data;
  destTail = destHead;

  return copy_rec(destHead->next, destTail, sourceHead->next) + 1;
}




int list::copy_only_arg(list & copyTo, int toCopy)
{
   if(!head) return 0;
   return copy_only_arg_rec(copyTo.head, copyTo.tail, head, toCopy);
}

int list::copy_only_arg_rec(node * & destHead, node * & destTail, node * sourceHead, int toCopy)
{
  if(!sourceHead) 
  {
     destHead = NULL;
     return  0;
  }
  if(sourceHead->data == toCopy)
  {
     destHead = new node;
     destHead->data = sourceHead->data;
     destTail = destHead;
  }
  else
     return copy_only_arg_rec(destHead, destTail, sourceHead->next, toCopy);
  return copy_only_arg_rec(destHead->next, destTail, sourceHead->next, toCopy) + 1;
}









