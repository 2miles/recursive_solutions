#include "dlist.h"

int main()
{
    list object;
    list object2;
    object.build();
    object.display();

    // PLEASE PUT YOUR CODE HERE to call the function assigned

    int result = object.add_after(99);
    cout << "We added " << result << " nodes";

    object.display();
    return 0;
}
