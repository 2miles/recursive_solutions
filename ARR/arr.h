// arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data; // some questions are char * data;
    node *next;
};

class table
{
public:
    /* These functions are already written */
    table();        // supplied.o
    ~table();       // supplied.o
    void build();   // supplied.o
    void display(); // supplied.o

    int count_nodes();
    int my_display();
    int display_all();
    int display_v2();
    int display_every_other();
    int sumEvens();
    int copy(table &to_copy);
    bool devide_special();
    int append_to_all();

private:
    node **head; // dynamically allocated array
    int size;    // the array size

    int count_nodes(int i);
    int count_nodes(node *head);
    int count_nodes(node *head, int &sum);

    int my_display(node **head);
    int my_display(node *head);

    int display_all(int index);
    int display_all(node *head);

    int display_v2(node **head);
    int display_v2(node *head);

    int display_every_other(node **head);
    int display_every_other(node *head);

    int sumEvens(node **head);
    int sumEvens(node *head);

    int copy(node **destArray, node **souceArray);
    int copy(node *&dest_head, node *source_head);

    void devide_special(node **head, int &longest, int &shortest,
                        int &count, int &sumLongest, int &sumShortest);

    void append_to_all(node **head);
    void append_to_all(node *head);
    void append_list(node *source, node *&dest);
};
