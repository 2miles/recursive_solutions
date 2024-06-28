#include "arr.h"

int table::count_nodes()
{
   if(!head) return 0;  //there is no array
   return count_nodes(0);
}

int table::count_nodes(int i)
{
   if(i == size) return 0;  //have reached the end of the array
   node * current_head = head[i]; //pointing to first node of array element
   int count = count_nodes(current_head); 
   count += count_nodes(++i);
   return count;
}

int table::count_nodes(node * head)
{
   if(!head) return 0;
   return count_nodes(head->next) + 1;
}
