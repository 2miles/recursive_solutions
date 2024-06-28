#include "arr.h"


//displays all the nodes and returns the total number of nodes

int table::display_all()
{
   if(!head) return 0;
   return display_all(0);
}

int table::display_all(int i)
{
   int count = 0;
   if(i == size) return 0;
   node * current_head = head[i]; 
   count = display_all(current_head);
   return count += display_all(++i);

}

int table::display_all(node * head)
{
   if(!head) return 0;
   if(!head->next)
   {
      cout << head->data << ' ';
      cout << endl;
   }
   else
      cout << head->data << ' ';
   return display_all(head->next) + 1;
}


int table::display_v2()
{
   if(!head) return 0;
   return display_v2(head);
}

int table::display_v2(node** head)
{
   int count = 0;
   if(head == this->head + size) return 0;
   count = display_v2(*head);
   return count += display_v2(++head);
}

int table::display_v2(node * head)
{
   if(!head) return 0;
   cout << head->data << ' ';
   if(!head->next)
      cout << endl;
   return display_v2(head->next) + 1;
}

int table::displayEveryOther()
{
   if(!head) return 0;
   return displayEveryOther(head);
}

int table::displayEveryOther(node ** head)
{
   int total = 0;
   if(head == this->head + size)
      return 0;
   total = displayEveryOther(*head);
   return total += displayEveryOther(++head);
}

int table::displayEveryOther(node * head)
{
   int count = 0;
   if(!head) 
   {
      cout << endl;
      return 0;
   }
   cout << head->data << ' ';
   head = head->next;
   if(head)
   {
      ++count;
      if(head->next)
         return displayEveryOther(head->next) + count;
   }
   cout << endl;
   return count;
}



