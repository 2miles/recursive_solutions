#include "dlist.h"


int main()
{
    list object;
    list object2;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    int result = object2.copyEvery2(object);

    cout << "We copied: " << result << " twos";
    object2.display();
    return 0;
}
