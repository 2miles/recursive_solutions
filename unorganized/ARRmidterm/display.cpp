#include "arr.h"

int table::myDisplay()
{
   if(!head) return 0;  //array is NULL
   return myDisplay(head);
}

int table::myDisplay(node ** head)
{
   int count = 0;
   if(head == this->head + size)  //we have gone past the array
      return 0;
   count = myDisplay(*head);   //call list display, grab count
   cout << endl;
   return myDisplay(++head) + count;  //call array display on next list, adding count
}

int table::myDisplay(node * head)
{
   if(!head) return 0;
   cout << head->data << ' ';
   return myDisplay(head->next) + 1;
}


int table::sumEvens()
{
   if(!head) return 0;
   return sumEvens(head);
}

int table::sumEvens(node ** head)
{
   int sum = 0;
   if(this->head + size == head)
      return 0;
   sum = sumEvens(*head);
   cout << endl;  //new line between lists
   return sumEvens(++head) + sum;
}

int table::sumEvens(node * head)
{
   if(!head) return 0;
   if(head->data %2 == 0)
   {
      cout << head->data << ' ';
      return sumEvens(head->next) + head->data;
   }
   return sumEvens(head->next);
}
