#include "clist.h"
//////////////////////////////////////////////////////////////////////////////
// Removes the last node in the queue. Returns true if a node was removed
// else returns false
//////////////////////////////////////////////////////////////////////////////
bool list::remove_last()
{
   if (!rear)
      return false;
   if (rear == rear->next)
      return true;
   return remove_last(rear->next);
}
bool list::remove_last(node *&rear)
{
   if (this->rear == rear->next)
   {
      node *temp = rear->next;
      node *hold = temp->next;
      delete temp;
      rear->next = hold;
      this->rear = rear;
      return true;
   }
   return remove_last(rear->next);
}

//////////////////////////////////////////////////////////////////////////////
// Remove the last node if it's data equals the first's nodes data.
// Return true if a node was removed, else return false.
//////////////////////////////////////////////////////////////////////////////
bool list::remove_if_rears()
{
   bool was_removed = false;
   if (!rear)
      return false;
   if (rear->next == rear)
      return false;
   return remove_if_rears(rear->next, rear->data, was_removed);
}

bool list::remove_if_rears(node *&rear, int rear_data, bool &was_removed)
{
   if (rear == this->rear)
      return was_removed;
   if (rear->data == rear_data)
   {
      was_removed = true;
      node *hold = rear->next;
      delete rear;
      rear = hold;
      return remove_if_rears(rear, rear_data, was_removed);
   }
   return remove_if_rears(rear->next, rear_data, was_removed);
}
//////////////////////////////////////////////////////////////////////////////
// Remove every other node in the list. Return the number of nodes removed.
//////////////////////////////////////////////////////////////////////////////
int list::remove_every_other()
{
   if (!rear)
      return 0; // list has no nodes
   if (rear == rear->next)
      return 0;                  // list has 1 node
   if (rear->next->next == rear) // list has 2 nodes
   {
      node *first = rear->next;
      rear = first;
      delete rear->next;
      rear->next = rear;
      return 1;
   }
   node *current = rear->next;
   return remove_every_other(current->next, rear->next);
}

int list::remove_every_other(node *&rear, node *first)
{
   // general case
   node *hold = rear->next;
   delete rear;
   rear = hold;
   if (rear == this->rear) // after deleting were at the last node
      return 1;
   if (rear->next == this->rear) // after deleting were at the second to last
   {
      this->rear = rear;
      delete rear->next;
      rear->next = first;
      return 2;
   }
   return remove_every_other(rear->next, first) + 1;
}
