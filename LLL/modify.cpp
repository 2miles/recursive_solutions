#include "list.h"

//////////////////////////////////////////////////////////////////////////////
// Reverse the linked list. Return the number of nodes in the list
//////////////////////////////////////////////////////////////////////////////
int list::reverse()
{
   if (!head)
      return 0;
   tail = head;
   return reverse(head);
}

// traverse all the way to the end.
// on the way back
// move each node to the front of the list
int list::reverse(node *head)
{
   int total = 0;
   if (!head)
      return 0;
   total = reverse(head->next) + 1;
   node *temp = head;
   head->next = this->head;
   head = NULL;
   this->head = temp;

   return total;
}

//////////////////////////////////////////////////////////////////////////////
// Reverses evey three elements of the list.
// Returns the number of nodes altered:
// 1-2-3-4-5-6  ->  3-2-1-6-5-4  ->  Returns 4
//////////////////////////////////////////////////////////////////////////////
int list::reverse_every_3()
{
   if (!head)
      return 0; // no elements
   if (head == tail)
      return 0; // one element
   if (head->next == tail)
      return 0; // two elements
   return reverse_every_3(head);
}

int list::reverse_every_3(node *&head)
{
   int total = 0;
   if (!head)
      return 0; // no elements left in LLL
   if (!head->next)
      return 0; // one element left in LLL
   if (!head->next->next)
      return 0; // two elements left in LLL
   total = swap_3_nodes(head);
   total += reverse_every_3(head->next->next->next);
   return total;
}

int list::swap_3_nodes(node *&head)
{

   node *hold = head;
   node *hold2 = head->next;
   node *hold3 = head->next->next->next;

   head = hold2->next; // if head == tail
   if (head == tail)
      tail = hold;
   head->next = hold2;
   hold2->next = hold;
   hold->next = hold3;
   return 2;
}
//////////////////////////////////////////////////////////////////////////////
// Remove all but the head and tail nodes. Return the sum of the data removed
//////////////////////////////////////////////////////////////////////////////
int list::remove_center()
{
   if (!head)
      return 0;
   if (head == tail)
      return 0;
   if (head->next == tail)
      return 0;
   return remove_center(head->next);
}

int list::remove_center(node *&head)
{
   int head_data = head->data;
   if (head == tail)
      return 0;
   node *hold = head->next;
   delete head;
   head = hold;
   return remove_center(head) + head_data;
}

//////////////////////////////////////////////////////////////////////////////
// Add the data of the first node divisible by 3 or 5 to every following node.
// Return the number of nodes that occur before a node is divisible by four
//////////////////////////////////////////////////////////////////////////////
int list::modify_after()
{
   bool first = true;
   int data = 0;
   if (!head)
      return 0;
   return modify_after(head, first, data);
}

int list::modify_after(node *head, bool &first, int &data)
{
   if (!head)
      return 0;
   if (first)
   {
      if (head->data % 3 == 0 || head->data % 5 == 0)
      {
         first = false;
         data = head->data;
         head->data -= data;
      }
   }
   head->data += data;
   if (first)
      return modify_after(head->next, first, data) + 1;
   return modify_after(head->next, first, data);
}

//////////////////////////////////////////////////////////////////////////////
// Moves the first node to the end of the list. Returns the sum of all the
// nodes but the one moved.
//////////////////////////////////////////////////////////////////////////////
int list::move_first_to_last()
{
   if (!head)
      return 0;
   if (!head->next)
      return head->data;

   node *hold = head->next;
   head->next = NULL;

   return move_first_to_last(hold, hold);
}
int list::move_first_to_last(node *&head, node *hold)
{
   int currentData = head->data;
   if (!head->next)
   {
      head->next = this->head;
      tail = this->head;
      this->head = hold;
      return currentData;
   }
   return currentData + move_first_to_last(head->next, hold);
}
