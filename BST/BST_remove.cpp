#include "table.h"

//////////////////////////////////////////////////////////////////////////////
// Removes the largest. Returns the value of the data removed.
//////////////////////////////////////////////////////////////////////////////
// Wrapper
int table::remove_largest()
{
   if (!root)
      return 0;
   return remove_largest(root);
}

// Recursive
int table::remove_largest(node *&root)
{
   int value = 0;
   if (!root->right)
   {
      value = root->data;
      node *hold = root->left;
      delete root;
      root = hold;
      return value;
   }
   return remove_largest(root->right);
}

//////////////////////////////////////////////////////////////////////////////
// Removes all nodes but the root. Returns the number of nodes removed.
//////////////////////////////////////////////////////////////////////////////
// Public Wrapper
int table::remove_except_root()
{
   if (!root)
      return 0;
   return remove_all(root->left) + remove_all(root->right);
}

// Private recursive
int table::remove_all(node *&root)
{
   int count = 0;
   if (!root)
      return 0;
   count = remove_all(root->left);
   count += remove_all(root->right);
   delete root;
   root = NULL;
   ++count;
   return count;
}

//////////////////////////////////////////////////////////////////////////////
// Removes root's in-order-successor. Returns the value of the node removed.
//////////////////////////////////////////////////////////////////////////////
int table::remove_roots_IOS()
{
   if (!root)
      return 0;
   return find_and_delete_IOS(root->right);
}

// Private recursive
int table::find_and_delete_IOS(node *&root)
{
   if (!root->left)
   {
      int value = root->data;
      node *temp = root->right;
      delete root;
      root = temp;
      return value;
   }
   return find_and_delete_IOS(root->left);
}

//////////////////////////////////////////////////////////////////////////////
// remove all the leafs. Return the number of nodes removed
//////////////////////////////////////////////////////////////////////////////
int table::remove_leafs()
{
   if (!root)
      return 0;
   return remove_leafs(root);
}

// Private recursive
int table::remove_leafs(node *&root)
{
   int count = 0;
   if (!root)
      return 0;
   if (!root->left && !root->right)
   {
      delete root;
      root = NULL;
      return 1;
   }
   count = remove_leafs(root->left);
   count += remove_leafs(root->right);
   return count;
}

//////////////////////////////////////////////////////////////////////////////
// Removes the largest two nodes. Returns the sum the the data removed.
//////////////////////////////////////////////////////////////////////////////
int table::remove_largest_two()
{
   int removed = 0;
   if (!root)
      return 0;
   return remove_largest_two(root, removed);
}

// Private recursive
int table::remove_largest_two(node *&root, int &removed)
{
   int value = 0;

   if (!root)
      return 0;
   if (!root->right) // we are at the largest
   {
      if (!root->left) // largest has no left child
      {
         cout << "LARGEST HAS NO LEFT CHILD\n";
         value = root->data;
         delete root;
         root = NULL;
         ++removed;
      }
      else // largest does have a left child
      {
         cout << "LARGEST DOES HAVE A LEFT CHILD\n";
         value = remove_largest(root->left); // remove the largest in largests left subtree
         ++removed;

         value += root->data; // remove the largest
         node *hold = root->left;
         delete root;
         root = hold;
         ++removed;
      }
      return value;
   }
   value += remove_largest_two(root->right, removed);
   if (removed < 2)
   {
      cout << "REMOVED: " << removed << endl;
      cout << "WWERE DELETING WITH HEAD RECURION\n";
      value += root->data;
      node *hold = root->left;
      delete root;
      root = hold;
      ++removed;
   }
   return value;
}

//////////////////////////////////////////////////////////////////////////////
// Removes any node who's data is divisible by 3.
// Returns the number of nodes removed
//////////////////////////////////////////////////////////////////////////////
int table::remove_if_divisible()
{
   if (!root)
      return 0;
   return remove_if_divisible(root);
}

// Private recursive
int table::remove_if_divisible(node *&root)
{
   int count = 0;
   if (!root)
      return 0;
   if (root->data % 3 == 0 && root->data % 5 == 0)
   {
      count += remove(root);
      count += remove_if_divisible(root);
      return count;
   }
   count += remove_if_divisible(root->left);
   count += remove_if_divisible(root->right);
   return count;
}

// Private helper
int table::remove(node *&root)
// removes the root node and returns 1
{
   if (!root)
      return 0;

   // root has no children
   if (!root->left && !root->right)
   {
      delete root;
      root = NULL;
      return 1;
   }

   // root had 1 child, a right
   else if (!root->left && root->right)
   {
      node *hold = root->right;
      delete root;
      root = hold;
   }

   // root had 1 child, a left
   else if (root->left && !root->right)
   {
      node *hold = root->left;
      delete root;
      root = hold;
   }

   // root has 2 children
   else
   {
      // right child has NO left child
      if (!root->right->left)
      {
         root->data = root->right->data;
         node *hold = root->right->right;
         delete root->right;
         root->right = hold;
      }
      // right child has a left child
      else
         root->data = delete_and_retrieve_smallest(root->right->left);
   }
   return 1;
}

// Private helper
int table::delete_and_retrieve_smallest(node *&root)
{
   int num = 0;
   if (!root)
      return 0;
   if (!root->left)
   {
      num = root->data;
      node *hold = root->right;
      delete root;
      root = hold;
      return num;
   }
   return delete_and_retrieve_smallest(root->left);
}

//////////////////////////////////////////////////////////////////////////////
// Removes all nodes who have only one child.
// Returns the number of nodes removed
//////////////////////////////////////////////////////////////////////////////
int table::remove_one_child()
{
   if (!root)
      return 0;
   return remove_one_child(root);
}

// Private recursive
int table::remove_one_child(node *&root)
{
   int count = 0;
   if (!root)
      return 0;
   if (!root->left && !root->right)
      return 0;

   if (!root->left)
   {
      root = root->right;
      ++count;
      count += remove_one_child(root);
      return count;
   }
   if (!root->right)
   {
      root = root->left;
      ++count;
      count += remove_one_child(root);
      return count;
   }
   count += remove_one_child(root->left);
   count += remove_one_child(root->right);
   return count;
}

//////////////////////////////////////////////////////////////////////////////
// Removes the smallest node with only one child.
// Returns the number of nodes removed.
//////////////////////////////////////////////////////////////////////////////
int table::remove_smallest_one_child()
{
   bool isRemoved = false;
   if (!root)
      return 0;
   return remove_smallest_one_child(root, isRemoved);
}

// Private recursive
int table::remove_smallest_one_child(node *&root, bool &isRemoved)
{
   int count = 0;

   if (!root)
      return 0;

   count = remove_smallest_one_child(root->left, isRemoved);

   if (!root->left && root->right && !isRemoved)
   {
      node *hold = root->right;
      delete root;
      root = hold;
      isRemoved = true;
      return 1;
   }
   if (root->left && !root->right && !isRemoved)
   {
      node *hold = root->left;
      delete root;
      root = hold;
      isRemoved = true;
      return 1;
   }

   count += remove_smallest_one_child(root->right, isRemoved);
   return count;
}

void table::remove_smallest()
{
   if (!root)
      return;
   remove_smallest(root);
}

//////////////////////////////////////////////////////////////////////////////
// Removes the node with the smalled data.
//////////////////////////////////////////////////////////////////////////////
void table::remove_smallest(node *&root)
{
   // either smalles has one right child or no children
   if (!root->left)
   {
      if (!root->right) // smallst has no choldern
      {
         delete root;
         root = NULL;
         return;
      }
      else
      {
         node *hold = root->right;
         delete root;
         root = hold;
         return;
      }
   }
   remove_smallest(root->left);
}

// Private recursive
int table::remove_smallest_two()
{
   bool removed = false;
   if (!root)
      return 1;
   return remove_smallest_two(root, removed);
}

//////////////////////////////////////////////////////////////////////////////
// Removes the two smallest nodes. Returns the number of nodes removed.
//////////////////////////////////////////////////////////////////////////////
int table::remove_smallest_two(node *&root, bool &removed)
{
   int total = 0;
   int number;
   if (!root)
      return 0;
   if (!root->left) // we are at the smallest node
   {
      if (!root->right) // smallest node has no children
      {
         number = root->data;
         delete root;
         root = NULL;
      }
      else
      // case 2: smallest has a right child
      //  delete the smallest's ios
      //  then on the way back delete the smallest
      {
         number = delete_smallest(root->right);
         number += root->data;
         node *hold = root->right;
         delete root;
         root = hold;
         removed = true;
      }
      return number;
   }
   total += remove_smallest_two(root->left, removed);
   if (!removed)
   {
      int result = root->data;
      node *hold = root->right;
      delete root;
      root = hold;
      removed = true;
      return result + number;
   }
   return total;
}

// Private helper
int table::delete_smallest(node *&root)
{
   if (!root)
      return 0;
   if (!root->left)
   {
      int temp = root->data;
      node *hold = root->right;
      delete root;
      root = hold;
      return temp;
   }
   return delete_smallest(root->left);
}
