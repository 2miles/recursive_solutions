#include "dlist.h"

int list::duplicate_every_two()
{
   if(!head) return 0;
   return duplicate_every_two(head, tail);
}

int list::duplicate_every_two(node *& head, node *& tail)
{
   if(head == tail)
   {
      if(head->data == 2)
      {
         head->next = new node;
         head->next->previous = head;
         tail = head->next;
         tail->next = NULL;
         head->next->data = 2;
         return 1;
      }
      return 0;
   }
   if(head->data ==2)
   {
      node * hold = head->next;
      head->next = new node;
      head->next->previous = head;
      head->next->data = 2;
      head->next->next = hold;
      hold->previous = head->next;
      return duplicate_every_two(hold, tail) + 1;
   }
   return duplicate_every_two(head->next, tail);
}


bool list::append_if_new(int to_add)
{
   if(!head) return false;
   return append_if_new(head, tail, to_add);
}


bool list::append_if_new(node *& head, node *& tail, int to_add)
{
   if(head == tail)
   {
      if(head->data != to_add)
      {
         head->next = new node;
         head->next->data = to_add;
         head->next->previous = head;
         head->next->next = NULL;
         tail = head->next;
         return true;
      }
      return false;
   }
   if(head->data == to_add)
      return false;
   return append_if_new(head->next, tail, to_add);
}



int list::append_average()
{
   int sum = 0;
   if(!head) return 0;
   return append_average(tail, sum);
}

int list::append_average(node *& tail, int & sum)
{
   sum += tail->data;
   if(tail->previous == NULL)
      return 1; 
   int total = append_average(tail->previous, sum) + 1;
   int result = sum / total;

   if(tail == this->tail)
   {
      tail->next = new node;
      tail->next->previous = tail;
      tail->next->next = NULL;
      tail->next->data = result;
      return result;
   }
   return total;
}


