#include "table.h"

//////////////////////////////////////////////////////////////////////////////
// Returns the number of nodes in the BST.
//////////////////////////////////////////////////////////////////////////////
int table::count()
{
   if (!root)
      return 0;
   return count(root);
}
// Private recursive
int table::count(node *root)
{
   int num = 0;
   if (!root)
      return 0;
   ++num;
   num += count(root->left);
   num += count(root->right);
   return num;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the number of nodes in the longest path from root to leaf.
//////////////////////////////////////////////////////////////////////////////
int table::longest_path()
{
   if (!root)
      return 0;
   return longest_path(root);
}

// Private recursive
int table::longest_path(node *&root)
{
   if (!root)
      return 0;
   return max(longest_path(root->left), longest_path(root->right)) + 1;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the number of times roots data appears in the tree.
//////////////////////////////////////////////////////////////////////////////
int table::count_root()
{
   if (!root)
      return 0;
   return count_root(root);
}

// Private recursive
int table::count_root(node *root)
{
   int count = 0;
   if (!root)
      return 0;
   if (root->data == this->root->data)
      ++count;
   if (root->data < this->root->data)
      count += count_root(root->left);
   else
      count += count_root(root->right);
   return count;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the number of nodes in root's in-order-successor's right subtree.
//////////////////////////////////////////////////////////////////////////////
int table::count_root_IOS_right_tree()
{
   if (!root)
      return 0;                // tree is empty
   node *ios = find_IOS(root); // get ios
   return count(ios->right);
}

// Private recursive
// return pointer to roots IOS
node *table::find_IOS(node *root)
{
   if (!root->right)
      return root;
   node *current = root->right;
   while (current->left)
      current = current->left;
   return current;
}

//////////////////////////////////////////////////////////////////////////////
// Returns the number of nodes in the left sub-tree of the node with the
// largest data.
//////////////////////////////////////////////////////////////////////////////
int table::count_largest_left()
{
   if (!root)
      return 0;
   node *largest = find_largest(root);
   return count(largest->left);
}

// Private recursive
// returns pointer to the largest data in the tree
node *table::find_largest(node *root)
{
   if (!root->right)
      return root;
   return find_largest(root->right);
}

//////////////////////////////////////////////////////////////////////////////
// Returns the number of duplicate data in the BST.
//////////////////////////////////////////////////////////////////////////////
int table::count_duplicates()
{
   int prev = 0;
   if (!root)
      return 0;
   return count_duplicates(root, prev);
}

// Private recursive
int table::count_duplicates(node *root, int &prev)
{
   int count = 0;
   if (!root)
      return 0;
   count = count_duplicates(root->left, prev);
   if (root->data == prev)
      ++count;
   prev = root->data;
   count += count_duplicates(root->right, prev);
   return count;
}
