#include "table.h"

int main()
{
   table object;

   object.build(); 	//builds a BST
   object.display();
   /*  PLACE YOUR FUNCTION CALL HERE */

   int result = object.levelOfFirst();
   cout << "The frist 15 is on level: " << result << endl;


    return 0;
}
