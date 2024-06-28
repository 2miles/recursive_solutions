// clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data; // some questions are a char * data;
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

    /* *****************YOUR TURN! ********************* */
    // Write your function prototype here:

    int find_largest();
    int find_largest(node *&data, int largest);
    int display_all_but_last();
    int display_all_but_last(node *rear);
    bool remove_last();
    bool remove_last(node *&rear);

    int copy(list &dest);
    int copy(node *&dest_rear, node *source_rear, node *real_d_rear);

    int count_evens();
    int count_evens(node *rear);

    bool append_new(int to_add);
    bool append_new(node *&rear, int to_add);

    int add_before_evens(int to_add);
    int add_before_evens(node *&rear, int to_add);

    bool remove_if_rears();
    bool remove_if_rears(node *&rear, int rear_data, bool &was_removed);

    int copy_even(list &dest);
    int copy_even(node *&dest_rear, node *source_rear, node *&real_d_rear);

    int average_evens();
    int average_evens(node *rear, int &sum);

    int remove_every_other();
    int remove_every_other(node *&rear, node *first);

    int copyV2(list &source_list);
    int copyV2(node *source_rear, node *&dest_rear, node *orig_source_rear);

    int add_after(int to_add);
    int add_after(node *&rear, int to_add);

private:
    node *rear;
};
