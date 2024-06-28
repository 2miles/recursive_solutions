#include "list.h"

int list::display_unique()
{
   int result;
   if(!head) return 0;

   cout << "ONLY UNIQUE DATA: ";
   result = display_unique(head);
   cout << endl;
   cout << "NUMBER OF DATA DISPLAYED: ";
   return result;
}

int list::display_unique(node * head)
{
   if(!head) return 0;
   if(is_in_list(this->head, head->data) == 1)
   {
      cout << head->data << ' ';
      return display_unique(head->next) + 1;
   }
   return display_unique(head->next);
}




//Displays a LLL but only displays each data once.
//Returns the number of data displayed

//Create a empty, temporary LLL in wrapper. 
//As we traverse the main LLL, append each data to the temp LLL 
//if it is not already in it. Then display the temp list.
//This requires us to traverse the whole temp LLL for each node 
//in the main LLL.
//Complexity: O(n + ( 1 + 2 + ... + n ))  ==  O(n + (n(n + 1))/2)
//            about as bad as O(n^2)>

//recursive solution
int list::display_uniquely()
{
   list tempList;  
   int result;
   if(!head) return 0;
   result = display_uniquely(head, tempList);
   tempList.display();
   return result;
}

int list::display_uniquely(node * head, list & tempList)
{
   if(!head) return 0;
   //is_in_list(data) return the number of times data appears
   if(!tempList.is_in_list(head->data))
   {
      tempList.append(head->data);
      return display_uniquely(head->next, tempList) + 1;
   }
   return display_uniquely(head->next, tempList);
}

/*
//iterative solution
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



/*
//displays only the unique data of an LLL
//Returns the number of data displayed

//Create a static array with size of the range of possible data
//As we traverse the main LLL increment the array index
//that corrisponds to the data in that node
//Then display every index number of the array if that data in 
//that index is equal to 1.

//Complexity O(2n);
//PROS: very fast
//CONS: Items are displayed in increasing order.
//      Must create a static array such that 
//      each array element corrisponds to a possible 
//      list data integer.

int list::display_unique()
{
   int tally[100] = {0}; //range of possible data
   int result = 0;  //the number of data displayed
   if(!head) return 0;
   display_unique(head, tally);
   display_tally(tally, result);
   return result;
}

void list:: display_tally(int tally[], int & result)
{
   for (int i = 0; i < 100; ++i){
      if(tally[i] == 1){
         ++result;
         cout << i << ' ';
      }
   }
}

void list::display_unique(node * head, int tally[])
{
   if(!head) return;
   ++tally[head->data];
   display_unique(head->next, tally);
}
*/



/*
//displays only the unique data of an LLL
//Returns the number of data displayed


//Create a empty, temporary LLL in wrapper. 
//As we traverse the main LLL, append each data to the temp LLL 
//if it is not already in the main list more than once.
//Then display the temp list.
//This requires us to traverse the whole main LLL for each node 
//in the main LLL.
//Complexity: O(n^2)

//recursive solution
int list::display_unique()
{
   int result;
   list tempList;
   if(!head) return 0;
   result = display_unique(head, tempList);
   tempList.display();
   return result;
}
int list::display_unique(node * head, list & tempList)
{
   if(!head) return 0;
   //is_in_list(data) return the number of times data appears
   if(is_in_list(head->data) < 2)
   
   {
      tempList.append(head->data);
      return display_unique(head->next, tempList) + 1;
   }
   return display_unique(head->next,tempList);
}

*/

/*
//iterative solution
int list::display_unique()
{
   int count = 0;
   list tempList;
   if(!head) return 0;
   node * current = head;
   while (current)
   {
      if( is_in_list(current->data) < 2)
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

