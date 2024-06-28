#include "list.h"

//add the data of the first node divisible by 3 or 5 to every following node
//return the number of node sthat occure before one is divisible by four
int list::modifyAfter()
{
   bool first = true;
   int data = 0;
   if(!head) return 0;
   return modifyAfter(head, first, data);
}

int list::modifyAfter(node * head, bool & first, int & data)
{
   if(!head) return 0;
   if(first)
   {
      if(head->data % 3 == 0 || head->data % 5 == 0)
      {
         first = false;
         data = head->data;
         head->data -= data;
      }
   }
   head->data += data;
   if(first)
      return modifyAfter(head->next, first, data) + 1;
   return modifyAfter(head->next, first, data);
}



