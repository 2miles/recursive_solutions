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
      int levelOfFirstData(int number);
      int levelOfLastData(int number);
      int displayLevel(int number);
      int longestPath();
      int averageIOS();


/* ************** PLACE YOUR PUBLIC PROTOTYPE HERE ***************** */
 
      //display in order
      //return the number of nodes displayed
 
 	private:
 		node * root;

/* ************** PLACE YOUR PRIVATE PROTOTYPE HERE ***************** */

      int levelOfFirstData(node * root, int number, bool & found);
      int levelOfLastData(node * root, int number, bool & found);
      int displayLevel(node * root, int & level, int number, int & sum);
      int longestPath(node * root, int & level, bool & found, int height, int & sum);
      int findHeight(node * root);
      int numberOfNodes(node * root, int & sum);
      node * getIOS(node * root);
};

  

