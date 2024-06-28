#include "list.h"


//simple, fast,  non repetitive version 
//that uses tail pointer
void list:: append(int to_append)
{
   if(!head)
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



/*
//recursive solution
//
//
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
   append(head, to_append);
}

void list::append(node * & head, int to_append)
{
   if(!head)
   {
      head = new node;
      head->data = to_append;
      tail = head;
      head->next = NULL;
      return;
   }
   append(head->next, to_append);
}
*/




/*
//iterative solution
//
//
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
