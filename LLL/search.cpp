#include "list.h"

// return the number of time a data occurs in the list
// if data not in list or list is empty, retuns 0;
//
// recursive solution
//
int list::is_in_list(int search)
{
   if (!head)
      return 0;
   return is_in_list(head, search);
}

int list::is_in_list(node *head, int search)
{
   if (!head)
      return 0;
   if (head->data == search)
      return is_in_list(head->next, search) + 1;
   return is_in_list(head->next, search);
}

/*
//iterative solution
int list::is_in_list(int search_for)
{
   int count = 0;
   if(!head) return 0;
   node * current = head;
   while(current)
   {
      if(current->data == search_for)
         ++count;
      current = current->next;
   }
   return count;
}
*/
