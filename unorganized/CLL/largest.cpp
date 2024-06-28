#include "clist.h"

//////////////////////////////////////////////////////////////////////////////
// returns the largest data in a CLL and removes every occurence of it
//////////////////////////////////////////////////////////////////////////////
int list::find_largest()
{
   if (!rear)
      return 0;
   return find_largest(rear->next, rear->data);
}

int list::find_largest(node *&rear, int largest)
{
   if (rear == this->rear)
      return largest;
   if (rear->data > largest)
      largest = rear->data;
   largest = find_largest(rear->next, largest);

   if (rear->data == largest)
   {
      node *temp = rear->next;
      delete rear;
      rear = temp;
   }

   return largest;
}
