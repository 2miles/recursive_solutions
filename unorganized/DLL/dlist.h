// doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data; // some questions use a char * data;
    node *previous;
    node *next;
};

class list
{
public:
    // These functions are already written
    list();         // supplied
    ~list();        // supplied
    void build();   // supplied
    void display(); // supplied

    /* *****************YOUR TURN! ******************************** */
    /* place your prototype here */

    int remove_larger();
    int remove_larger(node *&head, node *&tail, int first);

    int remove_every_other();
    int remove_every_other(node *&head, node *&tail);

    int duplicate_every_two();
    int duplicate_every_two(node *&head, node *&tail);

    int display_backwards();
    int display_backwards(node *head);

    bool append_if_new(int to_add);
    bool append_if_new(node *&head, node *&tail, int to_add);

    bool copy(list &the_copy);
    bool copy(node *&dest_head, node *&dest_tail, node *source_head);

    int append_average();
    int append_average(node *&tail, int &sum);

    bool copy_from(list &the_copy);
    bool copy_from(node *&dest_head, node *&dest_tail, node *source_head);

    int count_last();
    void count_last(node *tail, int &count);

    int display_unique();
    int display_unique(node *head);
    bool is_unique(node *head, int the_data, int &count);

    int copyV2(list &source_list);
    int copyV2(node *&dest_head, node *source_head, node *prev);

    int add_after(int to_add);
    int add_after(node *&head, int to_add);

private:
    node *head; // notice there is both a head
    node *tail; // and a tail, common for DLL
};
