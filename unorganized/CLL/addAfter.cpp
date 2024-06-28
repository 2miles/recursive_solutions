#include "clist.h"
//////////////////////////////////////////////////////////////////////////////
// Insert a node into the list directly after any node with the data = 2.
// Return the number of nodes inserted
//////////////////////////////////////////////////////////////////////////////
int list::add_after(int to_add)
{
   if (!rear)
      return 0;
   return add_after(rear->next, to_add);
}

int list::add_after(node *&rear, int to_add)
{
   if (rear == this->rear)
   {
      if (rear->data == 2)
      {
         node *hold = rear->next;
         rear->next = new node;
         this->rear = rear->next; // update this->rear
         rear->next->data = to_add;
         rear->next->next = hold;
         return 1;
      }
      return 0;
   }
   if (rear->data == 2)
   {
      node *hold = rear->next;
      rear->next = new node;
      node *curr = rear->next;
      curr->data = to_add;
      curr->next = hold;
      return add_after(rear->next, to_add) + 1;
   }
   return add_after(rear->next, to_add);
}
