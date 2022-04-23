#include "table.h"

//////////////////////////////////////////////////////////////////////////////
// Copies BST. Returns the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy(table &to_copy)
{
   if (!to_copy.root)
      return 0;
   return copy(root, to_copy.root);
}

// Private recursive
int table::copy(node *&dest_root, node *source_root)
{
   int count = 0;
   if (!source_root)
      return 0;
   dest_root = new node;
   dest_root->data = source_root->data;
   ++count;
   count += copy(dest_root->left, source_root->left);
   count += copy(dest_root->right, source_root->right);
   return count;
}

//////////////////////////////////////////////////////////////////////////////
// Copies just the 'leafs'. Returns number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy_leafs(table &to_copy)
{
   if (!to_copy.root)
      return 0;
   return copy_leafs(root, to_copy.root);
}

// Private recursive
int table::copy_leafs(node *&dest_root, node *source_root)
{
   int sum = 0;
   if (!source_root)
      return 0;
   if (!source_root->left && !source_root->right)
   {
      // copy node
      dest_root = new node;
      dest_root->data = source_root->data;

      dest_root->left = NULL;
      dest_root->right = NULL;
      sum = dest_root->data;
      return sum;
   }

   if (dest_root)
   {
      node *current = dest_root;
      while (current->right)
         current = current->right;
      sum += copy_leafs(current->right, source_root->left);
   }
   else
      sum += copy_leafs(dest_root, source_root->left);

   if (dest_root)
   {
      node *current = dest_root;
      while (current->right)
         current = current->right;
      sum += copy_leafs(current->right, source_root->right);
   }
   else
      sum += copy_leafs(dest_root, source_root->right);

   return sum;
}

//////////////////////////////////////////////////////////////////////////////
// Copies the two nodes with the largest data.
// Returns the average of of the data copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy_largest_two(table &to_copy)
{
   if (!to_copy.root)
      return 0;
   return copy_largest_two(root, to_copy.root) / 2;
}

// Private recursive
int table::copy_largest_two(node *&dest_root, node *source_root)
{
   int sum = 0;
   if (!source_root->right && source_root->left)
   {
      dest_root = new node;
      dest_root->data = source_root->data;
      dest_root->left = NULL;
      dest_root->right = new node;
      dest_root->right->data = largest_data(source_root->left);
      dest_root->right->left = dest_root->right->right = NULL;
      sum = dest_root->data + dest_root->right->data;
      return sum;
   }

   if (!source_root->right->right && !source_root->right->left)
   {
      dest_root = new node;
      dest_root->data = source_root->data;
      dest_root->left = NULL;
      dest_root->right = new node;
      dest_root->right->data = source_root->right->data;
      dest_root->right->left = dest_root->right->right = NULL;
      sum = dest_root->data + dest_root->right->data;
      return sum;
   }
   sum += copy_largest_two(dest_root, source_root->right);
   return sum; // i dont htink this code ever happens but the compiler was bummed so i added it
}

// Private helper
// return the largest data in a tree
int table::largest_data(node *root)
{
   if (!root)
      return 0;
   if (!root->right)
      return root->data;
   return largest_data(root->right);
}

//////////////////////////////////////////////////////////////////////////////
// Copies just the nodes with even data. Returns the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy_evens(table &to_copy)
{
   if (!to_copy.root)
      return 0;
   return copy_evens(root, to_copy.root);
}

// Private recursive
int table::copy_evens(node *&dest, node *source)
{
   int count = 0;
   if (!source)
      return 0;
   if (dest)
      count += copy_evens(dest->right, source);
   else
   {
      if (source->data % 2 == 0)
      {
         dest = new node;
         dest->data = source->data;
         dest->left = dest->right = NULL;
         ++count;
         count += copy_evens(dest->left, source->left);
         count += copy_evens(dest->right, source->right);
      }
      else
      {
         count += copy_evens(dest, source->left);
         count += copy_evens(dest, source->right);
      }
   }
   return count;
}

//////////////////////////////////////////////////////////////////////////////
// Copies root and it's in-order-successor. Return the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy_root_and_successor(table &to_copy)
{
   if (!to_copy.root)
      return 0;

   root = new node;
   root->data = to_copy.root->data;
   root->left = root->right = NULL;
   if (!to_copy.root->right)
      return 1;

   root->right = new node;
   root->right->data = smallest(to_copy.root->right);
   root->right->left = root->right->right = NULL;
   return 2;
}

// Private helper
int table::smallest(node *root)
{
   if (!root->left)
      return root->data;
   return smallest(root->left);
}

//////////////////////////////////////////////////////////////////////////////
// Copies all nodes but the root. Returns the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy_not_root(table &to_copy)
{
   int count = 0;
   if (!to_copy.root)
      return 0; // source tree is empty
   if (!to_copy.root->right && !to_copy.root->left)
      return 0;                              // source tree has one node
   if (!to_copy.root->right)                 // source tree root has one left child
      return copy(root, to_copy.root->left); // source tree root has one right child
   if (!to_copy.root->left)
      return copy(root, to_copy.root->right);
   else // source tree root ahs two children
   {
      node *hold = to_copy.root->right;
      count = copy(root, to_copy.root->left);
      node *largestNode = largest(root);
      count += copy(largestNode->right, hold);
      return count;
   }
}

// Private recursive
// return a pointer to the largest element in the tree
node *table::largest(node *root)
{
   if (!root)
      return NULL;
   if (!root->right)
      return root;
   return largest(root->right);
}

//////////////////////////////////////////////////////////////////////////////
// Copies all nodes but the largest. Returns the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy_not_largest(table &to_copy)
{
   if (!to_copy.root)
      return 0;
   return copy_not_largest(root, to_copy.root);
}

// recursive function:
// keep calling copy_root_and_left_sub on roots right child
// until roots right child is the largest element
// Then either return or copy largest's left subtree
int table::copy_not_largest(node *&dest_root, node *source_root)
{
   int count = 0;
   if (!source_root->right && !source_root->left)
      return count;
   if (!source_root->right && source_root->left)
   {
      count += copy(dest_root, source_root->left);
      return count;
   }
   count += copy_root_and_left_sub(dest_root, source_root);
   count += copy_not_largest(dest_root->right, source_root->right);
   return count;
}
// copy root and left subtree HELPER
int table::copy_root_and_left_sub(node *&dest_root, node *source_root)
{
   int count = 0;
   if (!source_root)
      return 0;
   dest_root = new node;
   dest_root->data = source_root->data;
   dest_root->left = dest_root->right = NULL;
   ++count;
   count += copy(dest_root->left, source_root->left);
   return count;
}

//////////////////////////////////////////////////////////////////////////////
// Copies all nodes greater thatn the root. Returns the number of nodes copied.
//////////////////////////////////////////////////////////////////////////////
int table::copy_greater_than_root(table &to_copy)
{
   if (!to_copy.root)
      return 0;
   if (!to_copy.root->right)
      return 0;
   return copy_greater_than_root(root, to_copy.root->right, to_copy.root->data);
}

// Private recursive
int table::copy_greater_than_root(node *&dest, node *source, int original)
{
   int count = 0;
   if (!source)
      return 0;
   if (dest)
      count += copy_greater_than_root(dest->right, source, original);
   if (source->data > original)
   {
      dest = new node;
      dest->data = source->data;
      dest->left = dest->right = NULL;
      ++count;
      count += copy_greater_than_root(dest->left, source->left, original);
      count += copy_greater_than_root(dest->right, source->right, original);
   }
   else
   {
      count += copy_greater_than_root(dest, source->left, original);
      count += copy_greater_than_root(dest, source->right, original);
   }
   return count;
}