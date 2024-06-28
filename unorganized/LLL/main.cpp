#include "list.h"

int main()
{
    list object;
    list object2;   //blank list to copy into

    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    int result = object.reverseEvery3();
    cout << "we reversed  " << result << " nodes";
   
    object.display();  //displays the LLL again!


    return 0;
}
