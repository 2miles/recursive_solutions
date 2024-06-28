#include "list.h"

int list::display_last()
{
   int first_data;
   if(!head) return 0;
   if(!head->next) return 0;
   first_data = head->data;
   return display_last(head->next, first_data);
}

int list::display_last(node * head, int first)
{
   if(!head) return 0;
   if(!head->next && head->data != first)
   {
      cout << head->data;
      return head->data;
   }
   return display_last(head->next, first);
}
