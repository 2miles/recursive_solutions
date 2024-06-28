#include "table.h"

//copy argument tree into this object
//return the number of nodes copied
///////////////////////////////////////////////////
int table::copy(table & to_copy)
{
   if(!to_copy.root) return 0;
   return copy(root,to_copy.root);
}

int table::copy( node *& dest_root, node * source_root)
{
   int count = 0;
   if(!source_root) return 0;
   dest_root = new node;
   dest_root->data = source_root->data;
   ++count;
   count += copy(dest_root->left, source_root->left);
   count += copy(dest_root->right, source_root->right);
   return count;
}


//copy just the leafs of argument into this tree
//////////////////////////////////////////////////////
int table::copyLeafs(table & to_copy)
{
   if(!to_copy.root) return 0;
   return copyLeafs(root, to_copy.root);
}

int table::copyLeafs(node *& dest_root, node * source_root)
{
   int sum = 0;
   if(!source_root) return 0;
   if(!source_root->left && !source_root->right)
   {
      //copy node
      dest_root = new node;
      dest_root->data = source_root->data;

      dest_root->left = NULL;
      dest_root->right = NULL;
      sum = dest_root->data;
      return sum;
   }

   if(dest_root)
   {
      node * current = dest_root;
      while(current->right)
         current = current->right;
      sum += copyLeafs(current->right, source_root->left);
   }
   else
      sum += copyLeafs(dest_root, source_root->left);

   if(dest_root)
   {
      node * current = dest_root;
      while(current->right)
         current = current->right;
      sum += copyLeafs(current->right, source_root->right);
   }
   else
      sum += copyLeafs(dest_root, source_root->right);

   return sum;
}


//copy the largest two data in argument list into this list
//Retrun the average o;f the data of the two data copied
/////////////////////////////////////////////////////////////
int table::copyLargestTwo(table & to_copy)
{
   if(!to_copy.root) return 0;
   return copyLargestTwo( root, to_copy.root) / 2;
}

int table::copyLargestTwo(node *& dest_root, node * source_root)
{
   int sum = 0;
   if(!source_root->right && source_root->left)
   {
      dest_root = new node;
      dest_root->data = source_root->data;
      dest_root->left = NULL;
      dest_root->right = new node;
      dest_root->right->data = largestData(source_root->left);
      dest_root->right->left = dest_root->right->right = NULL;
      sum = dest_root->data + dest_root->right->data;
      return sum;
   }

   if(!source_root->right->right && !source_root->right->left) 
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
   sum += copyLargestTwo(dest_root, source_root->right);
   return sum;  //i dont htink this code ever happens but the compiler was bummed so i added it 
}

//return the largest data in a tree
int table::largestData(node * root)
{
   if(!root) return 0;
   if(!root->right) return root->data;
   return largestData(root->right);
}


//copy the even data
//////////////////////////////////////////////////////////////
int table::copyEvens(table & to_copy)
{
   if(!to_copy.root) return 0;
   return  copyEvens(root, to_copy.root);
}
int table::copyEvens(node *& dest_root, node * source_root)
{

   int count = 0;
   if(!source_root) return 0;

   if(source_root->data % 2 == 0)
   {
      dest_root = new node;
      dest_root->data = source_root->data;
      ++count;
      dest_root->left = NULL;
      dest_root->right = NULL;
   }

   node * current;
   if(dest_root)
   {
      current = dest_root;
      while(current->left && current->data >= source_root->data)
         current = current->left;
      count += copyEvens(current->left, source_root->left);//
   }
   else
      count += copyEvens(dest_root, source_root->left);//


   if(dest_root)
   {
      current = dest_root;
      while(current->right && current->data < source_root->data)
         current = current->right;
      count += copyEvens(current->right, source_root->right);//
   }
   else
      count += copyEvens(dest_root, source_root->right);//
   return count;
}

int table::copyRootAndSuccessor(table & to_copy)
{
   if(!to_copy.root) return 0;

   root = new node;
   root->data = to_copy.root->data;
   root->left = root->right = NULL;
   if(!to_copy.root->right) return 1;

   
   root->right = new node;
   root->right->data = smallest(to_copy.root->right);
   root->right->left = root->right->right = NULL;
   return 2;
}

int table::smallest(node * root)
{
   if(!root->left) return root->data;
   return smallest(root->left);
}


