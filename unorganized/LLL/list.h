//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
   public:
   //These functions are already written for you
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied
    
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    //
     int copy( list & copy_to);
     int copy_only_arg( list & copy_to, int toCopy);

     //int is_in_list(int search_for);
     int is_in_list(int data);
     void append(int to_append);
     int display_uniquely();
     int display_unique();
     int display_last();
     int average_unique();
     int move_first_to_last();

     int copy_even(list & to_copy);
     int copy_even(node *& dest_head, node *& dest_tail, node * source_head);

     int average_evens();
     int average_evens(node * head, int & sum);

     int remove_center();
     int remove_center(node *& head);

     int count_last();
     void count_last(node * head, int & last, int & count);

     int copyP2(list &);
     int copyP2(node *& dest, node * source, node * s_tail);


     
     int modifyAfter();
     int modifyAfter(node * head, bool & first, int & data);

     int reverse();
     int reverse(node * head);

     int appendIfDivisible(int to_add);
     void appendIfDivisible(node *& head, int to_add, int first, int & count);
     void appendXNodes(node *& head, int to_add, int count, int & subtract);

     int reverseEvery3();
     int reverseEvery3(node * & head);
     int swap3Nodes(node *& head);

     

   private:		//notice there is both a head and a tail!
      node * head;
      node * tail;

     int copy_rec(node *& destHead, node *& destTail, 
                  node * sourceHead);
     int copy_only_arg_rec(node *& destHead, node *& destTail,
                           node * sourceHead, int toCopy);
     void append(node * & head, int to_append);
     //int is_in_list(node * head, int search_for);
     int is_in_list(node * head, int data);
     //int display_unique(node * head, list & tempList);
     int display_unique(node * head);
     //void display_unique(node * head, int tally[]);
     //void display_tally(int tally[], int & result);
     int display_uniquely(node * head, list & tempList);
     int display_last(node * head, int first);
     int count_unique(node * head, int & sum);
     int move_first_to_last(node *& head, node * hold);
};



