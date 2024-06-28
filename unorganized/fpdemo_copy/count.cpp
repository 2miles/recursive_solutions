#include "table.h"

//return the number of nodes in the tree
//////////////////////////////////////////////
int table::count ()
{
   if(!root) return 0;
   return count(root);
}
int table::count (node * root)
{
   int num = 0;
   if(!root) return 0;
   ++num;
   num += count(root->left);
   num += count(root->right);
   return num;
}


//return the number of nodes in the longest path
//////////////////////////////////////////////////
int table::longestPath()
{
   if(!root) return 0;
   return longestPath(root);
}

int table::longestPath(node *& root)
{
   if(!root) return 0;
   return max(longestPath(root->left), longestPath(root->right)) + 1;
}


//return the number of times roots data aprears in the tree
//////////////////////////////////////////////////////
int table::countRoot()
{
   if(!root) return 0;
   return countRoot(root);
}

int table::countRoot(node * root)
{
   int count = 0;
   if(!root) return 0;
   if(root->data == this->root->data)
      ++count;
   if(root->data < this->root->data)
      count += countRoot(root->left);
   else
      count += countRoot(root->right);
   return count;
}


//return the number of nodes in root's IOS's right sub-tree
////////////////////////////////////////////////////
int table::countRootIOSRightTree()
{
   if(!root) return 0; //tree is empty
   node * ios = findIOS(root);  //get ios
   return count(ios->right);
}

//return pointer to roots IOS
node * table::findIOS(node * root)
{
   if(!root->right) 
      return root;
   node * current = root->right;
   while (current->left)
      current = current->left;
   return current;
}


//return number of nodes in largest's left subtree
//////////////////////////////////////////////////
int table::countLargestLeft()
{
   if(!root) return 0;
   node * largest = findLargest(root);
   return count(largest->left);
}

//returns pointer to the largest data in the tree
node * table::findLargest(node * root)
{
   if(!root->right) return root;
   return findLargest(root->right);
}

//return the number of duplicates in the tree
/////////////////////////////////////////////////
int table::countDuplicates()
{
   int prev = 0;
   if(!root) return 0;
   return countDuplicates(root, prev);
}

int table::countDuplicates(node * root, int & prev)
{
   int count = 0;
   if(!root) return 0;
   count = countDuplicates(root->left, prev);
   if(root->data == prev)
      ++count;
   prev = root->data;
   count += countDuplicates(root->right, prev);
   return count;

}
