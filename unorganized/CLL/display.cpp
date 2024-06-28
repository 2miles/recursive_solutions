#include "clist.h"
//////////////////////////////////////////////////////////////////////////////
// Display all but the lat node. Return the sum of all the data displayed
//////////////////////////////////////////////////////////////////////////////
int list::display_all_but_last()
{
   if (!rear)
      return 0;
   return display_all_but_last(rear->next);
}

int list::display_all_but_last(node *rear)
{
   if (rear == this->rear)
      return 0;
   cout << rear->data << ' ';
   return display_all_but_last(rear->next) + rear->data;
}
