#include "table.h"

int main()
{
    table object;
    table object2;

    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    int result = object2.copyRootAndSuccessor(object);
    cout << "We copied " << result << " nodes";
    cout << endl;
    cout << "Copy: ";
    object2.display();

    return 0;
}
