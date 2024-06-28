#include "list.h"


int list::average_unique()
{
   int sum = 0;
   int result = count_unique(head, sum); 
   result  = sum / result; //calculate average
   return result;
}

//return the number of unique data
//update sum to be the sum of unique data
int list::count_unique(node * head, int & sum)
{
   if(!head) return 0;
   if(is_in_list(head->data) == 1)
   {
      sum += head->data;
      return count_unique(head->next, sum) + 1;
   }
   return count_unique(head->next, sum);
}


int list::is_in_list(int data)
{
   if(!head) return 0;
   return is_in_list(head, data);
}

int list::is_in_list(node * head, int data)
{
   if(!head) return 0;
   if(head->data == data) 
   {
      return is_in_list(head->next, data) + 1;
   }  
   return is_in_list(head->next, data);
}

