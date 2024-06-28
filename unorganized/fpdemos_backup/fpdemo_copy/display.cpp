#include "table.h"

int table::inOrderDisplay()
{
   if(!root) return 0;
   return inOrderDisplay(root);
}

int table::inOrderDisplay( node *& root)
{
   int count = 0;
   if(!root) return 0;
   count = inOrderDisplay(root->left) + 1;
   cout << root->data << ' ';
   count += inOrderDisplay(root->right);
   return count;

}
