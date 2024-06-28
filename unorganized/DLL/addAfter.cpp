#include "dlist.h"

int list::add_after(int to_add)
{
   if (!head)
      return 0;
   return add_after(head, to_add);
}

int list::add_after(node *&head, int to_add)
{
   if (head == tail)
   {
      if (head->data == 2)
      {
         head->next = new node;
         head->next->data = to_add;
         head->next->previous = head;
         head->next->next = NULL;
         tail = head->next;
         return 1;
      }
      return 0;
   }
   if (head->data == 2)
   {
      node *hold = head->next;
      head->next = new node;
      node *new_node = head->next;
      new_node->previous = head;
      new_node->data = to_add;
      new_node->next = hold;
      hold->previous = new_node;
      return add_after(new_node->next, to_add) + 1;
   }
   return add_after(head->next, to_add);
}
