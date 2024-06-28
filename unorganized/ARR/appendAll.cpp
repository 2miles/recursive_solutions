#include "arr.h"

int table::appendToAll()
{
   if(!head) return 0; // the array pointer is empty
   if(size < 2) return 0; //the list has only one list, so do nothing
   appendToAll(head); //start processing the first list
   return 1;
}


void table::appendToAll(node** head)
{
   if(head == this->head + size) 
      return;
   appendToAll(*head);
   appendToAll(++head);
}

//append the first list to the end of the list.
void table::appendToAll(node* head)
{
   //traverse to end of the list
   //then call the append list function
   //using *(this->head) as source argument
   
   if(!head)
   {
      appendList(*(this->head), head);
      return;
   }
   appendToAll(head->next);
}


//copy a list
void table::appendList(node * source, node *& dest)
{
   if(!source)
   {
      dest = NULL;
      return;
   }
   dest = new node;
   dest->data = source->data;
   appendList(source->next, dest->next);
}




