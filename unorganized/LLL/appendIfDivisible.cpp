#include "list.h"

int list::appendIfDivisible(int to_add)
{
   int count = 0;
   if(!head) return 0;
   appendIfDivisible(head, to_add, head->data, count);
   return count;
}

void list::appendIfDivisible(node *& head, int to_add, int first, int &count)
{
   int subtract = 0;
   if(!head)
   {
      appendXNodes(head, to_add, count, subtract);
      return;
   }
   if(head->data % first == 0)
      ++count;
   appendIfDivisible(head->next, to_add, first, count);

}

void list::appendXNodes(node *& head, int to_add, int count, int & subtract)
{
   int num = count - subtract;
   if(num == 0) 
      return;
   if(num == 1) 
   {
      head = new node;
      tail = head;
      head->data = to_add;
      head->next = NULL;
   }
   else
   {
      head = new node;
      head->data = to_add;
   }
   appendXNodes(head->next, to_add, count, ++subtract);
}


