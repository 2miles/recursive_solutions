#include "dlist.h"

int list::remove_larger()
{
   if(!head) return 0;
   if(head == tail) return 1;
   return remove_larger(head->next, tail, head->data) + 1;
}

int list::remove_larger( node * & head, node * & tail, int first)
{
   if(head == tail)
   {
      if(head->data > first)
      {
         tail = tail->previous;
         delete head;
         head = NULL;
         return 0;
      }
      return 1;

   }
   if(head->data > first)
   {
      node * hold = head->next;
      hold->previous = head->previous;
      delete head;
      head = hold;
      return remove_larger(head, tail, first);
   }
   return remove_larger(head->next, tail, first) + 1;

}

//remove every other node, return the number of nodes removed
int list::remove_every_other()
{
   if(!head) return 0;
   if(head == tail) return 0;
   return remove_every_other(head->next, tail);
}

int list::remove_every_other( node *& head, node *& tail)
{
   if(!head) return 0;
   if(head == tail)
   {
      tail = head->previous;
      delete head;
      head = NULL;
      return 1;
   }
   node * hold = head->next;
   hold->previous = head->previous;
   delete head;
   head = hold;
   return remove_every_other(head->next, tail) + 1;
   
}



