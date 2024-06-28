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

       int display_all();
       int display_all(int index);
       int  display_all(node * head);

       int count_nodes();
       int count_nodes(int i);
       int count_nodes(node * head);

       int display_v2();
       int display_v2(node** head);
       int display_v2(node * head);

       int displayEveryOther();
       int displayEveryOther(node** head);
       int displayEveryOther(node* head);

       bool devideSpecial();
       void devideSpecial(node ** head, int & longest, int & shortest,
                          int & count, int & sumLongest, int & sumShortest);
       int countNodes(node * head, int & sum);


       int  appendToAll();
       void appendToAll(node ** head);
       void appendToAll(node * head);
       void appendList(node * source, node *& dest);

    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:

    private:
       node ** head; 	//dynamically allocated array
       int size; 	//the array size
};
