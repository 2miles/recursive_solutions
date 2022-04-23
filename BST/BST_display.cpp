#include "table.h"
//////////////////////////////////////////////////////////////////////////////
// Displays data in-order. Returns the number of nodes in the BST.
//////////////////////////////////////////////////////////////////////////////
int table::in_order_display()
{
   if (!root)
      return 0;
   return in_order_display(root);
}
// Private recursive
int table::in_order_display(node *&root)
{
   int count = 0;
   if (!root)
      return 0;
   count = in_order_display(root->left) + 1;
   cout << root->data << ' ';
   count += in_order_display(root->right);
   return count;
}
