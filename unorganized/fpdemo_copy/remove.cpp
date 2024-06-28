#include "table.h"

//remove the largest item
//return the item removed
/////////////////////////////////////////////////
int table::removeLargest()
{
   if(!root) return 0;
   return removeLargest(root);
}

/*
int table::removeLargest(node *& root)
{
   if(!root->right) //we are at the largest
   {
      int largestData = root->data;
      if(!root->left)//CASE 1: no children
      {
         delete root;
         root = NULL;
      }
      else//CASE 2: left child
      {
         node * hold = root->left;
         delete root;
         root->right = hold;
      }
      return largestData;
   }
   return removeLargest(root->right);
}
*/


//remove all the nodes in the left and right subtrees
//Return the nomber of nodes removed
///////////////////////////////////////////////////
int table::removeExceptRoot()
{
   if(!root) return 0;
   return removeAll(root->left) + removeAll(root->right);
}

int table::removeAll(node *& root)
{
   int count = 0;
   if(!root) return 0;
   count = removeAll(root->left);
   count += removeAll(root->right);
   delete root;
   root = NULL;
   ++count;
   return count;
}

//remove roots ios and return the value
/////////////////////////////////////////////////
int table::removeRootsIOS()
{
   if(!root) return 0;
   return findAndDeleteIos(root->right);
}


int table::findAndDeleteIos(node *& root)
{
   if(!root->left)
   {
      int value = root->data;
      node * temp = root->right;
      delete root;
      root = temp;
      return value;
   }
   return findAndDeleteIos(root->left);
}


//remove all the leafs
//return the number of nodes removed
////////////////////////////////////////////////////
int table::removeLeafs()
{
   if(!root) return 0;
   return removeLeafs(root);
}

int table::removeLeafs(node *& root)
{
   int count = 0;
   if(!root) return 0;
   if(!root->left && !root->right)
   {
      delete root;
      root = NULL;
      return 1;
   }
   count = removeLeafs(root->left);
   count += removeLeafs(root->right);
   return count;
}

//remove the largst 2 items in the tree
//return the sum of the two numbers

int table::removeLargest2()
{
   int removed = 0;
   if(!root) return 0;
   return removeLargest2(root, removed);
}

int table::removeLargest2(node *& root, int & removed)
{
   int value = 0;

   if(!root) return 0;
   if(!root->right) //we are at the largest
   {
      if(!root->left)  //largest has no left child
      {
         cout << "LARGEST HAS NO LEFT CHILD\n";
         value = root->data;
         delete root;
         root = NULL;
         ++removed;
      }
      else //largest does have a left child
      {
         cout << "LARGEST DOES HAVE A LEFT CHILD\n";
         value = removeLargest(root->left); //remove the largest in largests left subtree
         ++removed;

         value += root->data; //remove the largest
         node * hold = root->left;
         delete root;
         root = hold;
         ++removed;
      }
      return value;
   }
   value += removeLargest2(root->right, removed);
   if(removed < 2)
   {
      cout << "REMOVED: " << removed << endl;
      cout << "WWERE DELETING WITH HEAD RECURION\n";
      value += root->data;
      node * hold = root->left;
      delete root;
      root = hold;
      ++removed;
   }
   return value;
}

//remove the larges and return the value of the item removed
int table::removeLargest(node *& root)
{
   int value = 0;
   if(!root->right)
   {
      value = root->data;
      node * hold = root->left;
      delete root;
      root = hold;
      return value;
   }
   return removeLargest(root->right);
}
