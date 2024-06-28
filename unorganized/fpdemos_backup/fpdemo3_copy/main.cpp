#include "table.h"

int main()
{
   table object;

   object.build(); 	//builds a BST
   object.display();
   /*  PLACE YOUR FUNCTION CALL HERE */

   int result = object.averageIOS();
   cout << "The the avargage of the data in roots ios left tree: " << result << endl;

    return 0;
}
