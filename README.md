# Recursive Functions for C++ Data Structures

This is a huge list of recursive solutions to various C++ data structure problems.
It's a compilation of all the practice problems I worked on in preperation for 
Karla Fant's Portland State University computer science proficiency demos. These demos were required for entry exam for upper division CS classes.

---
## File orginazation 
Each directory contains an implementation of a specific data structure: 

- BST -- Binary Search Tree
- ARR -- Array of Linked Lists
- LLL -- Linear Linked List
- DLL -- Double Linked List
- CLL -- Circular Linked List

---
## Compiling and running
Each directory is meant to be compiled and executed seperatly. The `main.cpp` 
in each is used as a driver to test the various member functions defined for
that data structure. Each directory also contains a `supplied.o` object file
containing the constructors, destructors, build, and display funcitons for each
data structure.   
To build, simply compile with `g++`:
```
g++ *.cpp *.o
./a.out
```
**note**: the `supplied.o` file has been pre-compiled to run on Linux hardware

---
# List of functions

## Binary Search Tree
BST Copying functions
- `int copy(table &to_copy)`
  - Copies BST. Returns the number of nodes copied.
- `int copy_leafs(table &to_copy)`
  - Copies just the 'leafs'. Returns number of nodes copied.
- `int copy_largest_two(table &to_copy)`
  - Copies the two nodes with the largest data. Returns the average of of the data copied.
- `int copy_evens(table &to_copy)`
  - Copies just the nodes with even data. Returns the number of nodes copied.
- `int copy_root_and_successor(table &to_copy)`
  - Copies root and it's in-order-successor. Return the number of nodes copied.
- `int copy_not_root(table &to_copy)`
  - Copies all nodes but the root. Returns the number of nodes copied.
- `int copy_not_largest(table &to_copy)`
  - Copies all nodes but the largest. Returns the number of nodes copied.
- `int copy_greater_than_root(table &to_copy)`
  - Copies all nodes greater thatn the root. Returns the number of nodes copied.

BST Counting functions
- `int count()`
  - Returns the number of nodes in the BST.
- `int longest_path()`
  - Returns the number of nodes in the longest path from root to leaf.
- `int count_root()`
  - Returns the number of times roots data appears in the tree.
- `int count_root_IOS_right_tree()`
  - Returns the number of nodes in root's in-order-successor's right subtree.
- `int count_largest_left()`
  - Returns the number of nodes in the left sub-tree of the node with the largest data.
- `int count_duplicates()`
  - Returns the number of duplicate data in the BST.

BST Display functions
- `int in_order_display()`
  - Displays data in-order. Returns the number of nodes in the BST.

BST Insert functions
- `void insert(int to_add)`
  - Inserts given data into the BST.

BST General functions
- `bool appear_twice()`
  - Return true if roots data appears more than once, else return false.
- `int level_of_first()`
  - Returns the level of the first occurence of node with data = 15. Else return 0.
- `int most_frequent()`
  - Returns the data the occurs most frequently. If none occur most frequent, return the smalled data.
- `int average()`
  - Returns the average of all the data in the BST.
- `int last_15()`
  - Returns the level of the last occurence of node with data = 15, when traversing in order. Else returns 0.
- `int retrieve_IOS()`
  - Returns roots in-order-successor.
- `int average_IOS()`
  - Returns the average of the data in root's in-order-successor's right sub-tree.
- `int level_of_first_data(int number)`
  - Returns the level of the first occurence of given number when doing an in order traversal.
- `int level_of_last_data(int number)`
  - Returns the level of the last occurence of given number when doing an in order traversal.
- `int display_level(int number)`
  - Display all the data on a given level and return the average of that data.
- `int longest_path()`
  - Display the data along the longest path from root to leaf and return the average of that data.

BST Removal functions
- `int remove_largest()`
  - Removes the largest. Returns the value of the data removed.
- `int remove_except_root()`
  - Removes all nodes but the root. Returns the number of nodes removed.
- `int remove_rootsIOS()`
  - Removes root's in-order-successor. Returns the value of the node removed.
- `int remove_leafs()`
  - Removes all the 'leafs'. Returns the number of nodes removed.
- `int remove_largest_two()`
  - Removes the largest two nodes. Returns the sum the the data removed.
- `int remove_if_divisible()`
  - Removes any node who's data is divisible by 3. Returns the number of nodes removed
- `int remove_one_child()`
  - Removes all nodes who have only one child. Returns the number of nodes removed
- `int remove_smallest_one_child()`
  - Removes the smallest node with only one child. Returns the number of nodes removed.
- `void remove_smallest()`
  - Removes the node with the smalled data.
- `int remove_smallest_two()`
  - Removes the two smallest nodes. Returns the number of nodes removed.
---

## Array of singularly linked lists
ARR functions
- `int count_nodes()`
  - Return the number of nodes
- `int my_display()`
  - Display all the nodes. Return the number of nodes displayed
- `int display_all()`
  - Display all the nodes. Return the number of nodes displayed
- `int display_v2()`
  - Display all the nodes. Return the number of nodes displayed
- `int display_every_other()`
  - Displays every other data. Returns the number of nodes displayed
- `int sumEvens()`
  - Return the sum of the even data
- `int copy(table &to_copy)`
  - Copy the array of linked lists. Retrun the number of nodes copied.
- `bool devide_special()`
  - Returns true if the sum of the data in the shortest linked list devides the sum of the data in the longest linked list.
- `int append_to_all()`
  - Append the first list in the array to all the other lists. Return 1 if any lists were appended, else return 0
---

## Linearly Linked List
LLL append functions
- `void append(int to_append)`
  - Append argument list to the end of this list.
- `int append_if_divisible(int to_add)`
  - For each data in the list that is divisible by the first node's data, append the given data to the end of the list. Return the number of nodes appended.

LLL copy functions
- `int copy(list &copyTo)`
  - Copy the list. Return the number of nodes copied
- `int copy_v2(list &copyTo)`
  - Copy the list. Return the number of nodes copied
- `int copy_only_arg(list &copyTo, int toCopy)`
  - Copy the elements of the list with data equal to the given argument. Return the number of nodes copied
- `int copy_even(list &to_copy)`
  - Copy the even data. Return the number of nodes copied

LLL count functions
- `int average_evens()`
  - Return the average of the even data in the list
- `int average_unique()`
  - Return the average of the unique data in the list
- `int is_in_list(int data)`
  - Return the number of times given data occurs in the list
- `int count_last()`
  - Return the number of times the last data appears in the list

LLL display functions
- `int display_last()`
  - Display and return the last data if it doesnt equal the first data, else don't display, and return 0
- `int display_unique()`
  - Display only the unique data. Return the number of unique data
- `int display_uniquely()`
  - Displays a LLL but only displays each data once. Returns the number of data displayed

LLL modify functions
- `int reverse()`
  - Reverse the linked list. Return the number of nodes in the list
- `int reverse_every_3()`
  - Reverses evey three elements of the list. Returns the number of nodes altered:
- `int remove_center()`
  - Remove all but the head and tail nodes. Return the sum of the data removed
- `int modify_after()`
  - Add the data of the first node divisible by 3 or 5 to every following node. Return the number of nodes that occur before a node is divisible by four
- `int move_first_to_last()`
  - Moves the first node to the end of the list. Returns the sum of all the nodes but the one moved.
---
## DLL
## CLL
