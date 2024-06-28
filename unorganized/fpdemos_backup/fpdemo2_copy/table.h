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
      void insert(int to_add);
      int mostFrequent();
 
      int otherCopyEvens(table & dest);
      int copyNotLargest(table & to_copy);
      int removeOneChild();
      int copyNotRoot(table & to_copy);
      int average();
      int removeSmallestOneChild();
      void removeSmallest();
      int removeEveryLeaf();
      int copyEvens(table &);
      int retrieveIOS();
      int copyGreaterThanRoot(table &);
      int removeIfDivisible();
      int removeSmallestTwo();
      int copyEvensIf(table & to_copy);
      int last15();
      int levelOfFirst();
 	private:
 		node * root;

/* ************** PLACE YOUR PRIVATE PROTOTYPE HERE ***************** */

      void insert(node *& root, int to_add);
      void mostFrequent(node * root, int & prev, int & mostFreq, int & count, int & largest);
      int otherCopyEvens(node *& dest, node * current);
      int copyRootAndLeftSub(node *& dest, node * source);
      int copy(node *& dest, node * source);
      int copyNotLargest(node *& dest_root, node * source_root);
      int removeOneChild(node *& root);
      int average(node * root, int & sum);
      node * largest(node * root);
      int removeSmallestOneChild(node *& root, bool & isremoved);
      void removeSmallest(node *& root);
      int removeEveryLeaf(node *& root);
      int copyEvens(node *&, node*);
      int retrieveIOS(node *  root);
      int copyGreaterThanRoot(node *& dest, node * source, int original);
      int removeIfDivisible(node *&);
      int remove(node *&);
      int deleteAndRetrieveSmallest(node *&);
      int removeSmallestTwo(node *& root, bool & removed);
      int deleteSmallest(node *& root);
      int copyEvensIf(node *& dest, node * source);
      int last15(node *, bool & found);
      int levelOfFirst(node * root, bool & found);

};

  

