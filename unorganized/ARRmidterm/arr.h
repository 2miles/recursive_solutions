//arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;  //some questions are char * data;
    node * next;
};

class table
{
    public:
    /* These functions are already written */
       table();		//supplied
       ~table();	//supplied
       void build();  	//supplied
       void display();  //supplied

       int myDisplay();
       int copy(table & to_copy);
       int sumEvens();


    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:

    private:
       node ** head; 	//dynamically allocated array
       int size; 	//the array size

       int myDisplay(node ** head);
       int myDisplay(node * head);

       int copy(node ** destArray, node ** souceArray);
       int copy(node *& dest_head, node * source_head);

       int sumEvens(node ** head);
       int sumEvens(node * head);
};
