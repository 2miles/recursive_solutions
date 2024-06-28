#include "list.h"

int list::reverse()
{
   if(!head) return 0;
   tail = head;
   return reverse(head);
}

//traverse all the way to the end.
//on the way back
//move each node to the front of the list
int list::reverse(node * head)
{
   int total = 0;
   if(!head) return 0;
   total = reverse(head->next) + 1;
   node * temp = head;
   head->next = this->head;
   head = NULL;
   this->head = temp;

   return total;
}
