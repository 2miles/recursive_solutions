//table.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class table
{
    public:
    	//These functions are supplied already
    	table();			//supplied
    	~table();			//supplied
      void build(); 		//supplied
      void display(); 	//supplied


/* ************** PLACE YOUR PUBLIC PROTOTYPE HERE ***************** */
 
      //display in order
      //return the number of nodes displayed
      int inOrderDisplay(); 
      int copy(table & to_copy);
      int copyLeafs(table & to_copy);
      int copyLargestTwo(table & to_copy);
      int count();
      void insert(int to_add);
      int longestPath();
      int countRoot();
      int countRootIOSRightTree();
      int countLargestLeft();
      int removeLargest();
      int removeExceptRoot();
      int removeRootsIOS();
      int removeLeafs();
      int removeLargest2();
      bool appearTwice();
      int countDuplicates();
      int copyEvens(table & to_copy);
      int copyRootAndSuccessor(table & to_copy);
 
 	private:
 		node * root;

/* ************** PLACE YOUR PRIVATE PROTOTYPE HERE ***************** */

      int inOrderDisplay( node *& root);
      int copy(node *& dest, node * source);
      //int copyNoChildren(node * source);
      int copyLeafs(node *& dest, node * source);
      int copyLargestTwo(node *& dest_root, node * source_root);
      int largestData(node * root);
      int count(node * root);
      void insert(node *& root, int to_add);
      int longestPath(node *& root);
      int countRoot(node * root);
      int countRootIOSRightTree(node * root);
      node * findIOS(node * root);
      node * findLargest( node * root);
      int removeLargest(node *& root);
      int removeAll(node *& root);
      int findAndDeleteIos(node *& root);
      int removeLeafs(node *& root);
      int removeLargest2(node *& root, int & removed);
      bool appearTwice(node * root, int rootData);
      int countDuplicates(node * root, int & prev);
      int copyEvens(node *& dest, node * souce);
      int smallest(node * root);
};
  

