#include "list.h"

//////////////////////////////////////////////////////////////////////////////
// Append argument list to the end of this list.
//////////////////////////////////////////////////////////////////////////////
// simple, fast,  non repetitive version
// that uses tail pointer
void list::append(int to_append)
{
   if (!head)
   {
      head = new node;
      head->data = to_append;
      tail = head;
      return;
   }
   tail->next = new node;
   tail = tail->next;
   tail->data = to_append;
   tail->next = NULL;
}

//////////////////////////////////////////////////////////////////////////////
// Append argument list to the end of this list.
// iterative solution
//////////////////////////////////////////////////////////////////////////////
/*
void list::append(int to_append)
{
   if(!head)
   {
      head = new node;
      head->data = to_append;
      tail = head;
      head->next = NULL;
      return;
   }
   node * current = head;
   while(current->next)
      current = current->next;
   current->next = new node;
   current = current->next;
   current->data = to_append;
   current->next = NULL;
   tail = current;
}
*/
//////////////////////////////////////////////////////////////////////////////
// For each data in the list that is divisible by the first node's data,
// append the given data to the end of the list. Return the number of
// nodes appended.
//////////////////////////////////////////////////////////////////////////////
int list::append_if_divisible(int to_add)
{
   int count = 0;
   if (!head)
      return 0;
   append_if_divisible(head, to_add, head->data, count);
   return count;
}

void list::append_if_divisible(node *&head, int to_add, int first, int &count)
{
   int subtract = 0;
   if (!head)
   {
      append_x_nodes(head, to_add, count, subtract);
      return;
   }
   if (head->data % first == 0)
      ++count;
   append_if_divisible(head->next, to_add, first, count);
}

void list::append_x_nodes(node *&head, int to_add, int count, int &subtract)
{
   int num = count - subtract;
   if (num == 0)
      return;
   if (num == 1)
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
   append_x_nodes(head->next, to_add, count, ++subtract);
}
