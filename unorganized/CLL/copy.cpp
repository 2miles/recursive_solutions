#include "clist.h"
/*
int list::copy(list & dest)
{
   if(!rear) return 0;
   return copy(dest.rear, rear, dest.rear);
}

int list::copy(node * & dest_rear, node * source_rear, node *& real_d_rear)
{
   if(source_rear->next == rear)
   {
      dest_rear = new node;
      dest_rear->data = source_rear->data;
      dest_rear->next = real_d_rear;
      return 1;
   }
   dest_rear = new node;
   dest_rear->data = source_rear->data;
   return copy(dest_rear->next, source_rear->next, real_d_rear) + 1;
}


*/
//////////////////////////////////////////////////////////////////////////////
// Copy just the even data. Return the number of nodes copied
//////////////////////////////////////////////////////////////////////////////
int list::copy_even(list &dest)
{
   if (!rear)
      return 0;
   return copy_even(dest.rear, rear, dest.rear);
}

int list::copy_even(node *&dest_rear, node *source_rear, node *&real_d_rear)
{
   if (source_rear->next == rear)
   {
      if (source_rear->data % 2 == 0)
      {
         dest_rear = new node;
         dest_rear->data = source_rear->data;
         dest_rear->next = real_d_rear;
         return 1;
      }
      dest_rear = real_d_rear;
      return 0;
   }
   if (source_rear->data % 2 == 0)
   {
      dest_rear = new node;
      dest_rear->data = source_rear->data;
      return copy_even(dest_rear->next, source_rear->next, real_d_rear) + 1;
   }
   return copy_even(dest_rear, source_rear->next, real_d_rear);
}
//////////////////////////////////////////////////////////////////////////////
// Copy the CLL. Return the number of nodes copied
//////////////////////////////////////////////////////////////////////////////
int list::copy(list &dest)
{
   if (!rear)
      return 0;
   return copy(dest.rear, rear->next, dest.rear);
}

int list::copy(node *&dest_rear, node *source_rear, node *real_d_rear)
{
   if (source_rear == this->rear)
   {
      dest_rear = new node;
      dest_rear->data = source_rear->data;
      dest_rear->next = real_d_rear;
      return 1;
   }
   dest_rear = new node;
   dest_rear->data = source_rear->data;
   return copy(dest_rear->next, source_rear->next, real_d_rear) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Copy the CLL. Return the number of nodes copied
//////////////////////////////////////////////////////////////////////////////
int list::copyV2(list &source_list)
{
   if (!source_list.rear)
      return 0;
   return copyV2(source_list.rear, rear, source_list.rear);
}

int list::copyV2(node *source_rear, node *&dest_rear, node *orig_s_rear)
{
   if (source_rear->next == orig_s_rear)
   {
      dest_rear = new node;
      dest_rear->data = source_rear->data;
      dest_rear->next = rear;
      return 1;
   }
   dest_rear = new node;
   dest_rear->data = source_rear->data;
   return copyV2(source_rear->next, dest_rear->next, orig_s_rear) + 1;
}
