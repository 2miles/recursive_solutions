#include "clist.h"

int main()
{
    list object;
    object.build();   // builds a circular LL
    object.display(); // displays the list

    // PLEASE PUT YOUR CODE HERE to call the function assigned

    int result = object.add_after(99);
    cout << "We added " << result << " nodes";

    object.display(); // resulting list after your function call!

    return 0;
}
