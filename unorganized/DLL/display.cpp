#include "dlist.h"

int list::display_backwards()
{
   if(!head) return 0;
   return display_backwards(head);
}

int list::display_backwards(node * head)
{

   if(head == tail)
   {
      cout << head->data << ' ';
      return tail->data;
   }
   int result = display_backwards(head->next);
   cout << head->data << ' ';
   if(head == this->head)
      cout << tail->data << ' ';
   return result;
}


int list::display_unique()
{
   if(!head) return 0;
   return display_unique(head);
}

int list::display_unique(node * head)
{
   int count = 0;
   if(!head) return 0;
   if(is_unique(this->head, head->data, count))
   {
      cout << head->data << ' ';
      return display_unique(head->next) + head->data;
   }
   return display_unique(head->next);
}

bool list::is_unique(node * head, int the_data, int & count)
{
   if(!head)  return true;
   if(count > 1) return false;
   if(head->data == the_data)
      ++count;
   return is_unique(head->next, the_data, count);
}





