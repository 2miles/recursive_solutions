#include "list.h"
//////////////////////////////////////////////////////////////////////////////
// Display and return the last data if it doesnt equal the first data, else
// don't display, and return 0
//////////////////////////////////////////////////////////////////////////////
int list::display_last()
{
   int first_data;
   if (!head)
      return 0;
   if (!head->next)
      return 0;
   first_data = head->data;
   return display_last(head->next, first_data);
}

int list::display_last(node *head, int first)
{
   if (!head)
      return 0;
   if (!head->next && head->data != first)
   {
      cout << head->data;
      return head->data;
   }
   return display_last(head->next, first);
}

//////////////////////////////////////////////////////////////////////////////
// Display only the unique data. Return the number of unique data
//////////////////////////////////////////////////////////////////////////////
int list::display_unique()
{
   int result;
   if (!head)
      return 0;

   cout << "ONLY UNIQUE DATA: ";
   result = display_unique(head);
   cout << endl;
   cout << "NUMBER OF DATA DISPLAYED: ";
   return result;
}

int list::display_unique(node *head)
{
   if (!head)
      return 0;
   if (is_in_list(this->head, head->data) == 1)
   {
      cout << head->data << ' ';
      return display_unique(head->next) + 1;
   }
   return display_unique(head->next);
}

//////////////////////////////////////////////////////////////////////////////
// Displays a LLL but only displays each data once.
// Returns the number of data displayed
//////////////////////////////////////////////////////////////////////////////

// Create a empty, temporary LLL in wrapper.
// As we traverse the main LLL, append each data to the temp LLL
// if it is not already in it. Then display the temp list.
// This requires us to traverse the whole temp LLL for each node
// in the main LLL.
// Complexity: O(n + ( 1 + 2 + ... + n ))  ==  O(n + (n(n + 1))/2)
//             about as bad as O(n^2)>

// recursive solution
int list::display_uniquely()
{
   list tempList;
   int result;
   if (!head)
      return 0;
   result = display_uniquely(head, tempList);
   tempList.display();
   return result;
}

int list::display_uniquely(node *head, list &tempList)
{
   if (!head)
      return 0;
   // is_in_list(data) return the number of times data appears
   if (!tempList.is_in_list(head->data))
   {
      tempList.append(head->data);
      return display_uniquely(head->next, tempList) + 1;
   }
   return display_uniquely(head->next, tempList);
}
//////////////////////////////////////////////////////////////////////////////
// Display Uniquely, iterative solution
//////////////////////////////////////////////////////////////////////////////
/*
int list::display_uniquely()
{
   list tempList;
   int count = 0;
   if(!head) return 0;
   node * current = head;
   while (current)
   {
      if(!tempList.is_in_list(current->data))
      {
         tempList.append(current->data);
         ++count;
      }
      current = current->next;
   }
   tempList.display();
   return count;
}
*/
