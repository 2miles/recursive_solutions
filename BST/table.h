// table.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
      int data; // some questions use char * data;
      node *left;
      node *right;
};

class table
{
public:
      table();        // supplied.o
      ~table();       // supplied.o
      void build();   // supplied.o
      void display(); // supplied.o

      /* ************** PUBLIC PROTOTYPES ***************** */
      int in_order_display();

      int copy(table &to_copy);
      int copy_leafs(table &to_copy);
      int copy_largest_two(table &to_copy);
      int copy_evens(table &to_copy);
      int copy_root_and_successor(table &to_copy);
      int copy_not_root(table &to_copy);
      int copy_not_largest(table &to_copy);
      int copy_greater_than_root(table &);

      int count();
      int count_root();
      int count_root_IOS_right_tree();
      int count_largest_left();
      int count_duplicates();

      int most_frequent();
      int level_of_first();
      int average();
      int last_15();
      int retrieve_IOS();
      int average_IOS();
      int level_of_first_data(int number);
      int level_of_last_data(int number);
      int display_level(int);
      int longest_path();
      int longest_path_avg();

      int remove_largest();
      int remove_except_root();
      int remove_roots_IOS();
      int remove_leafs();
      int remove_largest_two();
      int remove_if_divisible();
      int remove_smallest_one_child();
      void remove_smallest();
      int remove_smallest_two();
      int remove_one_child();

      void insert(int to_add);
      bool appear_twice();

private:
      node *root;

      /* ************** PRIVATE PROTOTYPES ***************** */
      int in_order_display(node *&root);

      int copy(node *&dest, node *source);
      int copy_leafs(node *&dest, node *source);
      int copy_largest_two(node *&dest_root, node *source_root);
      int copy_evens(node *&dest, node *souce);
      int copy_not_largest(node *&dest_root, node *source_root);
      int copy_root_and_left_sub(node *&dest, node *source);
      int copy_greater_than_root(node *&dest, node *source, int original);

      int count(node *root);
      int count_root(node *root);
      int count_root_IOS_right_tree(node *root);
      int count_duplicates(node *root, int &prev);

      void most_frequent(node *root, int &prev, int &mostFreq, int &count, int &largest);
      int level_of_first(node *root, bool &found);
      int average(node *root, int &sum);
      int last_15(node *, bool &found);
      int retrieve_IOS(node *root);
      int number_of_nodes(node *root, int &sum);
      node *get_IOS(node *root);
      int level_of_first_data(node *root, int number, bool &found);
      int level_of_last_data(node *root, int number, bool &found);
      int display_level(node *root, int &level, int number, int &sum);
      int longest_path_avg(node *root, int &level, bool &found, int height, int &sum);
      int find_height(node *root);

      int remove_largest(node *&root);
      int remove_all(node *&root);
      int remove_leafs(node *&root);
      int remove_largest_two(node *&root, int &removed);
      int find_and_delete_IOS(node *&root);
      int remove_if_divisible(node *&);
      int remove(node *&);
      int delete_and_retrieve_smallest(node *&);
      int remove_one_child(node *&root);
      int remove_smallest_one_child(node *&root, bool &isremoved);
      void remove_smallest(node *&root);
      int remove_smallest_two(node *&root, bool &removed);
      int delete_smallest(node *&root);

      int largest_data(node *root);
      void insert(node *&root, int to_add);
      int longest_path(node *&root);
      node *find_IOS(node *root);
      node *find_largest(node *root);
      bool appear_twice(node *root, int rootData);
      int smallest(node *root);
      node *largest(node *root);
};
