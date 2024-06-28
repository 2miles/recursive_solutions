//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        
        int copy( list & to_copy);

        int removeEvery2();
        int copyEvery2( list & to_copy);

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */


     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL

         int copy(node *& dest, node * prev, node * source);
         int removeEvery2(node *& head, node * prev);
         int copyEvery2(node *& dest_head, node * prev, node * source_head);
};

