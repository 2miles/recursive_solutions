#include "list.h"
//////////////////////////////////////////////////////////////////////////////
// Return the average of the even data in the list
//////////////////////////////////////////////////////////////////////////////
int list::average_evens()
{
   int sum = 0;
   if (!head)
      return 0;
   int total = average_evens(head, sum);
   return sum / total;
}

int list::average_evens(node *head, int &sum)
{
   if (!head)
      return 0;
   if (head->data % 2 == 0)
   {
      sum += head->data;
      return average_evens(head->next, sum) + 1;
   }
   return average_evens(head->next, sum);
}

//////////////////////////////////////////////////////////////////////////////
// Return the average of the unique data in the list
//////////////////////////////////////////////////////////////////////////////
int list::average_unique()
{
   int sum = 0;
   int result = count_unique(head, sum);
   result = sum / result; // calculate average
   return result;
}

// return the number of unique data
// update sum to be the sum of unique data
int list::count_unique(node *head, int &sum)
{
   if (!head)
      return 0;
   if (is_in_list(head->data) == 1)
   {
      sum += head->data;
      return count_unique(head->next, sum) + 1;
   }
   return count_unique(head->next, sum);
}

int list::is_in_list(int data)
{
   if (!head)
      return 0;
   return is_in_list(head, data);
}

int list::is_in_list(node *head, int data)
{
   if (!head)
      return 0;
   if (head->data == data)
   {
      return is_in_list(head->next, data) + 1;
   }
   return is_in_list(head->next, data);
}

//////////////////////////////////////////////////////////////////////////////
// Return the number of times the last data appears in the list
//////////////////////////////////////////////////////////////////////////////
int list::count_last()
{
   int last;
   int count = 0;
   if (!head)
      return 0;
   if (head == tail)
      return 1;
   count_last(head, last, count);
   return count;
}

void list::count_last(node *head, int &last, int &count)
{
   if (head == tail)
   {
      last = head->data;
      ++count;
      return;
   }
   count_last(head->next, last, count);
   if (head->data == last)
      ++count;
}
