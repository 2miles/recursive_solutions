#include "clist.h"
//////////////////////////////////////////////////////////////////////////////
// Append given data to the end of the queue if that same data is not all ready
// at the end of the queue. Return true if data was added, else return false
//////////////////////////////////////////////////////////////////////////////
bool list::append_new(int to_add)
{
   if (!rear) // list is empty
   {
      rear = new node;
      rear->data = to_add;
      rear->next = rear;
      return true;
   }
   return append_new(rear->next, to_add);
}

bool list::append_new(node *&rear, int to_add)
{
   if (rear == this->rear) // stopping condition
   {
      if (rear->data != to_add)
      {
         // add the node and update this->rear
         node *hold = rear->next;
         rear->next = new node;
         node *current = rear->next;
         this->rear = current;
         current->data = to_add;
         current->next = hold;
         return true;
      }
      return false;
   }
   if (rear->data == to_add) // general
      return false;
   else
      return append_new(rear->next, to_add);
}

//////////////////////////////////////////////////////////////////////////////
// Insert the given data into the list before every even data. Return the
// number of nodes inserted
//////////////////////////////////////////////////////////////////////////////
int list::add_before_evens(int to_add)
{
   if (!rear)
      return 0;
   return add_before_evens(rear->next, to_add);
}

int list::add_before_evens(node *&rear, int to_add)
{
   if (rear == this->rear)
   {
      if (rear->data % 2 == 0)
      {
         node *hold = rear;
         rear = new node;
         rear->data = to_add;
         rear->next = hold;
         // this->rear = hold;
         return 1;
      }
      return 0;
   }

   if (rear->data % 2 == 0)
   {
      node *hold = rear;
      rear = new node;
      rear->data = to_add;
      rear->next = hold;
      return add_before_evens(hold->next, to_add) + 1;
   }
   return add_before_evens(rear->next, to_add);
}
