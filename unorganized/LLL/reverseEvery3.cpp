#include "list.h"

int list::reverseEvery3()
{
   if(!head) return 0; //no elements
   if(head == tail) return 0; //one element
   if(head->next == tail) return 0; //two elements
   return reverseEvery3(head);
}

int list::reverseEvery3( node* &head)
{
   int total = 0;
   if(!head) return 0; //no elements left in LLL
   if(!head->next) return 0; //one element left in LLL
   if(!head->next->next) return 0; //two elements left in LLL
   total = swap3Nodes(head);
   total += reverseEvery3(head->next->next->next);
   return total;
}

int list::swap3Nodes(node* &head)
{

   node * hold = head;
   node * hold2 = head->next;
   node * hold3 = head->next->next->next;

   head = hold2->next; //if head == tail
   if(head == tail)
      tail = hold;
   head->next = hold2;
   hold2->next = hold;
   hold->next = hold3;
   return 2;
}






