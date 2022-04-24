// list.h
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
  list();         // supplied
  ~list();        // supplied
  void build();   // supplied
  void display(); // supplied

  /* **************** Public Prototypes ******************************** */
  // Write your function prototype here:
  //
  void append(int to_append);
  int append_if_divisible(int to_add);

  int copy(list &copy_to);
  int copy_v2(list &);
  int copy_only_arg(list &copy_to, int toCopy);
  int copy_even(list &to_copy);

  int average_evens();
  int average_unique();
  int is_in_list(int data);
  int count_last();

  int display_last();
  int display_unique();
  int display_uniquely();
  int move_first_to_last();

  int reverse();
  int reverse_every_3();
  int remove_center();
  int modify_after();

private: // notice there is both a head and a tail!
  node *head;
  node *tail;

  /* **************** Private Prototypes ******************************** */
  void append(node *&head, int to_append);
  void append_if_divisible(node *&head, int to_add, int first, int &count);
  void append_x_nodes(node *&head, int to_add, int count, int &subtract);

  int copy_rec(node *&destHead, node *&destTail, node *sourceHead);
  int copy_v2(node *&dest, node *source, node *s_tail);
  int copy_only_arg_rec(node *&destHead, node *&destTail, node *sourceHead, int toCopy);
  int copy_even(node *&dest_head, node *&dest_tail, node *source_head);

  int average_evens(node *head, int &sum);
  int count_unique(node *head, int &sum);
  int is_in_list(node *head, int data);
  void count_last(node *head, int &last, int &count);

  int display_last(node *head, int first);
  int display_unique(node *head);
  int display_uniquely(node *head, list &tempList);

  int reverse(node *head);
  int reverse_every_3(node *&head);
  int swap_3_nodes(node *&head);
  int remove_center(node *&head);
  int modify_after(node *head, bool &first, int &data);
  int move_first_to_last(node *&head, node *hold);
};
